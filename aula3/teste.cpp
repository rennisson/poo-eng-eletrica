#include <iostream>
#include <string>

// Faça os includes necessários

using namespace std;

class Video {
public: 
  string nome;
  int duracao;
  int visualizacoes = 0;

  void assistir (int tempo);    
  void imprimir ();
};

/**
 * Verifica se o vídeo ja foi postado
 * @return TRUE se o vídeo é repetido, FALSE caso contrario.
*/
bool repetido(Video* v1, Video* v2);

// IMPLEMENTE OS METODOS DA CLASSE

/**
 * Incrementa mais um no atributo 'visualizacoes' se 'tempo' é maior que 30% de 'duracao'
 * @param tempo tempo de video assistido
*/
void Video::assistir(int tempo) {
  if (tempo >= (double) this->duracao * 0.3) this->visualizacoes++;
}

/**
 * Imprime as informações do objeto
*/
void Video::imprimir() {
  cout << "Video: " << this->nome << " - " << this->duracao << " min - " << this->visualizacoes << " visualizacoes" << endl;
}

class Canal {
public:
  string nome;
  Video* v1 = NULL;
  Video* v2 = NULL;
  int quantidade = 0;

  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  bool postar(Video* v);
};

// IMPLEMENTE OS METODOS DA CLASSE

/**
 * Retorna a duração total do canal
 * @return retorna a duração total do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getDuracaoTotal() {
  if (this->quantidade == 1) return this->v1->duracao;
  if (this->quantidade == 2) return this->v1->duracao + this->v2->duracao;
  return 0;
}

/**
 * Retorna o numero total de visualições do canal
 * @return retorna o numero total de visualizações do canal. Se não há vídeos postados, retorna ZERO
*/
int Canal::getTotalDeVisualizacoes() {
  if (this->quantidade == 1) return this->v1->visualizacoes;
  if (this->quantidade == 2) return this->v1->visualizacoes + this->v2->visualizacoes;
  return 0;
}

bool Canal::postar(Video* v) {
  if (this->quantidade == 0) {
    this->v1 = v;
    this->quantidade++;
    return true;
  }

  if (this->quantidade == 1 && !repetido(v, this->v1)) {
    this->v2 = v;
    this->quantidade++;
    return true;
  } 

  return false;
}

bool repetido(Video* v1, Video* v2) {
  if (v1 == v2) return true;
  return false;
}

// IMPLEMENTE A FUNCAO TESTE
void teste () {
  Video *video = new Video;
  video->nome = "1 hour of Wii music";
  video->duracao = 64;
  video->assistir(18);
  video->assistir(2);
  video->assistir(57);

  video->assistir(61);
  video->assistir(43);
  video->imprimir();

  Video *video2 = new Video;
  video2->nome = "bidoofwave";
  video2->duracao = 591;
  video2->assistir(303);
  video2->assistir(109);
  video2->assistir(487);

  Canal *canal = new Canal;
  canal->postar(video);
  canal->postar(video2);

  video2->imprimir();
  cout << "Duração total do canal: " << canal->getDuracaoTotal() << endl;
  cout << "Total de visualizações do canal: " << canal->getTotalDeVisualizacoes() << endl;

}


//* COMENTE O MAIN AO SUBMETER
int main () {
  teste();
  return 0;
}

//*/