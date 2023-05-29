#include "Plataforma.h"
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

/**
 * Adiciona um usuario na plataforma.
 * @return True caso tenha adicionado o usuario no vetor de usuarios. False, caso o vetor de usuarios esteja cheio ou o usuario já exista.
*/
bool Plataforma::adicionar(Usuario* usuario) {
    if (quantidadeDeUsuarios >= maximoDeUsuarios) return false;

    for (int i = 0; i <= quantidadeDeUsuarios; i++) {
        if (usuario == usuarios[i]) return false;
    }

    usuarios[quantidadeDeUsuarios] = usuario;
    quantidadeDeUsuarios++;
    return true;
}

/**
 * Retorna a quantidade de usuarios da plataforma
*/
int Plataforma::getQuantidadeDeUsuarios() {
    return quantidadeDeUsuarios;
}

/**
 * Retorna o vetor de usuarios da plataforma
*/
Usuario** Plataforma::getUsuarios() {
    return usuarios;
}
