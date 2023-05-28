#ifndef USUARIOVERIFICADO_H
#define USUARIOVERIFICADO_H
#include "Usuario.h"
#include <string>

class UsuarioVerificado : public Usuario {
public:
    UsuarioVerificado(string nome, string nomeDoCanal, int maximo);
    virtual ~UsuarioVerificado();
};

#endif