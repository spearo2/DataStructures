#include <iostream>
using namespace std;

typedef struct node{
    int key;
    string data;
    struct node *parent, *left_child, *right_child;
} tree_node;

typedef struct {
    int key;
    string data;
} Element;

#include "Queue.cpp"

  // TODO: Define the MaxHeap class
  class LMaxHeap{
    private:
        tree_node *root;
        int maxidx;

    public:
        LMaxHeap();
        ~LMaxHeap();
        bool isEmpty() {return (root == NULL);};
        void insert(Element item);
        Element deletion ();
        void Print();
        tree_node* find_parent(int index);
        tree_node* find_node(int index);

};

