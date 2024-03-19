#pragma once
#include <string>
#include <ostream>


using std::string;
using std::ostream;

class Estudiante{
protected:
	int matricula = 0;
	string name;
	int puntuacion = 0;

public:
	Estudiante(int matricula, string name, int puntuacion);
	Estudiante() {};

	int getMatri()const { return matricula; };
	string getName()const { return name; };
	int getPunt()const { return puntuacion; };

};

ostream &operator<<(ostream& out, const Estudiante& estudiante);
bool operator<(const Estudiante& e1, const Estudiante& e2);

