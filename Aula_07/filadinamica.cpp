#include <iostream>
#include <cstddef>
#include <new>
#include "filadinamica.h"

using namespace std;

   filadinamica::filadinamica()
   {
      front = NULL;
      rear = NULL;
   }

   filadinamica::~filadinamica()
   {
      no *tmp;
      while (front != NULL)
      {
         tmp = front;
         front = front->proximo;
         delete tmp;   
      }
      rear = NULL;
   }

   bool filadinamica::isEmpty()
   {
      return (front == NULL);
   }

   bool filadinamica::isFull()
   {
      no *tmp;
      try
      {
         tmp = new no;
         delete tmp;
         return false;
      }
      catch(bad_alloc exception)
      {
         return true;         
      }
   }

   void filadinamica::push(tipoItem item)
   {
      if (isFull())
      {
         cout << "A fila está cehia! \n";
      } else
      {
         no *NoNovo = new no;
         NoNovo->valor = item;
         NoNovo->proximo = NULL;

         if (front == NULL)
         {
            front = NoNovo;
         } else
         {
            rear->proximo = NoNovo;
         }
         rear = NoNovo;
      }
   }

   tipoItem filadinamica::pop()
   {
      if (isEmpty())
      {
         cout << "A fila está vazia!\n";
         return 0;
      } else
      {
         no *tmp = front;
         tipoItem item = front->valor;
         front = front->proximo;
         if (front == NULL)
         {
            rear = NULL;
         }
         delete tmp;
         return item;
      }
   }

   void filadinamica::print()
   {
      no *tmp = front;
      while (tmp != NULL)
      {
         cout << tmp->valor << "|";
         tmp = tmp->proximo;
      }
      cout << endl;
   }
