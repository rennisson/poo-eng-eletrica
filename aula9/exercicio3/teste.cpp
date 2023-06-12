#include <iostream>
#include <string>
#include <stdexcept>
#include "Video.h"
#include "Canal.h"
#include "Lista.h"
#include "VideoCurto.h"
#include "NaoVerificado.h"

// Faça os includes necessários

using namespace std;

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  try {
    Canal *c = new Canal("half alive", 2);
    Video *v1 = new Video("still fell", 18);
    Video *v2 = new Video("runaway", 19);
    Video *v3 = new Video("hot tea", 58);
    Video *v4 = new VideoCurto("pure gold", 3);

    c->postar(v1);
    //c->postar(v1);
    //c->postar(v4);
    c->postar(v2);
    c->imprimir();

    c->postar(v3);
  }
  catch (invalid_argument *e) {
    cout << e->what() << endl;
    delete e;
  }
  catch (NaoVerificado *e) {
    cout << e->what() << endl;
    delete e;
  }
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}
//*/