#include <iostream>
#include "aluno.h"

struct No{
   Aluno aluno;
   No *esquerda;
   No *direita;
};

class BST{
   private:
   No *raiz;

   public:
   BST();
   ~BST();
   void popTree(No *noAtual);
   No *getRaiz();
   bool isEmpty();
   bool isFull();
   void push(Aluno item);
   void pop(Aluno item);
   void removerBusca(Aluno item, No *&noAtual);
   void deletarNo(No *&noAtual);
   void getSucessor(Aluno &sucessor, No *tmp);
   void search(Aluno &item, bool &busca);
   void printPreOrdem(No *noAtual);
   void printEmOrdem(No *noAtual);
   void printPosOrdem(No *noAtual);
};
