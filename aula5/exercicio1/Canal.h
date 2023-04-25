#ifndef CANAL_H
#define CANAL_H
#include <string>
#include "Video.h"

class Canal {
private:
  string nome;
  int maximoDeVideos;
  Video **videos;
  int quantidade;

public:
  // Construtor
  Canal(string nome, int maximoDeVideos);

  string getNome();
  void setNome(string nome);
  int getQuantidade();
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  Video** getVideos();
  bool postar(Video* v);
  void imprimir();
};

#endif // CANAL_H