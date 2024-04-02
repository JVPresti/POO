#pragma once
#include <string>
#include <functional>

using std::string;
using std::function;

class Opcion{
protected:
	string descripcion;
	char tecla;
	function<void(void)> accion;// Se ejecuta la accion de la opcion

public:
	Opcion(char tecla=0, string desc="", function<void(void)> a=[](){});

	//Getters
	char GetTecla()const { return tecla; }
	string GetDescripcion()const { return descripcion; }
	void desplegar()const;
	void ejecutar()const { accion(); }

};

