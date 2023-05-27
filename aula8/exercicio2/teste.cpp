#include <iostream>
#include <string>
#include "Video.h"
#include "Canal.h"
#include "Lista.h"
#include "VideoCurto.h"

// Faça os includes necessários

using namespace std;

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  Video* v = new Video("More like you", 338);
  v->assistir(102);
  v->assistir(68);
  v->imprimir();
  v->setPorcentagem(0.2);
  v->assistir(102);
  v->assistir(68);
  v->imprimir();
  delete v;
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}
//*/