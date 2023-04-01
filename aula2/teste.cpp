#include <iostream>
#include <string>
using namespace std;

// FACA OS INCLUDES NECESSARIOS

/**
 * Retorna um ponteiro para a posição do video procurado
 * 
 * @param titulos vetor que guarda os titulos dos videos
 * @param duracoes vetor que guarda a duracao dos videos
 * @param titulo titulo do video procurado
 * @param duracao duracao do video procurado
 * @param quantidade tamanho do vetor 'titulos' e 'duracoes'
 * @return Retorna um ponteiro para a posição do video procurado, se não encontrar retorna NULL;
*/
string* encontrarVideo (string titulos[], int duracoes[], string titulo, int duracao, int quantidade);

/**
 * Retorna a média de duracoes
 * @param duracoes vetor que guarda a duracao dos videos
 * @param quantidade tamanho do vetor 'duracoes'
 * @param[out] minimo guarda o valor minimo do vetor
 * @param[out] maximo guarda o valor maximo do vetor
 * @return Retorna a média de duracoes, se 'duracoes' estiver vazio retorna ZERO;
*/
double calcularEstatisticas (int duracoes[], int quantidade, int& minimo, int* maximo);

/**
 * Calcula a media de duracoes
 * @param duracoes vetor que guarda a duracao dos videos
 * @param quantidade tamanho do vetor 'duracoes'
 * @return a media de duracoes do vetor 'duracoes'
*/
double calculaMedia(int duracoes[], int quantidade);

///* COMENTE O MAIN ANTES DE ENVIAR
int main() {
    // FACA TESTES
    string titulos[] = {"Gameplay de Elden Ring", "lofi hip hop radio", "portal speedrun"};
    int duracoes[] = {100, 60, 9};
    int quantidade = sizeof(duracoes) / sizeof(duracoes[0]);

    cout << encontrarVideo(titulos, duracoes, "portal speedrun", 9, quantidade) << endl;

    cout << encontrarVideo(titulos, duracoes, "x", 0, quantidade) << endl;

    string titulos[] = {"Gameplay de Elden Ring", "lofi hip hop radio", "portal speedrun"};
    int duracoes[] = {9, 60, 100};
    int quantidade = sizeof(duracoes) / sizeof(duracoes[0]);

    int minimo = 0;
    int maximo = 0;
    int *pMaximo = &maximo;

    cout << calcularEstatisticas(duracoes, quantidade, minimo, pMaximo) << endl;

    int duracoes1[10] = {};
    quantidade = sizeof(duracoes1) / sizeof(duracoes1[0]);
    cout << calcularEstatisticas(duracoes, 0, minimo, pMaximo) << endl;

    string titulos3[] = {"TESTE"};
    int duracoes[] = {9};
    int quantidade = sizeof(duracoes) / sizeof(duracoes[0]);

    cout << calcularEstatisticas(duracoes, quantidade, minimo, pMaximo) << endl;

    // Implementar!
    return 0;
}
//*/

string* encontrarVideo (string titulos[], int duracoes[], string titulo, int duracao, int quantidade) {

    string *pEndereco;
    pEndereco = NULL;

    for (int i = 0; i < quantidade; i++) {
        if (titulos[i] == titulo && duracoes[i] == duracao) {
            pEndereco = &titulos[i];
        }
    }

    return pEndereco;
}

double calcularEstatisticas (int duracoes[], int quantidade, int& minimo, int* maximo) {

    double media = 0;

    // Array vazio
    if (quantidade == 0) {
        minimo = 0;
        *maximo = 0;
        media = 0;
        return media;
    }

    // Tratamento dos valores 'minimo' e 'maximo'
    if (minimo > *maximo) {
        int temp = *maximo;
        *maximo = minimo;
        minimo = temp;
    }

    *maximo = duracoes[0];
    minimo = duracoes[0];
    int soma = 0;
    
    for (int i = 1; i < quantidade; i++) {
        if (duracoes[i] >= *maximo) {
            *maximo = duracoes[i];
        }
        else if (duracoes[i] <= minimo) {
            minimo = duracoes[i];
        }

        soma += duracoes[i];
    }

    media = calculaMedia(duracoes, quantidade);
    return media;

}

double calculaMedia(int duracoes[], int quantidade) {
    int soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += duracoes[i];
    }

    return (double) soma / quantidade;
}
