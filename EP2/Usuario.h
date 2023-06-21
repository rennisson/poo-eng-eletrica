#ifndef USUARIO_H
#define USUARIO_H
#include "Canal.h"
#include <string>

class Usuario {
protected:
    string nome;
    Canal* canal;
public:
    Usuario(string nome, string nomeDoCanal);
    Usuario(string nome, Canal* canal);
    virtual ~Usuario();
    Canal* getCanal();
    string getNome();
};

#endif