#include "CuentaHabiente.h"
#include <iostream>
#include "CuentaDeCheques.h"

using std::cout;

CuentaHabiente::CuentaHabiente(int numero, const string& nombre, const string& curp){
	numeroCuentaH = numero;
	this->nombre = nombre;
	this->curp = curp;
}

void CuentaHabiente::agregarCuenta(CuentaDeCheques* cuenta){
	cuentas.push_back(cuenta);
}

void CuentaHabiente::imprimirEstadoCuenta() const{
	cout << "Numero de cuenta habiente: " << numeroCuentaH << " (" << curp << ")\n";
	cout << "Numero de cuentas: " << cuentas.size() << "\n";
	for (const auto& cuenta : cuentas) {
		cout << "Cuenta numero: " << cuenta->getNumeroCuenta() << "\n";
		cout << "Saldo: " << cuenta->getSaldo() << "\n";
	}
}
