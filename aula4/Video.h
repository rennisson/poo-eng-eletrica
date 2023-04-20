#ifndef VIDEO_H
#define VIDEO_H

#ifndef STRING
#define STRING
#include <string>
#endif // STRING

using namespace std;

class Video {

public:
  string nome;
  int duracao;
  int visualizacoes = 0;
  string getNome();
  void setNome(string nome);
  int getDuracao();
  void setDuracao(int duracao);
  int getVisualizacoes();
  void assistir (int tempo);    
  void imprimir ();
};

#endif // VIDEO_H