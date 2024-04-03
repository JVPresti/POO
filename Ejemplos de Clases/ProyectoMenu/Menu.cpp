#include "Menu.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

Menu::Menu(string titulo){
	this->titulo = titulo;
}

void Menu::agregar(Opcion laOpcion){
	//Agregamos la opcion al mapa con el metodo insert
	if(opciones.find(laOpcion.GetTecla()) == opciones.end())
		opciones.insert({laOpcion.GetTecla(),laOpcion});
	else
		throw "La tecla ya esta asignada a otra opcion";
}

void Menu::eliminar(char tecla){
	auto it = opciones.find(tecla);
	if (it != opciones.end()) {
		opciones.erase(it);
	}
	else{
		throw "La tecla no esta asignada a ninguna opcion";
	}
}

void Menu::desplegar(){
	cout << titulo << endl;
	//Desplegar las opciones
	for (auto& par : opciones) {
		par.second.desplegar();
	}
}

char Menu::seleccionar(){
	char selec;

	while(true){
		cout << "Seleccione una opcion: ";
		cin >> selec;
		//Buscamos la opcion seleccionada
		auto it = opciones.find(selec);
		if (it != opciones.end()) {
			(*it).second.ejecutar();
			return selec;
		}
		else {
			cout << "Opcion no valida" << endl;
		}
	}
	return selec;
}


