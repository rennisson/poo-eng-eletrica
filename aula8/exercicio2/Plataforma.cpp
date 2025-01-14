#include "PLataforma.h"
#include "Usuario.h"
#include <iostream>

Plataforma::Plataforma() {
    quantidadeDeUsuarios = 0;
    usuarios = new Usuario*[maximoDeUsuarios];
}

Plataforma::~Plataforma() {
    cout << "Destrutor de Plataforma" << endl;
    for (int i = 0; i < maximoDeUsuarios; i++) delete usuarios[i];
    delete usuarios;
    cout << "Plataforma deletada" << endl;
}

bool Plataforma::adicionar (Usuario* usuario) {
    if (quantidadeDeUsuarios >= maximoDeUsuarios) return false;

    for (int i = 0; i <= quantidadeDeUsuarios; i++) {
        if (usuario == usuarios[i]) return false;
    }

    usuarios[quantidadeDeUsuarios] = usuario;
    quantidadeDeUsuarios++;
    return true;
}

int Plataforma::getQuantidadeDeUsuarios() {
    return quantidadeDeUsuarios;
}

Usuario** Plataforma::getUsuarios() {
    return usuarios;
}
