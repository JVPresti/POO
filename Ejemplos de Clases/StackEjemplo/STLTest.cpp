#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include "Persona.h"
#include <conio.h>
#include "Estudiante.h"
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::stack;
using std::string;
using namespace std;



void stackTest() {
	cout << "Stack Test" << endl;
	//Creamos una pila de numeros enteros
	stack<int> pila;
	int n;
	while (true) {
		cout << "Dame un numero (-1 para terminar): ";
		cin >> n;
		if(n == -1) break;
		pila.push(n);
	}

	cout << "Cantidad de elementos en la pila: " << pila.size() << endl;
	cout << "Elemento en el tope de la pila: " << pila.top() << endl;
	cout << "Todos los elemetnos de la pila: ";
	while (!pila.empty()) {
		cout << pila.top() << ", ";
		pila.pop(); //pop solamente remueve el elemento del tope, no nos regresa nada
	}

}

void stackTest2() {
	//Verificamos si una frase poporcionada por el usuario es palindromo
	string frase;
	cout << "Dame una frase: ";
	std::getline(cin, frase);
	stack <char> pila;
	for (int i = 0; i < frase.size(); i++) {
		if(frase[i] != ' ')
			pila.push(tolower(frase[i]));
	}

	bool palindromo = true;
	for (char c : frase) {
		if (c != ' ') {
			if (tolower(c) != pila.top()) {
				palindromo = false;
				break;
			}
			pila.pop();
		}
	}

	if(palindromo == true)
		cout << "La frase \"" <<frase << "\" es palindromo" << endl;
	else
		cout << "La frase \"" << frase << "\" no es palindromo" << endl;

	
	
}

void stackTest3() {
	stack<Persona> personas;
	personas.push(Persona("Sosimo", 20));
	personas.push(Persona("Nicanor", 23));
	personas.push(Persona("Espergencia", 30));
	
	//con emplace, la pila creara el objeto con los parametros enviados. Si utilizamos push, el objeto enviado como parametro sera copiado
	//al parametro local de push, al hacer la asignacion se hara tora copia del objeto. emplace evita que se hagan copias innecesarias
	personas.emplace("Sempronio", 25);

	cout << "Personas: " << endl;
	while (!personas.empty()) {
		cout << personas.top() << endl;
		personas.pop();
	}
}

//Cola de enteros
void queueTest() {
	queue<int> cola;
	int n;
	while (true) {
		cout << "Dame un numero (-1 para terminar): ";
		cin >> n;
		if (n == -1) break;
		cola.push(n);
	}
	cout << "Numero de elementos en la cola: " << cola.size() << endl;
	cout << "Ultmo elemento de la cola: " << cola.back() << endl;
	cout << "Primer elemento de la cola: " << cola.front() << endl;

	cout << "Elementos de la cola: ";
	while (!cola.empty()) {
		cout << cola.front() << ", ";
		cola.pop();
	}
	cout << endl;

}

void queueTest2() {
	//deque es una cola doble. En la cola doble, se pueden agregar elementos al incio o al final de la cola. Tambien se pueden quitar del inicio o del final
	deque<int> cola;
	int n;
	bool  alt = true; //Para alternar entre agregar al inicio o al final
	while (true) {
		cout << "Dame un numero (-1 para terminar): ";
		cin >> n;
		if (n == -1) break;
		
		if (alt) {
			cola.push_back(n);
		}
		else {
			cola.push_front(n);
		}
		alt = !alt;
	}
	cout << "Numero de elementos en la cola: " << cola.size() << endl;
	_getch();
	cout << "Elemento al inicio de la cola: " << cola.front() << endl;
	_getch();
	cout << "Elemento al final de la cola: " << cola.back() << endl;
	_getch();
	
	cout << "Elementos de la cola: ";
	while (!cola.empty()) {
		cout << cola.front() << ", ";
		cola.pop_front();
	}
}

void pqueueTest() {
	//Una cola de prioridad utiliaz la prioridad de los elementos para dar siempre acecso al que tiene mayor prioridad.
	//Internamente utiliza un arbol balanceado a la izquierda para mantener en la raiz del arbol el elemento con mayor prioridad
	priority_queue<int> cola;
	int n;
	while (true) {
		cout << "Dame un numero (-1 para terminar): ";
		cin >> n;
		if (n == -1) break;
		cola.push(n);
	}
	cout << "Cantidad de elementos en la cola: " << cola.size() << endl;
	_getch();
	cout << "Elemento con mayor prioridad: " << cola.top() << endl;
	_getch();
	cout << "Elementos de la cola: ";
	while (!cola.empty()) {
		cout << cola.top() << ", ";
		cola.pop();
	}
}

void pqueueTest2() {
	priority_queue<Estudiante> cola;
	//Agregamos varios estudiantes
	cola.push(Estudiante(456321, "Espergecia Perez", 3456));
	cola.push({567891, "Abudemio McGregor", 4231});
	Estudiante e;
	e = { 999666, "Sempronio Gomez", 7234 };
	cola.push(e);
	cola.emplace(666999, "Juan Torres", 3245);

	cout << "Cantidad de estudiantes en la cola: " << cola.size() << endl;
	cout << "Estudiante con mayor prioridad / puntuacion: " << cola.top() << endl;
	cout << "Estudiantes en la cola: " << endl;
	while(!cola.empty()){
		cout << cola.top() << endl;
		cola.pop();
	}

}

void vectorTest() {
	//Un vector es un contenedor secuencial en el que los elementos estan almacenados de forma contigua en memoria.
	//De forma similar a un arreglo. El vector puede ser utilizado en sustitucion de un arreglo, con la diferencia de que el vector tiene tamaño dinamico
	vector<int> v(5);
	for (int i = 0; i < 5; i++) {
		//Los elementos del vector se pueden acceder por posicion utilizando el operador []
		v[i] = rand() % 100;
	}
	cout << "Elementos del vector: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
	v.resize(10); //Se modifica el tamaño del vector

	//El vector es un contenedor que puede ser iterado con un for basado en rango
	cout << "Elementos del vector: ";
	for (int n : v) {
		cout << n << ", ";
	}
	cout << endl;
	//Si se necesita un espacio extra, se puede agregar un elemento nuevo al final del vector con push_back
	v.push_back(rand() % 100);
	cout << "Nuevo tamaño del vector: " << v.size() << endl;
	cout << "Nuevo vector: ";
	//Los contenedores secuenciales pueder ser recorridos por medio de un iterador
	//Un iterador es un objeto que "apunta" a un elemento del contenedor. El iterador puede ser recorrido al siguiente elemento en la secuencia almacenada en el contendor.
	//Los contenedores que soportan el uso de iteradores tienen el metood begin(), que devuelv un iterador al inicio de la secuancia
	//Y end() que devuelve un iterador al final de la secuencia

	vector<int>::iterator it;
	//Obtenemos el iterador al inicio del vector con el metodo begin()
	it=v.begin();
	//Mientras el iterador no este en el fin de la secuencia, seguimos iterando
	while (it != v.end()) {
		//Para acceder al elemento al que apunta el iterador, se utiliza el operador de contenido *
		cout << *it << ", ";
		it++;
	}
	cout << endl;

}


int main(){

	//stackTest();
	//stackTest2();
	//stackTest3();
	//queueTest();
	//queueTest2();
	//pqueueTest();
	//pqueueTest2();
	vectorTest();
}
