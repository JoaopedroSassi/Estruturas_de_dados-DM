#include <iostream>
#include "hash.h"

using namespace std;

int main(){
   cout << "Programa gerador de hash!\n";

   cout << "Digite o tamanho da hash:";
   int tam_vet;
   cin >> tam_vet;

   cout << "Digite o número máximo de elementos:";
   int max;
   cin >> max;

   cout << "Fator de carga: " << float(max) / float(tam_vet) << endl;

   Hash alunoHash(tam_vet, max);

   int ra = 0, opcao = 0;
   string nome;
   bool busca;

   do
   {
      cout << "0 - Parar o algoritmo\n";
      cout << "1 - Inserir um elemento\n";
      cout << "2 - Remover um elemento\n";
      cout << "3 - Buscar um elemento\n";
      cout << "4 - Imprimir a hash\n";
      cin >> opcao;

      if (opcao == 1){
         cout << "Digite o RA do aluno:";
         cin >> ra;
         cout << "Digite o nome do aluno:";
         cin >> nome;
         Aluno aluno(ra, nome);
         alunoHash.push(aluno);
      } else if (opcao == 2){
         cout << "Digite o RA a ser inserido:";
         cin >> ra;
         Aluno aluno(ra, " ");
         alunoHash.pop(aluno);
      } else if (opcao == 3){
         cout << "Digite o RA a ser buscado:";
         cin >> ra;
         Aluno aluno(ra, " ");
         alunoHash.search(aluno, busca);
         if (busca){
            cout << "Aluno encontrado!\n";
            cout << "RA: " << aluno.obterRa() << endl;
            cout << "Nome:" << aluno.obterNome() << endl;
         } else {
            cout << "ERRO | Aluno não encontrado!";
         }
      } else if (opcao == 4){
         alunoHash.print();
      }
   } while (opcao != 0);
   
   return 0;
}