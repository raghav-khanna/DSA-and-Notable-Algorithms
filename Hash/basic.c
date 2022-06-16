#include<stdio.h>
#include<stdlib.h>

struct hash
{
    int key;
};

// hash linked list

struct node
{
    int data;
    struct node* next;
};

void insert_beginning(struct node **head, int new_data)
{
    struct node* ptr = *head;
    /* 1. allocate node */
    struct node* temp = (struct node*) malloc(sizeof(struct node));
 
    /* 2. put in the data  */
    temp->data  = new_data;
 
    /* 3. Make next of new node as head */
    temp->next = (ptr);
 
    /* 4. move the head to point to the new node */
    *head = temp;
}

void printLinkedList(struct node* head) 
{
   struct node* ptr = head;
   while (ptr != NULL) 
   {
      printf("%d  -> ",ptr->data);
      ptr = ptr->next;
   }
   printf("NULL\n");
}

void deleteNode(struct node **head,int info)
{
    struct node* ptr = *head;
    struct node* prevptr = ptr;
    if(ptr == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    while(ptr->data != info)
    {
        prevptr = ptr;
        ptr = ptr -> next;
    }
    if(ptr == *head)
    {
        *head = ptr -> next ;
    }
    else
    {
        prevptr -> next = ptr -> next;
    }
    free(ptr);
}

// hash arr function

void inihash(struct hash ht[],int y)
{
    for (int i=0;i<y;i++)
    {
     ht[i].key = -1;
    }
}

int hashmulti(int y,int x)
{
    double k = 0.618033;
    int z = (y)*((k*x)-(int)(k*x));
    printf("%d\n\n",z);
    return z;
}

int chkhasharr(int x)
{
    if(x == -1)
    {
        return 1; //not exist
    }
    else
    {
        return 0; //exists
    }
}

void delhasharr(struct hash ht[],int y)
{
    printf("Enter the number to be deleted - ");
    int x;
    scanf("%d",&x);
    int z = hashmulti(y,x);
    if(chkhasharr(ht[z].key) == 0)
    {
        ht[z].key = -99;
    }
    else
    {
        printf("The number does not exists\n");
    }
}

void hasharr(struct hash ht[],int y)
{
    printf("Enter number - ");
    int x;
    scanf("%d",&x);
    int z = hashmulti(y,x);
    if(chkhasharr(ht[z].key) == 1)
    {
        ht[z].key = x;
    }
    else
    {
        printf("Already exists\n");
    }
}

// hash ll function

int chkhashll(struct node *ptr,int x)
{
    while (ptr != NULL ) 
    {
        if(ptr->data == x)
        {
            return 0; //exists
        }
        ptr = ptr->next;
    }
    return 1; // does not exist
}

void delhashll(struct node *ptr[],int y)
{
    printf("Enter the number to be deleted - ");
    int x;
    scanf("%d",&x);
    int z = hashmulti(y,x);
    if(chkhashll(ptr[z],x) == 1)
    {
        deleteNode(&ptr[z],x);
    }
    else
    {
        printf("The number does not exists\n");
    }
}

void hashll(struct node *ptr[],int y)
{
    printf("Enter number - ");
    int x;
    scanf("%d",&x);
    int z = hashmulti(y,x);
    if(chkhashll(ptr[z],x) == 1)
    {
        insert_beginning(&ptr[z],x);
    }
    else
    {
        printf("Already exists\n");
    }
}

void main()
{
    printf("Enter the size of array\n");
    int y;
    scanf("%d",&y);
    // struct hash hashtable[100];
    // printf("Initializing the Hash Table\n");
    // inihash(hashtable,y);
    // hasharr(hashtable,y);
    // hasharr(hashtable,y);
    // hasharr(hashtable,y);
    // hasharr(hashtable,y);
    // for(int i = 0;i<y;i++)
    // {
    //     printf("%d ",hashtable[i].key);
    // }
    // delhasharr(hashtable,y);
    // for(int i = 0;i<y;i++)
    // {
    //     printf("%d ",hashtable[i].key);
    // }
    
    struct node *head[100];
    for(int i = 0;i<y;i++)
    {
        head[i] = NULL;
    }
    hashll(head,y);
    hashll(head,y);
    hashll(head,y);
    hashll(head,y);
    hashll(head,y);
    for(int i = 0; i<y; i++){
        printLinkedList(head[i]);
        printf("\n");
    }

}