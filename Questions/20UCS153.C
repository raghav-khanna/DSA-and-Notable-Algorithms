/*
Name - Raghav Khanna
Roll No. - 20UCS153
Subject - DSA LAB
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> //For Generating a different result everytime 


//Structure Storing the Information of every node
struct node{
    char name[50];
    struct node *next;
};

void insert(struct node **, char []); //Inserting the Nodes
void printList(struct node *);        //Printing the Whole List
int rollDice(int);                    //Rolling the Dice   
void deleteNode(struct node **,int ); //Deleting the Node

//Function Used for Inserting the Nodes
void insert(struct node **head, char name[50]){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name,name);
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

//Function for Printing the List
void printList(struct node *head){
    struct node *temp;
    temp = head;
    while(temp != NULL){
		printf("%s \n",temp->name);
		temp = temp->next;
	}
    printf("\n");
}

//Function for Rolling the Dice
int rollDice(int max){
    srand(time(0));
    int num;
    if(max>6) max==6;
    num = rand()%max + 1;
    return num;
}

//Function for Deleting the Nodes
void deleteNode(struct node **head,int num){
    struct node *temp = *head;
    if(num==1){
        *head = temp->next;
        printf("Deleting the Person - %s \n",temp->name);
        free(temp);
        return;
    }
    for(int i=0;i<num-2;i++){
        temp = temp->next;
        //Temp Points to (n-1)th Node
    }
    struct node *temp2 = temp->next; //nth Node
    temp->next = temp2->next; //(n+1)th Node
    printf("Deleting the Person - %s \n",temp2->name);
    free(temp2);
}

int main(){
    char name[50]; // Name of the Person
    int num;       // To Store the Value of Dice 
    struct node *head = NULL; //Head of the List
    for(int i=0;i<20;i++){
        printf("Enter the Name of Person - %d --> ",i+1);
        scanf("%s",name); //Input the Name 
        insert(&head,name); //Insert the Name as a Node
    }
    printf("The List of the Names - \n"); //Printing the List of the Names
    printList(head);  
    for(int i=20;i>1;i--){
        //Rolling the Dice and Deleting the Node of that Number
        num = rollDice(i);
        deleteNode(&head,num);
    }
    //Finally Printing the Name of the Winner
    printf("\n--------The Winner is--------- \n \t");
    printList(head);
    return 0;

}

//gcc 20UCS153.c -o output
// ./output