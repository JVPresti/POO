#define _CRT_SECURE_NO_WARNIGS
#include "CuentaDeCheques.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //srand(time(0));
    //CuentaDeCheques persona1("Juan", 1234, "2 de agosto");
    //CuentaDeCheques persona2("Pedro", 5678, "3 de agosto");
    CuentaDeCheques persona1;
    CuentaDeCheques persona2;

    persona1.depositar(1000);
    persona1.preguntarSaldo(&persona1);

    cout << "Depositar 500 a la cuenta de Pedro" << endl;
    persona2.depositar(500);

    cout << "Retirar 200 de la cuenta de Juan" << endl;
    persona1.retirar(200, &persona1); //! FALTA QUE ACTUALCE EL SALDO, NO LO REGRESA, CREO QUE TENGO QUE USAR PUNTEROS
    //persona1.preguntarSaldo(&persona1);

    cout << "Transferir 100 de la cuenta de Juan a la cuenta de Pedro" << endl;
    persona1.transferir(100, &persona2);
    
    persona2.preguntarSaldo(&persona2);
    persona1.preguntarSaldo(&persona1);

    return 0;
}

//SOLO FALTA QUE ASIGNE EL NOMBRE AUTOMATICO, Y HACER UN MENU PARA HACER CUALQUIER COSA
