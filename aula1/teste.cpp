#include <iostream>
#include <string>

// FACA OS INCLUDES NECESSARIOS

using namespace std;

// IMPLEMENTE AS FUNCOES
bool monetizacao (int duracao, int tempoAssistido, bool jaAssistiu);
int tempoVisualizacaoTotal (int visualizacoes[], int duracoes[], int quantidade);
bool assistiuVideosRepetidos (string urls[], int quantidade);

//* COMENTE O MAIN ANTES DE ENVIAR
/*
int main (){
    // FACA TESTES
    std::cout << "------ TESTES DA CLASSE monetizacao() -------\n";
    std::cout << "monetizacao(40, 20, false) retornou " << monetizacao(40, 20, false) << " e deve retornar TRUE\n";
    std::cout << "monetizacao(60, 45, true) retornou " << monetizacao(60, 45, true) << " e deve retornar FALSE\n";
    std::cout << "monetizacao(10, 2, false) retornou " << monetizacao(10, 2, false) << " e deve retornar FALSE\n";

    std::cout << std::endl;

    std::cout << "------ TESTES DA CLASSE tempoVisualizacaoTotal() -------\n";

    int visualizacoes1[] = { 16, 21, 12 };
    int duracoes1[] = { 10, 20, 30 };
    int quantidade = sizeof(visualizacoes1) / sizeof(visualizacoes1[0]);

    std::cout << "tempoVisualizacaoTotal(visualizacoes, duracoes, quantidade) retornou "
                << tempoVisualizacaoTotal(visualizacoes1, duracoes1, quantidade)
                << " e deve retornar 940\n";

    int visualizacoes2[] = { 10, 10, 10, 10, 10, 10 };
    int duracoes2[] = { 10, 10, 10, 10, 10, 10 };
    quantidade = sizeof(visualizacoes2) / sizeof(visualizacoes2[0]);

    std::cout << "tempoVisualizacaoTotal(visualizacoes, duracoes, quantidade) retornou "
                << tempoVisualizacaoTotal(visualizacoes2, duracoes2, quantidade)
                << " e deve retornar 600\n";

    int visualizacoes3[] = { 10 };
    int duracoes3[] = { 3 };
    quantidade = sizeof(visualizacoes3) / sizeof(visualizacoes3[0]);

    std::cout << "tempoVisualizacaoTotal(visualizacoes, duracoes, quantidade) retornou "
                << tempoVisualizacaoTotal(visualizacoes3, duracoes3, quantidade)
                << " e deve retornar 30\n";

    std::cout << std::endl;

    std::cout << "------ TESTES DA CLASSE assistiuVideosRepetidos() -------\n";

    std::string urls1[] = {"zI_cLtW3PnA", "uvh8wVgLTS8", "zI_cLtW3PnA"}; 
    quantidade = sizeof(urls1) / sizeof(urls1[0]);
    std::cout << "assistiuVideosRepetidos({'zI_cLtW3PnA', 'uvh8wVgLTS8', 'zI_cLtW3PnA'}, 3) retornou "
                << assistiuVideosRepetidos(urls1, quantidade)
                << " e deve retornar TRUE\n";

    std::string urls2[] = {"zI_cLtW3PnA", "uvh8wVgLTS8", "g7C2it9cCsY", "QyPR77rg1to"}; 
    quantidade = sizeof(urls2) / sizeof(urls2[0]);
    std::cout << "assistiuVideosRepetidos({'zI_cLtW3PnA', 'uvh8wVgLTS8', 'g7C2it9cCsY', 'QyPR77rg1to'}, 4) retornou "
                << assistiuVideosRepetidos(urls2, quantidade)
                << " e deve retornar FALSE\n";

    
    return 0;
}
*/
//*/

bool monetizacao(int duracao, int tempoAssistido, bool jaAssistiu) {
    if (jaAssistiu) return false;

    if (tempoAssistido >= (double) duracao * 0.3) return true;
    else return false;
}

int tempoVisualizacaoTotal(int visualizacoes[], int duracoes[], int quantidade) {

    int tempoTotal = 0;  // guarda o tempo total de visualizacoes

    for (int i = 0; i < quantidade; i++) {
        tempoTotal += visualizacoes[i] * duracoes[i];
    }

    return tempoTotal;
}

bool assistiuVideosRepetidos(std::string urls[], int quantidade) {
    // Não é necessário comparar o ultimo elemento do array, por isso utilizamos (quantidade - 1)
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i+1; j < quantidade; j++) {
            if (urls[j] == urls[i]) {
                return true;
            }
        }
    }
    return false;
}