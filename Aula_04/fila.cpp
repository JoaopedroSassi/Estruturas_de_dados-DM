#include <iostream>
#include "fila.h"

using namespace std;

   fila::fila(){
      first = 0;
      last = 0;
      vet = new tipoItem[maxItens];
   }

   fila::~fila(){
      delete [] vet;
   }

   bool fila::isEmpty(){
      if (first == last){
         return true;
      } else {
         return false;
      }
      
   }

   bool fila::isFull(){
      if (last - first == maxItens){
         return true;
      } else {
         return false;
      }
   }

   void fila::push(tipoItem item){
      if (isFull()){
         cout << "A fila está cheia!\n";
         cout << "Esse elemento não pode ser inserido";
      } else {
         vet[last % maxItens] = item; 
         last++;
      }
   }

   tipoItem fila::pop(){
      if (isEmpty()){
         cout << "A fila esta vazia!\n";
         cout << "Nenhum elemento foi removido!\n";
         return 0;
      } else{
         first++;            
         return vet[(first-1) % maxItens];
      }
   }

   void fila::print(){
      cout << "Fila:";
      for (int i = first; i < last; i++){
         cout << vet[i % maxItens] << " | ";
      }
      cout << endl;
   }
