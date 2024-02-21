#define _CRT_SECURE_NO_WARNIGS
#include "CuentaDeCheques.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    CuentaDeCheques persona1("Juan", 1234, "2 de agosto");
    CuentaDeCheques persona2("Pedro", 5678, "3 de agosto");

    cout << "Depositar 1000 a la cuenta de Pedro" << endl;
    persona1.depositar(1000);

    cout << "Depositar 500 a la cuenta de Juan" << endl;
    persona2.depositar(500);

    cout << "El total en la cuenta de Juan es de " << persona2.saldo << endl;
    cout << "Retirar 200 de la cuenta de Juan" << endl;
    persona1.retirar(200); //! FALTA QUE ACTUALCE EL SALDO, NO LO REGRESA, CREO QUE TENGO QUE USAR PUNTEROS
    cout << "El total en la cuenta de Juan es de " << persona2.saldo << endl;

    cout << "Transferir 100 de la cuenta de Juan a la cuenta de Pedro" << endl;
    persona1.transferir(100, &persona2);
    cout << "El total en la cuenta de Juan es de " << persona2.saldo << endl;
    
    return 0;
}
