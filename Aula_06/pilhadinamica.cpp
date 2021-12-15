#include <iostream>
#include <cstddef>
#include "pilhadinamica.h"

using namespace std;

   pilhaDinamica::pilhaDinamica()
   {
      noTopo = NULL;
   }

   pilhaDinamica::~pilhaDinamica()
   {
      node *noTemp;
      while (noTemp != NULL)
      {
         noTemp = noTopo;
         noTopo = noTopo->proximo;
         delete noTemp;
      }
   }

   bool pilhaDinamica::isEmpty()
   {
      return (noTopo == NULL);
   }

   bool pilhaDinamica::isFull()
   {
      node *noNovo;
      try
      {
         noNovo = new node;
         delete noNovo;
         return false;
      }
      catch(bad_alloc exception)
      {
         return true;
      }
   }

   void pilhaDinamica::push(tipoItem item)
   {
      if (isFull())
      {
         cout << "A pilha está cheia!" << endl;
      } else {
         node *noNovo = new node;
         noNovo->valor = item;
         noNovo->proximo = noTopo;
         noTopo = noNovo;
      }
   }

   tipoItem pilhaDinamica::pop()
   {
      if (isEmpty())
      {
         cout << "A pilha está vazia!\n";
         return 0;
      } else{
         node *noTemp = noTopo;
         tipoItem item = noTopo->valor;
         noTopo = noTopo->proximo;
         delete noTemp;
         return item;
      }
   }

   void pilhaDinamica::print()
   {
      node *noTemp = noTopo;
      while (noTemp != NULL)
      {
         cout << noTemp->valor << "|";
         noTemp = noTemp->proximo;
      }
      cout << endl;
   }


