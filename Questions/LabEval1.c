#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void insert(struct node **head, int n){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    if((*head)==NULL){
        temp->next = NULL;
        *head = temp;
    }else{
        struct node *temp1 = *head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = NULL;
    }

}

void printList(struct node *head){
    struct node *temp;
    temp = head;
    while(temp != NULL){
		printf("%d \t",temp->data);
		temp = temp->next;
	}
    printf("\n");
}

void insertBegin(struct node **head, int n){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = *head;
    *head = temp;
}

struct node * makeChanges(struct node *head){
    struct node* temp,*prev;
    temp = head;
    prev = NULL;
    while(temp!=NULL){
        //If data is even
        if(((temp->data)%2) == 0){
            //If the Number is even then inserting it in the beginning 
            insertBegin(&head,temp->data);
            prev->next = temp->next;
        }
        prev = temp;
        temp = temp->next;
    }
    
    return head;
}

int main(){
	int data,size;
    struct node *head = NULL;
    printf("Please Enter the size of the List ");
    scanf("%d",&size);
    printf("Please Enter the Numbers \n");
    for(int i=0;i<size;i++){
        scanf("%d",&data);
        insert(&head,data);
    }
    printf("The Entered List is \t");
    printList(head);
    head = makeChanges(head);
    printf("The Changed List is \t");
    printList(head);
    return 0;
}