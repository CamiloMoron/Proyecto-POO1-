#pragma once
#include <functional>

using namespace std;

template <class Generico>

class Arreglo
{
private:
	Generico* arr;
	Generico* possarr;
	int pos;
	unsigned int size;
public:
	Arreglo(unsigned int size = 50) :size(size), pos(-1)
	{
		arr = new Generico[size];
	}
	void Imprimir(function<void(Generico)> func)
	{
		for (int i = 0; i <= pos; i++)
		{
			func(arr[i]);
		}
	}
	void push_back(Generico g)
	{
		arr[++pos] = g;
	}
	void pop_back()
	{
		arr[pos] = NULL;
		--pos;
	}
	void pop_position(int position)
	{
		int post = position;
		for (int i = 0; i <= pos; i++)
		{
			arr[post] = arr[post + 1];  
			++post;
		}
		--pos;
	}
};