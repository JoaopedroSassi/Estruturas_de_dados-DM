#include <iostream>
#include <cstddef>
#include "arvorebinaria.h"

using namespace std;

   BST::BST(){
      raiz = NULL;
   }

   BST::~BST(){
      popTree(raiz);
   }

   void BST::popTree(No *noAtual){
      if (noAtual != NULL){
         popTree(noAtual->esquerda);
         popTree(noAtual->direita);
         delete noAtual;
      }
   }

   No *BST::getRaiz(){
      return raiz;
   }

   bool BST::isEmpty(){
      return (raiz == NULL);
   }

   bool BST::isFull(){
      try{
         No *tmp = new No;
         delete tmp;
         return false;
      } catch(bad_alloc exception){
         return true;
      }
   }

   void BST::push(Aluno item){
      if (isFull()){
         cout << "A arvore está cheia!";
      } else{
         No *noNovo = new No;
         noNovo->aluno = item;
         noNovo->direita = NULL;
         noNovo->esquerda = NULL;
         if (raiz == NULL){
            raiz = noNovo;
         } else {
            No *tmp = raiz;
            while (tmp != NULL){
               if (item.getRa() < tmp->aluno.getRa()){
                  if (tmp->esquerda == NULL){
                     tmp->esquerda = noNovo;
                     break;
                  } else {
                     tmp = tmp->esquerda;
                  }
               } else {
                  if (tmp->direita == NULL){
                     tmp->direita = noNovo;
                     break;
                  } else {
                     tmp = tmp->direita;
                  }
               }
            }
         }
      }
   }

   void BST::pop(Aluno item){
      removerBusca(item, raiz);
   }

   void BST::removerBusca(Aluno item, No *&noAtual){
      if (item.getRa() < noAtual->aluno.getRa()){
         removerBusca(item, noAtual->esquerda);
      } else if (item.getRa() > noAtual->aluno.getRa()){
         removerBusca(item, noAtual->direita);
      } else {
         deletarNo(noAtual);
      }
   }

   void BST::deletarNo(No *&noAtual){
      No *tmp = noAtual;
      if (noAtual->esquerda == NULL){
         noAtual = noAtual->direita;
         delete tmp;
      } else if (noAtual->direita == NULL){
         noAtual = noAtual->esquerda;
         delete tmp;
      } else {
         Aluno sucessor;
         getSucessor(sucessor, noAtual);
         noAtual->aluno = sucessor;
         removerBusca(sucessor, noAtual->direita);
      }
   }

   void BST::getSucessor(Aluno &sucessor, No *tmp){
      tmp = tmp->direita;
      while (tmp->esquerda != NULL){
         tmp = tmp->esquerda;
      }
      sucessor = tmp->aluno;
   }

   void BST::search(Aluno &item, bool &busca){
      busca = false;
      No *noAtual = raiz;
      while (noAtual != NULL){
         if (item.getRa() < noAtual->aluno.getRa()){
            noAtual = noAtual->esquerda;
         } else if (item.getRa() > noAtual->aluno.getRa()){
            noAtual = noAtual->direita;
         } else {
            busca = true;
            item = noAtual->aluno;
            break;
         }
      }
   }

   void BST::printPreOrdem(No *noAtual){
      if (noAtual != NULL){
         cout << noAtual->aluno.getNome() << ":";
         cout << noAtual->aluno.getRa() << endl;

         printPreOrdem(noAtual->esquerda);
         printPreOrdem(noAtual->direita);
      }
   }

   void BST::printEmOrdem(No *noAtual){
      if (noAtual != NULL){
         printEmOrdem(noAtual->esquerda);

         cout << noAtual->aluno.getNome() << ":";
         cout << noAtual->aluno.getRa() << endl;

         printEmOrdem(noAtual->direita);
      }
   }

   void BST::printPosOrdem(No *noAtual){
      if (noAtual != NULL){
         printPosOrdem(noAtual->esquerda);

         printPosOrdem(noAtual->direita);

         cout << noAtual->aluno.getNome() << ":";
         cout << noAtual->aluno.getRa() << endl;
      }
   }
