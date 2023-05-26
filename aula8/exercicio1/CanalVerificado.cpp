#include "CanalVerificado.h"
#include <string>

CanalVerificado::CanalVerificado(string nome, int maximo) : Canal(nome, maximo) {}

CanalVerificado::~CanalVerificado() {}

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