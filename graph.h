#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;
class graph
{
public:
    graph();                                                //default constructor
    graph(int **m, int ver);                                //param constructor
    ~graph();                                               //destructor
    graph(graph& other);                                    //copy constructor
    graph& operator=(graph& other);                         //overloaded =
    int shortestPath(int start, int end);                   //return the distance
    int findShortestForAllB(int start, vector<int> &trip);  //return the distance
private:
    int** matrix;                                           //if no path, the distance is 0
    int V;                                                  //version
    int** distance;                                         //distance between every 2 nodes
    int** path;                                             //[i][j] is the parent of j in the path of i to j
    void FloydWarshall();                                   //algorithm
    void printPathInFW(int i, int j);                       //prints path

    struct node{
        int index;
        bool isTheEnd=true;
        int dist;
        bool indexReached[25];
        node* children[5]={NULL,NULL,NULL,NULL,NULL};
        node* pre;
        node (node* par,int i, int d){
            pre=par;
            index=i;
            if(pre){//pre exist
                dist = d+pre->dist;
                for(int t=0;t<25;t++)
                    indexReached[t]=pre->indexReached[t];
                indexReached[i]=true;
            }
            else{// it is a root
                dist=0;
                for(int t=0;t<25;t++)
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
    void spinTree(node* n);                                 //finds connections to nodes
    void findDest(node* headptr, node* &target, int& min);  //finds correct destination
    void printPath(node* tar);                              //prints path of node
    void loadPath(node* tar, vector<int> &trip);            //load path to graph
};

#endif // GRAPH_H
