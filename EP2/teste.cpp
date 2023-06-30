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
#include "NaoVerificado.h"
#include <vector>
#include <stdexcept>

// Faça os includes necessários

using namespace std;

void interface();
bool cadastrar_usuario(Plataforma* plataforma);
void logar(Plataforma* plataforma);
void tela_usuario(Plataforma* plataforma, Usuario* usuario);
void postar_video(Usuario* usuario);
bool criar_lista(Canal* canal);
Usuario* escolhe_usuario(Plataforma* plataforma);
Conteudo* escolhe_conteudo(Canal* canal);
bool assistir_video(Plataforma* plataforma);

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  Plataforma* plataforma = new Plataforma();

  while (true) {
    std::cout << endl << "ESCOLHA UMA OPCAO" << endl;
    std::cout << "1) Cadastrar usuario" << endl;
    std::cout << "2) Logar" << endl;
    std::cout << "0) Sair da plataforma" << endl;

    int opcao;
    std::cin >> opcao;
    std::cout << endl;

    switch (opcao) {
    case 0:
      delete plataforma;
      break;

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
  std::cout << "INFORME OS DADOS DO USUARIO:" << endl;
  std::cout << "Verificado (s/n)? ";
  string verificado;
  std::cin >> verificado;

  std::cout << "Digite o nome do usuario: ";
  string nome;
  std::cin >> nome;

  std::cout << "Digite o nome do seu canal: ";
  string nomeDoCanal;
  std::cin >> nomeDoCanal;

  Usuario* usuario;
  if (verificado == "s") usuario = new UsuarioVerificado(nome, nomeDoCanal);
  else if (verificado == "n") usuario = new Usuario(nome, nomeDoCanal);
  plataforma->adicionar(usuario);

  return true;
}

void logar(Plataforma* plataforma) {
  Usuario* usuario = escolhe_usuario(plataforma);
  if (usuario == NULL) return;
  tela_usuario(plataforma, usuario);
}

void tela_usuario(Plataforma* plataforma, Usuario* usuario) {
  while (true) {
    // Verifica se 'usuario' é verificado ou não
    UsuarioVerificado* usuarioVerificado = dynamic_cast<UsuarioVerificado*>(usuario);
    if (usuarioVerificado != NULL) std::cout << endl << "Usuario: " << usuario->getNome() << " (verificado)" << endl;
    else std::cout << endl << "Usuario: " << usuario->getNome() << endl;

    std::cout << "Canal: " << usuario->getCanal()->getNome() << endl;
    std::cout << "Quantidade de conteudos no canal: " << usuario->getCanal()->getConteudos()->size() << endl;
    std::cout << "------" << endl;
    std::cout << "ESCOLHA UMA OPCAO:" << endl;
    std::cout << "1) Postar video" << endl;
    std::cout << "2) Criar lista" << endl;
    std::cout << "3) Assistir video" << endl;
    std::cout << "0) Deslogar" << endl;

    int opcao;
    std::cin >> opcao;

    switch (opcao) {
    case 0:
      return;
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
    }
  }

}

void postar_video(Usuario* usuario) {
  string videoCurto;
  
  UsuarioVerificado* usuarioVerificado = dynamic_cast<UsuarioVerificado*>(usuario);
  if (usuarioVerificado != NULL) {   
    std::cout << "Video curto (s/n)? ";
    std::cin >> videoCurto;
  }
  
  string nomeDoVideo;
  std::cout << "Nome do video: ";
  std::cin >> nomeDoVideo;

  int duracao;
  std::cout << "Duracao: ";
  std::cin >> duracao;

  Video* video;
  if (videoCurto == "s") {
    try {
      video = new VideoCurto(nomeDoVideo, duracao);
    }
    catch (invalid_argument *e) {
      e->what();
      delete e;
    }
  }
  else {
    try {
      video = new Video(nomeDoVideo, duracao);
    }
    catch (invalid_argument *e) {
      e->what();
      delete e;
    }
  }
  std::cout << endl;

  Canal* canal = usuario->getCanal();
  try {
    canal->postar(video);
  }
  catch (NaoVerificado *e) {
    e->what();
  }
}

bool criar_lista(Canal* canal) {
  std::cout << endl;
  string nomeDaLista;
  std::cout << "Nome da lista: ";
  std::cin >> nomeDaLista;
  Lista* lista = new Lista(nomeDaLista);
  std::cout << endl;

  while (true) {
    Conteudo* conteudo = escolhe_conteudo(canal);
    if (conteudo == NULL) break;

    // Cast dinamico para verificar qual classe exatamente o objeto pertence
    Video* v = dynamic_cast<Video*>(conteudo);
    if (v != NULL) {
      try {
        lista->adicionar(v);
      }
      catch (invalid_argument *e) {
        e->what();
        std::cout << "Nao foi possivel adicionar" << endl;
        delete e;
      }
    }
    Lista* l = dynamic_cast<Lista*>(conteudo);
    if (l != NULL) {
      try {
        lista->adicionar(l);
      }
      catch (invalid_argument *e) {
        e->what();
        std::cout << "Nao foi possivel adicionar" << endl;
        delete e;
      }
    }

    std::cout << "Video adicionado a lista" << endl;
  }

  if (lista->getVideos()->size() == 0) return false;

  canal->postar(lista);
  std::cout << endl;
  return true;
}

bool assistir_video(Plataforma* plataforma) {
  Usuario* usuario = escolhe_usuario(plataforma);

  std::cout << "Canal: " << usuario->getCanal()->getNome() << endl;
  Conteudo* conteudo = escolhe_conteudo(usuario->getCanal());

  Lista* l = dynamic_cast<Lista*>(conteudo);
  if (l != NULL) {
    std::cout << "Nao foi possivel assistir" << endl;
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
    std::cout << "Diga o tempo assistido: ";
    std::cin >> tempo;
    v->assistir(tempo);
    return true;
  }
  
  return true;
}

Conteudo* escolhe_conteudo(Canal* canal) {
  vector<Conteudo*>* conteudos = canal->getConteudos();
  int opcao;
  std::cout << endl << "ESCOLHA O CONTEUDO" << endl;
    for (int i = 0; i < conteudos->size(); i++) {
      Video* v = dynamic_cast<Video*>((*conteudos)[i]);
      VideoCurto* vc = dynamic_cast<VideoCurto*>((*conteudos)[i]);
      Lista* l = dynamic_cast<Lista*>((*conteudos)[i]);

      if (v != NULL) {
        std::cout << i+1 << ") ";
        v->imprimir();
      }
      else if (vc != NULL) {
        std::cout << i+1 << ") ";
        vc->imprimir();
      }
      else if (l != NULL) {
        std::cout << i+1 << ") ";
        std::cout << "Lista: " << l->getNome() << " - " << l->getVideos()->size() << " video" << endl;
      }
    }   
    std::cout << "Digite o numero, ou ZERO para terminar: ";
    std::cin >> opcao;

    if (opcao == 0) return NULL;
    return (*conteudos)[opcao-1];
}

Usuario* escolhe_usuario(Plataforma* plataforma) {
  std::cout << endl << "ESCOLHA UM USUARIO" << endl;
  vector<Usuario*>* usuarios = plataforma->getUsuarios();

  for (int i = 0; i < plataforma->getQuantidadeDeUsuarios(); i++) {
    // Bloco que verifica se o usuario é verificado ou não
    UsuarioVerificado* usuarioVerificado = dynamic_cast<UsuarioVerificado*>((*usuarios)[i]);
    if (usuarioVerificado != NULL) std::cout << i+1 << ") " << (*usuarios)[i]->getNome() << " (verificado)" << endl;
    else std::cout << i+1 << ") " << (*usuarios)[i]->getNome() << endl;
  }

  int numeroUsuario;
  std::cout << "Digite o numero, ou 0 para cancelar: ";
  std::cin >> numeroUsuario;
  std::cout << endl;

  if (numeroUsuario == 0) return NULL;
  return (*usuarios)[numeroUsuario-1];
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}