#include <iostream>
#include "aluno.h"

struct No{
   Aluno aluno;
   No *esquerda;
   No *direita;
   int fatorB;
};

class ArvoreAVL{
   private:
   No *raiz;

   public:
   ArvoreAVL();
   ~ArvoreAVL();
   void popTree(No *noAtual);
   No *getRaiz();
   bool isEmpty();
   bool isFull();
   void push(Aluno item);
   void pop(Aluno item);
   void removerBusca(Aluno item, No *&noAtual, bool &diminuiu);
   void deletarNo(No *&noAtual, bool &diminuiu);
   void getSucessor(Aluno &sucessor, No *tmp);
   void search(Aluno &item, bool &busca);
   void printPreOrdem(No *noAtual);
   void printEmOrdem(No *noAtual);
   void printPosOrdem(No *noAtual);

   void rotacaoDireita(No *&tree);
   void rotacaoEsquerda(No *&tree);
   void rotacaoEsquerdaDireita(No *&tree);
   void rotacaoDireitaEsquerda(No *&tree);
   void realizarRotacao(No *&tree);
   void insereRecursivo(No *&noAtual, Aluno item, bool &cresceu);
};
