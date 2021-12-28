typedef struct node {
     int key;
     struct node *left_child, *right_child;
} tree_node;


class BST
{
    // TODO: Define a BST class 
    private:
        tree_node *root;
    public:
        tree_node* search(tree_node *tree, int key);
        tree_node* modified_search(int key);
        bool IsEmpty();
        void delete_node(int key);
        tree_node* delete_node(tree_node *ptr, int key);
        void insert_node(int num);
        void print();
        tree_node* search(int key);
        tree_node* find_max_node(tree_node* ptr);
};