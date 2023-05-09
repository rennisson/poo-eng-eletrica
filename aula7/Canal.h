#ifndef CANAL_H
#define CANAL_H
#include <string>
#include "Conteudo.h"
#include "Video.h"

class Canal {
private:
  string nome;
  int maximo;
  Conteudo **conteudos;
  int quantidade;

public:
  // Construtor
  Canal(string nome, int maximoDeVideos);
  Canal(string nome, Conteudo** conteudos, int quantidade);
  ~Canal();

  string getNome();
  void setNome(string nome);
  int getQuantidade();
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  Conteudo** getConteudos();
  bool postar(Conteudo* c);
  void imprimir();
};

#endif // CANAL_H