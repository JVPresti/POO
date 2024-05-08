#include "IngCivil.h"

IngCivil::IngCivil(string nombre, string cedula, int edad, int experiencia) :Ingeniero(nombre, cedula, edad, experiencia) {
}

void IngCivil::construir(){
	cout << "Construyendo... meneando la cuchara con estilo..." << endl;
}

void IngCivil::resolverProblemas(){
	construir();
}


