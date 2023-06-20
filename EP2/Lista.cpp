#include "Lista.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <algorithm>

Lista::Lista(string nome) : Conteudo(nome, 0) {
    this->quantidade = 0;
    this->videos = new list<Video*>();
};

Lista::~Lista() {
    cout << "Lista com " << videos->size() << " videos destruida" << endl;
    delete videos;
}

list<Video*>* Lista::getVideos() {
    return videos;
}

int Lista::getQuantidade() {
    return quantidade;
}

int Lista::getVisualizacoes() {
    int totalVisualizacoes = 0;
    for (Video* v : *videos) {
        totalVisualizacoes += v->getVisualizacoes();
    }

    return totalVisualizacoes;
}

int Lista::getDuracao() {
    if (quantidade == 0) throw new logic_error("Lista vazia");
    return duracao;
}

bool Lista::adicionar(Video* v) {
    if (v->getDuracao() == 0) return false;

    // Verifica se o video já está na lista
    list<Video*>::iterator repetido = find(videos->begin(), videos->end(), v);
    if (repetido != videos->end()) return false;

    videos->insert(videos->end(), v);
    quantidade++;

    // Bloco que atualiza a duracao total da lista
    int soma = 0;
    for (Video* v : *videos) {
        soma += v->getDuracao();
    }
    duracao = soma;

    return true;
}

void Lista::adicionar (Lista* l) {
    list<Video*>* lista = l->getVideos();

    // Adiciona todos os videos nao repetidos na lista
    for (Video *v : *lista) {
        adicionar(v);
    }
}

void Lista::imprimir() {
    cout << "Lista com " << quantidade << " videos: " << getNome() << " - " << duracao << " minutos" << endl;
    list<Video*>::iterator vid = videos->begin();

    int i = 0;
    for (Video* vid : *videos) {
        i++;
        cout << "\t" << i << ". " << (vid)->getNome() << endl << endl;
    }
}