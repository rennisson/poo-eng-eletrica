#ifndef CANAL_H
#define CANAL_H
#include <string>
#include <vector>
#include "Conteudo.h"
#include "Video.h"

class Canal {
private:

protected:
  string nome;
  int maximo;
  vector<Conteudo*>* conteudos;

public:
  // Construtor
  Canal(string nome);
  Canal(string nome, vector<Conteudo*>* conteudos);
  virtual ~Canal();

  virtual string getNome();
  virtual int getDuracaoTotal();
  virtual int getTotalDeVisualizacoes();
  virtual vector<Conteudo*>* getConteudos();
  virtual void postar(Conteudo* c);
  virtual void imprimir();
};

#endif // CANAL_H