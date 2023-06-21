#include "UsuarioVerificado.h"
#include "CanalVerificado.h"
#include <string>
#include <iostream> 

UsuarioVerificado::UsuarioVerificado(string nome, string nomeDoCanal) : Usuario(nome, new CanalVerificado(nomeDoCanal)) {}

UsuarioVerificado::UsuarioVerificado(string nome, Canal* canal) : Usuario(nome, canal) {}

UsuarioVerificado::~UsuarioVerificado() {}