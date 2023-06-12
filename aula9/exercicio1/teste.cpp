#include <iostream>
#include <string>
#include <stdexcept>
#include "Video.h"
#include "Canal.h"
#include "Lista.h"
#include "VideoCurto.h"

// Faça os includes necessários

using namespace std;

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  Video *v;
  VideoCurto *vc;
  Lista *l;
  try {
    v = new Video("June Gloom", 3);
    //vc = new VideoCurto("Science", -1);
    l = new Lista("Cape God", 4);
    cout << l->getDuracao() << endl;
  }
  catch (invalid_argument *e) {
    cout << e->what() << endl;
    delete e;
  }
  catch (logic_error *e) {
    cout << e->what() << endl;
    delete e;
  }

  l->adicionar(v);
  l->imprimir();
  delete l;
  delete v;

}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}
//*/