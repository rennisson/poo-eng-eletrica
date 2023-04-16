#ifndef CANAL_H
#define CANAL_H

#ifndef STRING
#define STRING
#include <string>;
#endif // STRING

#include "Video.h"

class Canal {
private:
  string nome;
  Video* v1 = NULL;
  Video* v2 = NULL;
  int quantidade = 0;

public:
  void setNome(string nome);
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  bool postar(Video* v);
};

#endif // CANAL_H