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

  // Lista* lista1 = new Lista("Musicas", 5);
  // Lista* lista2 = new Lista("Favoritos", 8);

  // Video* v1 = new Video("Valentine Texas", 42);
  // Video* v2 = new Video("Pleaser", 14);
  // Video* v3 = new Video("Everything Stays", 71);
  // Video* v4 = new Video("Everything", 71);
  // Video* v5 = new Video("P", 14);
  // Video* v6 = new Video("Valentine", 42);

  // lista1->adicionar(v1);
  // lista1->adicionar(v2);
  // lista1->adicionar(v3);

  // lista2->adicionar(v4);
  // lista2->adicionar(v5);
  // lista2->adicionar(v6);

  // lista1->adicionar(lista2);
  // lista1->imprimir();
  // lista2->imprimir();
  // cout << lista1->getVisualizacoes();
  // cout << lista2->getVisualizacoes();

  Canal* c = new Canal("teste", 10);
  Lista* lista1 = new Lista("Musicas", 8);
  Lista* lista2 = new Lista("Favoritos", 8);
  Video* v1 = new Video("Valentine Texas", 42);
  Video* v2 = new Video("Pleaser", 14);
  Video* v3 = new Video("Everything Stays", 71);
  Video* v4 = new Video("Thumbnail", 6);
  VideoCurto* v5 = new VideoCurto("Nobody", 4);


  lista2->adicionar(v1);
  lista2->adicionar(v4);
  lista2->adicionar(v5);

  c->postar(v5);
  
  lista1->adicionar(v1);
  lista1->adicionar(v2);
  lista1->adicionar(v3);

  lista2->adicionar(lista1);

  delete lista1;
  lista2->imprimir();
  delete lista2;

}

//* COMENTE O MAIN AO SUBMETER
// int main () {
//   teste();
//   return 0;
// }
//*/