#include "CanalVerificado.h"
#include <string>

CanalVerificado::CanalVerificado(string nome, int maximo) : Canal(nome, maximo) {}

CanalVerificado::~CanalVerificado() {}

/**
 * Posta um conteudo em Canal.
 * @return True caso seja possível adicionar o Conteudo no vetor de conteudos.
 * False, caso sua duração seja zero, caso o vetor de conteúdos já esteja cheio e
 * caso este já tenha sido postado anteriormente. 
*/
bool CanalVerificado::postar(Conteudo* c) {
    if (c->getDuracao() <= 0) return false;
    if (quantidade >= maximo) return false;

    // Verifica se o video é repetido
    for (int i = 0; i < quantidade; i++) {
        if (c == conteudos[i]) return false;
    }

    conteudos[quantidade] = c;
    quantidade++;

    return true;
}