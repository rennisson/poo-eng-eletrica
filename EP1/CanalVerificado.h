#ifndef CANALVERIFICADO_H
#define CANALVERIFICADO_H
#include "Canal.h"
#include "Conteudo.h"
#include <string>

/**
 * Classe derivada de Canal.
*/
class CanalVerificado : public Canal {
    public:
        CanalVerificado(string nome, int maximo);
        virtual ~CanalVerificado();
        virtual bool postar(Conteudo* c);
};

#endif
