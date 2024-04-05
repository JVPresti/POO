#pragma once
#include <string>

using std::string;

class Materia{
public:
	enum Etapa {
		BASICA,DISCIPLINARIA,TERMINAL
	};

protected:
	int clave;
	string nombre;
	int creditos;
	bool obligatoria;
	Etapa etapa;

public:
	Materia(int clave = 0, string nombre = "", int creditos = 0, bool obligatoria = false, Etapa etapa = BASICA);

	// Getters
	int getClave() const { return clave; }
	string getNombre() const { return nombre; }
	int getCreditos() const { return creditos; }
	bool esObligatoria() const { return obligatoria; }
	Etapa getEtapa() const { return etapa; }
	
	string toString() const;

};

