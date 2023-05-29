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
  cout << "Destruidor de canal: " << nome << " - " << quantidade << " conteudos" << endl;

  for (int i = 0; i < quantidade; i++) delete conteudos[i];

  delete conteudos;
  cout << "Canal destruido" << endl << endl;
}

/**
 * Retorna o nome do canal
*/
string Canal::getNome() {
  return nome;
}

/**
 * Retorna a quantidade de conteudos do canal
*/
int Canal::getQuantidade() {
  return quantidade;
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
  for (int i = 0; i < quantidade; i++) {
    soma += conteudos[i]->getDuracao();
  }
  return soma;
}

/**
 * Retorna o numero total de visualições do canal
 * @return retorna o numero total de visualizações do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getTotalDeVisualizacoes() {
  int soma = 0;
  for (int i = 0; i < quantidade; i++) {
    soma += conteudos[i]->getVisualizacoes();
  }
  return soma;
}

/**
 * Posta um conteudo em Canal.
 * @return True caso seja possível adicionar o Conteudo no vetor de conteudos.
 * False, caso o Conteudo seja um vídeo curto, caso sua duração seja zero, caso o vetor de conteúdos já esteja cheio e
 * caso este já tenha sido postado anteriormente. 
*/
bool Canal::postar(Conteudo* c) {
  // Verifica se o Conteudo 'c' é VideoCurto
  VideoCurto* vc = dynamic_cast<VideoCurto*>(c);
  if (vc != NULL) return false;

  if (c->getDuracao() <= 0) return false;
  if (quantidade >= maximo) return false;

  // Verifica se o video é repetido
  for (int i = 0; i < quantidade; i++) {
    if (c == conteudos[i]) return false;
  }

  conteudos[quantidade] = c;
  quantidade++;

  return true;
}

/**
 * Imprime as informações do objeto
*/
void Canal::imprimir() {
    cout << "Canal: " << nome << " - " << getDuracaoTotal() << " minutos totais" << endl;
    cout << "\t" << quantidade << " elementos postados" << endl << endl;
}