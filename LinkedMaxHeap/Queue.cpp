

typedef tree_node tree_comp;
// Definition of queue node
typedef struct t_queue_node {
    tree_comp *data;
    struct t_queue_node *link;   
} queue_node;


// Definition of Queue class
class Queue {
  private:
    queue_node *front;
    queue_node *rear;

  public:
    Queue();            
    ~Queue();           
    void delete_queue(queue_node *node_ptr); 
    void AddQ(tree_comp *e);
    tree_comp *DeleteQ();
    tree_comp *GetFront();
    bool IsEmpty();
};

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()    // recursive approach
{	
    delete_queue(front);
}

void Queue::delete_queue(queue_node* node_ptr) 
{
    if (node_ptr != NULL) 
    {
        delete_queue(node_ptr->link);
        delete node_ptr; 
    }
}

void Queue::AddQ(tree_comp *e)
{
    queue_node *new_node = new queue_node;

    if (new_node == NULL)
        return;

    new_node->data = e;
    new_node->link = NULL;
    if (front) 
        rear->link = new_node;       
    else 
        front = new_node; // queue is empty
    
    rear = new_node; 
}

tree_comp *Queue::DeleteQ()
{
    tree_comp *e;
    queue_node *del = NULL;
    if (front == NULL)
        return NULL;

    e = front->data;
    del = front;
    front = front->link;
    
    if (front == NULL) 
        rear = NULL; // the only one is deleted
   
    delete del;
    
    return e;
}

tree_comp *Queue::GetFront() 
{
    if (front != NULL)
        return front->data;
    else
        return NULL;
}

bool Queue::IsEmpty() 
{
    return (front == NULL);
}

