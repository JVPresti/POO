#pragma once
class CuentaDeCheques {
protected:
	char* fechaUltimaTransaccion;
	int numeroCuenta;
	double saldo;
	

public:
	char* nombreCliente;
	CuentaDeCheques(const char* name, int number, const char* fechax);
	CuentaDeCheques();
	~CuentaDeCheques();

	double depositar(double cantidad);
	double retirar(double cantidad, CuentaDeCheques* persona);
	double transferir(double cantidad, CuentaDeCheques* cuentaDestino);
	void preguntarSaldo(CuentaDeCheques* persona);

};
