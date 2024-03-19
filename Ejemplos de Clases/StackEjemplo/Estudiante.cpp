#include "Estudiante.h"

Estudiante::Estudiante(int matricula, string name, int puntuacion){
	this->matricula = matricula;
	this->name = name;
	this->puntuacion = puntuacion;
}

ostream& operator<<(ostream& out, const Estudiante& estudiante){
	out << "Estudiante [ Matricula: " << estudiante.getMatri() << " Nombre: " << estudiante.getName() << " Puntuacion: " << estudiante.getPunt() << " ]";
	return out;
}

bool operator<(const Estudiante& e1, const Estudiante& e2)
{
	//return e1.getPunt() < e2.getPunt();
	//return e1.getMatri() < e2.getMatri();
	return e1.getName() < e2.getName();
}
