#ifndef PERSISTENCIAPlataforma_H
#define PERSISTENCIAPlataforma_H
#include <string>
#include "Plataforma.h"

class PersistenciaPlataforma {
private:
    string arquivo;

public:
    PersistenciaPlataforma(string arquivo);
    ~PersistenciaPlataforma();
    void inserir(Plataforma* p);
    Plataforma* carregar();
};

#endif