#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char *name;
	struct node *next;
};

struct node *head = NULL;

void insert(char *s , int pos){

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->name = (char *)malloc(sizeof(char)*100);
	strcpy(temp->name,s);
	// temp->next = NULL;
	if(head==NULL){
		head = temp;
		temp->next = NULL;
	}else{
		struct node *temp1 = head;
		while(((temp1->next) != NULL) && pos>1){
			pos--;
			temp1 = temp1->next;
		}
		if(pos==0){
			temp->next = temp1;
			head = temp;
		}else{
			temp->next = temp1->next;
			temp1->next = temp;
		}

	}
	
}

void printList(){
	struct node *temp;
	temp = head;
	int i = 1;
	// if(temp->next == NULL){
	// 	printf("Node %d - \n", i);
	// 	printf("Data - %s\n", temp->name);
	// 	return;
	// }
	while(temp->next != NULL){
		printf("Node %d ---->", i);
		printf("\tData ---> %s\n", temp->name);
		i++;
		temp = temp->next;
	}
		printf("Node %d ---->", i);
		printf("\tData ---> %s\n", temp->name);
}

int main(){
	char name[100];
	for(int i=0;i<2;i++){
		printf("Enter the Name of the Candidate ");
		scanf("%s",name);
		insert(name,i);
	}
	printf("This is the List \n");
	printList();
	printf("Enter the Name of the Candidate to insert in the first position ");
	scanf("%s",name);
	insert(name,0);
	printf("This is the NEW List \n");
	printList();
	return 0;
	
}