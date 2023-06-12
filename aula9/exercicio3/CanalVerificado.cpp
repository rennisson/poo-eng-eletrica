#include "CanalVerificado.h"
#include <string>
#include <stdexcept>

CanalVerificado::CanalVerificado(string nome, int maximo) : Canal(nome, maximo) {}

CanalVerificado::~CanalVerificado() {}

void CanalVerificado::postar(Conteudo* c) {
    if (quantidade >= maximo) throw new overflow_error("Maximo de videos");

    // Verifica se o video é repetido
    for (int i = 0; i < quantidade; i++) {
        if (c == conteudos[i]) throw new invalid_argument("Conteudo repetido");
    }

    conteudos[quantidade] = c;
    quantidade++;
}