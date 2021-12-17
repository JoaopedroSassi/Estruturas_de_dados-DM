#include <iostream>
#include "hash.h"

using namespace std;

   int Hash::funcaoHash(Aluno aluno)
   {
      return (aluno.obterRa() % max_posicoes);
   }

   Hash::Hash(int tam_vetor, int max)
   {
      quant_itens = 0;
      max_itens = max;
      max_posicoes = tam_vetor;
      estrutura = new Aluno[tam_vetor];
   }

   Hash::~Hash()
   {
      delete [] estrutura;
   }

   bool Hash::estaCheio()
   {
      return (quant_itens == max_itens);
   }

   int Hash::obterTamanho()
   {
      return (quant_itens);
   }

   void Hash::push(Aluno aluno)
   {
      if (estaCheio())
      {
         cout << "A tabela hash está cheia!\n";
      } else 
      {
         int local = funcaoHash(aluno);
         estrutura[local] = aluno;
         quant_itens++;
      }
   }

   void Hash::pop(Aluno aluno)
   {
      int local = funcaoHash(aluno);
      if (estrutura[local].obterRa() != -1)
      {
         estrutura[local] = Aluno(-1, " ");
         quant_itens--;   
      }
   }

   void Hash::search(Aluno &aluno, bool &busca)
   {
      int local = funcaoHash(aluno);
      Aluno aux = estrutura[local];
      if (aluno.obterRa() != aux.obterRa())
      {
         busca = false;
      } else
      {
         busca = true;
         aluno = aux;
      }
   }

   void Hash::print()
   {
      cout << "Tabela hash:\n";
      for (int i = 0; i < max_posicoes; i++)
      {
         if (estrutura[i].obterRa() != -1)
         {
            cout << i << ":" << estrutura[i].obterRa() << "|" << estrutura[i].obterNome();
         }
      }
   }

