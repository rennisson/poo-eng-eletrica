#ifndef USUARIOVERIFICADO_H
#define USUARIOVERIFICADO_H
#include "Usuario.h"
#include <string>

/**
 * É um tipo de Usuario que possui um CanalVerificado. Subclasse de Usuario.
*/
class UsuarioVerificado : public Usuario {
    public:
        UsuarioVerificado(string nome, string nomeDoCanal, int maximo);
        virtual ~UsuarioVerificado();
};

#endif