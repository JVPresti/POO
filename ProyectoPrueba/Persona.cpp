#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persona.h"

using std::cout;
using std::endl;

//Funcion para reir
void Persona::reir() const {
	cout << "Jajaja..." << endl;
}

//Funcion para comer
void Persona::comer() const {
	cout << "nom, nom, nom" << endl;
}

//Funcion que imprime un saludo
void Persona::saludar() const {
	cout << "Hola, soy " << name;
	cout << " y tengo " << edad << endl;
}

//Funcion que decide si se rie o no
void Persona::hacerReir(int motivo) const {
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

//Funcion para dar el nombre
char* Persona::getName() const {
	return name;
}

//Funcion para cambiar el nombre de un objeto
void Persona::setName(const char* newName){
	if (name != nullptr) {
		free(name);
	}
	name = (char*) malloc(strlen(newName) + 1);
	strncpy(name, newName, strlen(newName));
	name[strlen(newName)] = 0;
}

//Funcion que te da la edad
int Persona::getEdad() const {
	return edad;
}

//Funcion que libera la memoria
void Persona::liberar() {
	free(name);
	name = nullptr;
}
