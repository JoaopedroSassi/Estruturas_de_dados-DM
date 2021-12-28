#include <iostream>

using namespace std;
typedef string TipoItem;

class Grafo{
   private:
      int ArestaNula;
      int MaxVertices;
      int NumVertices;
      TipoItem *Vertices;
      int **MatrizAdjac;

   public:    
      Grafo(int max, int aresta_nula);
      ~Grafo();
      int GetIndice(TipoItem item);
      bool IsFull();
      void PushVertice(TipoItem item);
      void PushAresta(TipoItem no_saida, TipoItem no_entrada, int peso);
      int GetPeso(TipoItem no_saida, TipoItem no_entrada);
      int GetGrau(TipoItem item);
      void PrintMatriz();
      void PrintVertices();
};