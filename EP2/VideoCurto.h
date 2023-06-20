#ifndef VIDEOCURTO_H
#define VIDEOCURTO_H

#include "Video.h"

class VideoCurto: public Video {
public:
    VideoCurto(string nome, int duracao);
    VideoCurto(string nome, int duracao, int visualizacoes);
    virtual ~VideoCurto();
    void assistir();
    virtual void assistir(int tempo);
    virtual void imprimir();
};

#endif