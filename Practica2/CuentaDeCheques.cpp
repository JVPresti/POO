#define _CRT_SECURE_NO_WARNINGS
#include "CuentaDeCheques.h"
#include <ctime>
#include <string>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

CuentaDeCheques::~CuentaDeCheques()
{
	free(nombreCliente);
	//free(fechaUltimaTransaccion); // ESTO ME CAUSA ERROR YA NO PUEDO MAS CON MI FOKIN VIDA
}

CuentaDeCheques::CuentaDeCheques(const char *name, int number, const char *fechax)
{
	nombreCliente = new char[strlen(name) + 1];
	strncpy_s(nombreCliente, strlen(name) + 1, name, _TRUNCATE);

	numeroCuenta = number;
	saldo = 0;

	fechaUltimaTransaccion = new char[strlen(fechax) + 1];
	strncpy_s(fechaUltimaTransaccion, strlen(fechax) + 1, fechax, _TRUNCATE);

	cout << "Cuenta de cheques creada" << endl;
}

double CuentaDeCheques::depositar(double cantidad)
{
	saldo += cantidad;
	time_t tm = time(0);
	string fecha = ctime(&tm);
	fecha.copy(fechaUltimaTransaccion, 20);

	return saldo;
}

double CuentaDeCheques::retirar(double cantidad)
{
	try
	{
		if (cantidad <= saldo)
		{
			saldo -= cantidad;
			time_t tm = time(0);
			string fecha = ctime(&tm);
			fecha.copy(fechaUltimaTransaccion, 50);
			return ;
		}
		else
		{
			throw "Saldo insuficiente";
		}
	}
	catch (const char *msg)
	{
		cerr << "Error: " << msg << endl;
		return -1;
	}
}

double CuentaDeCheques::transferir(double cantidad, CuentaDeCheques *cuentaDestino)
{
	if (cantidad <= saldo)
	{
		saldo -= cantidad;
		cuentaDestino->depositar(cantidad);
		time_t tm = time(0);
		string fecha = ctime(&tm);
		fecha.copy(fechaUltimaTransaccion, 50);
		return saldo;
	}
	else
		return -1;
}
