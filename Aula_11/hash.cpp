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
         cout << "A tabela hash est� cheia!\n";
      } else {
         int local = funcaoHash(aluno);
         while (estrutura[local].obterRa() > 0){
            local = (local + 1) % max_posicoes;   
         }
         estrutura[local] = aluno;
         quant_itens++;
      }
   }

   void Hash::pop(Aluno aluno)
   {
      int local = funcaoHash(aluno);
      bool test = false;
      while (estrutura[local].obterRa() != -1){
         if (estrutura[local].obterRa() == aluno.obterRa()){
            cout << "Elemento removido!\n";
            estrutura[local] = Aluno(-2, " ");
            quant_itens--;
            test = true;   
            break;
         }
         local = (local + 1) % max_posicoes;
      }
      if (!test){
         cout << "Elemento n�o encontrado!\n";
      }
      
   }

   void Hash::search(Aluno &aluno, bool &busca)
   {
      int local = funcaoHash(aluno);
      busca = false;
      while (estrutura[local].obterRa() != -1){
         if (estrutura[local].obterRa() == aluno.obterRa()){
            busca = true;
            aluno = estrutura[local];
            break;
         }
         local = (local + 1) % max_posicoes;
      }
   }

   void Hash::print()
   {
      cout << "Tabela hash:\n";
      for (int i = 0; i < max_posicoes; i++)
      {
         if (estrutura[i].obterRa() > 0)
         {
            cout << i << ":" << estrutura[i].obterRa() << "|" << estrutura[i].obterNome();
         }
      }
   }

