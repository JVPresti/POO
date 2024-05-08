#include "IngSoftware.h"

IngSoftware::IngSoftware(string nombre, string cedula, int edad, int experiencia) :Ingeniero(nombre, cedula, edad, experiencia)
{
}

void IngSoftware::programar(){
	cout << "Pidiendole un programa a ChatGPT..." << endl;
}

void IngSoftware::resolverProblemas(){
	cout << "Checando tiktok..." << endl;
	programar();
	cout << "Checando mi instagram..." << endl;
}
