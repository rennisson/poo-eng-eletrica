#include <iostream>
#include <string>
#include "Video.h"
#include "Canal.h"

// Faça os includes necessários

using namespace std;

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  Canal *canal = new Canal("Hoosiers", 7);

  Video *video1 = new Video("Killer", 34);
  for (int i = 0; i < 8; i++) {
    video1->assistir(12);
  }

  Video *video2 = new Video("Rules", 58);
  for (int i = 0; i < 4; i++) {
    video2->assistir(20);
  }

  Video *video3 = new Video("Ruby Blue", 17);
  for (int i = 0; i < 6; i++) {
    video3->assistir(10);
  }

  canal->postar(video1);
  canal->postar(video2);
  canal->postar(video3);
  canal->imprimir();
  
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}

//*/