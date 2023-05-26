#include "Video.h"
#include <iostream>
#include <string>

using namespace std;

// Construtor
Video::Video(string nome, int duracao) : Conteudo(nome, duracao) {
    this->visualizacoes = 0;
}

// Destrutor
Video::~Video() {
  cout << "Destrutor de video com " << visualizacoes << " visualizacoes: " << getNome() << endl; 
}

int Video::getVisualizacoes() {
    return visualizacoes;
}

/**
 * Incrementa 1 no atributo 'visualizacoes' se 'tempo' é maior que 30% de 'duracao'
 * @param tempo tempo de video assistido
*/
void Video::assistir(int tempo) {
  if (tempo >= (double) duracao * 0.3) visualizacoes++;
}

/**
 * Imprime as informações do objeto
*/
void Video::imprimir() {
  cout << "Video: " << getNome() << " - " << getDuracao() << " min - "
        << visualizacoes << " visualizacoes" << endl;
}