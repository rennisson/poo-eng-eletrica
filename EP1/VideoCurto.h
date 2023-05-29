#ifndef VIDEOCURTO_H
#define VIDEOCURTO_H

#include "Video.h"

/**
 * É um Video que possui uma duração entre 1 e 5 minutos. É subclasse de Video
*/
class VideoCurto: public Video {
    public:
        VideoCurto(string nome, int duracao);
        virtual ~VideoCurto();
        virtual void assistir();
        virtual void assistir(int tempo);
        virtual void imprimir();
};

#endif