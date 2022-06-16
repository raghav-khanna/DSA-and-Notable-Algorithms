//2 Linked Lists are given and we have to make a third one according to the given example

// HEAD 1 : 22 32 35 40 45 -> NULL
// HEAD 2 : 2 11 20 65 70 80 90 -> NULL

// HEAD 3 : 2 11 20 22 32 35 40 45 65 70 80 90 -> NULL

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
    while(temp->next != NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
    printf("%d ", temp->data);
    printf("\n");
}

struct node *makeThirdList(struct node *head1, struct node *head2, struct node *head3){
    struct node *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
	int cond1 = 0, cond2 = 0;
    while(1){
        int first = 0;
        if((ptr1->next == NULL) && cond1==1){
            //Copying rest of the elements of ptr2 directly
            while(ptr2 != NULL){
                insert(&head3,ptr2->data);
                ptr2 = ptr2->next;
            }
            return head3;
        }
        if((ptr2->next == NULL) && cond2==1){
            //Copying rest of the elements of ptr1 directly
            while(ptr1 != NULL){
                insert(&head3,ptr1->data);
                ptr1 = ptr1->next;
            }
            return head3;
        }
        if((ptr1->data) <= (ptr2->data)){
            insert(&head3,ptr1->data);
            first = 1;
            if(ptr1->next == NULL) 
                cond1 = 1;
            // printf("%d \n", ptr1->data);
            // printf("cond1 = %d", cond1);
        }
        if((ptr1->data) > (ptr2->data)){
            insert(&head3,ptr2->data);
            if(ptr2->next == NULL)
                cond2 = 1;
            // printf("%d \n", ptr2->data);
        }
       
        if((ptr1->next!=NULL) && first)
            ptr1 = ptr1->next;
        if((ptr2->next!=NULL) && !first)
            ptr2 = ptr2->next;
        if((ptr1->next == NULL) && (ptr2->next==NULL))
            break;
    }
    return head3;
}

int main(){
	int data;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    
    //Insertion in first List
    for(int i=0;i<3;i++){
        printf("Enter data for first List's Node - %d ",i+1);
        scanf("%d", &data);
        insert(&head1,data);
    }
    for(int i=0;i<4;i++){
        printf("Enter data for second List's Node - %d ",i+1);
        scanf("%d", &data);
        insert(&head2,data);
    }
    printf("Head 1 : \t");
    printList(head1);
    printf("Head 2 : \t");
    printList(head2);
    head3 = makeThirdList(head1,head2,head3);
    printf("Head 3 : \t");
    printList(head3);
    return 0;
}