#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include "vector.h"

using std::cout;
using std::string;
using std::endl;

int main(){
	Vector v1(10, 20, 5), v2 = {25, 11, 7}; // Esto es lo mismo que hacer Vector v2(25, 11, 7);
	Vector v3;
	//v3 = v1.sumar({ 20,11,10 }); esto se podria usar
	//v3= v1.sumar(v2);
	v3= v1 + v2;

	//cout << "Vector resultante: (" << v3.x << ", " << v3.y << ", " << v3.z << ")" << endl;
	
	/*cout << v1.toString() << " + " << v2.toString() << " = " << v3.toString() << endl;

	v3=v1.multplicar(v2);
	cout<< v1.toString() << " x " << v2.toString() << " = " << v3.toString() << endl;

	v3= v3.multplicar(2);
	cout<< v3.toString() << endl;
	*/
	v3= v2 * v1;
	cout << "Sobrecarga de operadores: " << endl;
	cout<< v3.toString() << endl;
	v3 = v3 * 2;
	cout << v3.toString() << endl;

	cout << v1 << " + " << v2 << " = " << v3 << endl;



}
