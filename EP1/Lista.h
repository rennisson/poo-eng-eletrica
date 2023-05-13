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
        virtual ~Lista();
        virtual bool adicionar(Video* v);
        virtual bool adicionar (Lista* l); 
        virtual void imprimir();
        virtual Video** getVideos();
        virtual int getQuantidade();
        virtual int getVisualizacoes();
};

#endif