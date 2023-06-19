#include "Conteudo.h"


Conteudo::Conteudo(string nome, int duracao) {
    this->nome = nome;
    this->duracao = duracao;
}

Conteudo::~Conteudo() {}

string Conteudo::getNome() {
    return nome;
}

int Conteudo::getDuracao() {
    return duracao;
}