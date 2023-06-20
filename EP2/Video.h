#ifndef VIDEO_H
#define VIDEO_H
#include "Conteudo.h"
#include <string>

using namespace std;

class Video : public Conteudo {
private:
  static double porcentagem;
public:
  Video(string nome, int duracao);
  Video(string nome, int duracao, int visualizacoes);
  virtual ~Video();
  virtual void assistir(int tempo);
  virtual int getVisualizacoes();    
  virtual void imprimir();
  static void setPorcentagem(double valor);
  static double getPorcentagem();
};

#endif // VIDEO_H