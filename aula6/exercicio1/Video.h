#ifndef VIDEO_H
#define VIDEO_H
#include "Conteudo.h"
#include <string>

using namespace std;

class Video : public Conteudo {
public:
  // Construtor
  Video(string nome, int duracao);
  // Destrutor
  ~Video();
  
  void assistir (int tempo);    
  void imprimir ();
};

#endif // VIDEO_H