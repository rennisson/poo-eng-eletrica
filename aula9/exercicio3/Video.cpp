#include "Video.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
double Video::porcentagem = 0.3;

// Construtor
Video::Video(string nome, int duracao) : Conteudo(nome, duracao) {
  if (duracao <= 0) throw new invalid_argument("Duracao invalida");
  visualizacoes = 0;
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
  if (tempo >= (double) duracao * Video::porcentagem) visualizacoes++;
}

/**
 * Imprime as informações do objeto
*/
void Video::imprimir() {
  cout << "Video: " << getNome() << " - " << getDuracao() << " min - "
        << visualizacoes << " visualizacoes" << endl;
}

void Video::setPorcentagem(double valor) {
  Video::porcentagem = valor;
}

double Video::getPorcentagem() {
  return Video::porcentagem;
}