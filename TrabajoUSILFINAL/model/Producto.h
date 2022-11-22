#pragma once
#include "Array.h"
#include <string>

using namespace std;

class Productos
{
private:
	int id;
	string producto;
	string marca;
	string categoria;
	float precio;
	string vendedor;
	int cantidad;
	string estado;
public:
	Productos(int id = 0, string producto = " ", string marca = " ", string categoria = "N/A", float precio = 0, string vendedor = " ", int cantidad = 0, string estado = "") : id(id), producto(producto), marca(marca), categoria(categoria), precio(precio), vendedor(vendedor), cantidad(cantidad), estado(estado)
	{
		
	}
	int getId()
	{
		return id;
	}
	string getProducto()
	{
		return producto;
	}
	string getMarca()
	{
		return marca;
	}
	float getPrecio()
	{
		return precio;
	}
	string getVendedor()
	{
		return vendedor;
	}
	string getCategoria()
	{
		return categoria;
	}
	int getCantidad()
	{
		return cantidad;
	}
};