#include <iostream>
#include "grafo.h"

using namespace std;

   Grafo::Grafo(int max, int aresta_nula){
      NumVertices = 0;
      MaxVertices = max;
      ArestaNula = aresta_nula;

      Vertices = new TipoItem[MaxVertices];

      MatrizAdjac = new int*[MaxVertices];
      for (int i = 0; i < MaxVertices; i++){
         MatrizAdjac[i] = new int[MaxVertices];
      }

      for (int i = 0; i < MaxVertices; i++){
         for (int j = 0; j < MaxVertices; j++){
            MatrizAdjac[i][j] = ArestaNula;
         }
      }
   }

   Grafo::~Grafo(){
      delete [] Vertices;
      for (int i = 0; i < MaxVertices; i++){
         delete [] MatrizAdjac[i];
      }
      delete [] MatrizAdjac;
   }

   int Grafo::GetIndice(TipoItem item){
      int indice = 0;
      while (item != Vertices[indice]){
         indice++;
      }
      if (item == Vertices[indice]){
         return indice;
      } else {
         return -1;
      }  
   }

   bool Grafo::IsFull(){
      return (NumVertices == MaxVertices);
   }

   void Grafo::PushVertice(TipoItem item){
      if (IsFull()){
         cout << "O número máximo de vértices foi alcançado!" << endl;
      } else{
         Vertices[NumVertices] = item;
         NumVertices++;
      }
   }

   void Grafo::PushAresta(TipoItem no_saida, TipoItem no_entrada, int peso){
      int linha = GetIndice(no_saida);
      int coluna = GetIndice(no_entrada);
      
      if ((linha == -1) || (coluna == -1)){
         cout << "ERRO | Índice não existente\n";
      } else {
         MatrizAdjac[linha][coluna] = peso;
         MatrizAdjac[coluna][linha] = peso;
      }
   }

   int Grafo::GetPeso(TipoItem no_saida, TipoItem no_entrada){
      int linha = GetIndice(no_saida);
      int coluna = GetIndice(no_entrada);
      
      if ((linha == -1) || (coluna == -1)){
         cout << "ERRO | Índice não existente GetPeso\n";
      } else {
         return (MatrizAdjac[linha][coluna]);
      }
   }

   int Grafo::GetGrau(TipoItem item){
      int linha = GetIndice(item);

      if (linha == -1){
         cout << "ERRO | Índice não existente GetGrau\n";
      } else {
         int grau = 0;
         for (int i = 0; i < MaxVertices; i++){
            if (MatrizAdjac[linha][i] != ArestaNula){
               grau++;
            }
         }

         return grau;
      }
   }

   void Grafo::PrintMatriz(){
      cout << "Matriz de Adjacência:\n";
      for (int i = 0; i < MaxVertices; i++){
         for (int j = 0; j < MaxVertices; j++){
            cout << MatrizAdjac[i][j] << " ";
         }
         cout << endl;
      }
   }

   void Grafo::PrintVertices(){
      cout << "Lista de Vertices:\n";
      for (int i = 0; i < NumVertices; i++){
         cout << i << ": " << Vertices[i] << endl;
      }
   }

