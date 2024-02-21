#pragma once
class CuentaDeCheques {
protected:
	char* nombreCliente;
	char* fechaUltimaTransaccion;
	int numeroCuenta;



public:
	double saldo;
	CuentaDeCheques(const char* name, int number, const char* fechax);
	~CuentaDeCheques();

	double depositar(double cantidad);
	double retirar(double cantidad);
	double transferir(double cantidad, CuentaDeCheques* cuentaDestino);

};
