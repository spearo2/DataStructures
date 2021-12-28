#include "LMaxHeap.cpp"

int main()
{
    LMaxHeap* maxheap = new LMaxHeap();
    Element e1, e2;
    
    // Max Heap
    cout << "Max Heap Insert" << endl << endl;
    e1.key = 3; e1.data = "?";
    maxheap->insert(e1);
    e1.key = 1; e1.data = "The";
    maxheap->insert(e1);
    e1.key = 7; e1.data = "Why";
    maxheap->insert(e1);
    e1.key = 4; e1.data = "Not";
    maxheap->insert(e1);
    e1.key = 2; e1.data = "World";
    maxheap->insert(e1);
    

    cout << "Max Heap Print: " << endl;
    maxheap->Print();
    cout << endl << endl;

    cout << "Max Heap Delete: " << endl;
    e2 = maxheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    e2 = maxheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    e2 = maxheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";

    cout << endl << endl;
    
    

    cout << "Max Heap Print: " << endl;
    maxheap->Print();
    cout << endl;
}
