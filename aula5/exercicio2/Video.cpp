#include "Video.h"
#include <iostream>
#include <string>

using namespace std;

// Construtor
Video::Video(string nome, int duracao) {
    this->nome = nome;
    this->duracao = duracao;
}

// Destrutor
Video::~Video() {
    cout << "Destruidor de video com " << this->visualizacoes << " visualizacoes: " << this->nome << endl; 
}

string Video::getNome() {
    return this->nome;
}

int Video::getDuracao() {
    return this->duracao;
}

int Video::getVisualizacoes() {
    return this->visualizacoes;
}

/**
 * Incrementa 1 no atributo 'visualizacoes' se 'tempo' é maior que 30% de 'duracao'
 * @param tempo tempo de video assistido
*/
void Video::assistir(int tempo) {
  if (tempo >= (double) this->duracao * 0.3) this->visualizacoes++;
}

/**
 * Imprime as informações do objeto
*/
void Video::imprimir() {
  cout << "Video: " << this->nome << " - " << this->duracao << " min - " << this->visualizacoes << " visualizacoes" << endl;
}