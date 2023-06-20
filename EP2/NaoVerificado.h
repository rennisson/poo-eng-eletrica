#ifndef NAOVERIFICADO_H
#define NAOVERIFICADO_H
#include <stdexcept>
#include <string>

using namespace std;

class NaoVerificado : public runtime_error {
    public:
        NaoVerificado();
};

#endif