#include "PersistenciaPlataforma.h"
#include "Conteudo.h"
#include "Video.h"
#include "VideoCurto.h"
#include "Usuario.h"
#include "UsuarioVerificado.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

PersistenciaPlataforma::PersistenciaPlataforma(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaPlataforma::~PersistenciaPlataforma() {}

void PersistenciaPlataforma::inserir(Plataforma* p) {

    ofstream output;
    output.open(arquivo, ios_base::app);

    for (Usuario* usuario : *p->getUsuarios()) {
        UsuarioVerificado* verificado = dynamic_cast<UsuarioVerificado*>(usuario);
        if (verificado != NULL) output << "v ";
        else output << "n ";

        output << usuario->getNome() << endl;
        Canal* c = usuario->getCanal();
        output << c->getNome() << "\n";

        int quantidadeDeVideos = 0;
        for (Conteudo* c : *(c->getConteudos())) {
            Video* v = dynamic_cast<Video*>(c);
            if (v != NULL) quantidadeDeVideos++;
        }

        output << quantidadeDeVideos << endl;

        for (Conteudo* c : *(c->getConteudos())) {
            Video* v = dynamic_cast<Video*>(c);
            if (v != NULL) {
                VideoCurto* vc = dynamic_cast<VideoCurto*>(v);
                if (vc != NULL) output << "s ";
                else output << "n ";
                output << v->getNome() << " " << v->getDuracao() << " " << v->getVisualizacoes() << endl;
            }
        }
    }
    output.close();
}

// PENDENTE
Plataforma* PersistenciaPlataforma::carregar() {

    // ifstream input;
    // input.open(arquivo);

    // if (input.fail()) { // Arquivo nao encontrado
    //     input.close();
    //     return new Plataforma();
    // }

    // string tipo, nome;
    // int duracao, visualizacoes;
    // int quantidade = 0;

    // input >> tipo >> nome;
    // while (input) {
    //     if (tipo == "v") {
    //         Video* v = new Video(nome, duracao, visualizacoes);
    //         conteudos[quantidade] = v;
    //     }
    //     else if (tipo == "s") {
    //         VideoCurto *vc = new VideoCurto(nome, duracao, visualizacoes);
    //         conteudos[quantidade] = vc;
    //     }
        
    //     quantidade++;
    //     input >> tipo >> nome >> duracao >> visualizacoes;
    // }

    // if (!input.eof()) {
    //     input.close();
    //     throw new logic_error("Erro de leitura");
    // }
    
    // if (quantidade == 0) {
    //     input.close();
    //     return NULL;
    // }

    // input.close();
    // return conteudos;
}

