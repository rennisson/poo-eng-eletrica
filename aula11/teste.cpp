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
  // Video *v1 = new Video("Heather", 25);
  // for (int i = 0; i < 7; i++) v1->assistir(24);

  // Video *v2 = new Video("Memories", 29);
  // for (int i = 0; i < 3; i++) v2->assistir(28);

  // VideoCurto *vc = new VideoCurto("Lookalike", 5);
  // for (int i = 0; i < 10; i++) vc->assistir();

  // Video *v3 = new Video("Telepath", 42);
  // for (int i = 0; i < 5; i++) v3->assistir(41); 

  // PersistenciaConteudo *p = new PersistenciaConteudo("teste.txt");
  // p->inserir(v1);
  // p->inserir(v2);
  // p->inserir(vc);
  // p->inserir(v3);

  // delete v1;
  // delete v2;
  // delete vc;
  // delete v3;

  PersistenciaConteudo *p = new PersistenciaConteudo("teste.txt");
  int quantidade = 10;
  Conteudo** conteudos = p->obter(quantidade);
  Canal *c = new Canal("Conan Gray", conteudos, quantidade);
  c->imprimir();
  delete c;
}

//* COMENTE O MAIN AO SUBMETER
// int main () {
//   teste();
//   return 0;
// }
//*/