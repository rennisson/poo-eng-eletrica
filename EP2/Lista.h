#ifndef LISTA_H
#define LISTA_H
#include "Video.h"
#include "Conteudo.h"
#include <list>

class Lista : public Conteudo {
    private:
        list<Video*>* videos;
    public:
        Lista(string nome);
        virtual ~Lista();
        void adicionar(Video* v);
        void adicionar(Lista* l);
        void imprimir();
        list<Video*>* getVideos();
        int getVisualizacoes();
        virtual list<Video*>* getVideos();
        virtual int getQuantidade();
        virtual int getVisualizacoes();
        virtual int getDuracao();
        virtual void imprimir();
};

#endif