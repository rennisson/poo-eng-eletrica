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
  Conteudo* c = new Video("pumpkin cowboy", 5);
  Video* v = new Video("my weird ice creams", 20);

  for (int i = 0; i < 6; i++) {
    v->assistir(20);
  }

  Canal* canal = new Canal("BDG", 10);
  canal->postar(c);
  canal->postar(v);

  Lista* lista = new Lista("unraveled", 29);
  Conteudo* c1 = new Video("mortal kuddlers", 15);
  Video* v1 = new Video("halo novels", 28);
  lista->adicionar(static_cast<Video*>(c1));
  lista->adicionar(v1);
  canal->postar(lista);
  
  canal->imprimir();
  v->imprimir();
  lista->imprimir();
  delete canal;
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}
//*/