#include "Opcion.h"
#include <iostream>

Opcion::Opcion(char tecla, string desc, function<void(void)> a){
	this->tecla = tecla;
	descripcion = desc;
	accion = a;
}

void Opcion::desplegar() const{
	std::cout << tecla << ") " << descripcion << std::endl;
}
