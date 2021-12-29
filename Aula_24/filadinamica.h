#ifndef FILADINAMICA_H 
#define FILADINAMICA_H 

#include "No.h"


class filadinamica{ 
  private:
  No* primeiro; 
  No* ultimo; 

  public:
  filadinamica(); 
  ~filadinamica(); 
  bool estavazio();
  bool estacheio(); 
  void inserir(TipoItem item); 
  TipoItem remover(); 
  void imprimir(); 
  
};

#endif
