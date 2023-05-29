#include "Lista.h"
#include <iostream>
#include <string>

Lista::Lista(string nome, int tamanho) : Conteudo(nome, 0) {
    this->tamanho = tamanho;
    this->quantidade = 0;
    this->videos = new Video*[tamanho];
};

Lista::~Lista() {
    cout << "Lista com " << quantidade << " videos destruida" << endl;
    delete videos;
}

/**
 * Retorna um vetor de videos
*/
Video** Lista::getVideos() {
    return videos;
}

/*
* Retorna a quantidade de conteudos da lista
*/
int Lista::getQuantidade() {
    return quantidade;
}

/*
* Retorna a quantidade de visualizacoes dos conteudos da lista
*/
int Lista::getVisualizacoes() {
    int totalVisualizacoes = 0;
    for (int i = 0; i < quantidade; i++) {
        totalVisualizacoes += videos[i]->getVisualizacoes();
    }

    return totalVisualizacoes;
}

/**
* Adiciona um video novo à lista.
* @return True se foi possivel adicionar o video na lista. False, caso o vetor 'videos' esteja cheio,
    o video já está na lista ou o video tem duracao zero
*/
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

/**
* Adiciona uma lista de videos à lista.
* @return True se foi possivel adicionar todos os videos da lista. False, caso o vetor 'videos' esteja cheio ou
*   algum dos videos já está na lista
*/
bool Lista::adicionar (Lista* l) {
    // Conta quantos videos repetidos há na lista 'l'
    int videosRepetidos = 0;
    for (int i = 0; i < quantidade; i++) {
        for (int j = 0; j < l->getQuantidade(); j++) {
            if (videos[i] == l->videos[j]) videosRepetidos++;
        }
    }

    // Verifica se há espaco suficiente para TODOS os videos nao repetidos
    int videosNaoRepetidos = l->quantidade - videosRepetidos;
    if (quantidade + videosNaoRepetidos > tamanho) return false;

    // Adiciona todos os videos nao repetidos na lista
    for (int i = 0; i < l->quantidade; i++) {
        adicionar(l->videos[i]);
    }

    return true;
}

/**
 * Imprime as informações do objeto
*/
void Lista::imprimir() {
    cout << "Lista com " << quantidade << " videos: " << getNome() << " - " << duracao << " minutos" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << "\t" << i+1 << ". " << videos[i]->getNome() << endl;
    }
}