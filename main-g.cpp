#include <iostream>
#include "graph.h"

using namespace std;

#define VERTICE 12

enum location{
    LosAngeles,  SanFrancisco,  Seattle,
    Denver,	Chicago, KansasCity,
    Dallas,	Houston, Miami,
    Atlanta, NewYork, Boston
};

ostream& operator <<(ostream& out, location a);

void minimumSpanningTree(int graph[VERTICE][VERTICE]);//primâ€™s algorithm
void printMST(int MST[VERTICE][VERTICE]);

int main(int argc, char *argv[])
{
    int** grapha=new int* [VERTICE];
    int** walker= grapha;
    for(int i=0;i<VERTICE;i++){
        *walker=new int[VERTICE];
        walker++;
    }
    int graphb[VERTICE][VERTICE]={{   0, 381,   0,1015,   0,1663,1435,   0,   0,   0,   0,   0},
                                 { 381,   0, 807,1267,   0,   0,   0,   0,   0,   0,   0,   0},
                                 {   0, 807,   0,1331,2097,   0,   0,   0,   0,   0,   0,   0},
                                 {1015,1267,1331,   0,1003, 599,   0,   0,   0,   0,   0,   0},
                                 {   0,   0,2097,1003,   0, 533,   0,   0,   0,   0, 787, 983},
                                 {1663,   0,   0, 599, 533,   0, 496,   0,   0, 864,1260,   0},
                                 {1435,   0,   0,   0,   0, 496,   0, 239,   0, 781,   0,   0},
                                 {   0,   0,   0,   0,   0,   0, 239,   0,1187, 810,   0,   0},
                                 {   0,   0,   0,   0,   0,   0,   0,1187,   0, 661,   0,   0},
                                 {   0,	  0,   0,   0,   0, 864, 781, 810, 661,   0, 888,   0},
                                 {   0,	  0,   0,	0, 787,1260,   0,	0,   0,	888,   0, 214},
                                 {   0,	  0,   0,	0, 983,   0,   0,	0,   0,   0, 214,	0}};
    for(int i=0;i<VERTICE;i++){
        for(int j=0;j<VERTICE;j++)
            grapha[i][j]=graphb[i][j];
    }

    graph test(grapha,12);
    test.shortestPath(2);
    cout<<endl;
    test.minSpanTree();
    test.FloydWarshall();
}

ostream& operator <<(ostream& out, location a){
    switch (a){
    case 0:
        out<<"Los Angeles";
        break;
    case 1:
        out<<"San Francisco";
        break;
    case 2:
        out<<"Seattle";
        break;
    case 3:
        out<<"Denver";
        break;
    case 4:
        out<<"Chicago";
        break;
    case 5:
        out<<"Kansas City";
        break;
    case 6:
        out<<"Dallas";
        break;
    case 7:
        out<<"Houston";
        break;
    case 8:
        out<<"Miami";
        break;
    case 9:
        out<<"Atlanta";
        break;
    case 10:
        out<<"New York";
        break;
    case 11:
        out<<"Boston";
        break;
    }
    return out;
}
