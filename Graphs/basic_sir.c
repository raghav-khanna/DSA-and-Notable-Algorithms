#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define INFINITY 9999
#define MAX 10

struct node
{
    int val;
    struct node *next;
};

struct queue
{
  struct node *front;
  struct node *rear;
};

//***********Queue Code************

    struct queue* createqueue()
    {
        struct queue* q = (struct queue*)malloc(sizeof(struct queue));
        q->front = q->rear = NULL;
        return q;
    }

    void enqueue(struct queue* q, int x)
    {   
        struct node* temp = (struct node*) malloc(sizeof(struct node));

        temp -> val = x;
        temp->next = NULL;
        
        if (q->rear == NULL) 
        {
            q->front = q->rear = temp;
            return;
        }

        q->rear->next = temp;
        q->rear = temp;
    }

    int isEmptyQueue(struct queue *q){
        if(q->front == NULL && q->rear == NULL){
            return 1;
        }else{
            return 0;
        }
    }

    void dequeue(struct queue* q)
    {
        if (q->front == NULL)
            return;

        struct node* temp = q->front;

        q->front = q->front->next;

        if (q->front == NULL)
            q->rear = NULL;

        free(temp);
    }

    int peek(struct queue* q)
    {
        return q->front->val;
    }

//**************Queue Code End*****************

//*************Stack Code**********************

    void push(struct node **head,int x)
    {
        
        struct node* ptr = *head;
        struct node* temp = (struct node*) malloc(sizeof(struct node));

        temp -> val  = x;

        temp -> next = ptr;

        *head = temp;
    }

    void pop(struct node **head)
    {
        struct node* ptr = *head;
        struct node* prevptr = ptr;
        if(ptr == NULL)
        {
            printf("Empty Linked List\n");
            return;
        }
        *head = ptr -> next ;
        free(ptr);
    }

    int stackPeek(struct node *head)
    {
        return head->val ;
    }

    int isEmptyStack(struct node *top){
        if(top == NULL){
            return 1;
        }else{
            return 0;
        }
    }

//*************Stack Code Ended******************

struct node * createnode(int v)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = v;
    newnode->next = NULL;
    return newnode;
}

int MIN(int a, int b){
    return a >= b ? b : a;
}

void creategraph_adjlist (struct node *adj_list[10], int n)
{
    int i, j;
    char choice;
    struct node *newnode, *cur;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
                continue;
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) : ", i, j);
            getchar(); // to eat unwanted '\n' in the buffer
            scanf("%c", &choice);
            if ( choice == 'y' || choice == 'Y' )
            {
                newnode = createnode(j);
                if ( adj_list[i] == NULL )
                    adj_list[i] = newnode;
                else
                {
                    cur = adj_list[i];
                    while(cur->next!= NULL)
                        cur = cur->next;
                    cur->next = newnode; // add vertex to end of list
		        } 
            }
        } // end of for j 
    } // end of for i
} // end of creategraph_list

int creategraph_adjmat(int adj_mat[][10], int n )
{
    int i, j;
    char choice;
    for (i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                adj_mat[i][j] = 0;
		             continue;
            } 
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :",i,j);
            getchar(); // to eat unwanted '\n' from buffer
            scanf("%c", &choice);
            if ( choice == 'y' || choice == 'Y' )
                adj_mat[i][j] = 1;
            else
                adj_mat[i][j] = 0;
	    } // end of for j
    } //end of for i
} // end of create graph using adjmatrix

int weightedGraphMat(int adj_mat[][10], int n )
{
    int i, j;
    char choice;
    for (i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                adj_mat[i][j] = 0;
		             continue;
            } 
            printf("Enter the weight of the edge b/w %d and %d [0 if no edge] - ",i,j);
            scanf("%d",&adj_mat[i][j]);
	    } // end of for j
    } //end of for i
} // end of create graph using adjmatrix


void bfs(int adjmat[][10], int n, int svertex)
{
    struct queue *q = createqueue(); // assuming queue is already implemented
    int i, v;
    int *visited = (int *)calloc(n+1,sizeof(int));
    enqueue(q,svertex);
    visited[svertex]= 1;
    printf("\nBFS sequence: \n");
    while(!isEmptyQueue(q))
     {
        v = peek(q);
        dequeue(q);
        printf(" %d ", v);
        for(i=1; i<=n;i++)
         {
            if(visited[i]==0 && adjmat[v][i] == 1)
             { 
                enqueue(q,i);
                visited[i] = 1;
             }
         }
     } // end of while
} // end of iterative BFS   

void dfs(int adjmat[][10], int n, int svertex)
{
    struct node *top = NULL; // assuming stack is already implemented
    int i, v;
    int *visited = (int *)calloc(n+1,sizeof(int));
    push(&top,svertex);
    visited[svertex]= 1;
    printf("\nDFS sequence: \n");
    while(!isEmptyStack(top))
     {
        v = stackPeek(top);
        pop(&top);
        printf(" %d ", v);
        for(i=1; i<=n;i++)
         {
            if(visited[i]==0 && adjmat[v][i] == 1)
             { 
                push(&top,i);
                visited[i] = 1;
             }
         }
     } // end of while
} // end of iterative DFS 


void dfsrecur(int adjmat[][10], int n, int svertex, int toposort[])
{
    int i, v;
    static int index;
    static int visited[11];
    visited[svertex] = 1;
    printf(" %d ",svertex);
    for(int i = 1;i<=n; i++){
        if(visited[i]==0 && adjmat[svertex][i] == 1){
            dfsrecur(adjmat,n,i,toposort);
        }
    }
    toposort[index] = svertex;
    index++;
    return;
} // end of iterative DFS 


void dijkstra(int adjmat[][10], int n, int svertex){
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextNode,i,j;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)    
            if(adjmat[i][j]==0 && i != j)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = adjmat[i][j];
    for(i=1;i<=n;i++)
    {
        distance[i] = cost[svertex][i];
        pred[i] = svertex;
        visited[i] = 0;
    }

    distance[svertex]=0;
    visited[svertex]=1;   
    count  = 1;
    while(count <= n-1)
    {
        mindistance=INFINITY;
        //nextnode gives the node at minimum distance
        for(i=1;i <= n;i++)
            if(distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextNode = i;
            }
        //check if a better path exists through nextNode
        visited[nextNode] = 1;

        for(i=1;i <= n;i++)
            if(!visited[i])
                if(mindistance+cost[nextNode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextNode][i];
                    pred[i]=nextNode;
                }
        count++;
    }
    
    //print the path and distance of each node
    for(i=1;i <= n;i++)
        if(i!=svertex && i != 0)
        {
            printf("\nDistance of node %d = %d ",i,distance[i]);
            printf("\nPath = %d ",i);
            j=i;
            do
            {
                j = pred[j];
                printf(" <- %d ",j);
            }while(j != svertex);
        }
}
 

int main(){

    //Creating Adjacency Matrix
    int adj_mat[10][10], n, svertex, toposort[10];
    printf("Enter the Number of Elements in the graph (Less than 10) : ");
    scanf("%d", &n);
    if(n > 10){
        printf("Invalid\n");
        return 0;
    }
    // creategraph_adjmat(adj_mat,n);
    // printf("Enter the starting Vertex for traversal ");
    // scanf("%d",&svertex);
    // if(svertex > n){
    //     printf("Invalid Starting Point");
    //     return 0;
    // }
    // printf("BFS Traversal of the graph is - \n");
    // bfs(adj_mat,n,svertex);
    // printf("\nDFS Traversal of the graph is - \n");
    // dfs(adj_mat,n,svertex);
    // printf("\nDFS Traversal of the graph is [Using recursion] - \n");
    // dfsrecur(adj_mat,n,svertex,toposort);
    // printf("\nTopological sort of the graph is [Using recursion] - \n");
    // for(int x = n-1 ; x >= 0 ; x--){
    //     printf(" %d ",toposort[x]);
    // }
    weightedGraphMat(adj_mat,n);
    printf("Enter the starting Vertex for Finding the Shortest Path ");
    scanf("%d",&svertex);
    dijkstra(adj_mat,n,svertex);

    return 1;
}