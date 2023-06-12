#include "Lista.h"
#include <iostream>
#include <string>
#include <stdexcept>

Lista::Lista(string nome, int tamanho) : Conteudo(nome, 0) {
    this->tamanho = tamanho;
    this->quantidade = 0;
    this->videos = new Video*[tamanho];
};

Lista::~Lista() {
    cout << "Lista com " << quantidade << " videos destruida" << endl;
    delete videos;
}

Video** Lista::getVideos() {
    return videos;
}

int Lista::getQuantidade() {
    return quantidade;
}

int Lista::getVisualizacoes() {
    int totalVisualizacoes = 0;
    for (int i = 0; i < quantidade; i++) {
        totalVisualizacoes += videos[i]->getVisualizacoes();
    }

    return totalVisualizacoes;
}

int Lista::getDuracao() {
    if (quantidade == 0) throw new logic_error("Lista vazia");
    return duracao;
}

bool Lista::adicionar(Video* v) {
    if (v->getDuracao() == 0) return false;
    if (quantidade >= tamanho) return false; // verifica se o vetor ja está cheio

    // Verifica se o video já está na lista
    for (int i = 0; i < quantidade; i++) {
        if (v == videos[i]) return false;
    }

    // Adiciona o video na lista
    videos[quantidade] = v;
    quantidade++;

    // Bloco que atualiza a duracao total da lista
    int soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += videos[i]->getDuracao();
    }
    duracao = soma;

    return true;
}

bool Lista::adicionar (Lista* l) {
    // Conta quantos videos repetidos há na lista 'l'
    int videosRepetidos = 0;
    for (int i = 0; i < this->quantidade; i++) {
        for (int j = 0; j < l->getQuantidade(); j++) {
            if (this->videos[i] == l->videos[j]) videosRepetidos++;
        }
    }

    // Verifica se há espaco suficiente para TODOS os videos nao repetidos
    int videosNaoRepetidos = l->quantidade - videosRepetidos;
    if (this->quantidade + videosNaoRepetidos > this->tamanho) return false;

    // Adiciona todos os videos nao repetidos na lista
    for (int i = 0; i < l->quantidade; i++) {
        this->adicionar(l->videos[i]);
    }

    return true;
}

void Lista::imprimir() {
    cout << "Lista com " << quantidade << " videos: " << getNome() << " - " << duracao << " minutos" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << "\t" << i+1 << ". " << videos[i]->getNome() << endl;
    }
}