#include "Ingeniero.h"

Ingeniero::Ingeniero(string nombre, string cedula, int edad, int experiencia):Profesionista(nombre, cedula, edad, experiencia){
}

void Ingeniero::resolverProblemas(){
	cout << "Resolviendo problemas de ingenieria" << endl;
}

void Ingeniero::trabajar(){
	//Para invocar el metodo trabajar de la clase padre utilizamos el operador de resolucion de ambito ::
	Profesionista::trabajar(); //Trabajar de profesionista
	resolverProblemas(); //Trabajar de ingeniero
}
