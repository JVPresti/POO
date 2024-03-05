  #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include "Sobrecargar.h"

using std::cout;
using std::endl;
using std::string;
using std::istringstream;

string remove_space(string str);

int main()
{
    string f = "1 / 2";
    Sobrecargar f1 = f;
    string cadena = "3 / 4";
    int num, den;
    char o;
    cadena = remove_space(cadena);
    istringstream in(cadena);
    in >> num >> o >> den;
    //cout << num << "/" << den << endl;
    Sobrecargar f2 = cadena;

    Sobrecargar f3 = f1 + f2;
    cout << f3.numerador << "/" << f3.denominador << endl;

    return 0;
    
}
