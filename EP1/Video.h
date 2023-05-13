#ifndef VIDEO_H
#define VIDEO_H
#include "Conteudo.h"
#include <string>

using namespace std;

class Video : public Conteudo {
public:
  Video(string nome, int duracao);
  virtual ~Video();
  virtual void assistir(int tempo);    
  virtual void imprimir();
};

#endif // VIDEO_H