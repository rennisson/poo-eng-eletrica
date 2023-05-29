#ifndef CANAL_H
#define CANAL_H
#include <string>
#include "Conteudo.h"
#include "Video.h"

/**
 * Classe responsável por ter a lista de Conteudos.
*/
class Canal {
  private:
    string nome;
    
  protected:
    int maximo;
    Conteudo **conteudos;
    int quantidade;

  public:
    // Construtor
    Canal(string nome, int maximoDeVideos);
    Canal(string nome, Conteudo** conteudos, int quantidade);
    virtual ~Canal();

    virtual string getNome();
    virtual int getQuantidade();
    virtual int getDuracaoTotal();
    virtual int getTotalDeVisualizacoes();
    virtual Conteudo** getConteudos();
    virtual bool postar(Conteudo* c);
    virtual void imprimir();
};

#endif // CANAL_H