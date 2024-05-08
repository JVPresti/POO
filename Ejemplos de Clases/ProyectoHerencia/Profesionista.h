#pragma once
#include "Persona.h"
#include <string>

using std::string;

class Profesionista:public Persona{
protected:
	string cedula;
	int experiencia;

public:
	Profesionista();
	Profesionista(string nombre, string cedula = "De Tepito", int edad = 25, int experiencia = 3);
	virtual void trabajar();
	//Sobreescritura
	//El calificador override sirve para marcar metodos que sobreescriben a un metodo heredado. Si no hay un metodo heredado con el mismo prototipo el compilador
	//marcara error.
	void Saludar() const override;
};

