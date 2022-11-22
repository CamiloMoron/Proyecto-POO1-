#pragma once
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Usuario //Almacena los atributos de tipo usuario, sus contructores, sus setters y sus getters//
{
private:
    char username[20];
    char password[20];
    char tipousuario[2];
public:
    Usuario() 
    {
        strcpy_s(this->username, " \0");
        strcpy_s(this->password, " \0");
        strcpy_s(this->tipousuario, " \0");
    }
    void agregar(char usuario[20], char password[20], char t[2])
    {
        strcpy_s(this->username, usuario); //Me fue revelado en un sueño//
        strcpy_s(this->password, password); //Aprendí C en un sueño lúcido//
        strcpy_s(this->tipousuario, t);
    }
    int imprimir(string usuarioporencontrar, string passwordporencontrar)
    {
        string usuario, password;
        string admin = "Camilo123";
        string contraad = "123456";
        usuario = this->username;
        password = this->password;
        if (admin == usuarioporencontrar && contraad == passwordporencontrar)
        {
            return 1;
        }
        if (usuario == usuarioporencontrar && password == passwordporencontrar)
        {
            return 0;
        } 
        else
        {
            return 2;
        }
    }
};