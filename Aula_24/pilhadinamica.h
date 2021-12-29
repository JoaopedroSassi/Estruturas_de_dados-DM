#ifndef PILHADINAMICA_H 
#define PILHADINAMICA_H 

#include "No.h"

class pilhadinamica{
    private:
    No* NoTopo;

    public:
    pilhadinamica(); 
    ~pilhadinamica(); 
    bool estavazio(); 
    bool estacheio(); 
    void inserir(TipoItem item);
    TipoItem remover(); 
    void imprimir(); 
};

#endif
