//
//  main.cpp
//  11. Tarea Nodo Dummy Listas
//
//  Created by Alex Vasquez on 10/9/19.
//  Copyright © 2019 Alex Vasquez. All rights reserved.
//
#include <iostream>
using namespace std;

template <typename T>
class Nodo{
public:
    T valor;
    Nodo<T>* siguiente = nullptr;
};

template <typename T>
class Lista{
public:

    Lista(){
        agregarDummy();
    }
    ~Lista(){
        auto actual = Dummy;
        while (actual){
            auto temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
        }

    void agregarDummy(){ // CREACION NODO DUMMY
        auto nodoDummy = new Nodo<T>;
        nodoDummy->valor = 0;
        nodoDummy -> siguiente = head;
        Dummy = nodoDummy;
    }
    
    void agregarInicio(T valor){
        if (Dummy->siguiente == nullptr){
        auto siguienteNodo = new Nodo<T>;
        siguienteNodo->valor = valor;
        Dummy->siguiente = siguienteNodo;
        head = siguienteNodo;
        }
        else if (Dummy->siguiente != nullptr){
        auto siguienteNodo = new Nodo<T>;
        siguienteNodo->valor = valor;
        siguienteNodo->siguiente = Dummy->siguiente;
        Dummy->siguiente = siguienteNodo;
        head = siguienteNodo;
        }
    }
    
    void agregarFin(T valor){
        auto actual = Dummy;
        while (actual->siguiente != nullptr){
            actual = actual->siguiente;
        }
        auto nuevoNodo = new Nodo<T>;
        nuevoNodo->valor = valor;
        actual->siguiente = nuevoNodo;
        if (Dummy->siguiente == nuevoNodo){
            head = nuevoNodo;
        }
    }
    
    void agregar(T valor, int posicion){
        if (posicion <=0){
            agregarInicio(valor);
            return;
        }
        if (posicion >= tamanio()){
            agregarFin(valor);
            return;
        }
        else{
            auto actual = Dummy;
            for (int i = 0; i<posicion; ++i){
                actual = actual->siguiente;
            }
            auto nuevoNodo = new Nodo<T>;
            nuevoNodo->valor = valor;
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        }
    }
    
    T sacarInicio(){
        if (Dummy->siguiente != nullptr){
        auto viejacabeza = head;
        auto resultado = viejacabeza->valor;
        Dummy->siguiente = viejacabeza->siguiente;
        head = Dummy->siguiente;
        delete viejacabeza;
        return resultado;
        }
        else{
            return T();
        }
    }
    
    T sacarFin(){
        if (Dummy->siguiente == nullptr){
            return T();
        }
        else{
        auto actual = Dummy;
        while (actual->siguiente->siguiente != nullptr){
            actual = actual->siguiente;
        }
        auto penultimo = actual;
        auto ultimo = actual->siguiente;
        penultimo->siguiente = nullptr;
        auto valor = ultimo->valor;
        delete ultimo;
        return valor;
        }
    }
    
    T sacar(int posicion){
        if (posicion < 0){
            return T();
        }
        if (posicion == 0){
            return sacarInicio();
        }
        if (posicion >= tamanio()){
            return sacarFin();
        }
        else{
            auto actual = Dummy;
            for (int i = 0; i<posicion; ++i){
                actual = actual->siguiente;
            }
            auto nodoViejo = actual->siguiente;
            auto valor = nodoViejo->valor;
            actual->siguiente = nodoViejo->siguiente;
            delete nodoViejo;
            return valor;
        }
    }
    
    void imprimir(){
        //auto actual = Dummy; // SI SE QUIERE MOSTRAR EL NODO DUMMY
        auto actual = head; // SI NO SE REQUIERE MOSTRAR LA EXISTENCIA DEL NODO DUMMY
        while (actual){
            cout << actual->valor << endl;
            actual = actual->siguiente;
        }
    }
    
    int tamanio(){
        int cuenta = 0;
        auto actual = head; // DE ESTA FORMA NO SE CUENTA EL NODO DUMMY
        while (actual){
            cuenta++;
            actual = actual->siguiente;
        }
        return cuenta;
    }
    
private:
    Nodo<T>* Dummy = nullptr;
    Nodo<T>* head = nullptr;

};

int main()
{
       Lista<float> lista;
       lista.sacarInicio();
       lista.agregarFin(30);
       lista.agregarInicio(40);
       lista.agregarFin(50);
       lista.agregar(300, 2);
       lista.agregar(100, 1);
       lista.agregarInicio(2);
        lista.agregar(250, 4);
       lista.imprimir();
       cout << "Se ha sacado " << lista.sacarInicio() << endl;
       lista.imprimir();
       cout << "Se ha sacado "<< lista.sacarFin() << endl;
       lista.imprimir();
       cout << "Se ha sacado " << lista.sacar(3) << endl;
       lista.imprimir();
       cout << "El tamanio de la lista es: " << lista.tamanio() << endl;

}


