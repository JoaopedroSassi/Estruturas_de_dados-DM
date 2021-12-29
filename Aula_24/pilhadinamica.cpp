#include <iostream>
#include "pilhadinamica.h"
#include <new>
#include <cstddef> 

using namespace std;

    pilhadinamica::pilhadinamica()
    {
        NoTopo = NULL;
    }

    pilhadinamica::~pilhadinamica() 
    {
        No* NoTemp;
        while (NoTopo != NULL){
            NoTemp = NoTopo;
            NoTopo = NoTopo->proximo;
            delete NoTemp;
        }
    }

    bool pilhadinamica::estavazio() 
    {
        return (NoTopo == NULL);
    }

    bool pilhadinamica::estacheio()
    {
        No* NoNovo;
        try{
            NoNovo = new No;
            delete NoNovo;
            return false;
        } catch(std::bad_alloc exception){
            return true;
        }
    }

    void pilhadinamica::inserir(TipoItem item)
    {
        if (estacheio()){
            cout << "A Pilha esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else{
            No* NoNovo = new No;
            NoNovo->valor = item;
            NoNovo->proximo = NoTopo;
            NoTopo = NoNovo;
        }
    }

    TipoItem pilhadinamica::remover()
    {
        if (estavazio()){
            cout << "A Pilha esta vazia!\n";
            cout << "Nao foi possivel remover nenhum elemento!\n";
            return 0;
        } else{
            No* NoTemp;
            NoTemp = NoTopo;
            TipoItem item = NoTopo->valor;
            NoTopo = NoTopo->proximo;
            delete NoTemp;
            return item;
        }
    }

    void pilhadinamica::imprimir() 
    {
        No* NoTemp = NoTopo;
        cout << "Pilha: [ ";
        while (NoTemp != NULL){
            cout << NoTemp->valor << " ";
            NoTemp = NoTemp->proximo;
        }
        cout << "]\n";
    }
