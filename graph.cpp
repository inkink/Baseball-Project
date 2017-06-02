#include <iostream>
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
}

graph::~graph(){
    int** walker=matrix;
    for(int i=0;i<V;i++){
        delete[] *walker;
        walker++;
    }
    delete[] matrix;
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
}

void graph::shortestPath(int startingPoint){//dijkstra
    int cost[V];
    int parent[V];
    bool determined[V];
    for(int i=0;i<V;i++){  //init
        cost[i]=INT_MAX;
        determined[i]=false;
        parent[i]=-1;
    }
    cost[startingPoint]=0;

    for(int count=0;count<V-1;count++){
        int processIndex=findProcessingIndex(cost,determined);
        for(int i=0;i<V;i++){
            if(matrix[processIndex][i]!=0 && !determined[i]){//if !=0, that means edge exists
                if((matrix[processIndex][i]+cost[processIndex])<cost[i]){//cost[processIndex]!=MAX
                    cost[i]=matrix[processIndex][i]+cost[processIndex];
                    parent[i]=processIndex;
                }
            }
        }
        determined[processIndex]=true;
    }
    printDijkstra(startingPoint,cost,parent);
}

void graph::minSpanTree(){
    bool reached[V];
    int** MST;
    MST=new int*[V];
    int** walker=MST;
    for(int i=0;i<V;i++){
        *walker=new int[V];
        walker++;
    }
    int min=INT_MAX;
    for (int i=0;i<V;i++){//init
        reached[i]=false;
        for (int j=0;j<V;j++)
            MST[i][j]=0;
    }
    reached[0]=true;
    int target;
    int source;
    for(int count=0;count<V-1;count++){
        min=INT_MAX;
        for (int i=0;i<V;i++){
            if(reached[i]){
                for (int j=0;j<V;j++){
                    if(matrix[i][j]!=0 && !reached[j]){
                        if(matrix[i][j]<min){
                            min=matrix[i][j];
                            source=i;
                            target=j;
                        }
                    }
                }
            }
        }
        MST[source][target]=min;
        reached[target]=true;
    }
    printMST(MST);
}

void graph::printMST(int** MST){
    cout<<"---Minimum Spanning Tree---"<<endl;
    int min=INT_MAX;
    int prevMin=0;
    int source;
    int target;
    for(int count=1;count<V;count++){
        min=INT_MAX;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(MST[i][j]!=0&&MST[i][j]<min&&MST[i][j]>prevMin){
                    min=MST[i][j];
                    source=i;
                    target=j;
                }
            }
        }
        prevMin=min;
        cout<<count<<":("<<source<<", "<<target<<") "
           <<min<<endl;
    }
}

int graph::findProcessingIndex(int distance[], bool determined[]){
    int min=INT_MAX;
    int target;
    for(int i=0;i<V;i++){
        if(!determined[i]){
            if(distance[i]<min){
                min=distance[i];
                target=i;
            }
        }
    }
    return target;
}

void graph::printDijkstra(int from, int cost[], int parent[]){
    cout<<"---shortest distance (starting from "<<from<<")---"<<endl;
    int min=INT_MAX;
    int prevMin=INT_MIN;
    int tempI;
    for(int count=0;count<V;count++){
        min=INT_MAX;
        for(int i=0;i<V;i++){
            if(cost[i]<min&&cost[i]>prevMin){
                tempI=i;
                min=cost[i];
            }
        }
        prevMin=min;
        cout<<tempI<<": "<<cost[tempI]<<'{';
        printPath(tempI,parent);
        cout<<'}'<<endl;
    }
}

void graph::printPath(int destination, int parent[],bool comma){
    if(destination!=-1){
        printPath(parent[destination],parent,true);
        cout<<destination;
        if(comma)
            cout<<", ";
    }
}

void graph::FloydWarshall(){
    cout<<endl<<"*** FW ***"<<endl;
    //init
    int distance[V][V];
    int** path;
    path=new int*[V];
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
    int max=0;
    int maxj=0;
    for(int j=0;j<V;j++){
        if (distance[2][j]>max){
            max=distance[2][j];
            maxj=j;
        }
    }
    cout<<"the path from 2 to "<<maxj<<" is:"<<endl;
    cout<<'2';
    printPathInFW(path,2,maxj);
    cout<<endl;
    cout<<"*** Raw Data ***"<<endl;
    cout<<"distance:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<setw(5)<<distance[i][j];
        }
        cout<<endl;
    }
    cout<<"path:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<setw(4)<<path[i][j];
        }
        cout<<endl;
    }
}

void graph::printPathInFW(int** path, int i, int j){

    if(path[i][j]!=-1){
        printPathInFW(path,i,path[i][j]);
        cout<<"->"<<j;
    }
}
