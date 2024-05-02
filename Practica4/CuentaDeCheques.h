#pragma once
class CuentaDeCheques{
private:
	int numeroCuenta;
	double saldo;
public:
	CuentaDeCheques(int numero) : numeroCuenta(numero), saldo(0) {}

	int getNumeroCuenta() const { return numeroCuenta; }
	double getSaldo() const { return saldo; }
	void depositar(double cantidad);
	bool retirar(double cantidad);
	bool transferir(CuentaDeCheques& destino, double cantidad);
	void imprimirEstadoCuenta() const;
};

