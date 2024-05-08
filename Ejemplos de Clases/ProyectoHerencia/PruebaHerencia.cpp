#include <iostream>
#include "Estudiante.h"
#include "Profesionista.h"
#include "IngCivil.h"
#include "IngSoftware.h"

using std::endl;
using std::cout;
using std::cin;

void usarProfesionista(Profesionista* profesionista) {
	cout << "------------------------------------" << endl;
	cout << "Usando profesionista" << endl;
	profesionista->GetNombre();
	profesionista->Saludar();
	profesionista->trabajar();
	cout << "------------------------------------" << endl;
}

int main(){
	Estudiante estudiante;
	Estudiante estudiante2(666000, "Guillermo", "Ing. en Sowere", 5, 20);
	Persona laPersona("Nicasio", 23);

	estudiante.Saludar();
	estudiante.estudiar();

	estudiante2.Saludar();
	laPersona.Saludar();

	Profesionista prof1;
	prof1.Saludar();
	prof1.trabajar();

	//Polimorfismo

	cout << "-------------------Polimorfismo-------------------" << endl;
	Persona* persona;
	//En un apuntador o referencia de persona podemos manejar una instancia de cualquier subclase
	persona = new Estudiante(990122, "George", "Ing. Civil");

	Persona &refPersona = estudiante2;
	persona->Saludar();

	refPersona.Saludar();

	IngSoftware is;
	IngCivil ic;
	
	usarProfesionista(&is);
	usarProfesionista(&ic);

}
