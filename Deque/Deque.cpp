#include <iostream>
#include <cstring>

using namespace std;

typedef struct t_list_node {
    char data[10];
    struct t_list_node *llink, *rlink;   
} list_node;


// Definition of Deque
class Deque
{
  private:
    list_node *front, *rear;
    int length;
 
  public:
    Deque();            
    ~Deque();   
    void delete_deque(list_node *node_ptr); // for ~Deque()
    void InsertFront(const char *data);
    void InsertRear(const char *data);
    void DeleteFront();
    void DeleteRear();
    int  GetLength();
    bool IsEmpty();
    void PrintFromFront();
    void PrintFromRear();
};

Deque::Deque()
{
    front = rear = NULL;
    length = 0;
}
 
Deque::~Deque()    // recursive approach
{	
    delete_deque(front);
}

// Delete Deque 
void Deque::delete_deque(list_node* node_ptr) 
{
    if (node_ptr != NULL) 
    {
        delete_deque(node_ptr->rlink);
        delete node_ptr; 
    }
}

// TODO: InsertFront() - Insert a new node at front end
// TODO: InsertRear() - Insert a new node at rear end
// TODO: DeleteFront() - Delete a node at front end
// TODO: DeleteRear() - Delete a node at rear end
// TODO: GetLength() - Return the number of nodes in deque
// TODO: IsEmpty() - Return true if deque is empty. Otherwise return false.
// TOOD: PrintFromFront() - Print all data start from front end
// TODO: PrintFromRear() - Print all data start from rear end
void Deque::InsertFront(const char *data)
{
    list_node *new_node = new list_node;

    if(new_node == NULL)
    {
        return;
    }

    strcpy(new_node->data,data);
    if(front == NULL)
    {
        rear = new_node;
        front = new_node;
    }
    else
    {
        new_node->llink = NULL;
        new_node->rlink = front;
        front->llink = new_node;

        front = new_node;
    }

}
void Deque::InsertRear(const char *data)
{
    list_node *new_node = new list_node;
    if(new_node == NULL)
    {
        return;
    }

    strcpy(new_node->data,data);
    if(rear == NULL)
    {
        rear = new_node;
        front = new_node;
    }
    else
    {
        new_node->rlink = NULL;
        new_node->llink = rear;
        rear->rlink = new_node;

        rear = new_node;
    }
    
}
void Deque::DeleteFront()
{
    if(IsEmpty())
    {
        return;
    }
    else
    {
        list_node *del = NULL;
        del = front;
        front->rlink->llink = NULL;
        front = front->rlink;
        delete del;
    } 
}
void Deque::DeleteRear()
{
    if(IsEmpty())
    {
        return;
    }
    else
    {
        list_node *del = NULL;
        del = rear;
        rear->llink->rlink = NULL;
        rear = rear->llink;
        delete del;
    } 
}
int Deque::GetLength()
{
    int count;
    list_node *cur = NULL;
        for(cur = front; cur!=NULL; cur = cur->rlink)
        {
            count++;
        }
        return count;
            
}
bool Deque::IsEmpty()
{
    if(front == rear)
                return true;
            else
                return false;
}
void Deque::PrintFromFront()
{
    list_node *cur = NULL;
        cout<< "Print from front(size="<<GetLength()<<"): ";
            for(cur = front; cur!=NULL; cur = cur->rlink)
            {
                cout << cur->data <<" ";
            }
}
void Deque::PrintFromRear()
{
    list_node *cur = NULL;
        cout<< "Print from rear(size="<<GetLength()<<"): ";
            for(cur = rear; cur!=NULL; cur = cur->llink)
            {
                cout << cur->data <<" ";
            }

}