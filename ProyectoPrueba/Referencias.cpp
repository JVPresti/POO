#include <iostream>
#include "Persona.h"

using std::cout;
using std::endl;

const double PI= 3.1416;

void usarPersona(Persona &persona) {
    cout  << "----Utilizando persona----" << endl;
    persona.saludar();
    persona.hacerReir(rand());
    cout << "---Persona utilizada---" << endl;

}

// Cuando se recibe un paramatreo por referencia, existe la posibilidad de que la funcion modifique el parametro afectando a la variable que utilizamos 
// para llamar a la funcion.
void usarPersona2(const Persona& persona) {
	cout << "----Usando otra vez a Persona: "<< persona.getName() << "----" << endl;
    persona.saludar();
    //No se pueden invocar metodos que no sean const si recibimos una variable const
    //persona.setName("Ifigenia");
    //persona.setEdad(-20);
    persona.hacerReir(rand());

    cout << "--------------------------------" << endl;
}


int main() {
    srand(time(NULL));

    Persona persona1("Sempronio", 20);
    Persona persona2("AMLO", 72);
    Persona* persona3 = new Persona("Abundio", 23);

    //persona3 = &persona1;

    persona1.saludar();
    usarPersona(persona2);
    usarPersona(*persona3);

    usarPersona2(persona1);
    persona1.saludar();

    cout<< "Adios..." << endl;


    delete persona3;
}

