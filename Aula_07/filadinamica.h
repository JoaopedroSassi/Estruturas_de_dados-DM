typedef int tipoItem;

struct no
{
   tipoItem valor;
   no *proximo;
};

class filadinamica{
   private:
      no *front;
      no *rear;


   public:
      filadinamica();
      ~filadinamica();
      bool isEmpty();
      bool isFull();
      void push(tipoItem item);
      tipoItem pop();
      void print();
};

