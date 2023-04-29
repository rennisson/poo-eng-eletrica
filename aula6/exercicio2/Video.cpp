#include "Video.h"
#include <iostream>
#include <string>

using namespace std;

// Construtor
Video::Video(string nome, int duracao) : Conteudo(nome, duracao) {
    
}

// Destrutor
Video::~Video() {
    cout << "Destruidor de video com " << this->visualizacoes << " visualizacoes: " << this->getNome() << endl; 
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
  cout << "Video: " << this->getNome() << " - " << this->getDuracao() << " min - "
        << this->visualizacoes << " visualizacoes" << endl;
}