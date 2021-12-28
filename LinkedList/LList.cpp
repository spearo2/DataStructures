
#include <iostream>
#include <cstring>

using namespace std;

typedef struct t_list_node {
    char data[4];
    struct t_list_node *link;   
} list_node;


// TODO: Define LList 
class LList {

    private:
        list_node *head;

    public:
        LList()
        {
            head = NULL;
        }
        //~LList();
        
        list_node *GetByData(const char *data)
        {
            list_node *cur = NULL;
            for (cur = head; cur != NULL; cur = cur->link)
            {
                if(strcmp(cur->data,data)==0)
                    break;
            }
            return cur;
        }

        list_node *GetByIndex(int n)
        {
            list_node *cur = NULL;
            int i;
            for(cur = head, i = 0; cur !=NULL && i<n; cur = cur->link,i++);
        return cur;
        }
        
        void Insert(const char *data)
        {
            list_node *new_node = new list_node;
            
            strcpy(new_node->data,data);
            
            new_node->link = head;
            head = new_node;
        }

        void InsertAfterNode(const char *data, list_node *ptr)
        {
            list_node *new_node = new list_node;
            
            strcpy(new_node->data,data);
            new_node->link = ptr->link;
            ptr->link = new_node;
            
        }

        void Delete(const char *data)
        {
            list_node* prev;
            list_node* cur = head;

            while(cur && strcmp(cur->data,data)!=0)
            {
                prev = cur;
                cur = cur->link;
            }

            if(cur)
            {
                if(cur == head)
                    head = cur->link;
                else
                    prev->link = cur->link;
            }
            delete cur;
        }
              
        bool IsEmpty()
        {
            return(head == NULL);
        }

        void Invert()
        {
            if(IsEmpty())
                return;
            list_node *cur = head;
            list_node *next = head->link;
            while(cur)
            {
                if(cur == head)
                    cur->link = NULL;
                else
                {    
                    cur->link = head;
                    head = cur;
                }
            cur = next;
                if(cur)
                {
                    next = next->link;
                }
            }   
        }

        void Print()
        {
            list_node *cur = NULL;
            cout<< "List : ";
            for(cur = head; cur!=NULL; cur = cur->link)
            {

                cout << cur->data <<" ";

            }
            cout << endl;
             
        }

        int GetLength()
        {
            int i;
            list_node *cur = NULL;
            for(cur = head,i=0;cur!=NULL;cur=cur->link,i++);
            return i;
        }

        void Concat(LList* src_list)
        {
            list_node *cur = NULL;
        
            for(cur = head;cur->link!=NULL;cur=cur->link);
               cout<<cur->data; 
            
            
            cur->link = src_list->head;

          

        }

        void Copy(LList* src_list)
        {
            list_node *cur1 = NULL;
            list_node *new_node = new list_node;
            list_node *cur2 = new_node;
            
            for(cur1 = src_list->head ;cur1 != NULL; cur1 = cur1->link)
            {
                
                if(cur1 == src_list->head)
                {
                    strcpy(new_node->data,cur1->data);
                    head = cur2;
                }

                else
                {
                    copy1(cur1->data,cur2);
                    cur2 = cur2->link;
                }
            }
        }

        void copy1(char* a, list_node *b)
        {
            list_node *new_node = new list_node;
            
            strcpy(new_node->data,a);
            b->link = new_node;
        }

};

// TODO: Implement member functions of LList: 
//       GetBytData(), GetByIndex(), Insert(), InsertAfterNode(), Delete(), Print(), IsEmpty()
//       GetLength(), Concat(), Copy() 
//list_node *cur;
//for(cur =head;cur!=NULL;cur=cur->link){i++;}
//cur->link = src_list->head
