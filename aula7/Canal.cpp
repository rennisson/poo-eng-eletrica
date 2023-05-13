#include "Canal.h"
#include "Video.h"
#include "VideoCurto.h"
#include <iostream>
#include <string>

// Construtores
Canal::Canal(string nome, int maximo) {
  this->nome = nome;
  this->maximo = maximo;
  this->quantidade = 0;
  this->conteudos = new Conteudo*[maximo];
}

Canal::Canal(string nome, Conteudo** conteudos, int quantidade) {
  this->nome = nome;
  this->quantidade = quantidade;
  this->maximo = quantidade;
  this->conteudos = conteudos;
}


// Destrutor
Canal::~Canal() {
  cout << "Destruidor de canal: " << this->nome << " - " << this->quantidade << " conteudos" << endl;

  for (int i = 0; i < quantidade; i++) {
    delete this->conteudos[i];
  }

  cout << "Canal destruido" << endl;
}

string Canal::getNome() {
  return this->nome;
}

int Canal::getQuantidade() {
  return this->quantidade;
}

/**
 * Retorna um ponteiro de ponteiro de Video
*/
Conteudo** Canal::getConteudos() {
  return conteudos;
}

/**
 * Retorna a duração total do canal
 * @return retorna a duração total do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getDuracaoTotal() {
  int soma = 0;
  for (int i = 0; i < this->quantidade; i++) {
    soma += this->conteudos[i]->getDuracao();
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
    soma += this->conteudos[i]->getVisualizacoes();
  }
  return soma;
}

bool Canal::postar(Conteudo* c) {
  VideoCurto* v = dynamic_cast<VideoCurto*>(c);
  if (v != NULL) {
    //cout << "E' video curto" << endl;
    return false;
  }

  if (c->getDuracao() <= 0) return false;
  if (this->quantidade >= this->maximo) return false;

  // Verifica se o video é repetido
  for (int i = 0; i < this->quantidade; i++) {
      if (c == this->conteudos[i]) return false;
  }

  this->conteudos[this->quantidade] = v;

  this->quantidade++;
  return true;
}

void Canal::imprimir() {
    cout << "Canal: " << this->nome << " - " << getDuracaoTotal() << " minutos totais" << endl;
    cout << "\t" << quantidade << " elementos postados" << endl << endl;
}