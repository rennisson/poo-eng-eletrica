#include "PersistenciaConteudo.h"
#include "Conteudo.h"
#include "Video.h"
#include "VideoCurto.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

PersistenciaConteudo::PersistenciaConteudo(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaConteudo::~PersistenciaConteudo() {}

void PersistenciaConteudo::inserir(Conteudo* c) {

    ofstream output;
    output.open(arquivo, ios_base::app);

    VideoCurto *vc = dynamic_cast<VideoCurto*>(c);
    if (vc != NULL) {
        output << "s " << vc->getNome() << " " << vc->getDuracao() << " " << vc->getVisualizacoes() << endl;
        output.close();
        return;
    }

    Video *v = dynamic_cast<Video*>(c);
    if (v != NULL) {
        output << "v " << v->getNome() << " " << v->getDuracao() << " " << v->getVisualizacoes() << endl;
        output.close();
        return;
    }
}

Conteudo** PersistenciaConteudo::obter(int& quantidade) {
    Conteudo** conteudos = new Conteudo*[10];

    ifstream input;
    input.open(arquivo);

    if (input.fail()) { // Arquivo nao encontrado
        input.close();
        throw new invalid_argument("Erro de leitura");
    }

    string tipo, nome;
    int duracao, visualizacoes;
    quantidade = 0;

    input >> tipo >> nome >> duracao >> visualizacoes;
    while (input) {

        if (tipo == "v") {
            Video* v = new Video(nome, duracao, visualizacoes);
            conteudos[quantidade] = v;
        }
        else if (tipo == "s") {
            VideoCurto *vc = new VideoCurto(nome, duracao, visualizacoes);
            conteudos[quantidade] = vc;
        }
        
        quantidade++;
        input >> tipo >> nome >> duracao >> visualizacoes;
    }

    if (!input.eof()) {
        input.close();
        throw new logic_error("Erro de leitura");
    }
    
    if (quantidade == 0) {
        input.close();
        return NULL;
    }

    input.close();
    return conteudos;
}

