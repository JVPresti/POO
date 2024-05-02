#include "CuentaDeCheques.h"
#include <iostream>
using std::cout;

void CuentaDeCheques::depositar(double cantidad){
	saldo += cantidad;
}

bool CuentaDeCheques::retirar(double cantidad){
	if (cantidad > saldo) {
		return false;
	}
	saldo -= cantidad;
	return true;

}

bool CuentaDeCheques::transferir(CuentaDeCheques& destino, double cantidad){
	if (retirar(cantidad)) {
		destino.depositar(cantidad);
		return true;
	}
	return false;
}

void CuentaDeCheques::imprimirEstadoCuenta() const{
	cout << "Numero de cuenta: " << numeroCuenta << "\nSaldo: " << saldo << "\n";
}
