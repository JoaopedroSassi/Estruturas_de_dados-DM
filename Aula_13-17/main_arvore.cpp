#include <iostream>
#include "arvorebinaria.h"

using namespace std;

int main(){
   BST arvoreAlunos;
   int opcao, ra, imp;
   string nome;
   bool busca = false;

   do{
      cout << "ARVORE BINARIA DE BUSCA" << endl;
      cout << "-------------------------------" << endl; 
      cout << "0 - Parar o algoritmo\n";
      cout << "1 - Inserir um elemento\n";
      cout << "2 - Remover um elemento\n";
      cout << "3 - Buscar um elemento\n";
      cout << "4 - Imprimir a arvore\n";
      cin >> opcao;

      if (opcao == 1){
         cout << "Digite o nome do aluno:";
         cin >> nome;
         cout << "Digite o RA do aluno:";
         cin >> ra;
         Aluno student(ra, nome);
         if (arvoreAlunos.isFull()){
            cout << "A arovre esta cheia!";
         } else {
           arvoreAlunos.push(student); 
         } 
      } else if (opcao == 2){
         cout << "Digite o RA do aluno a ser removido:";
         cin >> ra;
         Aluno student(ra, " ");
         arvoreAlunos.pop(student);
      } else if (opcao == 3){
         cout << "Digite o RA do aluno a ser buscado:";
         cin >> ra;
         Aluno student(ra, " ");
         arvoreAlunos.search(student, busca);
         if (busca){
            cout << "Aluno encontrado!" << endl;
            cout << "Nome: " << student.getNome() << endl;
            cout << "RA: " << student.getRa() << endl;
         } else{
            cout << "Aluno não encontrado!\n";
         }
      } else if(opcao == 4){
         cout << "1 - Pre ordem\n";
         cout << "2 - Em ordem!\n";
         cout << "3 - Pos ordem\n";
         cin >> imp;
         if (imp == 1){
            arvoreAlunos.printPreOrdem(arvoreAlunos.getRaiz());
         } else if (imp == 2){
            arvoreAlunos.printEmOrdem(arvoreAlunos.getRaiz());
         } else if (imp == 3){
            arvoreAlunos.printPosOrdem(arvoreAlunos.getRaiz());
         } else {
            cout << "ERRO | Opcao invalida" << endl;
         } 
      }
   } while (opcao != 0);
}