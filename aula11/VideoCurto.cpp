#include "VideoCurto.h"
#include <iostream>
using namespace std;

VideoCurto::VideoCurto(string nome, int duracao): Video (nome, duracao) {}

VideoCurto::VideoCurto(string nome, int duracao, int visualizacoes): Video (nome, duracao, visualizacoes) {}

VideoCurto::~VideoCurto() {
}

void VideoCurto::assistir() {
    visualizacoes++;
}

void VideoCurto::imprimir() {
    cout << "Video curto: " << this->getNome() << " - " << visualizacoes << " visualizacoes" << endl;
}