#include <iostream>
#include <cstddef>
#include "arvoreAVL.h"

using namespace std;

   ArvoreAVL::ArvoreAVL(){
      raiz = NULL;
   }

   ArvoreAVL::~ArvoreAVL(){
      popTree(raiz);
   }

   void ArvoreAVL::popTree(No *noAtual){
      if (noAtual != NULL){
         popTree(noAtual->esquerda);
         popTree(noAtual->direita);
         delete noAtual;
      }
   }

   No *ArvoreAVL::getRaiz(){
      return raiz;
   }

   bool ArvoreAVL::isEmpty(){
      return (raiz == NULL);
   }

   bool ArvoreAVL::isFull(){
      try{
         No *tmp = new No;
         delete tmp;
         return false;
      } catch(bad_alloc exception){
         return true;
      }
   }

   void ArvoreAVL::push(Aluno item){
      bool cresceu;
      insereRecursivo(raiz, item, cresceu);
   }

   void ArvoreAVL::insereRecursivo(No *&noAtual, Aluno item, bool &cresceu){
      if (noAtual == NULL) {
            noAtual = new No;
            noAtual->direita = NULL;
            noAtual->esquerda = NULL;
            noAtual->aluno = item;
            noAtual->fatorB = 0;
            cresceu = true;
            return;
         }  
         if (item.getRa() < noAtual->aluno.getRa()) {
            insereRecursivo(noAtual->esquerda, item, cresceu);
            if (cresceu){
                  noAtual->fatorB-=1;   
            } 
         } else {
            insereRecursivo(noAtual->direita, item, cresceu);
            if (cresceu){
                  noAtual->fatorB+=1;
            }    
         } 

         realizarRotacao(noAtual);

         if (cresceu && noAtual->fatorB == 0){
            cresceu = false;
         }
   }

   void ArvoreAVL::pop(Aluno item){
      bool diminuiu;
      removerBusca(item, raiz, diminuiu);
   }

   void ArvoreAVL::removerBusca(Aluno item, No *&noAtual, bool& diminuiu){
      if (item.getRa() < noAtual->aluno.getRa()){
         removerBusca(item, noAtual->esquerda, diminuiu);
         if (diminuiu){
            noAtual->fatorB+=1;
         }
      } else if (item.getRa() > noAtual->aluno.getRa()){
         removerBusca(item, noAtual->direita, diminuiu);
         if (diminuiu){
            noAtual->fatorB-=1;
         }
      } else{
         deletarNo(noAtual, diminuiu);
      }
      if (noAtual != NULL){
         realizarRotacao(noAtual);
         if (diminuiu && noAtual->fatorB != 0){
            diminuiu = false;
         }
      }
   }

   void ArvoreAVL::deletarNo(No *&noAtual, bool& diminuiu){
      No* temp = noAtual;
      if (noAtual->esquerda == NULL){
         noAtual = noAtual->direita;
         diminuiu = true;
         delete temp;
      } else if (noAtual->direita == NULL){
         noAtual = noAtual->esquerda;
         diminuiu = true;
         delete temp;
      } else{
         Aluno AlunoSucessor;
         getSucessor(AlunoSucessor, noAtual);
         noAtual->aluno = AlunoSucessor;
         removerBusca(AlunoSucessor, noAtual->direita, diminuiu);
         if (diminuiu){
            noAtual->fatorB-=1;
         }
      }
   }

   void ArvoreAVL::getSucessor(Aluno &sucessor, No *tmp){
      tmp = tmp->direita;
      while (tmp->esquerda != NULL){
         tmp = tmp->esquerda;
      }
      sucessor = tmp->aluno;
   }

   void ArvoreAVL::search(Aluno &item, bool &busca){
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

   void ArvoreAVL::printPreOrdem(No *noAtual){
      if (noAtual != NULL){
         cout << noAtual->aluno.getNome() << ":";
         cout << noAtual->aluno.getRa() << endl;

         printPreOrdem(noAtual->esquerda);
         printPreOrdem(noAtual->direita);
      }
   }

   void ArvoreAVL::printEmOrdem(No *noAtual){
      if (noAtual != NULL){
         printEmOrdem(noAtual->esquerda);

         cout << noAtual->aluno.getNome() << ":";
         cout << noAtual->aluno.getRa() << endl;

         printEmOrdem(noAtual->direita);
      }
   }

   void ArvoreAVL::printPosOrdem(No *noAtual){
      if (noAtual != NULL){
         printPosOrdem(noAtual->esquerda);

         printPosOrdem(noAtual->direita);

         cout << noAtual->aluno.getNome() << ":";
         cout << noAtual->aluno.getRa() << endl;
      }
   }



   void ArvoreAVL::rotacaoDireita(No *&pai){
      No *novoPai = pai->esquerda;
      pai->esquerda = novoPai->esquerda;
      novoPai->direita = pai;
      pai = novoPai;
   }

   void ArvoreAVL::rotacaoEsquerda(No *&pai){
      No *novoPai = pai->direita;
      pai->direita = novoPai->esquerda;
      novoPai->esquerda = pai;
      pai = novoPai;
   }

   void ArvoreAVL::rotacaoEsquerdaDireita(No *&pai){
      No *filho = pai->esquerda;
      rotacaoEsquerda(filho);
      pai->esquerda = filho;
      rotacaoDireita(pai);
   }


   void ArvoreAVL::rotacaoDireitaEsquerda(No *&pai){
      No *filho = pai->direita;
      rotacaoDireita(filho);
      pai->direita = filho;
      rotacaoEsquerda(pai);
   }


   void ArvoreAVL::realizarRotacao(No *&pai){
      No *filho;
      No *neto; 

      if (pai->fatorB == -2){ 
         filho = pai->esquerda;

         if (filho->fatorB == -1){ 
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaoDireita(pai);
         } else if (filho->fatorB == 0){ 
            pai->fatorB = -1;
            filho->fatorB = 1;
            rotacaoDireita(pai);
         } else if (filho->fatorB == 1){ 
            neto = filho->direita;
            if (neto->fatorB == -1){
               pai->fatorB = 1;
               filho->fatorB = 0;
            } else if (neto->fatorB == 0){
               pai->fatorB = 0;
               filho->fatorB = 0;                
            } else if (neto->fatorB == 1){
               pai->fatorB = 0;
               filho->fatorB = -1;                
            }
            neto->fatorB = 0; 
            rotacaoDireitaEsquerda(pai);  
         } 
      }else if(pai->fatorB == 2){ 
         filho = pai->direita;
         if (filho->fatorB == 1) { 
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaoEsquerda(pai);
         } else if (filho->fatorB == 0){      
            pai->fatorB = 1;
            filho->fatorB = -1;
            rotacaoEsquerda(pai);
         } else if (filho->fatorB == -1){ 
            neto = filho->esquerda;
            if (neto->fatorB == -1){
               pai->fatorB =  0;
               filho->fatorB = 1; 
            } else if (neto->fatorB == 0){
               pai->fatorB =  0;
               filho->fatorB = 0; 
            } else if (neto->fatorB == 1){
               pai->fatorB =  -1;
               filho->fatorB = 0; 
            }
            neto->fatorB = 0;
            rotacaoDireitaEsquerda(pai);
         }
      }

   }  
   