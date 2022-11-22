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
	fstream archivo; 
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
		grabarusuario.open("usuario.bin", ios::in | ios::app | ios::binary); //Graba los inputs de usuario de Main controller y el output de Encriptaci�n//
		if (grabarusuario.fail())
		{
			cout << "Error al abrir la DB" << endl;
		}
		else
		{
			grabarusuario.write((char*)&obj, sizeof(Usuario)); //A la hora de escribir en bin, se tiene que trabajar con cadenas de chars//
			grabarusuario.close();
			cout << "Usuario creado satisfactoriamente" << endl;
		}
	}
	int leer(string usuarioporencontrar, string password)
	{
		int cont = 0;
		int aux = 0;
		Usuario imp = Usuario(); //llama al constructor vacio encontrado en usuario//
		archivo.open("usuario.bin", ios::in | ios::binary); 
		if (archivo.fail())
		{
			cout << "Error al leer" << endl;
		}
		else
		{
			while (!archivo.eof()) //"mientras no se llegue al final del archivo"//
			{
				archivo.read((char*)&imp, sizeof(Usuario));
				if (!archivo.eof())
				{
					cont = imp.imprimir(usuarioporencontrar, password);
					if (cont == 0)
					{
						return 0;
					}
					if (cont == 1)
					{
						return 1;
					}
				}
			}
		}
		archivo.close();
		
		
	}
	/*
	string Encriptar(string pass, int clave)
	{
		transform(pass.begin(), pass.end(), pass.begin(), ::toupper);
		Utiliza encriptaci�n C�sar para la contrase�a, le indica a la funci�n transform de la librer�a algorithm donde empieza
		password y donde termina y de donde a donde quiere que la modifique con toupper que convierte los char en el string pass
		a may�scula para trabajar con la tabla ASCII
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
	*/

	//Algoritmo de encriptación usado antes de la transición a archivos .bin para la encriptacion de usuario contrasena
};
