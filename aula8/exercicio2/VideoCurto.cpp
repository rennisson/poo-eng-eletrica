#include "VideoCurto.h"
#include <iostream>
using namespace std;

VideoCurto::VideoCurto(string nome, int duracao): Video (nome, duracao) {}

VideoCurto::~VideoCurto() {
    cout << "Destrutor de video com " << visualizacoes << " visualizacoes: " << this->getNome() << endl; 
}

void VideoCurto::assistir() {
    visualizacoes++;
}

void VideoCurto::imprimir() {
    cout << "Video curto: " << this->getNome() << " - " << visualizacoes << " visualizacoes" << endl;
}