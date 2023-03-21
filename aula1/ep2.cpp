#include <iostream>

int tempoVisualizacaoTotal(int visualizacoes[], int duracoes[], int quantidade);

/*
int main() {
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
}
*/

int tempoVisualizacaoTotal(int visualizacoes[], int duracoes[], int quantidade) {

    int tempoTotal = 0;  // guarda o tempo total de visualizacoes

    for (int i = 0; i < quantidade; i++) {
        tempoTotal += visualizacoes[i] * duracoes[i];
    }

    return tempoTotal;
}