#include "aluno.h"

class Hash
{
   private:
   int funcaoHash(Aluno aluno);
   int max_itens;
   int max_posicoes;
   int quant_itens;
   Aluno *estrutura;
   
   public:
      Hash(int tam_vetor, int max);
      ~Hash();
      bool estaCheio();
      int obterTamanho();
      void push(Aluno aluno);
      void pop(Aluno aluno);
      void search(Aluno &aluno, bool &busca);
      void print();
};
