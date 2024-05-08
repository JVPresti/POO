#pragma once
#include "Profesionista.h"

class Ingeniero:public Profesionista{
public:
	Ingeniero(string nombre="William", string cedula = "De Tepito", int edad = 25, int experiencia = 3);
	virtual void resolverProblemas();
	virtual void trabajar() override;
};

