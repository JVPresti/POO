#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <sstream> // streams basados en cadena
#include <iomanip>

Vector::Vector(double x, double y, double z){
	//Todo objeto tiene un apuntador a si mismo que se llama this. Es una forma de hacer referencia a si mismo
	this->x = x;
	this->y = y;
	this->z = z;

}

Vector Vector::sumar(Vector v2){
	Vector r;
	r.x= this->x + v2.x;
	r.y= this->y + v2.y;
	r.z= this->z + v2.z;
	return r;
}

Vector Vector::multplicar(Vector v2){

	Vector r;
	r.x = this->y * v2.z - this->z * v2.y;
	r.y = this->z * v2.x - this->x * v2.z;
	r.z = this->x * v2.y - this->y * v2.x;

	return r;
}

//Multiplicacion por un escalar
Vector Vector::multplicar(double s){
	Vector r;
	r.x= this->x * s;
	r.y= this->y * s;
	r.z= this->z * s;

	return r;
}

Vector Vector::operator*(Vector v2){
	Vector r;
	r.x = this->y * v2.z - this->z * v2.y;
	r.y = this->z * v2.x - this->x * v2.z;
	r.z = this->x * v2.y - this->y * v2.x;

	return r;
}

Vector Vector::operator*(double s){
	Vector r;
	r.x = this->x * s;
	r.y = this->y * s;
	r.z = this->z * s;

	return r;
}

Vector Vector::operator+(Vector v2){

	Vector r;
	r.x = this->x + v2.x;
	r.y = this->y + v2.y;
	r.z = this->z + v2.z;
	return r;
}

//Convierte la informacion a cadena
string Vector::toString(){
	//char cad[128];
	//sprintf(cad, "(%.2lf, %.2lf, %.2lf)", x, y, z);
	std::ostringstream out;

	//out<< std::setprecision(2) << "(" << x << ", " << y << ", " << z << ")";
	out << *this;

	return out.str(); 
}

Vector operator*(double s, Vector v){
	return v*s;
}

ostream& operator<<(ostream& out, Vector v)
{
	out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return out;
}
