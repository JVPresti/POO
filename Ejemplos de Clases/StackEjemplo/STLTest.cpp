#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include "Persona.h"
#include <conio.h>

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
	cout << "Numero de elementos en la cola: " << cola.size() << _getch();
	cout << "Elemento al inicio de la cola: " << cola.front() << _getch();
	cout << "Elemento al final de la cola: " << cola.back() << _getch();
	
	cout << "Elementos de la cola: ";
	while (!cola.empty()) {
		cout << cola.front() << ", ";
		cola.pop_front();
	}


}

int main(){

	//stackTest();
	//stackTest2();
	//stackTest3();
	//queueTest();
	queueTest2();
}
