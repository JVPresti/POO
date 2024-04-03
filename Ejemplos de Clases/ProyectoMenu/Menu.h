#pragma once
#include <string>
#include "Opcion.h"
#include <map>

using std::string;
using std::map;

class Menu{
protected:
	string titulo;
	//Para manejar las multiples instancias de opcion en este menu, utilizaremos un mapa
	map<char, Opcion> opciones;

public:
	Menu(string titulo = "Menu");
	void agregar(Opcion laOpcion);
	void eliminar(char tecla);
	void desplegar();
	char seleccionar();
};

