#include "Usuario.h"
#include <string>

Usuario::Usuario(string nome, string nomeDoCanal, int maximo) {
    this->nome = nome;
    this->nomeDoCanal = nomeDoCanal;
    this->maximo = maximo;
};

Usuario::Usuario(string nome, Canal* canal) {
    this->nome = nome;
    this->canal = canal;
};

Usuario::~Usuario() {};

Canal* Usuario::getCanal() {
    return canal;
}

string Usuario::getNome() {
    return nome;
}