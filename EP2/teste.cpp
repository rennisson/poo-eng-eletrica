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
    Video* v1 = new Video("Video 1", 10, 1);
    Video* v2 = new Video("Video 2", 11, 2);
    Video* v3 = new Video("Video 3", 12, 3);
    Video* v4 = new Video("Video 4", 13, 4);
    Video* v5 = new Video("Video 5", 14, 5);
    Video* v6 = new Video("Video 6", 15, 6);
    Video* v7 = new Video("Video 7", 16, 7);
    Video* v8 = new Video("Video 8", 17, 8);
    Video* v9 = new Video("Video 9", 18, 9);
    Video* v10 = new Video("Video 10", 19, 10);
    Video* v11 = new Video("Video 11", 20, 11);
    Video* v12 = new Video("Video 12", 21, 12);
    Video* v13 = new Video("Video 12", 21, 12);

    Canal* canal = new Canal("TESTE");
    canal->postar(v1);
    canal->postar(v2);
    // canal->postar(v3);
    // canal->postar(v4);
    // canal->postar(v5);
    // canal->postar(v6);
    // canal->postar(v7);
    // canal->postar(v8);
    // canal->postar(v9);
    // canal->postar(v10);
    // canal->postar(v11);
    canal->postar(v12);
    canal->postar(v13);

    //Lista* maisVistos = canal->criarListaComVideosMaisVistos(5, "Mais vistos");
    canal->imprimir();
    //maisVistos->imprimir();
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}