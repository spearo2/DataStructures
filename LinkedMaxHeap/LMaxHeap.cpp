#include "LMaxHeap.h"
//Constructor
LMaxHeap::LMaxHeap()
{
    root = nullptr;
    maxidx = 0;
}

//method to insert node into tree. used the algorithm to disconnect and reconncecting the link
void LMaxHeap::insert(Element item)
{
    tree_node* node = nullptr;
    tree_node* parent = nullptr;
    tree_node* grandpa = nullptr;
    int count = 0;
    tree_node* temp = nullptr;
    node = new tree_node;
    temp = new tree_node;
    node->data = item.data;
    node->key = item.key;
    node->left_child = node->right_child = nullptr;
    maxidx++;
    int i = maxidx;
    

    //when heap is empty
    if(i == 1)
    {
        root = node;
        
        return;
    }
    
    parent = find_parent(i);
    
    //when new node's key is smaller than the parent's
    if ((i!=1) && (item.key < parent->key))
    {
        
        node->parent = parent;
        
        (parent->left_child ? parent->right_child : parent->left_child) = node;
        
        return;
    }
    //when new node's key is bigger than the parent's
    while ((i!=1) && (item.key > parent->key))
    {
        
        if(count != 0)
        {
            temp->left_child = node->left_child;    
            temp->right_child = node->right_child;     
        }    

        
        parent = find_parent(i);
         
        if(i>3)
        {    
            grandpa = find_parent(i/2);
        }
        //when node's parent is root
        if(i<=3)
        {
            root = node;
            
            if(i==2)
            {
                root->left_child = parent;
                root->right_child = parent->right_child;
                
            }
            else if(i==3)
            {
                root->left_child = parent->left_child;
                root->right_child = parent;
                
            }
            
            parent->parent = node;
            
            if(count != 0)
            {
                parent->left_child = temp->left_child;
                parent->right_child = temp->right_child;
            }
            else
                parent->left_child = parent->right_child = nullptr;
            

            return;
        }
        //rest of the cases
        node->parent = grandpa;
        if(parent->left_child && parent->left_child != node)
        {
            node->right_child = parent;
            node->left_child = parent->left_child;
        }
        else
        {
            node->left_child = parent;
            node->right_child = parent->right_child;
        }
        

        if(count != 0)
            {
                parent->left_child = temp->left_child;
                parent->right_child = temp->right_child;
            }
        else
            parent->left_child = parent->right_child = nullptr;
        count++;


        if(grandpa->left_child == parent)
        {
            grandpa->left_child = node;
        }
        else if(grandpa->right_child)
        {
            grandpa->right_child = node;
        }
        parent->parent = node;
        parent = grandpa;
        i /= 2;

    }
    delete(temp);
    return;
}

//method that finds the parent of node. sepearted this since I was being confused so much
tree_node* LMaxHeap::find_parent(int index)
{
    Queue queue;
    tree_node* ptr = root;
    
    if(!ptr)
    {
        return NULL;
    }
    
    queue.AddQ(ptr);
    if(index == 1)
    {
        return NULL;
    }
    for(int i = 1; i<index/2+1;i++)
    {
        ptr = queue.DeleteQ();
  
        if(i == index/2)
        {
            break;
        }

        if(ptr->left_child)
            queue.AddQ(ptr->left_child);
        if(ptr->right_child)
            queue.AddQ(ptr->right_child);
        
    }

    return ptr;
}

//method that finds the node at the argument index
tree_node* LMaxHeap::find_node(int index)
{
    Queue queue;
    tree_node* ptr = root;
    
    if(!ptr)
    {
        return NULL;
    }  
    queue.AddQ(ptr);
    if(index == 1)
    {
        return NULL;
    }
    for(int i = 1; i<index+1;i++)
    {
        ptr = queue.DeleteQ();
        if(i == index)
        {
            break;
        }
        if(ptr->left_child)
            queue.AddQ(ptr->left_child);
        if(ptr->right_child)
            queue.AddQ(ptr->right_child);
        
    }
    
    return ptr;
}
//method that deletes node and return the data of deleted node. used the algorithm of swapping the data regardless of links
Element LMaxHeap::deletion()
{
    Element item;
    if(!root)
    {
        cout<<endl<<endl;
        cout<<"there is no more node to delete";
        return item;
    }
    item.key = root->key;
    item.data = root->data;
    
    
    //when root is the last node to delete
    if(!root->left_child)
    {      
        root = nullptr;
        return item;
    }

    int count = 0;
    tree_node* node = nullptr;
    tree_node* parent = nullptr;
    tree_node* del = nullptr;
    tree_node* temp = nullptr;
    tree_node* cur = nullptr;
    node = new tree_node;
    temp = new tree_node;
    del = root;
    
    node = find_node(maxidx);
    
    parent = find_parent(maxidx);
    maxidx--;
    
    root->key = node->key;
    root->data = node->data;

    if(parent->left_child == node)
        parent->left_child = nullptr;
    else
        parent->right_child = nullptr;
    node->parent = nullptr;
    delete node;
    cur = root;
    
    while(cur->left_child)
    {
        if(cur->right_child)
        {
             if(cur->right_child->key < cur->left_child->key && cur->key < cur->left_child->key)
             {
                temp->key = cur->key;
                temp->data = cur->data;

                cur->key = cur->left_child->key;
                cur->data = cur->left_child->data;

                cur->left_child->key = temp->key;
                cur->left_child->data = temp->data;
                cur = cur->left_child;   
             }
             else if(cur->right_child->key > cur->left_child->key && cur->key < cur->right_child->key)
             {
                temp->key = cur->key;
                temp->data = cur->data;

                cur->key = cur->right_child->key;
                cur->data = cur->right_child->data;

                cur->right_child->key = temp->key;
                cur->right_child->data = temp->data;
                cur=cur->right_child;
             }
             else
             {
                 break;
             }
        }
        else
        {
            if(cur->key < cur->left_child->key)
            {
                temp->key = cur->key;
                temp->data = cur->data;

                cur->key = cur->left_child->key;
                cur->data = cur->left_child->data;

                cur->left_child->key = temp->key;
                cur->left_child->data = temp->data;
                cur = cur->left_child;
                 
            }
            else
            {
                break;
            }
        }
    }
        
     return item;
}
//method that prints the whole tree in level-order. It travels the whole tree.
void LMaxHeap::Print()
{
    
    tree_node *ptr = root;
    Queue queue;
    if(!ptr)
    {
        cout<<"tree is empty!";
        return;
    }
        
    queue.AddQ(ptr);
    for(;;)
    {
        ptr = queue.DeleteQ();
        if(!ptr)
            break;
        cout << "[" << ptr->key <<" "<< ptr->data << "]";
        if(ptr->left_child)
            queue.AddQ(ptr->left_child);
        if(ptr->right_child)
            queue.AddQ(ptr->right_child);
    }
}
