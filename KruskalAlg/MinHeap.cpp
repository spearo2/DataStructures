// Element takes information of an edge
typedef struct {
    int src;
    int dest;
    int weight;
} Element;

#define MAX_SIZE 30

class MinHeap{
  // TODO: Define the MinHeap class
    private:
        Element heap[MAX_SIZE];
        int index;

    public:
        MinHeap(){index = 0;};
        ~MinHeap(){index = 0;};
        bool isEmpty() {return (index == 0);};
        bool isFull() {return (index == MAX_SIZE-1);};
        void swap(Element *a, Element *b);
        void insert(Element item);
        Element deletion ();
        void Print();
        void Clear();
};


// TODO: implement the member functions of MinHeap class
void MinHeap::swap(Element *a, Element *b)
{
    Element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeap::insert(Element item)
{
    if(isFull())
    {
        cout<<"The Heap is Full" << endl;
        return;
    }

    int i = ++index;
    
    while ((i != 1) && (item.weight < heap[i/2].weight))
    {
        
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;

}

Element MinHeap::deletion()
{
    int parent, larger;
    Element item = heap[1];
    heap[1] = heap[index--];
    parent = 1;
    while (parent*2 <= index)
    {
        if(parent*2+1 <= index)
        {
            if(heap[parent*2].weight < heap[parent*2+1].weight)
            {
                larger = parent*2;
            }
        
            else
            {
                larger = parent*2+1;
            }
        }
        else
        {
            larger = parent*2;
        }
        if(heap[parent].weight <= heap[larger].weight)
            break;
        swap(&heap[parent], &heap[larger]);
        parent = larger;
    }
    return item;
}

void MinHeap::Clear()
{
    while(index!=0)
    {
        deletion();
    }
   
}
 void MinHeap::Print()
 {
    
     for(int i = 1; i<index+1;i++)
     {
         cout<<"["<<heap[i].src<<" -> "<<heap[i].dest<<", "<<heap[i].weight<<"]";
     }
 }
