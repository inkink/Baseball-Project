#include <iomanip>
#include "graph.h"

using namespace std;

graph::graph()
{
}

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

int graph::shortestPath(int start, int end){
    printPathInFW(start,end);
    return distance[start][end];
}

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
    //output
//    cout<<"*** Raw Data ***"<<endl;
//    cout<<"distance:"<<endl;
//    for(int i=0;i<V;i++){
//        for(int j=0;j<V;j++){
//            cout<<setw(5)<<distance[i][j];
//        }
//        cout<<endl;
//    }
//    cout<<"path:"<<endl;
//    for(int i=0;i<V;i++){
//        for(int j=0;j<V;j++){
//            cout<<setw(4)<<path[i][j];
//        }
//        cout<<endl;
//    }
}

void graph::printPathInFW(int i, int j){
    if(path[i][j]!=-1){
        printPathInFW(i,path[i][j]);
        cout<<"->"<<j;
    }
}

//
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

void graph::printPath(node* tar){
    if(tar->pre)
        printPath(tar->pre);
    cout<<tar->index<<' ';
}

void graph::loadPath(node* tar, vector<int> &trip)
{
    if(tar->pre)
        loadPath(tar->pre, trip);
    trip.push_back(tar->index);
}
