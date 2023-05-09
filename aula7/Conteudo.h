#ifndef CONTEUDO_H
#define CONTEUDO_H
#include <string>
using namespace std;

class Conteudo {
    private:
        string nome;
    protected:
        int duracao;
        int visualizacoes;
    public:
        Conteudo(string nome, int duracao);
        ~Conteudo();

        string getNome();
        int getDuracao();
        virtual int getVisualizacoes();
};

#endif