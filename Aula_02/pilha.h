typedef int tipoItem;
const int maxItem = 100;

class pilha{
   private:
   int tamanho;
   tipoItem *estrutura;

   public:
   pilha();
   ~pilha();
   bool estaCheia();
   bool estaVazia();
   void push(tipoItem item);
   tipoItem pop();
   void print();
   int length();
};