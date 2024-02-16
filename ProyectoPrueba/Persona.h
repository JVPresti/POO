#pragma once
class Persona {
	//Los miembros de la clase pueden ser privados o publicos, por default son privados, pero se puede cambiar al tipo que nos convenga
	//Existen 3 tipos de proteccion:
	//Public: Los miembros son accesibles desde cualquier parte del programa
	//Private: Los miembros son accesibles solo desde la misma clase
	//Protected: Los miembros son accesibles desde la misma clase y desde las clases hijas
	//Para poner el tipo de proteccion, es utilizada la palabra clave seguida de dos puntos antes de la declaracion de los miembros

protected:
	int edad;
	//char name[30];
	char* name; //Con memoria dinamica

	void reir();
	void comer();
	
public:
	void saludar();
	void hacerReir(int motivo);
	void liberar();
	
	//Los objetos pueden tener constructores, que son funciones que se ejecutan automaticamente cuando el objeto es creado
	//El constructor es una funcion que tiene el mismo nombre que la clase, y no tiene tipo de retorno
	//Los constructores pueden tener argumentos, pero no pueden ser llamados directamente

	//Constructores
	Persona(const char* elName, int laEdad); //Asigna nombre y edad por parametro
	Persona(); //Asigna nombre y edad por default

	//Destructor
	~Persona();

	//En c++ podemos usar el mismo nombre para diferentes funciones, siempre y cuando los parametros sean diferentes
	//Ciamdp implementamos funciones de este tipo, se le llama sobrecarga de funciones

	//Los objetos pueden tener un destructor, El destructor es una funcion que se ejecuta automaticamente cuando el objeto es eliminado
	//El destructor es una funcion que tiene el mismo nombre que la clase, pero precedido por el simbolo ~

};
