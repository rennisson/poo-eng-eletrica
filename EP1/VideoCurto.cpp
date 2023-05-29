#include "VideoCurto.h"
#include <iostream>
using namespace std;

VideoCurto::VideoCurto(string nome, int duracao): Video (nome, duracao) {}

VideoCurto::~VideoCurto() {}

/**
 * Incrementa 1 em 'visualizacoes' não importa o tempo assistido
*/
void VideoCurto::assistir() {
    visualizacoes++;
}

/**
 * Incrementa 1 em 'visualizacoes' não importa o tempo assistido. Redefinição da classe Video.
*/
void VideoCurto::assistir(int tempo) {
    visualizacoes++;
}

/**
 * Imprime as informacoes do objeto
*/
void VideoCurto::imprimir() {
    cout << "Video curto: " << getNome() << " - " << visualizacoes << " visualizacoes" << endl;
}