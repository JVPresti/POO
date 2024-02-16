#include <iostream>
#include "Persona.h"

using std::cout;
using std::endl;

void usarPersona(Persona *persona) {
    cout  << "----Utilizando persona----" << endl;
    persona->saludar();
    persona->hacerReir(rand());
    cout << "---Persona utilizada---" << endl;

}


int main()
{
    srand(time(NULL));

    Persona persona1("Sempronio", 20);
    Persona persona2("AMLO", 72);
    Persona* persona3 = new Persona("Abundio", 23);

    //persona3 = &persona1;

    persona1.saludar();
    usarPersona(&persona2);
    usarPersona(persona3);

    cout<< "Adios..." << endl;


    delete persona3;
}

