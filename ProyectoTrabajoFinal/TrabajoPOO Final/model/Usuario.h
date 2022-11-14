#pragma once
#include <string>

using namespace std;

class Usuario //Almacena los atributos de tipo usuario, sus contructores, sus setters y sus getters//
{
private:
    string username;
    string password;
    int tipousuario;
public:
    Usuario(string username, string password, int tipousuario = 0) : tipousuario(tipousuario)
    {
        this->username = username;
        this->password = password;
        this->tipousuario = tipousuario;
    }
    void setUsername(string username)
    {
        this->username = username;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
    string getUsername()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }
    int getTipousuario()
    {
        return tipousuario;
    }
};