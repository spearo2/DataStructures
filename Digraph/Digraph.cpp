#include <iostream>
#include <iomanip>
using namespace std; 
#include "Stack.cpp"                        // We may need to print path

#define MAX_VERTICES    50
#define INFINITY        999999

class Digraph {
  private: 
    int  graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int  distance[MAX_VERTICES];            // Distance for shortest path
    int  parent[MAX_VERTICES];              // We may need to print path
    bool valid[MAX_VERTICES];               // To count the number of vertices
    bool found[MAX_VERTICES];               // Set for shortest path 
    int  num;                               // Number of vertices currently in use  
    
  public: 
    Digraph();
    void InsertEdge(int src, int dest, int cost);
    int  GetNumVertices() { return num; };
    void ShortestPath(int v);
    int  Choose();                          
    void PrintAdjMatrix();                  // Print adjacency matrix
    void PrintShortestPath(int v);          // Print length of shortest path
    void PrintPath(int src, int dest);      // Print path
}; 


Digraph::Digraph() 
{
    num = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        parent[i] = -1;
        valid[i] = false;                      
        found[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            graph[i][j] = INFINITY;
        }
    }
}


// Insert an edge from vertex src to vertex dest
void Digraph::InsertEdge(int src, int dest, int cost) 
{
    graph[src][dest] = cost;

    if (!valid[src])
    {
        valid[src] = true;
        num++;
    }

    if (!valid[dest])
    {
        valid[dest] = true;
        num++;
    }
}


// TODO: Implement a Dijikstra Algorithm
void Digraph::ShortestPath(int v)
{
    // Initialization
    int i, u, w;
    for(i = 0; i < num; i++)
    {
        found[i] = false;
        distance[i] = graph[v][i];

        if(distance[i] != INFINITY)
            parent[i] = v;
        else    
            parent[i] = -1;
    }
    // Determine shortest paths from vertext v 
    found[v] = true;
    distance[v] = 0;
    for(i = 0;i < num - 2;i++)
    {
        u = Choose();
        found[u] = true;
        for(w = 0; w < num; w++)
        {
            if(!found[w] && distance[u] + graph[u][w] < distance[w])
                {
                distance[w] = distance[u] + graph[u][w];
                parent[w] = u;
                }
        }
    }
    PrintShortestPath(v); 
}


// TODO: Find the smallest distance not yet checked and return the corresponding vertex
int Digraph::Choose()
{
    int i, smallest, idx;
    
    for(i = 0; i < num;i++)
    {
        if(!found[i])
        {
            smallest = distance[i];
            idx = i;

            break;
        }
    }

    for(i = 0; i < num;i++)
    {
        if(!found[i])
        {
            if(distance[i] < smallest)
            {
                smallest = distance[i];
                idx = i;
            }
        }
    }

    return idx;
}


void Digraph::PrintAdjMatrix()
{
    cout << "   "; 
    for (int i = 0; i < num; i++)
        cout << setw(3) << right << "[" << i << "]"; 

    cout << endl;
    for (int i = 0; i < num; i++)
    {
        cout << setw(1) << left << "[" << i << "]"; 
        for (int j = 0; j < num; j++)
        {
            if (graph[i][j] < INFINITY)
                cout << setw(5) << right << graph[i][j];
            else    
                cout << setw(5) << right << -1;
        }
        cout << endl;
    }
}


void Digraph::PrintShortestPath(int v)
{
    cout << "Dest\tCost\t Path" << endl;
    for (int i = 0; i < num; i++)
    {
        if (i != v)
        {
            cout << i << "\t";

            if (distance[i] < INFINITY) 
                cout << distance[i] << "\t ";
            else if (distance[i] == INFINITY)
                cout << -1 << "\t ";

            PrintPath(v, i);
            cout << endl;
        }
    }
}

// TODO: Print Path
void Digraph::PrintPath(int src, int dest)
{
    
    
    if(parent[dest] != -1)
    {
        Stack *stack = new Stack();
        int i = dest;
    
        while (parent[i] != -1)
        {
            stack->Push(i);
            i = parent[i];
        }
        stack->Push(i);
        while(!stack->IsEmpty())
        {
            cout<<stack->Pop() <<" ";
        }
    }
    else
    {
        cout<<"No Path";
    }
}
