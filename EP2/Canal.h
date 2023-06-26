#ifndef CANAL_H
#define CANAL_H
#include <string>
#include <vector>
#include "Conteudo.h"
#include "Lista.h"
#include "Video.h"

class Canal {
private:
  vector<Video*>* getVideos();

protected:
  string nome;
  vector<Conteudo*>* conteudos;
  int quantidadeDeVideos;

public:
  // Construtor
  Canal(string nome);
  Canal(string nome, vector<Conteudo*>* conteudos);
  virtual ~Canal();

  virtual string getNome();
  virtual int getDuracaoTotal();
  virtual int getTotalDeVisualizacoes();
  virtual vector<Conteudo*>* getConteudos();
  Lista* criarListaComVideosMaisVistos(int quantidade, string nome);
  virtual void postar(Conteudo* c);
  virtual void imprimir();
};

#endif // CANAL_H