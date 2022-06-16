#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

void insert_beginning(struct node **head, int new_val){
    struct node *ptr = *head;
    struct node *temp = (struct node *) malloc(sizeof(struct node));
 
    temp->val  = new_val;
 
    temp->next = (ptr);
 
    *head = temp;
}

void createlist(struct node *ptr[],int mat[][2])
{
    for(int i=1;i<=12;i++)
    {
        insert_beginning(&ptr[mat[i][0]],(mat[i][1]));
    }
}

void printLinkedList(struct node *head) 
{
   struct node *ptr = head;
   while (ptr != NULL) 
   {
      printf("%d  -> ",ptr->val);
      ptr = ptr->next;
   }
   printf("NULL\n");
}

void printgraph(struct node *ptr[])
{
    for(int i = 1;i<9;i++)
    {
        printf("%d -> ",i);
        printLinkedList(ptr[i]);
        printf("\n");
    }
}

int degree(struct node *ptr[], int v){
    int deg = 0;
    for(int i = 1;i<=8; i++){
        if(i == v) continue;
        while(ptr[i] != NULL){
            if(ptr[i]->val == v) deg++;
            ptr[i] = ptr[i]->next;
        }
    }
    while(ptr[v] != NULL){
            deg++;
            ptr[v] = ptr[v]->next; 
    }
    return deg;
}

// void cycle(struct node *ptr[], int visited[], struct node *head){
//     if(head == NULL){
//         return;
//     }   
// }

void main()
{
    int v[8] = {1,2,3,4,5,6,7,8};
    int e[12][2] = {{1,2}, {1,3}, {2,4}, {4,3}, {2,5}, {3,4}, {4,6}, {5,6}, {4,7}, {5,7}, {6,8},{7,8}};
    struct node *head[9];
    //Initializing the List
    for(int i = 0;i<9;i++)
    {
        head[i] = NULL;
    }
    createlist(head,e);
    printf("List was created successfully. Printing the list - \n");
    printgraph(head);
    printf("Enter the Vertex to check it's degree - ");
    int deg;
    scanf("%d", &deg);
    printf("Degree of %d is -> %d\n",deg,degree(head,deg));

    // for(int i = 1; i<=8; i++){
    //     int visited[] = {0,0,0,0,0,0,0,0,0};
    //     cycle(head,visited,head[i]);

    // }

}