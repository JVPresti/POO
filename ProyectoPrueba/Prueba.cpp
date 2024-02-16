// Prueba.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Persona.h"

using std::cout;
using std::endl;
using std::cin;

//Funcion que crea un objeto de clase persona en memoria estatica y otro en memoria dinamica
void Foo() {
    Persona personaLocal("Jilvherto", 15);
    personaLocal.saludar();
    Persona* personaDinamica = new Persona("AMLO", 72);
    personaDinamica->saludar();
    if (true) {
        Persona otra("Juaquin", 45);
        otra.hacerReir(rand());
    }
}


int main()
{
    srand(time(NULL));

    Foo(); //Llamamos a la funcion Foo que crea un objeto de clase persona en memoria estatica y otro en memoria dinamica

    //Creamos un par de objetos de clase persona
    //Existen 2 formas de crear un objeto
    //Estatica, el objeto se crea en memoria estatica en el stack del programa
    //Dinamica, el objeto se crea en memoria dinamica
    Persona laPersona("Juana", 19); //Estatica
    //En este punto del programa, ya existe un objeto de clase persona en la memoria (en el stack) 
    //Tiene nombre, edad y el comportamiento de la persona

    //El comando new devuelve la direccion de meoria del objeto recien creado en el heap. Necesitamos un puntero para almacenar esa direccion
    Persona* otraPersona;
    //Dinamica
    otraPersona = new Persona("Nicolas", 25);
    //La principal dierencia entre los objetos en memoria estatica y los objetos en memoria dinamica es que los objetos estaticos se eliminan
    //automaticamente cuando el programa o bloque de codigo termina, mientras que los objetos dinamicos no. Es necesario liberar la memoria manualmente (delete)

    //Para utilziar el objeto, podemos acceder a sus miembros (variables o funciones) por medio de los mismos operadores que utilizamos para las estructuras
    // . cuando es estatico
    // -> cuando es dinamico

    laPersona.saludar();
    laPersona.hacerReir(rand());
    
    otraPersona->saludar();

    Persona tercerPersona("Maria de todos los angeles", 22);
    tercerPersona.saludar();


    //tercerPersona.liberar();
    delete otraPersona; //Eliminamos el objeto de la memoria dinamica

}
