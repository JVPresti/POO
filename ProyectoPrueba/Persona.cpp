#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persona.h"

using std::cout;
using std::endl;

void Persona::reir() {
	cout << "Jajaja..." << endl;
}

void Persona::comer() {
	cout << "nom, nom, nom" << endl;
}

Persona::Persona(){
	//Los constructores se utilizan para inicializar atributos y reservr recursos que pudiera utilizar el objeto
	edad = 20;
	name = (char*) malloc(7); 
	strncpy(name, "Sosimo", 6); // Copia el contenido de la cadena de texto en el segundo argumento al primer argumento
	name[6] = 0;
	
}

Persona::Persona(const char* elName, int laEdad){
	edad= laEdad;
	name=(char* ) malloc(strlen(elName)+1);
	strncpy(name, elName, strlen(elName));
	name[strlen(elName)] = 0;
}

Persona::~Persona(){
	if (name != nullptr) {
		cout << "Adios, " << name << endl;
		free(name);
	}
}

void Persona::saludar(){
	cout << "Hola, soy " << name;
	cout << " y tengo " << edad << endl;
}

void Persona::hacerReir(int motivo){
	if ((motivo % 3) == 0) {
		reir();
	}
	else {
		cout << "mal momo :( " << endl;
	}
}

void Persona::liberar() {
	free(name);
	name = nullptr;
}
