#include "Canal.h"
#include "Video.h"
#include <iostream>

Canal::Canal(string nome, int maximoDeVideos) {
  this->nome = nome;
  this->maximoDeVideos = maximoDeVideos;
  this->quantidade = 0;
  this->videos = new Video*[maximoDeVideos];
}

string Canal::getNome() {
  return this->nome;
}

void Canal::setNome(string nome) {
  this->nome = nome;
}

int Canal::getQuantidade() {
  return this->quantidade;
}

/**
 * Retorna um ponteiro de ponteiro de Video
*/
Video** Canal::getVideos() {
  return videos;
}

/**
 * Retorna a duração total do canal
 * @return retorna a duração total do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getDuracaoTotal() {
  int soma = 0;
  for (int i = 0; i < this->quantidade; i++) {
    soma += this->videos[i]->getDuracao();
  }
  return soma;
}

/**
 * Retorna o numero total de visualições do canal
 * @return retorna o numero total de visualizações do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getTotalDeVisualizacoes() {
  int soma = 0;
  for (int i = 0; i < this->quantidade; i++) {
    soma += this->videos[i]->getVisualizacoes();
  }
  return soma;
}

bool Canal::postar(Video* v) {
  if (v->getDuracao() <= 0) return false;
  if (this->quantidade >= this->maximoDeVideos) return false;

  // Verifica se o video é repetido
  for (int i = 0; i < this->quantidade; i++) {
      if (v == this->videos[i]) return false;
  }

  this->videos[this->quantidade] = v;

  this->quantidade++;
  return true;
}

void Canal::imprimir() {
    cout << "Canal: " << this->nome << " - " << this->quantidade << " videos - "
        << this->getTotalDeVisualizacoes() << " visualizacoes totais" << endl;
    
    cout << endl;
    
    for (int i = 0; i < this->quantidade; i++) {
      this->videos[i]->imprimir();
      cout << endl;
    }
}