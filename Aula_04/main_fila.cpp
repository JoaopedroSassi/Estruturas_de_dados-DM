#include <iostream>
#include "fila.h"

using namespace std;

int main(){
   setlocale(LC_ALL, "Portuguese");

   fila fila1;
   int opcao;
   tipoItem item;

   cout << "Progama de filas ieieiei\n";
   cout << "------------------------\n";
   do
   {
      cout << "0 - Encerrar o programa\n";
      cout << "1 - Inserir um elemento\n";
      cout << "2 - Remover um elemento\n";
      cout << "3 - Imprimir a fila\n";
      cin >> opcao;

      if (opcao == 1){
         cout << "Digite o elemento a ser inserido:";
         cin >> item;
         fila1.push(item);
      } else if (opcao == 2){
         item = fila1.pop();
         cout << "O elemento removido foi " << item << endl;
      } else if (opcao == 3){
         fila1.print();
      } else {
         cout << "Erro | Opção inválida!";
      }
   } while (opcao != 0);

   cout << "Obrigado por utilizar nosso programa :D";


   return 0;
}