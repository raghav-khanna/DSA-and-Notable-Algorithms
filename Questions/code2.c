#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void createGraphMat(int v[], int e[][2], int n, int adjMat[MAX][MAX]){
    
    for(int i=1;i<=n;i++){
        for(int j = 1; j<=n ; j++){
            adjMat[i][j] = 0;
        }
    }

    for(int i = 0;i < 10; i++){
        adjMat[e[i][0]][e[i][1]] = 1;
    }
}

void inDegree(int adjmat[MAX][MAX], int n){
    int indeg = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){
            if(adjmat[j][i] == 1){
                indeg += 1;
            }
        }
        printf("Indegree of Vertex %d is %d \n",i,indeg);
        indeg = 0;
    }
}

void outDegree(int adjmat[MAX][MAX], int n){
    int outdeg = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){
            if(adjmat[i][j] == 1){
                outdeg += 1;
            }
        }
        printf("Outdegree of Vertex %d is %d \n",i,outdeg);
        outdeg = 0;
    }
}

void displayInDegree(int adjmat[MAX][MAX], int v, int n){
    int indeg = 0;

        for(int j = 1; j<=n; j++){
            if(adjmat[j][v] == 1){
                indeg += 1;
            }
        }
    printf("Indegree of Vertex %d is %d \n",v,indeg);
    indeg = 0;
    
}

int isConnected(int adjMat[MAX][MAX],int n){
    int i = 1, result = 0;
    while(i<=n){
        for(int j = 1;j<=n;j++){
            if(adjMat[i][j] == 1){
                result  = 1;
                break;
            }
        }

        for(int j = 1;j<=n;j++){
            if(adjMat[j][i] == 1){
                result = 1;
                break;
            }
        }
        if(result == 0)
            return 0;
        i++;
    }
    return 1;
}


int main(){
    int adjMat[MAX][MAX];
    int n = 6, vertex = 0;
    int v[] = {1, 2, 3, 4, 5, 6};
    int e[][2] = {{1,2}, {1,3}, {2,3}, {2,4}, {2,5}, {3,4}, {3, 6}, {4,5}, {4,6}, {5,6}};
    createGraphMat(v,e,n,adjMat);
    printf("Adjacency Matrix Representation of the Graph - \n");
    for(int i=1;i<=n;i++){
        for(int j = 1; j<=n ; j++){
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
    printf("Printing indegree of each vertex - \n");
    inDegree(adjMat,n);
    printf("Printing outdegree of each vertex - \n");
    outDegree(adjMat,n);

    printf("\n\nEnter the vertex whose indegree you want - ");
    scanf("%d", &vertex);
    displayInDegree(adjMat,vertex,n);
    if(isConnected(adjMat,n)){
        printf("\n\nGraph is Connected!!\n");
    }else{
        printf("\n\nGraph is NOT Connected!!\n");
    }
    return 0;
}