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
void tela_usuario(Plataforma* plataforma, Usuario* usuario);
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
      break;
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
  cout << "Digite o nome do usuario: ";
  string nome;
  cin >> nome;
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
    else cout << i+1 << ") " << usuarios[i]->getNome() << endl;
  }

  int numeroUsuario;
  cout << "Digite o numero, ou 0 para cancelar: ";
  cin >> numeroUsuario;

  if (numeroUsuario == 0) return;
  tela_usuario(plataforma, usuarios[numeroUsuario-1]);
}

void tela_usuario(Plataforma* plataforma, Usuario* usuario) {
  // Verifica se 'usuario' é verificado ou não
  UsuarioVerificado* usuarioVerificado = dynamic_cast<UsuarioVerificado*>(usuario);
  if (usuarioVerificado != NULL) cout << "Usuario: " << usuario->getNome() << " (verificado)" << endl;
  else cout << "Usuario: " << usuario->getNome() << endl;

  cout << "Canal: " << usuario->getCanal()->getNome() << endl;
  cout << "Quantidade de conteudos no canal: " << usuario->getCanal()->getQuantidade() << endl;
}

//* COMENTE O MAIN AO SUBMETER
int main() {
  interface();
  return 0;
}
//*/