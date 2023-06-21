#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Usuario.h"
#include <vector>

class Plataforma {
private:
    vector<Usuario*>* usuarios;
public:
    Plataforma();
    ~Plataforma();
    void adicionar (Usuario* usuario);
    int getQuantidadeDeUsuarios();
    vector<Usuario*>* getUsuarios();
    const int maximoDeUsuarios = 20;
};

#endif
