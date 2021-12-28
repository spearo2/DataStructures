// Definition of Element class
class Element{
  public: 
    int key;
    char str[20];

    Element(int e_key, const char *e_str) {
        key = e_key;
        strcpy(str, e_str);
    }
};


// Definition of queue node
typedef struct t_queue_node {
    Element *data;
    struct t_queue_node *link;   
} queue_node;


// TODO: Define LQueue class 
// Definition of LQueue class
class LQueue {
    private:
        t_queue_node* front;
        t_queue_node* rear;

    public:
        LQueue()
        {
            front = NULL;
            rear = NULL;
        }

        ~LQueue()
        {
            delete front;
            delete rear;
        }

        void AddQ(Element *e)
        {
            queue_node *new_node = new queue_node;

            if(new_node == NULL)
            {
                return;
            }

            new_node->data = e;
            new_node->link = NULL;
            if(front)
            {
                rear->link = new_node;
            }
            else
                front = new_node;

            rear = new_node;
        }

        Element* DeleteQ()
        {
            Element *e;
            queue_node *del = NULL;
            if(front==NULL)
            {
                return NULL;
            }

            e = front->data;
            del = front;
            front = front->link;
            if(front == NULL)
                rear = NULL;
            delete del;
            return e;
        }

        void Print()
        {
            queue_node *cur = NULL;
            cout<< "Queue : ";
            for(cur = front; cur!=NULL; cur = cur->link)
            {

                cout << cur->data->str <<" ";

            }
            cout << endl;
             
        }

        bool IsEmpty()
        {
            if(front == rear)
                return true;
            else
                return false;
    
        }
};

// TODO: Implement member functions of LQueue class: 
//       LQueue(), ~LQueue(), AddQ(), DeleteQ(), Print(), IsEmpty()
