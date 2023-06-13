#include "Canal.h"
#include "Video.h"
#include "VideoCurto.h"
#include "NaoVerificado.h"
#include <iostream>
#include <string>
#include <stdexcept>


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

  for (int i = 0; i < quantidade; i++) {
    delete conteudos[i];
  }

  delete conteudos;

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
  try {
    for (int i = 0; i < quantidade; i++) {
      soma += conteudos[i]->getDuracao();
    }
  }
  catch (logic_error *e) {
    delete e;
  };
  
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

void Canal::postar(Conteudo* c) {
  // Verifica se o Conteudo 'c' é VideoCurto
  VideoCurto* vc = dynamic_cast<VideoCurto*>(c);
  if (vc != NULL) throw new NaoVerificado;

  if (quantidade >= maximo) throw new overflow_error("Maximo de videos");

  // Verifica se o video é repetido
  for (int i = 0; i < quantidade; i++) {
    if (c == conteudos[i]) throw new invalid_argument("Conteudo repetido");
  }

  conteudos[this->quantidade] = c;
  quantidade++;
}

void Canal::imprimir() {
    cout << "Canal: " << nome << " - " << getDuracaoTotal() << " minutos totais" << endl;
    cout << "\t" << quantidade << " elementos postados" << endl;

    for (int i = 0; i < quantidade; i++) {
      conteudos[i]->imprimir();
    }
}