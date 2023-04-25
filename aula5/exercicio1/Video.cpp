#include "Video.h"
#include <iostream>

using namespace std;

Video::Video(string nome, int duracao) {
    this->nome = nome;
    this->duracao = duracao;
    this->visualizacoes = 0;
}

string Video::getNome() {
    return this->nome;
}

void Video::setNome(string nome) {
    this->nome = nome;
}

int Video::getDuracao() {
    return this->duracao;
}

void Video::setDuracao(int duracao) {
    this->duracao = duracao;
}

int Video::getVisualizacoes() {
    return this->visualizacoes;
}

/**
 * Incrementa 1 no atributo 'visualizacoes' se 'tempo' é maior que 30% de 'duracao'
 * @param tempo tempo de video assistido
*/
void Video::assistir(int tempo) {
  if (tempo >= (double) this->duracao * 0.3) this->visualizacoes++;
}

/**
 * Imprime as informações do objeto
*/
void Video::imprimir() {
  cout << "Video: " << this->nome << " - " << this->duracao << " min - " << this->visualizacoes << " visualizacoes" << endl;
}