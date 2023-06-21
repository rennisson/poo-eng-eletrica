#include "Lista.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <algorithm>

Lista::Lista(string nome) : Conteudo(nome, 0) {
    this->videos = new list<Video*>();
};

Lista::~Lista() {
    cout << "Lista com " << videos->size() << " videos destruida" << endl;
    delete videos;
}

list<Video*>* Lista::getVideos() {
    return videos;
}

int Lista::getVisualizacoes() {
    int totalVisualizacoes = 0;
    for (Video* v : *videos) {
        totalVisualizacoes += v->getVisualizacoes();
    }

    return totalVisualizacoes;
}

int Lista::getDuracao() {
    if (videos->empty()) throw new logic_error("Lista vazia");
    return duracao;
}

void Lista::adicionar(Video* v) {
    if (v->getDuracao() == 0) return;

    // Verifica se o video já está na lista
    list<Video*>::iterator repetido = find(videos->begin(), videos->end(), v);
    if (repetido != videos->end()) throw new invalid_argument("Video ja adicionado");

    // Se não é repetido, adiciona o video na lista
    videos->insert(videos->end(), v);

    // Bloco que atualiza a duracao total da lista
    int soma = 0;
    for (Video* v : *videos) {
        soma += v->getDuracao();
    }
    duracao = soma;
}

void Lista::adicionar (Lista* l) {
    list<Video*>* lista = l->getVideos();

    // Adiciona todos os videos nao repetidos na lista
    for (Video *v : *lista) {
        adicionar(v);
    }
}

void Lista::imprimir() {
    cout << "Lista com " << videos->size() << " videos: " << getNome() << " - " << duracao << " minutos" << endl;
    list<Video*>::iterator vid = videos->begin();
}