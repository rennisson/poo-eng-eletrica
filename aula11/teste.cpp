#include <iostream>
#include <string>
#include <stdexcept>
#include "Video.h"
#include "Canal.h"
#include "CanalVerificado.h"
#include "Lista.h"
#include "VideoCurto.h"
#include "NaoVerificado.h"
#include "PersistenciaConteudo.h"

// Faça os includes necessários

using namespace std;

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  CanalVerificado* c = new CanalVerificado("dodie");
  Video* v1 = new Video("Monster", 118, 8);
  Video* v2 = new Video("Human", 23, 6);
  VideoCurto* vc = new VideoCurto("Boys like you", 4, 5);
  Lista* l = new Lista("Build a problem");

  c->postar(v1);
  c->postar(v2);
  c->postar(vc);
  c->postar(l);

  c->imprimir();
  delete c;

  // Lista* l1 = new Lista("Freckle season");
  // Lista* l2 = new Lista("Singles");
  // Video* v1 = new Video("Pretending", 208, 0);
  // VideoCurto* vc = new VideoCurto("Heavy", 3, 14);
  // Video* v2 = new Video("Figure it out", 54, 3);
  // Video* v3 = new Video("Flatline", 85, 7);
  // l2->adicionar(v1);
  // l2->adicionar(v3);
  // l1->adicionar(vc);
  // l1->adicionar(v2);
  // l2->adicionar(l1);
  // l1->adicionar(l2);
  // l1->imprimir();
  // l2->imprimir();
  // delete l1;
  // delete l2;
  // delete v1;
  // delete v2;
  // delete vc;
  // delete v3;
}

//* COMENTE O MAIN AO SUBMETER
// int main () {
//   teste();
//   return 0;
// }
//*/