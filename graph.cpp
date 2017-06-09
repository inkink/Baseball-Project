#include <iomanip>
#include "graph.h"

using namespace std;

/***********************************************************
 * CONSTRUCTOR O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The constructor creates an empty graph
 * *******************************************************/
graph::graph()
{
}

/***********************************************************
 * CONSTRUCTOR O(n^2)
 * ________________________________________________________
 * PRE-CONDITIONS
 * m   - matrix value
 * ver - version number
 *
 * POST-CONDITIONS
 * The constructor creates a graph
 * *******************************************************/
graph::graph(int **m, int ver){
    V=ver;
    matrix = new int*[ver];
    int** temp=matrix;
    for(int i=0; i<ver;i++){
        *temp=new int[ver];
        temp++;
        for(int j=0; j<ver; j++)
            matrix[i][j]=m[i][j];
    }
    FloydWarshall();
}

/***********************************************************
 * DESTRUCTOR O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The destructor frees any dynamically allocated memory
 * *******************************************************/
graph::~graph(){
    int** walker=matrix;
    for(int i=0;i<V;i++){
        delete[] *walker;
        walker++;
    }
    delete[] matrix;
    walker=distance;
    for(int i=0;i<V;i++){
        delete[] *walker;
        walker++;
    }
    delete[] distance;
    walker=path;
    for(int i=0;i<V;i++){
        delete[] *walker;
        walker++;
    }
    delete[] path;
    V=0;
}

/***********************************************************
 * COPY CONSTRUCTOR O(n^2)
 * ________________________________________________________
 * PRE-CONDITIONS
 * other - other graph to copy
 *
 * POST-CONDITIONS
 * The function will create a graph using another graph's
 * info
 * *******************************************************/
graph::graph(graph& other){
    V=other.V;
    matrix = new int*[V];
    int** temp=matrix;
    for(int i=0; i<V;i++){
        *temp=new int[V];
        temp++;
        for(int j=0; j<V; j++)
            matrix[i][j]=other.matrix[i][j];
    }
}

/***********************************************************
 * FUNCTION operator= O(n^2)
 * ________________________________________________________
 * PRE-CONDITIONS
 * other - other graph to copy from
 *
 * POST-CONDITIONS
 * The function will assign this graph's info to other's
 * graph's info
 * *******************************************************/
graph& graph::operator=(graph& other){
    int** walker=matrix;
    for(int i=0;i<V;i++){
        delete[] *walker;
        walker++;
    }
    delete[] matrix;
    V=other.V;
    matrix = new int*[V];
    walker=matrix;
    for(int i=0; i<V;i++){
        *walker=new int[V];
        walker++;
        for(int j=0; j<V; j++)
            matrix[i][j]=other.matrix[i][j];
    }
    return other;
}

/***********************************************************
 * FUNCTION shortestPath O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * start - starting point
 * end   - end point
 *
 * POST-CONDITIONS
 * The function will find the shortest path from start
 * to end
 * *******************************************************/
int graph::shortestPath(int start, int end){
    printPathInFW(start,end);
    return distance[start][end];
}

/***********************************************************
 * FUNCTION FloydWarshall O(n^2)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will use the floyd warshall algorithm
 * to find the shortest path
 * *******************************************************/
void graph::FloydWarshall(){
    //init
    path=new int*[V];
    distance=new int*[V];
    int** walker=path;
    for(int i=0;i<V;i++){
        *walker=new int[V];
        *walker++;
        for(int j=0;j<V;j++){
            if(i==j)
                path[i][j]=-1;
            else
                path[i][j]=i;
        }
    }
    walker=distance;
    for(int i=0;i<V;i++){
        *walker=new int[V];
        *walker++;
    }
    //distance is copy from the matrix, if no path, INT_MAX
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(matrix[i][j]==0)
                distance[i][j]=INT_MAX;//if no path, max
            else
                distance[i][j]=matrix[i][j];
            if(i==j)
                distance[i][j]=0; //if to itself, 0
        }
    }
    //start
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(distance[i][k]!=INT_MAX&&distance[k][j]!=INT_MAX){
                    if(distance[i][j]>distance[i][k]+distance[k][j]){
                        distance[i][j]=distance[i][k]+distance[k][j];
                        path[i][j]=k;
                    }
                }
            }
        }
    }
}

/***********************************************************
 * FUNCTION printPathInFW O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * i - from 0 to V(which is the number of vertices)
 * j - from 0 to V(which is the number of vertices)
 *
 * POST-CONDITIONS
 * The function will print the path according to the path matrix
 * *******************************************************/
void graph::printPathInFW(int i, int j){
    if(path[i][j]!=-1){
        printPathInFW(i,path[i][j]);
        cout<<"->"<<j;
    }
}

/***********************************************************
 * FUNCTION findShortestForAllB O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * start - starting int point
 * trip  - list of ints of the trip
 *
 * POST-CONDITIONS
 * The function will
 * *******************************************************/
int graph::findShortestForAllB(int start, vector<int>&trip){
    node* root;
    root=new node(NULL,start,0);
    spinTree(root);
    node* target;
    int minD=INT_MAX;
    findDest(root,target,minD);

    printPath(target);
    loadPath(target, trip);
    return minD;
}

/***********************************************************
 * FUNCTION findDest O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * headptr - is a pointer of a node
 * target  - output (pass by reference)
 * min     - output (pass by reference)
 *
 * POST-CONDITIONS
 * The function will find the shortest completed path from the tree
 * Since it is recrusion, the output would be pass by refernce
 * *******************************************************/
void graph::findDest(node* headptr,node* &target, int& min){
    if(headptr->isTheEnd){
        if(headptr->dist < min){
            min=headptr->dist;
            target=headptr;
        }
    }
    for(int i=0;i<5;i++){//temp 5
        if(headptr->children[i]){
            findDest(headptr->children[i],target,min);
        }
    }
}

/***********************************************************
 * FUNCTION spinTree O(n^2)
 * ________________________________________________________
 * PRE-CONDITIONS
 * n -  the tree would spin with  the root as n
 *
 * POST-CONDITIONS
 * The function will find all the possible path from n and record the total distance
 * *******************************************************/
void graph::spinTree(node* n){
    //put every reachable and unreached node as child
    for(int i=0;i<V;i++){
        if(!(n->indexReached[i])){//if unreached
            if(matrix[n->index][i]!=0){//reachable
                //then want to add i as a child of n
                int j=0;
                while(n->children[j]!=NULL)
                    j++;//find a empty slop
                int d=matrix[n->index][i];
                n->children[j]=new node(n,i,d);
                spinTree(n->children[j]);
            }
        }
    }
}

/***********************************************************
 * FUNCTION printPath O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * tar - target node
 *
 * POST-CONDITIONS
 * The function will
 * *******************************************************/
void graph::printPath(node* tar){
    if(tar->pre)
        printPath(tar->pre);
    cout<<tar->index<<' ';
}

/***********************************************************
 * FUNCTION loadPath O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * tar  - target node
 * trip - list of ints of trip points
 *
 * POST-CONDITIONS
 * The function will
 * *******************************************************/
void graph::loadPath(node* tar, vector<int> &trip)
{
    if(tar->pre)
        loadPath(tar->pre, trip);
    trip.push_back(tar->index);
}
