#pragma once
#include "Ingeniero.h"
class IngSoftware:public Ingeniero{
public:
	IngSoftware(string nombre = "El Metodo", string cedula = "De reddit", int edad = 25, int experiencia = 3);
	virtual void programar();
	virtual void resolverProblemas() override;
};

