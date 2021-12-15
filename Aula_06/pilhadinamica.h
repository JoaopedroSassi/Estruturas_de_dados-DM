typedef int tipoItem;

struct node
{
   tipoItem valor;
   node *proximo;
};

class pilhaDinamica{
   private:
   node *noTopo;

   public:
   pilhaDinamica();
   ~pilhaDinamica();
   bool isEmpty();
   bool isFull();
   void push(tipoItem item);
   tipoItem pop();
   void print();

};