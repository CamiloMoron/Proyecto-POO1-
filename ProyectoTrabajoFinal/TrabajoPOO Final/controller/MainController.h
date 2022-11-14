#pragma once
#include "UsuarioController.h"
#include "CatController.h"
#include "../model/Producto.h"
using namespace std;

class MainController
{
private:
	string producto;
	string marca;
	string ccategoria;
	float precio;
	string vendedor;
	int opc = 0;
	int idaescoger;
	float preciototal = 0;
	float precioconigv = 0;
	int position;
	string usuario;
	string password;
	int cantidad;
	Arreglo<Productos> prod;
	UsuarioController Uc;
	int posicion = 0;
	int contadordeproductos = 0;
	int codCategoria;
	string nomCategoria;
	CatController Cc;
public:
	MainController()
	{
	}
	void grabar(Productos obj)
	{
		ofstream grabarproductos;
		grabarproductos.open("productos.csv", ios::app);
		if (grabarproductos.is_open())
		{
			grabarproductos << obj.getId() << ";" << obj.getProducto() << ";" << obj.getMarca() << ";" << obj.getCategoria() << ";" << obj.getPrecio() << ";" << obj.getVendedor() << endl;
			grabarproductos.close();
		}
		else
		{
			cout << "Ocurrio un error al abrir el archivo" << endl;
		}
	}
	int imprimirlistadocsv(bool leer)
	{
		int cont = 0;
		ifstream leerproductos;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leerproductos.open("productos.csv", ios::in);
		if (leerproductos.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		if (leer == true)
		{
			while (getline(leerproductos, linea))
			{
				stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
				string id, producto, marca, precio, vendedor, categoria;
				getline(stream, id, limite);
				getline(stream, producto, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
				getline(stream, marca, limite);
				getline(stream, categoria, limite);
				getline(stream, precio, limite);
				getline(stream, vendedor, limite);
				cont++;
				cout << "ID: " << id << " Nombre: " << producto << " Categoria: " << categoria <<  " Marca: " << marca << " Precio : " << precio << " Vendedor : " << vendedor << endl;
			}
		}
		else
		{
			while (getline(leerproductos, linea))
			{
				stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
				string id, producto, marca, precio, vendedor;
				getline(stream, id, limite);
				getline(stream, producto, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
				getline(stream, marca, limite);
				getline(stream, precio, limite);
				getline(stream, vendedor, limite);
				cont++;
			}
		}
		return cont +1;
		leerproductos.close();
	}
	float igv()
	{
		ifstream leerproductos;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leerproductos.open("igv.csv", ios::in);
		if (leerproductos.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leerproductos, linea))
		{
			float precioenfloat;
			int identero;
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string igv;
			float igvfloat;
			getline(stream, igv, limite);
			igvfloat = stof(igv);
			return igvfloat;
		}
		leerproductos.close();
	}
	void elegirproducto(int IDdeproducto, int cantidad)
	{
		ifstream leerproductos;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leerproductos.open("productos.csv", ios::in);
		if (leerproductos.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leerproductos, linea))
		{
			float precioenfloat;
			int identero;
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string id, producto, marca, precio, vendedor, categoria;
			getline(stream, id, limite);
			getline(stream, producto, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
			getline(stream, marca, limite);
			getline(stream, categoria, limite);
			getline(stream, precio, limite);
			getline(stream, vendedor, limite);
			precioenfloat = stof(precio);
			identero = stoi(id);
			if (IDdeproducto == identero)
			{
				for (int i = 0; i < cantidad; i++)
				{
					prod.push_back(Productos(identero, producto, marca, categoria, precioenfloat, vendedor));
				}
			}
			else
			{
				cout << "No existe el ID del producto" << endl;
			}
		}
		leerproductos.close();
	}
	void elegirproducto(string productoporbuscar)
	{
		ifstream leerproductos;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leerproductos.open("productos.csv", ios::in);
		if (leerproductos.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leerproductos, linea))
		{
			float precioenfloat;
			int identero;
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string id, producto, marca, precio, vendedor, categoria;
			getline(stream, id, limite);
			getline(stream, producto, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
			getline(stream, marca, limite);
			getline(stream, categoria, limite);
			getline(stream, precio, limite);
			getline(stream, vendedor, limite);
			precioenfloat = stof(precio);
			identero = stoi(id);
			if (productoporbuscar == producto)
			{
				cout << "ID: " << id << " Nombre: " << producto << "Categoria: " << categoria << " Marca: " << marca << " Precio : " << precio << " Vendedor : " << vendedor << endl;
			}
		}
		leerproductos.close();
	}
	void login()
	{
		do
		{
			system("cls");
			cout << "     MENU DE USUARIO      " << endl;
			cout << "1.Iniciar Sesion          " << endl;
			cout << "2.Crear Usuario           " << endl;
			cout << "3.Salir                   " << endl;
			cin >> opc;
			switch (opc)
			{
			case 1:
				cout << "Ingresar Usuario Existente: " << endl;
				cin >> usuario;
				cout << "Ingresar Password:          " << endl;
				cin >> password;
				if (Uc.leer(usuario, Uc.Desencriptar(password, -5)) == 1)
				{
					/*el m�todo Leer de la clase UsuarioController recibe dos valores de tipo string, uno es usuario y otro contrase�a
					en este caso como la contrse�a se guarda encriptada, se llama al metodo Desencriptar que recibe dos inputs,
					el de la contrase�a original y la llave de desencriptaci�n, que en este caso es fija pero se puede randomizar y
					asignar a usuarios individuales. Si el output del m�todo booleano Leer es cierto, el input del usuario es igual al
					que se tiene guardado en el csv para ese username, dando acceso al usuario al men� de opciones de compra */
					system("cls");
					Menu();
				}
				else
				{
					if (Uc.leer(usuario, Uc.Desencriptar(password, -5)) == 2)
					{
						system("cls");
						MenuAdmin();
					}
					system("cls");
					cout << "Cerrando sesion (si ve este mensaje al ingresar su usuario, ha ocurrido un error de grabacion en la BD, comuniquese con el administrador) " << endl;
					system("pause");
				}
				break;
			case 2:
				cout << "Ingresar Usuario Nuevo:     " << endl;
				cin >> usuario;
				cout << "Ingresar Password:          " << endl;
				cin >> password;
				/*Se crea un objeto de tipo Usuario que tiene dos atributos de tipo string, usuario y contrase�a, se pasa el usuario
				como lo escribe usuario del programa y la contrase�a pasa al m�todo encriptar, que recibe la contrase�a y la clave de
				encriptaci�n y encripta la contrase�a. Luego de a�ade este objeto al arreglo de objetos Uc y se graba sus valores en el
				csv con el m�todo grabar, dando como resultado un archivo con el username y el password encriptado de cada usuario*/
				Usuario usr(usuario, Uc.Encriptar(password, 5),0);
				Uc.grabar(usr);
				break;
			}
		} while (opc != 3); //Sale del loop una vez opc=2//
	}
	void carrito()
	{
		prod.Imprimir([&](Productos p)
			{cout << "ID: " << p.getId() << " Producto: " << p.getProducto() << "Marca : " << p.getMarca() << "Precio : " << p.getPrecio() << "Vendedor : " << p.getVendedor() << endl; });
		cout << "Checkout" << endl;
		prod.Imprimir([&](Productos p)
			{ preciototal = p.getPrecio() + preciototal; });
		cout << "Precio Total: " << preciototal << endl;
		precioconigv = (preciototal * (igv() / 100)) + preciototal;
		cout << "Precio con IGV: " << igv() << "% " << precioconigv << endl;
		preciototal = precioconigv = 0;
		system("pause");
		system("cls");
	}
	void Menu()
	{
		do
		{
			cout << "              MENU                " << endl;
			cout << "1. Listado de Productos:          " << endl;
			cout << "2. Elegir producto:               " << endl;
			cout << "3. Carrito de compras:            " << endl;
			cout << "4. Eliminar producto del carrito: " << endl;
			cout << "5. Buscar Producto                " << endl;
			cout << "6. Buscar producto en el carrito  " << endl;
			cout << "7. Salir                          " << endl;
			cin >> opc;
			switch (opc)
			{
			case 1:
				imprimirlistadocsv(true);
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "Digite el ID del producto a elegir al carrito: " << endl;
				cin >> idaescoger;
				cout << "Digite la cantidad: " << endl;
				cin >> cantidad;
				elegirproducto(idaescoger, cantidad);
				system("cls");
				break;
			case 3:
				carrito();
				break;
			case 4:
				prod.Imprimir([&](Productos p)
				{cout << ++posicion << " | ID: " << p.getId() << " Producto: " << p.getProducto() << " Marca : " << p.getMarca() << " Precio : " << p.getPrecio() << " Vendedor : " << p.getVendedor() << endl; });
				cout << "Digite el numero de orden que desea borrar: " << endl;
				cin >> position;
				--position;
				prod.pop_position(position);
				break;
			case 5:
				cout << "Buscar producto: " << endl;
				cin >> producto;
				elegirproducto(producto);
				break;
			case 6:
				cout << "Producto por buscar: " << endl;
				cin >> producto;
				prod.Imprimir([&](Productos p)
					{ if (p.getProducto() == producto)
				{
					++contadordeproductos;
					cout << " | ID: " << p.getId() << " Producto: " << p.getProducto() << " Marca : " << p.getMarca() << " Precio : " << p.getPrecio() << " Vendedor : " << p.getVendedor() << endl;
				} });
				if (contadordeproductos == 0)
				{
					cout << "No se encontro ningun producto en su carrito con ese nombre" << endl;
				}
				contadordeproductos = 0;
				break;
			default:
				break;
			}
		} while (opc != 7);
	}
	void MenuAdmin()
	{
		do
		{
			cout << "              MENU                " << endl;
			cout << "1. Listado de Productos:          " << endl;
			cout << "2. Elegir producto:               " << endl;
			cout << "3. Carrito de compras:            " << endl;
			cout << "4. Agregar productos a la BD:     " << endl; //Todavía solo lo he implementado para que aparezcan como opciones, no he implementado contadores ni cambiado string categoria a int codcategira
			cout << "5. Eliminar producto del carrito: " << endl;
			cout << "6. Buscar producto                " << endl;
			cout << "7. Buscar producto en el carrito  " << endl;
			cout << "8. Agregar categorias             " << endl;
			cout << "9. Listado de categorias          " << endl;
			cout << "10. Salir                          " << endl;
			cin >> opc;
			switch (opc)
			{
			case 1:
				imprimirlistadocsv(true);
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "Digite el ID del producto a elegir al carrito: " << endl;
				cin >> idaescoger;
				cout << "Digite la cantidad: " << endl;
				cin >> cantidad;
				elegirproducto(idaescoger, cantidad);
				system("cls");
				break;
			case 3:
				carrito();
				break;
			case 4:
				cout << "Digite el nombre del producto: " << endl;
				cin >> producto;
				cout << "Digite la marca: " << endl;
				cin >> marca;
				cout << "Digite el codigo de la categoria: " << endl;
				Cc.imprimirlistadocategoria();
				cin >> ccategoria;
				cout << "Digite el precio: " << endl;
				cin >> precio;
				cout << "Digite el vendedor: " << endl;
				cin >> vendedor;
				grabar(Productos(imprimirlistadocsv(false), producto, marca, ccategoria, precio, vendedor));
				system("pause");
				system("cls");
				break;
			case 5:
				prod.Imprimir([&](Productos p)
					{cout << ++posicion << " | ID: " << p.getId() << " Producto: " << p.getProducto() << " Marca : " << p.getMarca() << " Precio : " << p.getPrecio() << " Vendedor : " << p.getVendedor() << endl; });
				cout << "Digite el numero de orden que desea borrar: " << endl;
				cin >> position;
				--position;
				prod.pop_position(position);
				break;
			case 6:
				cout << "Buscar producto: " << endl;
				cin >> producto;
				elegirproducto(producto);
				break;
			case 7:
				cout << "Producto por buscar: " << endl;
				cin >> producto;
				prod.Imprimir([&](Productos p)
					{ if (p.getProducto() == producto)
				{
					++contadordeproductos;
					cout << " | ID: " << p.getId() << " Producto: " << p.getProducto() << " Marca : " << p.getMarca() << " Precio : " << p.getPrecio() << " Vendedor : " << p.getVendedor() << endl;
				} });
				if (contadordeproductos == 0)
				{
					cout << "No se encontro ningun producto en su carrito con ese nombre" << endl;
				}
				contadordeproductos = 0;
				break;
			case 8: 
			{cout << "Codigo de categoria: "<<endl;
					cin>>codCategoria;
					cout << "Nombre de categoria "<< endl;
					cin>>nomCategoria;
					Categoria categ(codCategoria,nomCategoria);
					Cc.grabar(categ);
					system("pause");
					system ("cls");}
					break;
			case 9:
				Cc.imprimirlistadocategoria();
				system ("pause");
				system ("cls");
				break;
			default:
				break;
			}
		} while (opc != 10);	
	}
};