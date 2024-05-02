#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class CuentaDeCheques;

class CuentaHabiente{
private:
	int numeroCuentaH;
	string nombre;
	string curp;
	vector<CuentaDeCheques*> cuentas;

public:
	CuentaHabiente(int numero, const string& nombre, const string& curp);
	int getNumeroCuentaH() const { return numeroCuentaH; }
	const string getNombre() const { return nombre; }
	const string getCurp() const { return curp; }
	void agregarCuenta(CuentaDeCheques* cuenta);
	vector<CuentaDeCheques*> getCuentas() const { return cuentas; }
	void imprimirEstadoCuenta() const;

};

