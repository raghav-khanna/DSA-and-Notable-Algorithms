//Level Order Traversal Using Queue

#include<stdio.h>
#include<stdlib.h>


struct treenode{
    struct treenode * left;
    int data;
    struct treenode* right;
};


struct node
{
    struct treenode* data;
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

void enqueue(struct queue* q, struct treenode *x)
{   
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(x == NULL) return;
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

struct treenode* dequeue(struct queue* q)
{
	if (q->front == NULL)
		return NULL;

	struct node* temp = q->front;

	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;
    return temp->data;
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

struct treenode* create()
{
	struct treenode* p;
	int val;
	printf("Enter val(-1 for terminate):");
	scanf("%d",&val);
	if(val==-1)
	  return NULL;
	p=(struct treenode *)malloc(sizeof(struct treenode ));
	p->data=val;
	printf("Enter left child of %d:\n",val);
	p->left=create();
 	printf("Enter right child of %d:\n",val);
	p->right=create();
	return p;
}

void levelOrder(struct treenode* root){
    struct queue *q = createqueue();
    struct treenode* temp;
    enqueue(q,root);
    while(q->front != NULL){
        temp = dequeue(q);
        if(temp != NULL){
            printf("%d ",temp->data);
            enqueue(q,temp->left);
            enqueue(q,temp->right);
        }
    }
}

void main()
{
    // struct queue *q = createqueue();
    struct treenode *root = NULL;
    root = create();
    levelOrder(root);
	
}