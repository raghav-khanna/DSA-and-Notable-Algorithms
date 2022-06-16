#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct queue
{
  struct node *front;
  struct node *rear;
};

struct queue* createqueue()
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->front = q->rear = NULL;
	return q;
}

void enqueue(struct queue* q, int x)
{   
    struct node* temp = (struct node*) malloc(sizeof(struct node));

    temp -> data = x;
	temp->next = NULL;
	
    if (q->rear == NULL) 
    {
		q->front = q->rear = temp;
		return;
	}

    q->rear->next = temp;
	q->rear = temp;
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

void peek(struct queue* q)
{
    printf("%d",q->front->data);
}

void printqueue(struct queue* q) 
{
   struct node* ptr = q->front;
   while (ptr != NULL) 
   {
      printf("%d  -> ",ptr->data);
      ptr = ptr->next;
   }
   printf("NULL\n");
}

void main()
{
    struct queue *q = createqueue();
	enqueue(q, 10);
	enqueue(q, 20);
    printqueue(q);
	dequeue(q);
	dequeue(q);
	enqueue(q, 30);
	enqueue(q, 40);
    printqueue(q);
	enqueue(q, 50);
	dequeue(q);
    printqueue(q);
}