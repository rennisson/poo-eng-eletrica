#include "Usuario.h"
#include "Canal.h"
#include <string>
#include <iostream>

Usuario::Usuario(string nome, string nomeDoCanal, int maximo) {
    this->nome = nome;
    this->canal = new Canal(nomeDoCanal, maximo);
};

Usuario::Usuario(string nome, Canal* canal) {
    this->nome = nome;
    this->canal = canal;
};

Usuario::~Usuario() {
    cout << "Destrutor de Usuario: " << nome << endl;
    delete canal;
};

/**
 * Retorna o canal do usuario
*/
Canal* Usuario::getCanal() {
    return canal;
}

/**
 * Retorna o nome do usuario
*/
string Usuario::getNome() {
    return nome;
}