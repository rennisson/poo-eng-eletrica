#ifndef VIDEO_H
#define VIDEO_H
#include <string>

using namespace std;

class Video {
private: 
  string nome;
  int duracao;
  int visualizacoes;

public:
  // Construtor
  Video(string nome, int duracao);
  
  string getNome();
  void setNome(string nome);
  int getDuracao();
  void setDuracao(int duracao);
  int getVisualizacoes();
  void assistir (int tempo);    
  void imprimir ();
};

#endif // VIDEO_H