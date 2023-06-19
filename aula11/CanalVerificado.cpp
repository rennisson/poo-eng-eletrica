#include "CanalVerificado.h"
#include <string>
#include <stdexcept>    

CanalVerificado::CanalVerificado(string nome) : Canal(nome) {}

CanalVerificado::~CanalVerificado() {}

void CanalVerificado::postar(Conteudo* c) {
    // Verifica se o video é repetido
    // Verifica se o video é repetido
    vector<Conteudo*>::iterator repetido = find(conteudos->begin(), conteudos->end(), c);
    if (repetido != conteudos->end()) throw new invalid_argument("Conteudo repetido");

    conteudos->insert(conteudos->end(), c);
}