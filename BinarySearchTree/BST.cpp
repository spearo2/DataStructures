// TODO: Implement member functions of BST class
bool BST::IsEmpty()
{
    return (root == NULL);
}

tree_node* BST::search(tree_node *tree, int key)
{
    if(!tree) return NULL;
    if(key == tree->key) return tree;
    if(key < tree->key)
        return search(tree->left_child, key);
    else
        return search(tree->right_child, key);
}

tree_node* BST::search(int key)
{
    return search(root, key);
}

tree_node* BST::modified_search(int key)
{
    tree_node *tree = root;
    while(tree)
    {
        if(key == tree->key)
            return NULL;
        else if(key < tree->key)
        {
            if(tree->left_child == NULL)
                return tree;
            else
                tree = tree->left_child;
        }
        else
        {
            if(tree->right_child == NULL)
                return tree;
            else
                tree = tree ->right_child;
        }
    }
    return NULL;
}
void BST::insert_node(int num)
{
    tree_node *ptr = NULL, *parent = NULL;
    parent = modified_search(num);

    if(parent || IsEmpty())
    {
        ptr = new tree_node;
        ptr->key = num;
        ptr->left_child = ptr->right_child = NULL;

        if(IsEmpty())
            root = ptr;
        else
        {
            if(num < parent->key)
            {
                parent->left_child = ptr;
            }
            else
                parent->right_child = ptr;
        }
    }
}
void BST::delete_node(int key)
{
    delete_node(root,key);
}

tree_node* BST::delete_node(tree_node *ptr, int key)
{
    if(ptr == NULL)
    {
        return NULL;
    }
    if(ptr->key > key)
    {
        ptr->left_child = delete_node(ptr->left_child, key);
    }
    else if (ptr->key <key)
    {
        ptr->right_child = delete_node(ptr->right_child, key);
    }
    else
    {
        tree_node *temp_node;
        // from here
        if(ptr->right_child != NULL && ptr->left_child!=NULL)
            {
                temp_node = find_max_node(ptr->left_child);
                ptr->key = temp_node->key;
                ptr->left_child = delete_node(ptr->left_child, temp_node->key);
            }

        else
        {
            temp_node = (ptr->left_child == NULL) ? ptr->right_child : ptr->left_child;
            delete ptr;
            return temp_node;
            // if(ptr->left_child == NULL && ptr->right_child == NULL)
            //     {
            //         temp_node = NULL;
            //     }
            // else if((ptr->left_child != NULL && ptr->right_child == NULL) || (ptr->right_child != NULL && ptr->left_child == NULL))
            // {
            //     if(ptr->left_child == NULL)
            //     {
            //         temp_node = ptr->right_child;
            //     }
            //     else if(ptr->right_child == NULL)
            //     {
            //         temp_node = ptr->left_child;
            //     }
            //     delete ptr;
            //     return temp_node;
            // }
        }
    }
    return ptr;
}
tree_node* BST::find_max_node(tree_node* ptr)
{  
    tree_node* cur = ptr;
    while(cur->right_child !=NULL)
        cur = cur->right_child;
    return cur;
}
void BST::print()
{
    tree_node *ptr = root;
    Queue queue;
    if(!ptr)
        return;
    queue.AddQ(ptr);
    for(;;)
    {
        ptr = queue.DeleteQ();
        if(!ptr)
            break;
        cout << "[" << ptr->key << "]";
        if(ptr->left_child)
            queue.AddQ(ptr->left_child);
        if(ptr->right_child)
            queue.AddQ(ptr->right_child);
    }
}