#ifndef CANAL_H
#define CANAL_H
#define MAXIMO_VIDEOS 15
#include <string>
#include "Video.h"

class Canal {
private:
  string nome;
  Video *videos[MAXIMO_VIDEOS];
  int quantidade = 0;

public:
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