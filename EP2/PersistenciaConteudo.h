#ifndef PERSISTENCIACONTEUDO_H
#define PERSISTENCIACONTEUDO_H
#include <string>
#include "Conteudo.h"

class PersistenciaConteudo {
private:
    string arquivo;

public:
    PersistenciaConteudo(string arquivo);
    ~PersistenciaConteudo();
    void inserir(Conteudo* c);
    Conteudo** obter(int& quantidade);
};

#endif