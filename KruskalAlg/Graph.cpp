#include <iostream>
using namespace std; 
#include "MinHeap.cpp"
#include "Stack.cpp"


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
    MinHeap* edges;                 // E = The all the edges of graph in minheap to sort it
    int parent[MAX_VERTICES];       // array of parent
    
  public: 
    Graph();
    bool IsEmpty();
    void InsertEdge(int src, int dest, int cost);
    void DFS_iter(int v);           // Iterative DFS 
    void PrintAdjList();            // Print all adjacency list
    int  GetNumVertices() { return num_valid_vertex; };
    void KruskalAlg();
    bool IsnotCycle(int v,int src,Graph *MCST);
}; 


Graph::Graph() 
{
    num_valid_vertex = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
        visited[i] = false;
        parent[i] = -1;
    }
    edges = new MinHeap(); 
}

bool Graph::IsEmpty()
{
    return (num_valid_vertex == 0);
}

// InsertEdge in both graph and minheap
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
    edges->insert(item);
    
}

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

// Based on Kruskal algorithm, finds the MCST
void Graph::KruskalAlg()
{
    int edgecounter = 0, total = 0;
    Element item;
    Graph* MCST = new Graph();  // T = {}
    while(edges->isEmpty() || edgecounter < num_valid_vertex-1)
    {
        item = edges->deletion();


         
        if(IsnotCycle(item.src,item.dest,MCST) && IsnotCycle(item.dest,item.src,MCST))
        {
            
            edgecounter++;
            MCST->InsertEdge(item.src,item.dest,item.weight);
            total = total +item.weight;
        }
    }

    if(edgecounter < num_valid_vertex-1)
    {
        cout<<"No Spanning Tree!";
        return;
    }
    cout<<"- DFS from 0: ";
    MCST->DFS_iter(0);
    cout<<endl;
    cout<<"- Total Cost: "<<total;

}
//Checks if there is cycle --> logic if v's parent is not w and w is visited then it makes a cycle.
bool Graph::IsnotCycle(int src,int dest,Graph* MCST)
{   
    int v = src;
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
        
        
        for (w = MCST->graph[v];w ; w = w->link)
        {
            if(!visited[w->vertex])
                {
                    parent[w->vertex] = v;
                    graphS.Push(w->vertex);   
                }
        }
    }
   
    if(visited[dest] && parent[src]!=dest)
        {
            return false;
        }
    return true;
 }
