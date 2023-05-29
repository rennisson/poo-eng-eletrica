#include "Conteudo.h"


Conteudo::Conteudo(string nome, int duracao) {
    this->nome = nome;
    this->duracao = duracao;
    this->visualizacoes = 0;
}

Conteudo::~Conteudo() {}

/**
 * Retorna o nome do conteudo
*/
string Conteudo::getNome() {
    return nome;
}

/**
 * Retorna a duracao do conteudo
*/
int Conteudo::getDuracao() {
    return duracao;
}

/**
 * Retorna o numero de visualizacoes do conteudo
*/
int Conteudo::getVisualizacoes() {
    return visualizacoes;
}