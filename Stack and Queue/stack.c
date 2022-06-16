
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void push(struct node **head,int x)
{
    
    struct node* ptr = *head;
    /* 1. allocate node */
    struct node* temp = (struct node*) malloc(sizeof(struct node));
 
    /* 2. put in the data  */
    temp -> data  = x;
 
    /* 3. Make next of new node as head */
    temp -> next = ptr;
 
    /* 4. move the head to point to the new node */
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

void peek(struct node *head)
{
    printf("%d",head->data);
}

void printStack(struct node* head) 
{
   struct node* ptr = head;
   while (ptr != NULL) 
   {
      printf("%d  -> ",ptr->data);
      ptr = ptr->next;
   }
   printf("NULL\n");
}

void main()
{
    struct node *top = NULL;
}