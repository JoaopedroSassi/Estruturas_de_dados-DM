#include <iostream>
#include "grafo.h"

using namespace std;

int main(){
   setlocale(LC_ALL, "Portuguese");

   int max, valor_aresta_nula;

   cout << "Digite a quantidade m�xima de v�rtices:\n";
   cin >> max;
   cout << "Digite o valor para representar a ausencia de aresta:\n";
   cin >> valor_aresta_nula;

   Grafo grafo(max, valor_aresta_nula);
   TipoItem item1, item2;
   int opcao, valor, peso;
   
   do{

      cout << "Matriz de Adjasc�ncia\n";
      cout << "---------------------------\n";
      cout << "0 - Parar o algoritmo\n";
      cout << "1 - Inserir v�rtice\n";
      cout << "2 - Inserir uma aresta\n";
      cout << "3 - Imprimir o grau de um v�rtice\n";
      cout << "4 - Imprimir o peso de uma aresta\n";
      cout << "5 - Imprimir a matriz de adjac�ncias\n";
      cout << "6 - Imprimir a lista de v�rtices\n";
      cin >> opcao;

      if (opcao == 1){
         cout << "Digite o elemento do v�rtice que sera inserido:";
         cin >> item1;
         grafo.PushVertice(item1);
      } else if (opcao == 2){
         cout << "Digite o v�rtice de saida:\n";
         cin >> item1;
         cout << "Digite o v�rtice de entrada:\n";
         cin >> item2;
         cout << "Digite o peso da aresta:\n";
         cin >> peso;
         grafo.PushAresta(item1, item2, peso);
      } else if (opcao == 3){
         cout << "Digite o v�rtice que ser� calculado o grau:\n";
         cin >> item1;
         valor = grafo.GetGrau(item1);
         if (valor != -1){
            cout << "O grau desse v�rtice �: " << valor << endl;
         }
      } else if (opcao == 4){
         cout << "Digite o v�rtice de saida:\n";
         cin >> item1;
         cout << "Digite o v�rtice de entrada:\n";
         cin >> item2;
         valor = grafo.GetPeso(item1, item2);
         if (valor != -1){
            cout << "O peso dessa aresta �: " << valor << endl;
         }
      } else if (opcao == 5){
         grafo.PrintMatriz();
      } else if (opcao == 6){
         grafo.PrintVertices();
      }
   } while (opcao != 0);

   return 0;
}