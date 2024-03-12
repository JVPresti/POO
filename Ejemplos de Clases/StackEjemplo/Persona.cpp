#include "Persona.h"
#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

void Persona::Reir()const {
	cout << "Jajajaja" << endl;
}

void Persona::Comer()const{
	cout << "Nom, nom, nom...." << endl;
}

Persona::Persona()
{
	// los constructores se utilizan para inicializar
	//atributos y reservar recursos que pudiera
	//utilizar el objeto.
	edad = 20;
	nombre="Sosimo";
}

Persona::Persona(const char* el_nombre, int la_edad)
{
	edad = la_edad;
	nombre = el_nombre;
	
}

void Persona::HacerReir(int motivo) const
{
	if ((motivo % 3) == 0) {
		Reir();
    }
	else
		cout << ":|" << endl;
}

std::string Persona::GetNombre() const
{
	return nombre;
}

void Persona::SetNombre(const char* nuevo_nombre)
{
	nombre = nuevo_nombre;
}

void Persona::Saludar() const
{
	cout << "Hola, yo soy " << nombre;
	cout << " y tengo " << edad << " anios"<<endl;
}

/*
Persona::~Persona()
{
	if (nombre != nullptr) {

		cout << "Ejecutando destructor de " << nombre << "..." << endl;
		free(nombre);
	}
}*/

ostream& operator<<(ostream& out, Persona& persona){
	out << "Persona[" << persona.GetNombre() <<", "<<persona.GetEdad() <<"]";
	return out;
}
