#pragma once
#pragma once
#include "UsuarioController.h"
#include "CatController.h"
#include "../model/Producto.h"
using namespace std;

class MainController
{
private:
	int ad = 0;
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
	int respuesta;
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
			grabarproductos << obj.getId() << ";" << obj.getProducto() << ";" << obj.getMarca() << ";" << obj.getCategoria() << ";" << obj.getPrecio() << ";" << obj.getVendedor() << ";" << obj.getCantidad() << endl;
			grabarproductos.close();
		}
		else
		{
			cout << "Ocurrio un error al abrir el archivo" << endl;
		}
	}
	void grabarfacturas(string usuario, string producto, string marca, string categoria, float precio, string vendedor, int cantidad, string estado)
	{
		ofstream grabarproductos;
		grabarproductos.open("facturas.csv", ios::app | ios::in);
		if (grabarproductos.is_open())
		{
			grabarproductos << usuario << ";" << producto << ";" << marca << ";" << categoria << ";" << precio << ";" << vendedor << ";" << cantidad << ";" << estado << endl;
			grabarproductos.close();
		}
		else
		{
			cout << "Ocurrio un error al abrir el archivo" << endl;
		}
	}
	void grabarfacturasaprobadas(string usuario, string producto, string marca, string categoria, string precio, string vendedor, string cantidad)
	{
		ofstream grabarproductos1;
		grabarproductos1.open("facturasaprobadas.csv", ios::app | ios::in);
		if (grabarproductos1.is_open())
		{
			grabarproductos1 << usuario << ";" << producto << ";" << marca << ";" << categoria << ";" << precio << ";" << vendedor << ";" << cantidad << ";" << "Aprobado" << endl;
			grabarproductos1.close();
		}
		else
		{
			cout << "Ocurrio un error al abrir el archivo" << endl;
		}
	}
	void aprobarventa()
	{
		ifstream leerfacturas;
		string usuarioporaprobar;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leerfacturas.open("facturas.csv", ios::in);
		if (leerfacturas.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leerfacturas, linea))
		{
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string usuario, producto, marca, precio, vendedor, categoria, cantidad, estado;
			getline(stream, usuario, limite);
			getline(stream, producto, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
			getline(stream, marca, limite);
			getline(stream, categoria, limite);
			getline(stream, precio, limite);
			getline(stream, vendedor, limite);
			getline(stream, cantidad, limite);
			getline(stream, estado, limite);
			if (estado == "Compra realizada, esperando pago")
			{
				cout << "Usuario: " << usuario << " Nombre: " << producto << " Categoria: " << categoria << " Marca: " << marca << " Precio : " << precio << " Vendedor : " << vendedor << " Cantidad: " << cantidad << " Estado: " << estado << endl;
			}
		}
		leerfacturas.close();
		cout << "Digite que usuario desea aprobar" << endl;
		cin >> usuarioporaprobar;
		leerfacturas.open("facturas.csv", ios::in);
		if (leerfacturas.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		while (getline(leerfacturas, linea))
		{
			stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
			string usuario, producto, marca, precio, vendedor, categoria, cantidad, estado;
			getline(stream, usuario, limite);
			getline(stream, producto, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
			getline(stream, marca, limite);
			getline(stream, categoria, limite);
			getline(stream, precio, limite);
			getline(stream, vendedor, limite);
			getline(stream, cantidad, limite);
			getline(stream, estado, limite);
			if (estado == "Compra realizada, esperando pago" && usuario == usuarioporaprobar)
			{
				grabarfacturasaprobadas(usuario, producto, marca, categoria, precio, vendedor, cantidad);
			}
		}


		leerfacturas.close();
	}
	int imprimirfacturas()
	{
		ifstream leerproductos;
		string linea = " "; //almacena la l�nea del documento mientras lo lee linea por linea//
		char limite = ';';  //Determina el fin de linea en el csv, que es un ;//
		leerproductos.open("facturas.csv", ios::in);
		if (leerproductos.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
			exit(1); //Equivalente del break//
		}
		else
		{
			while (getline(leerproductos, linea))
			{
				stringstream stream(linea); //Convierte todos los valores almacenados en linea en un string//
				string id, producto, marca, precio, vendedor, categoria, cantidad, estado;
				getline(stream, id, limite);
				getline(stream, producto, limite); //Almacena el usuario en donde encuentra el usuario en el documento y contrase�a de la misma forma//
				getline(stream, marca, limite);
				getline(stream, categoria, limite);
				getline(stream, precio, limite);
				getline(stream, vendedor, limite);
				getline(stream, cantidad, limite);
				getline(stream, estado, limite);
				cout << "ID: " << id << " Nombre: " << producto << " Categoria: " << categoria << " Marca: " << marca << " Precio : " << precio << " Vendedor : " << vendedor << " Cantidad: " << cantidad << " Estado: " << estado << endl;
			}
		}
		leerproductos.close();
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
				cout << "ID: " << id << " Nombre: " << producto << " Categoria: " << categoria << " Marca: " << marca << " Precio : " << precio << " Vendedor : " << vendedor << endl;
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
		return cont + 1;
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
				prod.push_back(Productos(identero, producto, marca, categoria, precioenfloat, vendedor, cantidad));
				
			}
			else
			{
				cout << "No existe el ID del producto" << endl;
			}
		}
		leerproductos.close();
	}
	void buscarproducto(string productoporbuscar)
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
		Usuario nuevo;
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
				ad = Uc.leer(usuario, password);
				if (ad == 0)
				{
					Menu();
				}
				if (ad == 1)
				{
					MenuAdmin();
				}
					/*el m�todo Leer de la clase UsuarioController recibe dos valores de tipo string, uno es usuario y otro contrase�a
					en este caso como la contrse�a se guarda encriptada, se llama al metodo Desencriptar que recibe dos inputs,
					el de la contrase�a original y la llave de desencriptaci�n, que en este caso es fija pero se puede randomizar y
					asignar a usuarios individuales. Si el output del m�todo booleano Leer es cierto, el input del usuario es igual al
					que se tiene guardado en el csv para ese username, dando acceso al usuario al men� de opciones de compra */
				break;
			case 2:
				cout << "Ingresar Usuario Nuevo:     " << endl;
				cin >> usuario;
				cout << "Ingresar Password:          " << endl;
				cin >> password;
				string tipo = "0";
				nuevo.agregar(_strdup(usuario.c_str()), _strdup(password.c_str()), _strdup(tipo.c_str()));
				Uc.grabar(nuevo);
				break;
			}
		} while (opc != 3); //Sale del loop una vez opc=2//
	}
	void carrito()
	{
		prod.Imprimir([](Productos p)
			{cout << "ID: " << p.getId() << " Producto: " << p.getProducto() << " Marca : " << p.getMarca() << " Precio : " << p.getPrecio() << " Vendedor : " << p.getVendedor() << " Cantidad: " << p.getCantidad() << endl;  });
		cout << "Checkout" << endl;
		
		prod.Imprimir([&](Productos p)
			{ preciototal = (p.getPrecio() * p.getCantidad()) + preciototal; });
		
		cout << "Precio Total: " << preciototal << endl;
		precioconigv = (preciototal * (igv() / 100)) + preciototal;
		cout << "Precio con IGV: " << igv() << "% " << precioconigv << endl;
		preciototal = precioconigv = 0;
		cout << "DESEA REALIZAR LA COMPRA? (Si = 1/No = 0)" << endl;
		cin >> respuesta;
		if (respuesta == 1 )
		{
			prod.Imprimir([&](Productos p)
				{
					grabarfacturas(usuario, p.getProducto(), p.getMarca(), p.getCategoria(), p.getPrecio(), p.getVendedor(), p.getCantidad(), "Compra realizada, esperando pago");
				});
		}
		if (respuesta == 0)
		{
			prod.Imprimir([&](Productos p)
				{
					grabarfacturas(usuario, p.getProducto(), p.getMarca(), p.getCategoria(), p.getPrecio(), p.getVendedor(), p.getCantidad(), "Compra anulada");
				});
		}
		
		
		
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
					{cout << ++posicion << " | ID: " << p.getId() << " Producto: " << p.getProducto() << " Marca : " << p.getMarca() << " Precio : " << p.getPrecio() << " Vendedor : " << p.getVendedor() << " Cantidad: " << p.getCantidad() << endl; });
				cout << "Digite el numero de orden que desea borrar: " << endl;
				cin >> position;
				--position;
				prod.pop_position(position);
				break;
			case 5:
				cout << "Buscar producto: " << endl;
				cin >> producto;
				buscarproducto(producto);
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
			cout << "10. Verificar compras             " << endl;
			cout << "11. Salir                         " << endl;
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
				ccategoria = Cc.elegircat();
				cout << "Digite el precio: " << endl;
				cin >> precio;
				cout << "Digite el vendedor: " << endl;
				cin >> vendedor;
				grabar(Productos(imprimirlistadocsv(false), producto, marca, ccategoria, precio, vendedor, 0));
				
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
				buscarproducto(producto);
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
			{cout << "Codigo de categoria: " << endl;
			cin >> codCategoria;
			cout << "Nombre de categoria " << endl;
			cin >> nomCategoria;
			Categoria categ(codCategoria, nomCategoria);
			Cc.grabar(categ);
			system("pause");
			system("cls"); }
			break;
			case 9:
				Cc.imprimirlistadocategoria();
				system("pause");
				system("cls");
				break;
			case 10:
				aprobarventa();
			default:
				break;
			}
		} while (opc != 11);
	}
};

//Recordar grabar la venta, guardar en csv lo que está en el carrito//
//Agregar un "estado de venta" y la capacidad de anular ventas//