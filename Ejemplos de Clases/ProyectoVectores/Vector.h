#pragma once
#include <string>
#include <ostream>

using std::ostream;
using std::string;
class Vector{
public: 
	double x;
	double y;
	double z;
	
	//Utilizamos parametros default, si cuando mandamos a llamar esto, no ponemos nada, se inicializa en 0, si no, se inicializa con el valor que le pongamos
	Vector(double x=0, double y=0, double z=0);

	string toString(); //Genera una cadela con la informacion del vector

	// Operaciones vectoriales //

	Vector sumar(Vector v2);
	Vector multplicar(Vector v2);
	// En c++ se pueden sobrecargar las funciones
	Vector multplicar(double s);

	//En c++ se pueden sobrecargar los operadores, esto es que podemos definir que sucedera cuando se aplque un operador a un elemnto de determinado tipo
	//Para sobrecargar un operador se crea una funcion con un nombre especial. 
	//Cuando la funcion es miembro de una clase, el operando izquiero es el objeto al cual pertenece la funcion, y el operando derecho debe ser pasado como parametro
	//El nombre de la funcion es operator seguido del simbolo del operador que se quiere sobrecargar. El tipo de retorno debe ser congruente con la operacion

	Vector operator*(Vector v2);
	Vector operator*(double s);
	Vector operator+(Vector v2);

	double GetMagnitud();
	Vector GetUnitVector();

};
// Cuando el operador no es miemhro de la clase se deben reibir los dos operandos como parametro
Vector operator*(double s, Vector v); //Esto es para que se pueda hacer la multiplicacion de un escalar por un vector, pero en el orden contrario
//Sobrecargamos el operados << para poder enviar un vector de salida como en cout
ostream &operator<<(ostream &out, Vector v);
