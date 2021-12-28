#include <iostream>
using namespace std; 
#include "Stack.cpp"
#include "Queue.cpp"

#define MAX_VERTICES    50

typedef struct t_node {
    int vertex;
    struct t_node *link;
} node; 

class Graph {
  private: 
    node *graph[MAX_VERTICES];      // Adjacency list
    bool visited[MAX_VERTICES];     // Visited vertex
    int num_valid_vertex;           // Number of vertices currently in use  
    
  public: 
    Graph();
    bool IsEmpty();
    void InsertEdge(int src, int dest);
    void DFS_recur(int v);          // Recursive DFS
    void DFS_iter(int v);           // Iterative DFS
    void BFS_iter(int v);           // Iterative BFS 
    void PrintAdjList();            // Print all adjacency list
    int  GetNumVertices() { return num_valid_vertex; };
}; 


Graph::Graph() 
{
    num_valid_vertex = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
        visited[i] = false;
    }
}

bool Graph::IsEmpty()
{
    return (num_valid_vertex == 0);
}

// TODO: Insert an edge between vertex src and vertex dest
void Graph::InsertEdge(int src, int dest) 
{
}

// TODO: recursive DFS algorithm 
void Graph::DFS_recur(int v)
{
}

// TODO: iterative DFS algorithm
void Graph::DFS_iter(int v)
{
}

// TODO: iterative BFS algorithm
void Graph::BFS_iter(int v) 
{
}

// TODO: Print all adjacency lists linked by graph[]
void Graph::PrintAdjList()
{
}