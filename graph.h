#ifndef GRAPH_H
#define GRAPH_H

class graph
{
public:
    graph();
    graph(int **m, int ver);

    //big 3 not tested yet
    ~graph();
    graph(graph& other);
    graph& operator=(graph& other);

    void shortestPath(int startingPoint);
    void minSpanTree();
    void FloydWarshall();
    void printPathInFW(int** path, int i, int j);//recurison
private:
    int** matrix; //if no path, the distance is 0
    int V;

    int findProcessingIndex(int distance[], bool determined[]);
    void printDijkstra(int from, int cost[], int parent[]);
    void printPath(int destination, int parent[],bool comma=false);
    void printMST(int** MST);
};

#endif // GRAPH_H
