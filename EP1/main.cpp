#include <iostream>
#include <string>
#include "Plataforma.h"
#include "Usuario.h"
#include "UsuarioVerificado.h"
#include "Canal.h"
#include "Lista.h"
#include "Conteudo.h"
#include "Video.h"
#include "VideoCurto.h"

// Faça os includes necessários
using namespace std;

void interface();
bool cadastrar_usuario(Plataforma* plataforma);
void logar(Plataforma* plataforma);
void tela_usuario(Plataforma* plataforma, Usuario* usuario);
bool postar_video(Usuario* usuario);
bool criar_lista(Canal* canal);
Usuario* escolhe_usuario(Plataforma* plataforma);
Conteudo* escolhe_conteudo(Canal* canal);
bool assistir_video(Plataforma* plataforma);


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
    cout << endl;
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

  cout << endl << endl;
  return true;
}

void logar(Plataforma* plataforma) {
  Usuario* usuario = escolhe_usuario(plataforma);
  if (usuario == NULL) return;
  tela_usuario(plataforma, usuario);
}

void tela_usuario(Plataforma* plataforma, Usuario* usuario) {
  int opcao = -1;
  while (opcao != 0) {
    // Verifica se 'usuario' é verificado ou não
    UsuarioVerificado* usuarioVerificado = dynamic_cast<UsuarioVerificado*>(usuario);
    if (usuarioVerificado != NULL) cout << "Usuario: " << usuario->getNome() << " (verificado)" << endl;
    else cout << "Usuario: " << usuario->getNome() << endl;

    cout << "Canal: " << usuario->getCanal()->getNome() << endl;
    cout << "Quantidade de conteudos no canal: " << usuario->getCanal()->getQuantidade() << endl;
    cout << "------" << endl;
    cout << "ESCOLHA UMA OPCAO:" << endl;
    cout << "1) Postar video" << endl;
    cout << "2) Criar lista" << endl;
    cout << "3) Assistir video" << endl;
    cout << "0) Deslogar" << endl;
    cin >> opcao;

    switch (opcao) {
    case 0:
      delete plataforma;
      break;

    case 1:
      postar_video(usuario);
      break;
    
    case 2:
      criar_lista(usuario->getCanal());
      break;

    case 3:
      assistir_video(plataforma);
      break;

    default:
      break;
    }
  }

}

bool postar_video(Usuario* usuario) {
  string videoCurto;
  
  UsuarioVerificado* usuarioVerificado = dynamic_cast<UsuarioVerificado*>(usuario);
  if (usuarioVerificado != NULL) {   
    cout << "Video curto (s/n)? ";
    cin >> videoCurto;
  }
  
  string nomeDoVideo;
  cout << "Nome do video: ";
  cin >> nomeDoVideo;

  int duracao;
  cout << "Duracao: ";
  cin >> duracao;

  Video* video;
  if (videoCurto == "s") video = new VideoCurto(nomeDoVideo, duracao);
  else video = new Video(nomeDoVideo, duracao);
  cout << endl;

  Canal* canal = usuario->getCanal();
  return canal->postar(video);
}

bool criar_lista(Canal* canal) {
  cout << endl;
  string nomeDaLista;
  cout << "Nome da lista: ";
  cin >> nomeDaLista;
  Lista* lista = new Lista(nomeDaLista, 20);
  cout << endl;

  while (true) {
    bool adicionou = false;
    Conteudo* conteudo = escolhe_conteudo(canal);
    if (conteudo == NULL) break;

    // Cast dinamico para verificar qual classe exatamente o objeto pertence
    Video* v = dynamic_cast<Video*>(conteudo);
    if (v != NULL) adicionou = lista->adicionar(v);
    Lista* l = dynamic_cast<Lista*>(conteudo);
    if (l != NULL) adicionou = lista->adicionar(l);

    if (adicionou) cout << "Video adicionado a lista" << endl;
    else cout << "Nao foi possivel adicionar" << endl;
  }

  if (lista->getQuantidade() == 0) return false;
  
  canal->postar(lista);
  cout << endl;
  return true;
}

bool assistir_video(Plataforma* plataforma) {
  Usuario* usuario = escolhe_usuario(plataforma);

  cout << "Canal: " << usuario->getCanal()->getNome() << endl;
  Conteudo* conteudo = escolhe_conteudo(usuario->getCanal());

  Lista* l = dynamic_cast<Lista*>(conteudo);
  if (l != NULL) {
    cout << "Nao foi possivel assistir" << endl;
    return false;
  }

  VideoCurto* vc = dynamic_cast<VideoCurto*>(conteudo);
  if (vc != NULL) {
    vc->assistir();
    return true;
  }

  Video* v = dynamic_cast<Video*>(conteudo);
  if (v != NULL) {
    int tempo;
    cout << "Diga o tempo assistido: ";
    cin >> tempo;
    v->assistir(tempo);
    return true;
  }
  
  return true;
}

Conteudo* escolhe_conteudo(Canal* canal) {
  Conteudo** conteudos = canal->getConteudos();
  int opcao;
  cout << "ESCOLHA O CONTEUDO" << endl;
    for (int i = 0; i < canal->getQuantidade(); i++) {
      Video* v = dynamic_cast<Video*>(conteudos[i]);
      VideoCurto* vc = dynamic_cast<VideoCurto*>(conteudos[i]);
      Lista* l = dynamic_cast<Lista*>(conteudos[i]);

      if (v != NULL) {
        cout << i+1 << ") ";
        v->imprimir();
      }
      else if (vc != NULL) {
        cout << i+1 << ") ";
        vc->imprimir();
      }
      else if (l != NULL) {
        cout << i+1 << ") ";
        l->imprimir();
      }
    }   
    cout << "Digite o numero, ou ZERO para terminar: ";
    cin >> opcao;

    if (opcao == 0) return NULL;
    return conteudos[opcao-1];
}

Usuario* escolhe_usuario(Plataforma* plataforma) {
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
  cout << endl;

  if (numeroUsuario == 0) return NULL;
  return usuarios[numeroUsuario-1];
}

//* COMENTE O MAIN AO SUBMETER
int main() {
  interface();
  return 0;
}
//*/