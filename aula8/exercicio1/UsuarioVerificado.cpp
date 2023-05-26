#include "UsuarioVerificado.h"
#include "CanalVerificado.h"
#include <string>
#include <iostream> 

UsuarioVerificado::UsuarioVerificado(string nome, string nomeDoCanal, int maximo) : Usuario(nome, new CanalVerificado(nomeDoCanal, maximo)) {
}

UsuarioVerificado::~UsuarioVerificado() {}