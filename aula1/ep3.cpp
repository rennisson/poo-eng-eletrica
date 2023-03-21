#include <iostream>

bool assistiuVideosRepetidos(std::string urls[], int quantidade);

/*
int main() {
    std::cout << "------ TESTES DA CLASSE assistiuVideosRepetidos() -------\n";

    std::string urls1[] = {"zI_cLtW3PnA", "uvh8wVgLTS8", "zI_cLtW3PnA"}; 
    int quantidade = sizeof(urls1) / sizeof(urls1[0]);
    std::cout << "assistiuVideosRepetidos({'zI_cLtW3PnA', 'uvh8wVgLTS8', 'zI_cLtW3PnA'}, 3) retornou "
                << assistiuVideosRepetidos(urls1, 3)
                << " e deve retornar TRUE\n";

    std::string urls2[] = {"zI_cLtW3PnA", "uvh8wVgLTS8", "g7C2it9cCsY", "uvh8wVgLTS8", "g7C2it9cCsY"}; 
    quantidade = sizeof(urls2) / sizeof(urls2[0]);
    std::cout << "assistiuVideosRepetidos({'zI_cLtW3PnA', 'uvh8wVgLTS8', 'g7C2it9cCsY', 'uvh8wVgLTS8', 'g7C2it9cCsY'}, 3) retornou "
                << assistiuVideosRepetidos(urls2, 5)
                << " e deve retornar TRUE\n";
}
*/

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
