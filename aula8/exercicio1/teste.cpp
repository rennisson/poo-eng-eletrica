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
  Conteudo** c = new Conteudo*[4];

  Video* v1 = new Video("Stay Soft", 42);
  for (int i = 0; i < 5; i++) v1->assistir(40);

  Video* v2 = new Video("Lush", 26);
  for (int i = 0; i < 9; i++) v1->assistir(25);

  Lista* l = new Lista("Brooklyn Steel", 3);
  Video* v3 = new Video("Townie", 915);
  Video* v4 = new Video("Geyser", 14);
  Video* v5 = new Video("Nobody", 626);
  for (int i = 0; i < 6; i++) {
    v3->assistir(900);
    v4->assistir(13);
    v5->assistir(620);
  }

  l->adicionar(v3);
  l->adicionar(v4);
  l->adicionar(v5);

  Video* v6 = new Video("Carry me out", 4);

  c[0] = v1;
  c[1] = v2;
  c[2] = l;
  c[3] = v6;

  Canal* canal = new Canal("mitski mitski", c, 4);
  cout << canal->getTotalDeVisualizacoes() << endl;
  canal->imprimir();
  delete canal;
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}
//*/