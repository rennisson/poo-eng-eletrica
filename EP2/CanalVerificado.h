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
    virtual ~CanalVerificado();
    virtual void postar(Conteudo* c);
};

#endif
