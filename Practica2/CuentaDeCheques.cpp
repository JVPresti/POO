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

CuentaDeCheques::CuentaDeCheques(const char* name, int number, const char* fechax)
{
	nombreCliente = new char[strlen(name) + 1];
	strncpy_s(nombreCliente, strlen(name) + 1, name, _TRUNCATE);

	numeroCuenta = number;
	saldo = 0;

	fechaUltimaTransaccion = new char[strlen(fechax) + 1];
	strncpy_s(fechaUltimaTransaccion, strlen(fechax) + 1, fechax, _TRUNCATE);

	cout << "Cuenta de cheques creada" << endl;
}

CuentaDeCheques::CuentaDeCheques(){
	//srand(time(NULL));
	char nombres[][10] = {"Juan", "Pedro", "Maria", "Jose", "Luis", "Ana", "Sofia", "Carlos", "Fernando", "Ricardo"};
	int random = rand() % 10;
	nombreCliente = (char*)malloc(strlen(nombres[random]) + 1);
	strncpy_s(nombreCliente, strlen(nombres[random]) + 1, nombres[random], _TRUNCATE); //! NO SE PORQUE NO ME DEJA COPIAR EL NOMBRE, MIRA EL DOCUMENTO ANTIGUO
	numeroCuenta = rand() % 9999 + 1000;
	saldo = 0;

	//nombreCliente= (char*)malloc(8);
	//strncpy(nombreCliente, "Ricardo", 7);
	//nombreCliente[7] = '\0';

	fechaUltimaTransaccion = new char[20];
	time_t tm = time(0);
	string fecha = ctime(&tm);
	fecha.copy(fechaUltimaTransaccion, 20);
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

double CuentaDeCheques::retirar(double cantidad, CuentaDeCheques* persona)
{
	try
	{
		if (cantidad <= persona->saldo)
		{
			persona->saldo -= cantidad;
			time_t tm = time(0);
			string fecha = ctime(&tm);
			fecha.copy(fechaUltimaTransaccion, 50);
			return persona->saldo;
		}
		else
		{
			throw "Saldo insuficiente";
		}
	}
	catch (const char* msg)
	{
		cerr << "Error: " << msg << endl;
		return -1;
	}
}

double CuentaDeCheques::transferir(double cantidad, CuentaDeCheques* cuentaDestino)
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

void CuentaDeCheques::preguntarSaldo(CuentaDeCheques* persona)
{
	cout << "El nombre del cliente es: " << persona->nombreCliente << endl;
	cout << "El total en la cuenta es de " << persona->saldo << endl;
	cout << "La fecha de la ultima transaccion fue: " << persona->fechaUltimaTransaccion << endl;
}
