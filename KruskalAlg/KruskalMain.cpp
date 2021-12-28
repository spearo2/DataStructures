#include "Graph.cpp"

int main() 
{
    Graph *graph = new Graph(); 
    //test 1
    graph->InsertEdge(0, 1, 1); // src, dest, cost
    graph->InsertEdge(0, 2, 2);
    graph->InsertEdge(0, 5, 3);
    graph->InsertEdge(1, 2, 4);
    graph->InsertEdge(1, 5 ,5);
    graph->InsertEdge(1, 3, 7);
    graph->InsertEdge(2, 3, 6);
    graph->InsertEdge(3, 5, 8);
    graph->InsertEdge(3, 4, 9);
    // graph->InsertEdge(3, 6, 6);
    // graph->InsertEdge(4, 6, 9);
    // graph->InsertEdge(5, 6, 6);
    //test 2
    //  graph->InsertEdge(0, 1, 2);
    //  graph->InsertEdge(0, 5, 7);
    //  graph->InsertEdge(0, 6, 3);
    //  graph->InsertEdge(1, 6, 6);
    //  graph->InsertEdge(1, 2, 4);
    //  graph->InsertEdge(2, 7, 2);
    //  graph->InsertEdge(2, 3, 2);
    //  graph->InsertEdge(3, 7, 8);
    //  graph->InsertEdge(3, 4, 1);
    //  graph->InsertEdge(4, 8, 2);
    //  graph->InsertEdge(4, 5, 6);
    //  graph->InsertEdge(5, 8, 5);
    //  graph->InsertEdge(6, 7, 3);
    //  graph->InsertEdge(6, 8, 1);
    //  graph->InsertEdge(7, 8, 4);
    //test 3
    // graph->InsertEdge(0, 1, 4);
    // graph->InsertEdge(0, 7, 8);
    // graph->InsertEdge(1, 2, 8);
    // graph->InsertEdge(1, 7, 11);
    // graph->InsertEdge(2, 8, 2);
    // graph->InsertEdge(2, 3, 7);
    // graph->InsertEdge(2, 5, 4);
    // graph->InsertEdge(3, 6, 14);
    // graph->InsertEdge(3, 4, 9);
    // graph->InsertEdge(4, 5, 10);
    // graph->InsertEdge(5, 6, 2);
    // graph->InsertEdge(6, 8, 6);
    // graph->InsertEdge(6, 7, 1);
    // graph->InsertEdge(7, 8, 7);
    //test 4
    // graph->InsertEdge(0, 1, 7);
    // graph->InsertEdge(0, 3, 5);
    // graph->InsertEdge(1, 2, 8);
    // graph->InsertEdge(1, 3, 9);
    // graph->InsertEdge(1, 4, 7);
    // graph->InsertEdge(2, 4, 5);
    // graph->InsertEdge(3, 4, 15);
    // graph->InsertEdge(3, 5, 6);
    // graph->InsertEdge(4, 5, 8);
    // graph->InsertEdge(4, 6, 9);
    // graph->InsertEdge(5, 6, 11);

    cout << "Print All Lists: ";
    cout << graph->GetNumVertices();
    cout << " vertices are in use currently" << endl;
    graph->PrintAdjList();

    cout << endl;
    cout << "Kruskal Algorithm: " << endl;
    graph->KruskalAlg();

    return 0; 
}