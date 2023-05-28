#include "VideoCurto.h"
#include <iostream>
using namespace std;

VideoCurto::VideoCurto(string nome, int duracao): Video (nome, duracao) {}

VideoCurto::~VideoCurto() {
    cout << "Destrutor de video com " << visualizacoes << " visualizacoes: " << getNome() << endl; 
}

void VideoCurto::assistir() {
    visualizacoes++;
}

void VideoCurto::assistir(int tempo) {
    visualizacoes++;
}

void VideoCurto::imprimir() {
    cout << "Video curto: " << getNome() << " - " << visualizacoes << " visualizacoes" << endl;
}