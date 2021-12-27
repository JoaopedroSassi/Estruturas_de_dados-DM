#include "aluno.h"
using namespace std;

   Aluno::Aluno(){
      ra = -1;
      nome = " ";
   }

   Aluno::Aluno(int r, std::string n){
      ra = r;
      nome = n;
   }

   string Aluno::getNome(){
      return nome;
   }

   int Aluno::getRa(){
      return ra;
   }
