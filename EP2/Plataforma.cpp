#include "Plataforma.h"
#include "Usuario.h"
#include <iostream>
#include <algorithm>

Plataforma::Plataforma() {
    usuarios = new vector<Usuario*>();
}

Plataforma::~Plataforma() {
    cout << "Destrutor de Plataforma" << endl;
    for (Usuario* c : *usuarios) delete c;
    delete usuarios;
    cout << "Plataforma deletada" << endl;
}

void Plataforma::adicionar (Usuario* usuario) {
    // Verifica se o video já está na lista
    vector<Usuario*>::iterator repetido = find(usuarios->begin(), usuarios->end(), usuario);
    if (repetido != usuarios->end()) throw new invalid_argument("Usuario ja adicionado");

    // Se não é repetido, o usuario é adiciona em 'usuarios'
    usuarios->insert(usuarios->end(), usuario);
}

int Plataforma::getQuantidadeDeUsuarios() {
    return usuarios->size();
}

vector<Usuario*>* Plataforma::getUsuarios() {
    return usuarios;
}
