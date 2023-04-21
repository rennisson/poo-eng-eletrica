#ifndef VIDEO_H
#define VIDEO_H
#include <string>

using namespace std;

class Video {
private: 
  string nome;
  int duracao;
  int visualizacoes = 0;

public:
  // Construtor
  Video(string nome, int duracao);
  // Destrutor
  ~Video();
  
  string getNome();
  int getDuracao();
  int getVisualizacoes();
  void assistir (int tempo);    
  void imprimir ();
};

#endif // VIDEO_H