#include "Canal.h"
#include "Video.h"
#include <iostream>

void Canal::setNome(string nome) {
    this->nome = nome;
}

/**
 * Retorna a duração total do canal
 * @return retorna a duração total do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getDuracaoTotal() {
  float soma = 0;
  for (Video *video : this->videos) {
    soma += video->getDuracao();
  }
  return soma;
}

/**
 * Retorna o numero total de visualições do canal
 * @return retorna o numero total de visualizações do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getTotalDeVisualizacoes() {
  float soma = 0;
  for (Video *video : this->videos) {
    soma += video->getVisualizacoes();
  }
  return soma;
}

bool Canal::postar(Video* v) {
  if (v->getDuracao() <= 0) {
    return false;
  }


  for (int i = 0; i < MAXIMO_VIDEOS; i++) {
    if (this->videos[i] != NULL) {
      this->videos[i] = v;
      return true;
    }
  }

  // Se chegou aqui, é porque não há mais espaço no vetor 'videos'
  return false;
}

void Canal::imprimir() {
    cout << "Canal: " << this->nome << " - " << this->quantidade << " videos - "
        << this->getTotalDeVisualizacoes() << " visualizacoes totais" << endl;
    
    for (Video *video : this->videos) {
      video->imprimir();
    }
}