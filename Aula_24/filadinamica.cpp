#include <iostream>
#include "filadinamica.h"
#include <cstddef>
#include <new>

using namespace std;

    filadinamica::filadinamica(){
        primeiro = NULL;
        ultimo = NULL;
    }

    filadinamica::~filadinamica(){
        No* temp;
        while (primeiro != NULL){
            temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        }
        ultimo = NULL;
    }

    bool filadinamica::estavazio(){
        return (primeiro == NULL);
    }

    bool filadinamica::estacheio(){
        No* temp;
        try{
            temp = new No;
            delete temp;
            return false;
        } catch(std::bad_alloc exception){
            return true;
        }
    }

    void filadinamica::inserir(TipoItem item){
        if (estacheio()){
            cout << "A Fila esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else{
            No* NoNovo = new No;
            NoNovo->valor = item;
            NoNovo->proximo = NULL;
            if (primeiro == NULL){
                primeiro = NoNovo;
            } else{
                ultimo->proximo = NoNovo;
            }
            ultimo = NoNovo;
        }
    }

    TipoItem filadinamica::remover(){
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nao tem elemento a ser removido!\n";
            return 0;
        } else{
            No* temp = primeiro;
            TipoItem item = primeiro->valor;
            primeiro = primeiro->proximo;
            if (primeiro == NULL){
                ultimo = NULL;
            }
            delete temp;
            return item;
        }
    }

    void filadinamica::imprimir(){
        No* temp = primeiro;
        cout << "Fila= [ ";
        while (temp != NULL){
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << "]\n";
    }