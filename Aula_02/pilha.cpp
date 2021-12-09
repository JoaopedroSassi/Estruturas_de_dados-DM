#include <iostream>
#include "pilha.h"

using namespace std;

   pilha::pilha()
   {
      tamanho = 0;
      estrutura = new tipoItem[maxItem];
   }

   pilha::~pilha()
   {
      delete [] estrutura;
   }

   bool pilha::estaCheia()
   {
      return (tamanho == maxItem);
   }

   bool pilha::estaVazia()
   {
      return (tamanho == 0);
   }

   void pilha::push(tipoItem item)
   {
      if (estaCheia()){
         cout << "A pilha está cheia!";
      } else {
         estrutura[tamanho] = item;
         tamanho++;
      }
   }

   tipoItem pilha::pop()
   {
      if (estaVazia()){
         cout << "A pilha está vazia!";
      } else {
         tamanho--;
         return estrutura[tamanho];
      }
   }

   void pilha::print()
   {
      for (int i = 0; i < tamanho; i++)
      {
         cout << estrutura[i] << "|";
      }
      cout << endl;
      
   }

   int pilha::length()
   {
      return tamanho;
   }

