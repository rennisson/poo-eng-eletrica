#include "VideoCurto.h"
#include <iostream>
#include <stdexcept>
using namespace std;

VideoCurto::VideoCurto(string nome, int duracao): Video (nome, duracao) {
    if (duracao <= 5) throw new invalid_argument("Duracao muito alta");
}

VideoCurto::VideoCurto(string nome, int duracao, int visualizacoes): Video (nome, duracao, visualizacoes) {}

VideoCurto::~VideoCurto() {}

void VideoCurto::assistir() {
    visualizacoes++;
}

void VideoCurto::assistir(int tempo) {
    if (tempo >= (double) duracao * VideoCurto::porcentagem) visualizacoes++;
}

void VideoCurto::imprimir() {
    cout << "Video curto: " << getNome() << " - " << visualizacoes << " visualizacoes" << endl;
}