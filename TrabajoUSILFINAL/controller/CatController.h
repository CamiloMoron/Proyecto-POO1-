#include "../model/Categoria.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
class CatController
{
private:
	vector<Categoria> vectorCategoria;
public:
	CatController()
	{

	}
	Categoria get(int pos)
	{
		return vectorCategoria[pos];
	}
	int size()
	{
		return vectorCategoria.size();
	}
	void add(Categoria obj)
	{
		vectorCategoria.push_back(obj); 
	}
	void grabar(Categoria obj)
	{
		ofstream grabarcategoria;
		grabarcategoria.open("categoria.csv", ios::app); 
		if (grabarcategoria.is_open())
		{
			grabarcategoria << obj.getCodCat() << ";" << obj.getNomCat() << ";" << endl;
			grabarcategoria.close();
		}
		else
		{
			cout << "Ocurrio un error al abrir el archivo" << endl;
		}
	}
	void leer(Categoria obj)
	{
		ifstream leercategoria;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';'; //Determina el fin de linea en el csv, que es un ;//
		leercategoria.open("categoria.csv", ios::in);
		if (leercategoria.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leercategoria, linea))
		{
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string codCat, nomCat;
			int codint;
			getline(stream, codCat, limite); 
			getline(stream, nomCat, limite);
			codint = stoi(codCat);

			cout << "Codigo Categoria: " << codint << " Nombre Categoria: " << nomCat << endl;
		}
		leercategoria.close();
	}
	void imprimirlistadocategoria()
	{
		ifstream leercategoria;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leercategoria.open("categoria.csv", ios::in);
		if (leercategoria.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leercategoria, linea))
		{
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string// 
			string codcat, nombrecat;
			int codcatint;
			getline(stream, codcat, limite);
			getline(stream, nombrecat, limite);
			codcatint = stoi(codcat);
			cout << "Codigo categoria: " << codcatint << " Nombre categoria: " << nombrecat << endl;
		}
		leercategoria.close();
	}
	string elegircat()
	{
		int eleccion;
		cout << "Digite el ID de la categoria: " << endl;
		cin >> eleccion;
		ifstream leercategoria;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leercategoria.open("categoria.csv", ios::in);
		if (leercategoria.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leercategoria, linea))
		{
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string codcat, nombrecat;
			int codcatint;
			getline(stream, codcat, limite);
			getline(stream, nombrecat, limite);
			codcatint = stoi(codcat);
			if (eleccion == codcatint)
			{
				return nombrecat;
			}
		}
		leercategoria.close();
	}

};