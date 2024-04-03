#include <iostream>
#include "Menu.h"
#include <conio.h>

using std::cout;
using std::endl;

void listado() {
    cout << "Archivos en el folder: " << endl;
    system("dir");
    _getch();
}

void configuracionIp() {
    cout << "Configuracion de IP" << endl;
    system("ipconfig");
    _getch();
} 

void conexionesActivas() {
	cout << "Conexiones activas" << endl;
	system("netstat");
	_getch();
}

void configuracion() {
    cout << "Pendiente..." << endl;
    _getch();
}

int main(){
    Menu elMenu("Menu de prueba");
    //Agregamos opciones
    elMenu.agregar({ '1', "Ver listado de archivos", listado });
    elMenu.agregar({ '2',"Configuracion de IP", configuracionIp });
    //elMenu.agregar({ '3', "Conexiones activas", conexionesActivas });
	elMenu.agregar({ '3', "Configuracion", configuracion });
    elMenu.agregar({ '4', "Salir", []() {cout << "Saliendo..." << endl; } });
    do {
        system("cls");
        elMenu.desplegar();
    }while(elMenu.seleccionar() != '4');

        
}
