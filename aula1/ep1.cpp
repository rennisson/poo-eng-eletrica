#include <iostream>

bool monetizacao(int duracao, int tempoAssistido, bool jaAssistiu);

int main() {
    std::cout << "------ TESTES DA CLASSE monetizacao() -------\n";
    std::cout << "monetizacao(40, 20, false) retornou " << monetizacao(40, 20, false) << " e deve retornar TRUE\n";
    std::cout << "monetizacao(60, 45, true) retornou " << monetizacao(60, 45, true) << " e deve retornar FALSE\n";
    std::cout << "monetizacao(10, 2, false) retornou " << monetizacao(10, 2, false) << " e deve retornar FALSE\n";
}

bool monetizacao(int duracao, int tempoAssistido, bool jaAssistiu) {
    if (jaAssistiu) {
        return false;
    }

    if (tempoAssistido >= (double) duracao * 0.3) {
        return true;
    }
    else { return false; }
}
