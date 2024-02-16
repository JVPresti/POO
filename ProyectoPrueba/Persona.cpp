#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persona.h"

using std::cout;
using std::endl;

//Funcion para reir
void Persona::reir() {
	cout << "Jajaja..." << endl;
}

//Funcion para comer
void Persona::comer() {
	cout << "nom, nom, nom" << endl;
}

//Funcion que imprime un saludo
void Persona::saludar(){
	cout << "Hola, soy " << name;
	cout << " y tengo " << edad << endl;
}

//Funcion que decide si se rie o no
void Persona::hacerReir(int motivo){
	if ((motivo % 3) == 0) {
		reir();
	}
	else {
		cout << "mal momo :( " << endl;
	}
}

//Constructor que lo hace automatico
Persona::Persona(){
	//Los constructores se utilizan para inicializar atributos y reservr recursos que pudiera utilizar el objeto
	edad = 20;
	name = (char*) malloc(7); 
	strncpy(name, "Sosimo", 6); // Copia el contenido de la cadena de texto en el segundo argumento al primer argumento
	name[6] = 0;
	
}

//Constructor para crear un objeto con nombre y edad especificos
Persona::Persona(const char* elName, int laEdad){
	edad= laEdad;
	name=(char* ) malloc(strlen(elName)+1);
	strncpy(name, elName, strlen(elName));
	name[strlen(elName)] = 0;
}

//Elimina el objeto de la memoria
Persona::~Persona(){
	if (name != nullptr) {
		cout << "Adios, " << name << endl;
		free(name);
	}
}


//Funcion que libera la memoria
void Persona::liberar() {
	free(name);
	name = nullptr;
}
