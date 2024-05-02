#pragma once
#include <map>
#include "CuentaHabiente.h"
#include "CuentaDeCheques.h"
#include <iostream>

using std::map;
using std::cout;

class Banco{
private:
	int contadorCuentasH;
	int contadorCuentasC;
	map<int, CuentaHabiente*> cuentasH;
	map<int, CuentaDeCheques*> cuentasC;

public:
	Banco();
	~Banco();

	CuentaHabiente* crearCuentaH(const string &nombre, const string &curp);
	CuentaDeCheques* crearCuentaC(CuentaHabiente* cuentahabiente);
	void depositar(int numeroCuenta, double cantidad);
	bool retirar(int numeroCuenta, double cantidad);
	bool transferir(int origen, int destino, double cantidad);
	void imprimirReporteCH() const {
		for (auto& it : cuentasH) {
			cout << "--------------------------------\n";
			cout << "Numero de cuenta habiente: " << it.first << "\nNombre: " << it.second->getNombre() << "\nCURP: " << it.second->getCurp() << "\n";
			cout << "--------------------------------\n";
			it.second->imprimirEstadoCuenta();
		}
	}
	void imprimirEstadoCuenta(int numeroCuenta) const;
};

