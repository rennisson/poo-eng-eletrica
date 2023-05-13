#ifndef USUARIO_H
#define USUARIO_H
#include "Canal.h"
#include <string>

class Usuario {
protected:
    string nome;
    string nomeDoCanal;
    int maximo;
    Canal* canal;
public:
    Usuario(string nome, string nomeDoCanal, int maximo);
    Usuario(string nome, Canal* canal);
    virtual ~Usuario();
    virtual Canal* getCanal();
    virtual string getNome();
};

#endif