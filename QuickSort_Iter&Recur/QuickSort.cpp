#include <iostream>
#include <iomanip>
using namespace std; 
#include "stack.cpp"


#define MAX_SIZE 100

typedef struct {
    int key;

} Element;

class Sort {
  private: 
    Element *list;
    int num;         
    int cur;                        

    void swap(Element *e1, Element *e2);
    void QuickSort(int left, int right);
    void QuickSort_Iter( int left, int right);
    

  public: 
    Sort();
    void InsertElement(Element e);
    void QuickSort();
    void Print(int i);
}; 


Sort::Sort() 
{
    list = new Element[MAX_SIZE];
    num = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list[i].key = -1;
    }
}


void Sort::InsertElement(Element e)
{
    list[num] = e;
    num++; 
}
//Swaping function
void Sort::swap(Element *e1, Element *e2)
{
    Element temp; 

    temp = *e1; 
    *e1 = *e2;
    *e2 = temp;    
}
// Printing function
void Sort::Print(int i)
{
    if (i < 0)
        cout << "[Init]: ";
    else    
        cout << "[" << setw(4) << i << "]: ";

    for (int i = 0; i < num; i++)
        cout << setw(3) << list[i].key << "  ";
    cout << endl;
}



//Quick sort title
void Sort::QuickSort()
{
    cout << "Quick Sort" << endl;
    Print(-1);
    cur = 0; 
    
    QuickSort_Iter(0,num-1);
    //QuickSort(0, num-1);

    
}

//Recursive version
void Sort::QuickSort(int left, int right) 
{
    int pivot, i, j;
    if(left < right)
    {
        i = left;
        j = right+1;
        pivot = list[left].key;
        do {
            do i++; while(i <= right && list[i].key < pivot);
            do j--; while(j > left && list[j].key > pivot);
            if (i<j)
                swap(&list[i], &list[j]);
            } while (i<j);
            swap(&list[left], &list[j]);
            Print(cur++);

            QuickSort(left, j-1);
            QuickSort(j+1, right);
    }
}
//Iterative version
void Sort::QuickSort_Iter(int l, int r)
{
    int left = l;
    int right = r;
    int middle;
    int i, j, pivot, p;
    int counter = 0;
    Stack* stack = new Stack();
    stack->Push(l);
    stack->Push(r);
    while(left<right)
    {
        if (counter ==0)
        {
            j = stack->Pop()+1;
            i = stack->Pop();
            left = i;
            right = j-1;
            middle = (left+right)/2;
        }
        
        pivot = max(min(list[left].key,list[middle].key),min(max(list[left].key,list[middle].key),list[right].key));
        if(list[left].key == pivot)
            p = left;
        else if(list[middle].key == pivot)
            p = middle;
        else
            p = right;
        swap(&list[p],&list[left]);
        pivot = list[left].key;
        
        do {
            do i++; while((i <= right && list[i].key < pivot));
            do j--; while((j > left && list[j].key > pivot));
            if (i<j)
                swap(&list[i], &list[j]);
            } while (i<j);
            swap(&list[left], &list[j]);
            Print(cur++);
        
        if(j + 1 < right)
        {
            stack->Push(j+1);
            stack->Push(right);
        }
        
        if(j - 1 > left)
        {
            stack->Push(left);
            stack->Push(j - 1);
        }
        
        j = stack->Pop()+1;
        
        i = stack->Pop();
        
        left = i;
        right = j-1;
        middle = (left+right)/2;
        counter++;
    }
}
