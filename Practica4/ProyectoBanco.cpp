#include <iostream>
#include "Banco.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
	Banco banco;

	//Crear cuentahabiente
	auto* juan = banco.crearCuentaH("Juan Perez", "JUP123456");
	auto* maria = banco.crearCuentaH("Maria Gonzalez", "MAL654321");
	
	//Crear cuentas para cuentahabientes
	auto* cuentaJuan1 = banco.crearCuentaC(juan);
	auto* cuentaJuan2 = banco.crearCuentaC(juan);
	auto* cuentaMaria = banco.crearCuentaC(maria);


	//Realizar depositos
	banco.depositar(cuentaJuan1->getNumeroCuenta(), 1000);
	banco.depositar(cuentaMaria->getNumeroCuenta(), 2000);

	//Realizar retiros
	banco.retirar(cuentaJuan2->getNumeroCuenta(), 500); //Saldo insuficiente
	banco.retirar(cuentaMaria->getNumeroCuenta(), 500); //Saldo suficiente

	// Transferencia entre cuentas
	banco.transferir(cuentaJuan1->getNumeroCuenta(), cuentaMaria->getNumeroCuenta(), 300); // Transferencia exitosa

	// Imprimir reportes
	banco.imprimirReporteCH();
	cout << " --------------------------\n";

	// Imprimir estado de cuenta
	banco.imprimirEstadoCuenta(cuentaJuan1->getNumeroCuenta());
	banco.imprimirEstadoCuenta(cuentaMaria->getNumeroCuenta());
	cout << " --------------------------\n";

	return 0;
}
