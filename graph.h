#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;
class graph
{
public:
    graph();
    graph(int **m, int ver);

    //big 3 not tested yet
    ~graph();
    graph(graph& other);
    graph& operator=(graph& other);

    int shortestPath(int start, int end);  //return the distance
    int findShortestForAllB(int start, vector<int> &trip);    //return the distance



private:
    int** matrix; //if no path, the distance is 0
    int V;
    int** distance;//distance between every 2 nodes
    int** path;//[i][j] is the parent of j in the path of i to j

    void FloydWarshall();

    void printPathInFW(int i, int j);//recurison

    struct node{
        int index;
        bool isTheEnd=true;
        int dist;
        bool indexReached[25];//temp 25
        node* children[5]={NULL,NULL,NULL,NULL,NULL};//temp 5
        node* pre;
        node (node* par,int i, int d){
            pre=par;
            index=i;
            if(pre){//pre exist
                //dist = matrix[pre->index][i]+pre->dist;
                dist = d+pre->dist;
                for(int t=0;t<25;t++)//temp
                    indexReached[t]=pre->indexReached[t];
                indexReached[i]=true;
            }
            else{// it is a root
                dist=0;
                for(int t=0;t<25;t++)//temp 25
                   indexReached[t]=false;
                indexReached[i]=true;
            }
            for(int i=0;i<25;i++){ //if all index are reached, it is the end
                if(indexReached[i]==false)
                    isTheEnd=false;
            }
        }
    };
    //recursion
    void spinTree(node* n);
    void findDest(node* headptr, node* &target, int& min);//re
    void printPath(node* tar);
    void loadPath(node* tar, vector<int> &trip);
};

#endif // GRAPH_H
