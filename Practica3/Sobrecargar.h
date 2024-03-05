#pragma once
#include <string>
#include <iostream>
#include <ostream>

using std::string;
using std::ostream;

class Sobrecargar{
public:
	
	string numerador;
	string denominador;
	string resultado;

	Sobrecargar();
	Sobrecargar(string fra);


	//Aqui se sobrecarga los operadores
	Sobrecargar operator+(Sobrecargar fra);
	Sobrecargar operator-(Sobrecargar fra);
	Sobrecargar operator*(Sobrecargar fra);
	Sobrecargar operator/(Sobrecargar fra);
	Sobrecargar operator=(Sobrecargar fra);
	Sobrecargar operator<<(Sobrecargar fra);

};


