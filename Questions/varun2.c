#include<stdio.h>
#include<stdlib.h>
 
struct path {
   int r;
   int c;
   struct path* next;
};

int N,M;

void insert(struct path **head, int r, int c){
    struct path *temp;
    temp = (struct path *)malloc(sizeof(struct path));
    
    temp->r = r;
    temp->c = c;
    
    if((*head)==NULL){
        temp->next = NULL;
        *head = temp;
    }else{
        struct path *temp1 = *head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = NULL;
    }

}

void makeListOfPath(int n,int m){
    // int arr[n][m];

}



void printList(struct path *head){
    struct path *temp;
    temp = head;
    while(temp->next != NULL){
		printf("(%d,%d)->",temp->r,temp->c);
		temp = temp->next;
	}
    printf("(%d,%d) \n",temp->r,temp->c);
    // printf("\n");
}

void solution(int r, int c, int maze[N][M]){
    if(r>=N || c>= M){
        return;
    }
    if(maze[r][c]==0) return;
    if(r==N-1 && c==M-1){
        
        return;
    }
}

 
int main()
{
    scanf("%d %d",&N,&M);
    int maze[N][M];
    solution(0,0,maze)
   return 0;
}