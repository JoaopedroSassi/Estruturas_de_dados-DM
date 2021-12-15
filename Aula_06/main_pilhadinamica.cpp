#include <iostream>
#include "pilhadinamica.h"

using namespace std;

int main(){
   setlocale(LC_ALL, "Portuguese");

   pilhaDinamica pilha1;
   tipoItem item;

   cout << "Pilha pilha pilha:\n";
   cout << "--------------------------\n";
   
   int opcao = 0;
   do
   {
      cout << "0 - Parar o programa\n";
      cout << "1 - Inserir um elemento\n";
      cout << "2 - Remover um elemento\n";
      cout << "3 - Imprimir a pilha\n";
      cin >> opcao;

      if (opcao == 1){
         cout << "Digite o elemento a ser inserido:";
         cin >> item;
         pilha1.push(item);
      } else if (opcao == 2){
         item = pilha1.pop();
         cout << "Elemento removido: " << item << endl;
      } else if (opcao == 3){
         pilha1.print();
      } 
   } while (opcao != 0);

   return 0;
}