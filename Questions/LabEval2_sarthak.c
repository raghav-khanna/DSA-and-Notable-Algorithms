/*
Name - Sarthak Kapoor
Roll No. - 20UEC115
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char *achievement;
    long long int roll;
    float gpa;
    struct node *next;
};

void insert(struct node **head, char data[100], long long int roll, float gpa); // Function for inserting a node at the end
void printList(struct node *head); // Function used to printing the List
// void revList(struct node **head); // Function used to reverse the List

void insert(struct node **head, char data[100],long long int roll, float gpa){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->achievement = (char *)malloc(sizeof(char)*100);
    strcpy(temp->achievement,data);
    temp->roll = roll;
    temp->gpa = gpa;
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
		printf("%s -> Roll No. - %lld -> GPA - %f \n",temp->achievement,temp->roll,temp->gpa);
		temp = temp->next;
	}
    printf("\n");
}

void revList(struct node **head,struct node *p){
    if(p->next==NULL){
        *head = p;
        return;
    }
    revList(head,p->next);
    struct node *q = p->next;
    q->next = p;
    p->next = NULL;
}

int main(){
    int n,students; // number of achievements and number of students
    long long int roll; // Long Long Integer to Store the Roll Number
    float gpa; // Float type variable to Store the GPA 
    char achievement[100]; // Store the Qualification

    printf("Please Enter the number of Students - ");
    scanf("%d",&students);

    for(int j=0;j<students;j++){
    printf("Enter details for Student - %d \n",j+1);
    struct node *head = NULL;
   
    printf("Enter the number of Qualification you want to enter - ");
    scanf("%d",&n);
   
    for(int i=0;i<n;i++){
        printf("Enter Qualification, Roll No. and GPA of Student - %d ",j+1);
        scanf("%s %lld %f",achievement,&roll,&gpa);
        insert(&head,achievement,roll,gpa);
    }
   
    printf("The Entered List of Achievements is - \n");
    printList(head);
   
    printf("The Reversed List of Achievements is - \n");
    //Reversing the List
    revList(&head,head);
    //Printing the reversed list
    printList(head);
    }
    
    return 0;
}