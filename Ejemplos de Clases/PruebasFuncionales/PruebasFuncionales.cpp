#include <iostream>
#include <functional>
#include <vector>
#include <ostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::ostream;


ostream& operator<<(ostream& out, vector<int> v) {
	out << "[";
    for (int n : v)
        cout << n << " ";
	out << "]";
	return out;
}

void saludo() {
    cout << "Hola mundo..." << endl;
}

void saludar(function<void(void)> fs){
	cout << "Te voy a saludar" << endl;
    cout << "Preparate" << endl;
    fs();
    cout << "Listo!" << endl;
}

void saludo2() {
    srand(time(0));
    if ((rand() % 100) < 50) {
        cout << "Que transa" << endl;
    }
    else {
        cout << "Hola, buenos dias" << endl;
    }
}

int contarPares(vector<int> v) {
    int conteo = 0;
    for (int n : v){
        if ((n % 2) == 0) {
			conteo++;
		}
    }
    return conteo;
}

vector<int> extraerPares(vector<int> v) {
    vector<int> pares;
    for (int n : v) {
        if ((n % 2) == 0) {
            pares.push_back(n);
        }
    }
    return pares;
}

int contar(vector<int> v, function<bool(int)> p) {
    int conteo = 0;
    for (int n : v) {
        if (p(n)==true) {
            conteo++;
        }
    }
    return conteo;
}

vector<int> extraer(vector<int> v, function<bool(int)> p) {
    vector<int> elem;
    for (int n : v) {
        if (p(n)==true) {
            elem.push_back(n);
        }
    }
    return elem;
}

bool esPar(int x) {
    return ((x % 2) == 0);
}

bool esPrimo(int x) {
    if( x == 2 || x == 3 )return true;
    if( x == 1 || (x%2)==0 || (x%3)==0)return false;
    for (int d = 5; d <= x / 2; d += 2) {
        if((x%d)==0)return false;
    }
    return true;
}

int main()
{
    //saludo();
    //Las funciones pueden ser manejadas como objetos.
    //La clase function es una plantilla para crear objetos de tipo funcion. Estos objetos siempre tienen una funcion asociada.
    //La plantilla de function recibe como parametro el tipo de retorno de la funcion y los tipos de los parametros de la funcion.
    function<void(void)>f=saludo;
    //Para invocar la funcion, se utiliza el operador ();
    //f();
    //saludar(f);
    cout << endl;
    //saludar(saludo2);

    vector<int> numeros = { 6,9,11,666,85,42,1,8,2,25,21,777 };

    cout << "Vector: " << numeros << endl;
    /*cout << "Hay " << contarPares(numeros) << " numeros pares en el vector" << endl;

    vector<int> pares = extraerPares(numeros);
    cout << "Pares: " << pares << endl;
    */

    vector<int> n2 = extraer(numeros, esPar);
    cout << "Hay " << n2.size() << " numeros pares en el vector" << endl;
    cout << "Numeros pares: " << n2 << endl;

    n2=extraer(numeros, esPrimo);
    cout << "Hay " << n2.size() << " numeros primos en el vector" << endl;
    cout << "Numeros primos: " << n2 << endl;
    //Una forma de crear una funcion es por medio de una expresion alfa. La expresion alfa permite crear la funcion en el contexto del codigo en el que se va a 
    //Usar. Se recomienda que el codigo de la funcion sea corto, para no agregar complejidad a su lectura.
    //La sintaxis de una expresion alfa es:
    //      [](parametros)->tipo_de_retorno{cuerpo de la funcion}
    auto m5= [](int x)-> bool {return ((x % 2) == 0);};
    n2 = extraer(numeros, m5);
    cout << "Hay " << n2.size() << " numeros multiplos de 5 en el vector" << endl;
    cout << "Numeros multiplos de 5: " << n2 << endl;

    cout << "Hay " << std::count_if(numeros.begin(), numeros.end(), [](int x) {return ((x % 3) == 0);});
    cout << " numeros multiplos de 3 en el vector" << endl;




}

