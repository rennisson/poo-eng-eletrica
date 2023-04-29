#ifndef LISTA_H
#define LISTA_H
#include "Video.h"
#include "Conteudo.h"

class Lista : public Conteudo {
    private:
        int tamanho;
        int quantidade;
        Video** videos;
    public:
        Lista(string nome, int tamanho);
        ~Lista();

        bool adicionar(Video* v);
        void imprimir();

        Video** getVideos();
        int getQuantidade();
};

#endif