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


// Definition of stack node
typedef struct t_stack_node {
    Element *data;
    struct t_stack_node *link;   
} stack_node;


// TODO: Define LStack class 
// Definition of LStack class
class LStack {
    private:
 
        t_stack_node* top;

    public:
        LStack()
        {
            top = NULL;
            
        }

        ~LStack()
        {
            delete top;
        }

        void Push(Element *e)
        {
            stack_node *new_node = new stack_node;

            if(new_node == NULL)
            {
                return;
            }

            new_node->data = e;
            new_node->link = top;
            top = new_node;
        }

        Element *Pop()
        {
            Element *e;
            stack_node *del;

            if(top == NULL)
            {
                return NULL;
            }

            e = top->data;
            del = top;
            top = top->link;
            delete del;
            return e;
        }
        void Print()
        {
            stack_node *cur = NULL;
            cout<< "Stack : ";
            for(cur = top; cur!=NULL; cur = cur->link)
            {

                cout << cur->data->str <<" ";

            }
            cout << endl;
             
        }

        bool IsEmptyS() 
        {
        return (top == NULL); 
        }
};

// TODO: Implement member functions of LStack class: 
//       LStack(), ~LStack(), Push(), Pop(), Print(), IsEmpty()
