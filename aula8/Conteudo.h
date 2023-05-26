#ifndef CONTEUDO_H
#define CONTEUDO_H
#include <string>
using namespace std;

class Conteudo {
    private:
        string nome;
    protected:
        int duracao;
    public:
        Conteudo(string nome, int duracao);
        virtual ~Conteudo();
        virtual string getNome();
        virtual int getDuracao();
        virtual int getVisualizacoes() = 0;
        virtual void imprimir() = 0;
};

#endif