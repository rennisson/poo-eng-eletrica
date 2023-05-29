#ifndef VIDEO_H
#define VIDEO_H
#include "Conteudo.h"
#include <string>

using namespace std;

/**
 *  É um tipo de Conteudo que pode ser assistido e adicionado em Canal. É uma subclasse de Conteudo.
*/
class Video : public Conteudo {
  public:
    Video(string nome, int duracao);
    virtual ~Video();
    virtual void assistir(int tempo);    
    virtual void imprimir();
};

#endif // VIDEO_H