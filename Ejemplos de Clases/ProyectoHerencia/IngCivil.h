#pragma once
#include "Ingeniero.h"
class IngCivil:public Ingeniero{
public:
	IngCivil(string nombre = "Saul Pedro", string cedula = "De Tepito", int edad = 25, int experiencia = 3);
	virtual void construir();
	virtual void resolverProblemas() override;
};

