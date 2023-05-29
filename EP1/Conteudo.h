#ifndef CONTEUDO_H
#define CONTEUDO_H
#include <string>
using namespace std;

/**
 * Representa um conteúdo que é postado em Canal. 
*/
class Conteudo {
    private:
        string nome;
    protected:
        int duracao;
        int visualizacoes;
    public:
        Conteudo(string nome, int duracao);
        virtual ~Conteudo();
        virtual string getNome();
        virtual int getDuracao();
        virtual int getVisualizacoes();
};

#endif