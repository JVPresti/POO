#include "Materia.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using std::setw;
using std::right;
using std::left;

Materia::Materia(int clave, string nombre, int creditos, bool obligatoria, Etapa etapa){
	this->clave = clave;
	this->nombre = nombre;
	this->creditos = creditos;
	this->obligatoria = obligatoria;
	this->etapa = etapa;
}

string Materia::toString() const{
	std::ostringstream out;
	out << setw(6)<< clave << " " << setw(50) << left <<nombre << " " << setw(8) << left << creditos << " " << setw(4) << left << (obligatoria ? "Obl" : "Opt") << " ";
	switch (etapa) {
	case BASICA: out << "Basica\t"; break;
	case DISCIPLINARIA: out << "Disciplinaria\t"; break;
	case TERMINAL: out << "Terminal\t"; break;
	}

	return out.str();
}
