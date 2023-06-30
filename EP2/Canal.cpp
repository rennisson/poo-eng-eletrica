#include "Canal.h"
#include "Video.h"
#include "VideoCurto.h"
#include "NaoVerificado.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

bool compararVisualizacoes(Conteudo* i, Conteudo* j);


// Construtores
Canal::Canal(string nome) {
  this->nome = nome;
  this->conteudos = new vector<Conteudo*>();
}

Canal::Canal(string nome, vector<Conteudo*>* conteudos) {
  this->nome = nome;
  this->conteudos = conteudos;
}


// Destrutor
Canal::~Canal() {
  cout << "Destruidor de canal: " << nome << " - " << conteudos->size() << " conteudos" << endl;

  while (!conteudos->empty()) {
    Conteudo* ultimo = conteudos->back();
    conteudos->pop_back();
    delete ultimo;
  }

  delete conteudos;
  cout << "Canal destruido" << endl;
}

string Canal::getNome() {
  return this->nome;
}

/**
 * Retorna um ponteiro de ponteiro de Video
*/
vector<Conteudo*>* Canal::getConteudos() {
  return conteudos;
}

/**
 * Retorna a duração total do canal
 * @return retorna a duração total do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getDuracaoTotal() {
  int soma = 0;
  for (Conteudo *c : *conteudos) {
    try {
      soma += c->getDuracao();
    }
    catch (logic_error *e) {
      delete e;
    };    
  }
  
  return soma;
}

/**
 * Retorna o numero total de visualições do canal
 * @return retorna o numero total de visualizações do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getTotalDeVisualizacoes() {
  int soma = 0;
  vector<Conteudo*>::iterator c = conteudos->begin();
  while (c != conteudos->end()) {
    soma += (*c)->getVisualizacoes();
  }
  return soma;
}

void Canal::postar(Conteudo* c) {
  // Verifica se o Conteudo 'c' é VideoCurto
  VideoCurto* vc = dynamic_cast<VideoCurto*>(c);
  if (vc != NULL) throw new NaoVerificado;
  conteudos->insert(conteudos->end(), c);
}

Lista* Canal::criarListaComVideosMaisVistos(int quantidade, string nome) {
  return NULL;
//   if (quantidade > conteudos->size()) throw new invalid_argument("Nao foi possivel criar a lista");
  
//   vector<Conteudo*>* conteudosOrdenados = conteudos;
//   sort(conteudosOrdenados->begin(), conteudosOrdenados->end(), compararVisualizacoes);
//   reverse(conteudosOrdenados->begin(), conteudosOrdenados->end());
//   Lista* maisVistos = new Lista(nome);
  
//   for (int i = 0; i < quantidade; i++) {
//     Video* v = dynamic_cast<Video*>(conteudosOrdenados->back());
//     if (v != NULL) maisVistos->adicionar(v);
//   }
//   return maisVistos;
// }

// bool compararVisualizacoes(Conteudo* i, Conteudo* j) {
//   return i->getVisualizacoes() > i->getVisualizacoes();
}

void Canal::imprimir() {
    cout << endl << "Canal: " << nome << " - " << getDuracaoTotal() << " minutos totais" << endl;
    cout << "\t" << conteudos->size() << " elementos postados" << endl << endl;
    
    for (Conteudo *c : *conteudos) {
      c->imprimir();
    }
}