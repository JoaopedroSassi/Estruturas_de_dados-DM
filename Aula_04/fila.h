typedef int tipoItem;
const int maxItens = 100;

class fila{
   private:
   int first, last;
   tipoItem *vet;
   
   public:
   fila();
   ~fila();
   bool isEmpty();
   bool isFull();
   void push(tipoItem item);
   tipoItem pop();
   void print();
};
