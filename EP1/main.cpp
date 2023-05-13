#include <iostream>
#include <string>
#include "Plataforma.h"
#include "Usuario.h"
#include "UsuarioVerificado.h"
#include "Video.h"
#include "Canal.h"
#include "Lista.h"
#include "VideoCurto.h"

// Faça os includes necessários
using namespace std;

bool cadastrar_usuario(Plataforma* plataforma);
void logar(Plataforma* plataforma);
void interface();


// IMPLEMENTE A FUNCAO TESTE
void interface() {
  Plataforma* plataforma = new Plataforma();
  int opcao = -1;

  while (opcao != 0) {
    cout << "ESCOLHA UMA OPCAO" << endl;
    cout << "1) Cadastrar usuario" << endl;
    cout << "2) Logar" << endl;
    cout << "0) Sair da plataforma" << endl;

    cin >> opcao;

    switch (opcao) {
    case 1:
      cadastrar_usuario(plataforma);
      break;
    case 2:
      logar(plataforma);
    default:
      break;
    }
  }
}

bool cadastrar_usuario(Plataforma* plataforma) {
  cout << "INFORME OS DADOS DO USUARIO:" << endl;
  cout << "Verificado (s/n)? ";
  string verificado;
  cin >> verificado;
  cout << endl;
  cout << "Digite o nome do usuario: ";
  string nome;
  cin >> nome;
  cout << endl;
  cout << "Digite o nome do seu canal: ";
  string nomeDoCanal;
  cin >> nomeDoCanal;

  Usuario* usuario;
  if (verificado == "s") usuario = new UsuarioVerificado(nome, nomeDoCanal, 20);
  else if (verificado == "n") usuario = new Usuario(nome, nomeDoCanal, 20);
  plataforma->adicionar(usuario);

  return true;
}

void logar(Plataforma* plataforma) {
  cout << "ESCOLHA UM USUARIO" << endl;
  Usuario** usuarios = plataforma->getUsuarios();

  for (int i = 0; i < plataforma->getQuantidadeDeUsuarios(); i++) {
    // Bloco que verifica se o usuario é verificado ou não
    UsuarioVerificado* usuarioVerificado = dynamic_cast<UsuarioVerificado*>(usuarios[i]);
    if (usuarioVerificado != NULL) cout << i+1 << ") " << usuarios[i]->getNome() << " (verificado)" << endl;
    else cout << i << ") " << usuarios[i+1]->getNome() << " (verificado)" << endl;
  }

  int usuario;
  cout << "Digite o numero, ou 0 para cancelar: ";
  cin >> usuario;

  if (usuario == 0) return;
}

//* COMENTE O MAIN AO SUBMETER
int main() {
  interface();
  return 0;
}
//*/