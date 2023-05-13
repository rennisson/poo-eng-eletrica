#ifndef CANAL_H
#define CANAL_H
#include <string>
#include "Conteudo.h"
#include "Video.h"

class Canal {
private:

protected:
  string nome;
  int maximo;
  Conteudo **conteudos;
  int quantidade;

public:
  // Construtor
  Canal(string nome, int maximoDeVideos);
  Canal(string nome, Conteudo** conteudos, int quantidade);
  virtual ~Canal();

  virtual string getNome();
  virtual void setNome(string nome);
  virtual int getQuantidade();
  virtual int getDuracaoTotal();
  virtual int getTotalDeVisualizacoes();
  virtual Conteudo** getConteudos();
  virtual bool postar(Conteudo* c);
  virtual void imprimir();
};

#endif // CANAL_H