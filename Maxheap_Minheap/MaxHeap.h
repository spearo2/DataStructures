typedef struct {
    int key;
    string data;
} Element;

#define MAX_SIZE 30

  // TODO: Define the MaxHeap class
  class MaxHeap{
    private:
        Element heap[MAX_SIZE];
        int index;

    public:
        MaxHeap(){index = 0;};
        ~MaxHeap(){index = 0;};
        bool isEmpty() {return (index == 0);};
        bool isFull() {return (index == MAX_SIZE-1);};
        void swap(Element *a, Element *b);
        void insert(Element item);
        Element deletion ();
        void Print();

};

