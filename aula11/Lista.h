#ifndef LISTA_H
#define LISTA_H
#include "Video.h"
#include "Conteudo.h"
#include <list>

class Lista : public Conteudo {
    private:
        int quantidade;
        list<Video*>* videos;
    public:
        Lista(string nome);
        virtual ~Lista();
        virtual bool adicionar(Video* v);
        virtual void adicionar (Lista* l); 
        virtual list<Video*>* getVideos();
        virtual int getQuantidade();
        virtual int getVisualizacoes();
        virtual int getDuracao();
        virtual void imprimir();
};

#endif