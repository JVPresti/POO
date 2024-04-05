#include <iostream>
#include "Materia.h"
#include <iomanip>

using std::cout;
using std::endl;

int main()
{
    Materia m1(12345, "Programacion y metodos numericos", 7, true, Materia::Etapa::BASICA);
    Materia m2(23456, "Estadistica Avanzada", 6, true, Materia::Etapa::BASICA);
    
    cout << " Clave ";
    cout << std::setw(50) << std::left << " Nombre";
    cout << "Creditos tipo Etapa" << endl;


    cout << m1.toString() << endl;
    cout << m2.toString() << endl;
}
