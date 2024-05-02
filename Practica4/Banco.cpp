#include "Banco.h"
#include "CuentaHabiente.h"
#include "CuentaDeCheques.h"
#include <iostream>
#include <map>

using std::cout;

Banco::Banco(){
	contadorCuentasH = 0;
	contadorCuentasC = 0;
}

Banco::~Banco() {
	// Eliminar todas las cuentas de cheques
	for (auto& it : cuentasC) { 
		if (it.second) {
			delete it.second; 
		}
	}

	// Eliminar todos los cuentahabientes
	for (auto& it : cuentasH) { 
		if (it.second) {
			delete it.second;
		}
	}
}


CuentaHabiente* Banco::crearCuentaH(const string& nombre, const string& curp){
	contadorCuentasH++;
	auto* nuevoCuentaH = new CuentaHabiente(contadorCuentasH, nombre, curp);
	cuentasH[contadorCuentasH] = nuevoCuentaH;
	return nuevoCuentaH;
}

CuentaDeCheques* Banco::crearCuentaC(CuentaHabiente* cuentahabiente){
	contadorCuentasC++;
	auto* nuevaCuentaC = new CuentaDeCheques(contadorCuentasC);
	cuentasC[contadorCuentasC] = nuevaCuentaC;
	cuentahabiente->agregarCuenta(nuevaCuentaC);
	return nuevaCuentaC;
}

void Banco::depositar(int numeroCuenta, double cantidad){
	if (cuentasC.find(numeroCuenta) != cuentasC.end()) {
		cuentasC[numeroCuenta]->depositar(cantidad);
	}
	else {
		cout << "Cuenta no encontrada\n";
	}
}

bool Banco::retirar(int numeroCuenta, double cantidad){
	if (cuentasC.find(numeroCuenta) != cuentasC.end()) {
		return cuentasC[numeroCuenta]->retirar(cantidad);
	}
	cout << "Cuenta no encontrada\n";
	return false;
	
}

bool Banco::transferir(int origen, int destino, double cantidad){
	if (cuentasC.find(origen) != cuentasC.end() && cuentasC.find(destino) != cuentasC.end()) {
		return cuentasC[origen]->transferir(*cuentasC[destino], cantidad);
	}
	else{
		cout << "Una de las cuentas no fue encontrada\n";
		return false;
	}
	
}

//void Banco::imprimirReporteCH() const {
//	std::cout << "Reporte de cuentahabientes\n";
//
//	for (const auto& [key, cuentaH] : cuentahabientes) { 
//		if (cuentaH) {
//			cuentaH->imprimirEstadoCuenta(); 
//		}
//	}
//}


void Banco::imprimirEstadoCuenta(int numeroCuenta) const {
	auto it = cuentasC.find(numeroCuenta); 
	if (it != cuentasC.end() && it->second) {
		it->second->imprimirEstadoCuenta();
	}
	else {
		std::cout << "Cuenta no encontrada\n";
	}
}

