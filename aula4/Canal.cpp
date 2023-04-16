#include "Canal.h"
#include "Video.h"

void Canal::setNome(string nome) {
    this->nome = nome;
}

/**
 * Retorna a duração total do canal
 * @return retorna a duração total do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getDuracaoTotal() {
  if (this->quantidade == 1) return this->v1->getDuracao();
  if (this->quantidade == 2) return this->v1->getDuracao() + this->v2->getDuracao();
  return 0;
}

/**
 * Retorna o numero total de visualições do canal
 * @return retorna o numero total de visualizações do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getTotalDeVisualizacoes() {
  if (this->quantidade == 1) return this->v1->getVisualizacoes();
  if (this->quantidade == 2) return this->v1->getVisualizacoes() + this->v2->getVisualizacoes();
  return 0;
}

bool Canal::postar(Video* v) {
  if (this->quantidade == 0) {
    this->v1 = v;
    this->quantidade++;
    return true;
  }

  if (this->quantidade == 1 && v != this->v1) {
    this->v2 = v;
    this->quantidade++;
    return true;
  } 

  return false;
}