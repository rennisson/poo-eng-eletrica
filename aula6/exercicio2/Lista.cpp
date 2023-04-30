#include "Lista.h"
#include <iostream>
#include <string>

Lista::Lista(string nome, int tamanho) : Conteudo(nome, 0) {
    this->tamanho = tamanho;
    this->quantidade = 0;
    this->videos = new Video*[tamanho];
};

Lista::~Lista() {
    for (int i = 0; i < quantidade; i++) {
        delete videos[i];
    }
    cout << "Lista com " << quantidade << " videos destruida" << endl;
}

Video** Lista::getVideos() {
    return videos;
}

int Lista::getQuantidade() {
    return quantidade;
}

bool Lista::adicionar(Video* v) {
    if (v->getDuracao() == 0) return false;
    if (quantidade >= tamanho) return false;

    for (int i = 0; i < quantidade; i++) {
        if (v == videos[i]) return false;
    }

    videos[quantidade] = v;
    quantidade++;

    int soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += videos[i]->getDuracao();
    }
    duracao = soma;

    return true;
}

void Lista::imprimir() {
    cout << "Lista com " << quantidade << " videos: " << getNome() << " - " << duracao << " minutos" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << "\t" << i+1 << ". " << videos[i]->getNome() << endl;
    }
}