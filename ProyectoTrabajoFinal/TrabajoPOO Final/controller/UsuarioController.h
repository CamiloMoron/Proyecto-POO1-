#pragma once
#include "../model/Usuario.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class UsuarioController
{
private:
	vector<Usuario> vectorusuario; //Arreglo de objetos de tipo Usuario//
public:
	UsuarioController()
	{
	}
	Usuario get(int pos)
	{
		return vectorusuario[pos];
	}
	int size()
	{
		return vectorusuario.size();
	}
	void add(Usuario obj)
	{
		vectorusuario.push_back(obj); //Inserta los objetos de tipo Usuario al final del vector para poder seguir agregando din�micamente//
	}
	void grabar(Usuario obj)
	{
		ofstream grabarusuario;
		grabarusuario.open("usuario.csv", ios::app); //Graba los inputs de usuario de Main controller y el output de Encriptaci�n//
		if (grabarusuario.is_open())
		{
			grabarusuario << obj.getUsername() << ";" << obj.getPassword() << ";0"<< endl;
			grabarusuario.close();
		}
		else
		{
			cout << "Ocurrio un error al abrir el archivo" << endl;
		}
	}
	int leer(string usu, string pass)
	{
		ifstream leerusuario;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';'; //Determina el fin de linea en el csv, que es un ;//
		leerusuario.open("usuario.csv", ios::in);
		if (leerusuario.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leerusuario, linea))
		{
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string usuario, contrasena, admin;
			int adminint;
			getline(stream, usuario, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
			getline(stream, contrasena, limite);
			getline(stream, admin, limite);
			adminint = stoi(admin);
			if (usu == usuario)
			{
				if (pass == contrasena)
				{
					if (adminint == 1)
					{
						return 2;
					}
					if (adminint == 0)
					{
						return 1;
					}
					
					//Retorna un valor booleano verdadero cuando se encuentra la contrase�a asociada al usuario//
				}
			}
		}
		leerusuario.close();
	}
	string Encriptar(string pass, int clave)
	{
		transform(pass.begin(), pass.end(), pass.begin(), ::toupper);
		/*Utiliza encriptaci�n C�sar para la contrase�a, le indica a la funci�n transform de la librer�a algorithm donde empieza
		password y donde termina y de donde a donde quiere que la modifique con toupper que convierte los char en el string pass
		a may�scula para trabajar con la tabla ASCII*/
		string palabracodificada = "";
		for (auto c : pass)
		{
			if (isalpha(c)) //Conviere los char del string pass a valores en la tabla ASCII, no los n�meros//
			{
				c += clave; //Se le suma la clave de encriptaci�n para obtener un nuevo valor//
				if (c > 'Z')
				{
					c -= 26; //Se le resta 26 a la Z para que empiece nuevamente de A en vez de irse a otros s�mbolos de la tabla//
				}
				if (c < 'A')
				{
					c += 26;
				}
			}
			palabracodificada += c; //A�ade el nuevo char al string palabracodificada
		}
		return palabracodificada;
	}
	string Desencriptar(string pass, int clave)
	{
		return Encriptar(pass, -clave); //Para este algoritmo, desencriptar simplemente requiere usar la inversa de la clave//
	}
};