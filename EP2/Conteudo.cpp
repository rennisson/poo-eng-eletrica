#include "Conteudo.h"
#include <stdexcept>


Conteudo::Conteudo(string nome, int duracao) {
    try {
        this->nome = nome;
        this->duracao = duracao;
        this->visualizacoes = 0;
   }
   catch (invalid_argument *e) {
        e->what();
        delete e;
   }
}

Conteudo::~Conteudo() {}

string Conteudo::getNome() {
    return nome;
}

int Conteudo::getDuracao() {
    return duracao;
}