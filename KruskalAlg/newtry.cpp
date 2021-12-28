#include <iostream>
using namespace std; 
#include "MinHeap.cpp"
#include "Stack.cpp"
#include "Queue.cpp"

#define MAX_VERTICES    50

typedef struct t_node {
    int vertex;
    int weight;
    struct t_node *link;
} node; 

class Graph {
  private: 
    node *graph[MAX_VERTICES];      // Adjacency list
    bool visited[MAX_VERTICES];     // Visited vertex
    int num_valid_vertex;           // Number of vertices currently in use  
    MinHeap* edges;
    int parent[MAX_VERTICES];
    
  public: 
    Graph();
    bool IsEmpty();
    void InsertEdge(int src, int dest, int cost);
    void DFS_recur(int v); 
    void DFS_recu(int v);          // Recursive DFS
    void DFS_iter(int v);           // Iterative DFS
    void BFS_iter(int v);           // Iterative BFS 
    void PrintAdjList();            // Print all adjacency list
    int  GetNumVertices() { return num_valid_vertex; };
    void KruskalAlg();
    int DFS_Krus(int v);
    void Krus();
}; 


Graph::Graph() 
{
    num_valid_vertex = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
        visited[i] = false;
    }
    edges = new MinHeap(); 
}

bool Graph::IsEmpty()
{
    return (num_valid_vertex == 0);
}

// TODO: Insert an edge between vertex src and vertex dest
void Graph::InsertEdge(int src, int dest, int cost) 
{
    node* src_node = new node;
    node* dest_node = new node;
    
    if(!graph[src])
    {
        num_valid_vertex++;
    }
    if(!graph[dest])
    {
        num_valid_vertex++;
    }

    src_node->vertex = dest;
    dest_node->vertex = src;
    
    src_node->weight = cost;
    dest_node->weight = cost;

    src_node->link = graph[src];
    dest_node->link = graph[dest];
    
    graph[dest] = dest_node;
    graph[src] = src_node;
    
    Element item;
    item.dest = dest;
    item.src = src;
    item.weight = cost;
    
}
void Graph::DFS_recur(int v)
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        visited[i] = false;
    }  
    DFS_recu(v);
}

// TODO: recursive DFS algorithm 
void Graph::DFS_recu(int v)
{
    node * w;
    if(visited[v])
        return;
    visited[v] = true;
    cout<<v;
    for(w = graph[v]; w; w = w->link)
    {
        if(!visited[w->vertex])
            DFS_recu(w->vertex);
    }
}

// TODO: iterative DFS algorithm
void Graph::DFS_iter(int v)
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        visited[i] = false;
    }
    node* w;
    Stack graphS;
    graphS.Push(v);
    while (!graphS.IsEmpty())
    {
        v = graphS.Pop();
        if(visited[v])
            continue;
        visited[v] = true;
        cout<<v;
        for (w = graph[v];w ; w = w->link)
        {
            if(!visited[w->vertex])
                graphS.Push(w->vertex);
        }
    }   
}

// TODO: iterative BFS algorithm
void Graph::BFS_iter(int v) 
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        visited[i] = false;
    }
    Queue graphQ;
    node* w;
    cout<< v;
    visited[v] = true;
    graphQ.AddQ(v);
    while (!graphQ.IsEmpty())
    {
        v = graphQ.DeleteQ();
        for (w = graph[v]; w; w = w->link)
        {
            if(!visited[w->vertex])
            {
                cout<<w->vertex;
                visited[w->vertex] = true;
                graphQ.AddQ(w->vertex);
            }
            
        }
    }

    
}

// TODO: Print all adjacency lists linked by graph[]
void Graph::PrintAdjList()
{
    for(int i = 0;graph[i]; i++)
    {
        cout<<"graph["<<i<<"] ";
        for(node* cur = graph[i];cur;cur = cur->link)
        {
            cout<<cur->vertex;
            if(cur->link)
                cout<<" -> ";
        }
        cout<<endl;
    }
}

void Graph::KruskalAlg()
{
    
    edges->Print();
}
// void Graph::Krus()
// {   
//     int v = 0;
//     for (int i = 0; i < MAX_VERTICES; i++)
//     {
//         visited[i] = false;
//     }
//     Queue graphQ;
//     node* w;
//     cout<< v;
//     visited[v] = true;
//     graphQ.AddQ(v);
//     while (!graphQ.IsEmpty())
//     {
//         v = graphQ.DeleteQ();
//         for (w = graph[v]; w; w = w->link)
//         {
//             if(!visited[w->vertex])
//             {
//                 cout<<w->vertex;
//                 visited[w->vertex] = true;
//                 graphQ.AddQ(w->vertex);
//             }
            
//         }
//     }
// }
