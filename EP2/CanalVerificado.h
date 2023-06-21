#ifndef CANALVERIFICADO_H
#define CANALVERIFICADO_H
#include "Canal.h"
#include "Conteudo.h"
#include <string>

class CanalVerificado : public Canal {
private:
    string nome;
public:
    CanalVerificado(string nome);
    CanalVerificado(string nome, vector<Conteudo*>* conteudos);
    virtual ~CanalVerificado();
    virtual void postar(Conteudo* c);
};

#endif
