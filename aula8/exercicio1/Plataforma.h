#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Usuario.h"

class Plataforma {
private:
    Usuario** usuarios;
    int quantidadeDeUsuarios;
public:
    Plataforma();
    virtual ~Plataforma();
    virtual bool adicionar (Usuario* usuario);
    virtual int getQuantidadeDeUsuarios();
    virtual Usuario** getUsuarios();
    const int maximoDeUsuarios = 20;
};

#endif
