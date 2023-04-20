#include <iostream>
#include <string>
#include "Video.h"
#include "Canal.h"

// Faça os includes necessários

using namespace std;

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  Video *video = new Video;
  video->setNome("1 hour of Wii music");
  video->setDuracao(64);
  video->assistir(18);
  video->assistir(2);
  video->assistir(57);
  video->imprimir();

  video->assistir(61);
  video->assistir(43);

  Video *video2 = new Video;
  video2->setNome("bidoofwave");
  video2->setDuracao(591);
  video2->assistir(303);
  video2->assistir(109);
  video2->assistir(487);

  Canal *canal = new Canal;
  canal->setNome("Nintendo");
  canal->postar(video);
  canal->postar(video2);

  video2->imprimir();

  cout << canal->getDuracaoTotal() << endl;
  cout << canal->getTotalDeVisualizacoes() << endl;

  canal->imprimir();
}

//* COMENTE O MAIN AO SUBMETER
// int main () {
//   teste();
//   return 0;
// }

//*/