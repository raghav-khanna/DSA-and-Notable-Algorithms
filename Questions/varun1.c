#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
     char val;
     struct ListNode *next;
}Node;


int isPalindrome(Node *head);
Node* take_input(int n);

// Do not change anything above this line

void reverse(Node** head_ref)
{
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;
     
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void printList(Node *head){
    Node *temp;
    temp = head;
    while(temp != NULL){
		printf("%c ",temp->val);
		temp = temp->next;
	}
    printf("\n");
}

int isPalindrome(Node *head) {
    // write code here    
    // Return 0 and 1
    Node *p, *q, *newHead;
    p = head;
    q = head;
    if(p->next == NULL) return 0;
    //Splitting the list into two
    while(1){
        printf("Q and P are respectively %c %c \n", q->val, p->val);
        p = p->next->next;
        
        if(p == NULL){
            newHead = q->next;
            printf("Two Splitted Lists are  %c \n",q->next->val);
            printList(newHead);
            reverse(&newHead);
            printList(newHead);
            break;
        }
        if(p->next == NULL)
            return 0;
        q = q->next;
    }
    p = head;
    q = newHead;

    while(q != NULL && p != NULL){
        char revChar = (122 - (p->val)) + 97;
        printf("%c %c %c \n",p->val,q->val,revChar);
        if(revChar != q->val) return 0;
        printf("Hello\n");
        p = p->next;
        q = q->next;
    }
    return 1;

}

Node* take_input(int n){
	// Write code to take input here, do not change the return type.
    Node *head = NULL;
    Node *temp = (Node*)malloc(sizeof(Node));
    scanf("%c", &temp->val);
    head = temp;
    temp->next = NULL;
    n--;
    Node * temp2;
    temp2 = temp;
    while(n--){
        Node *temp1 = (Node*)malloc(sizeof(Node));
        scanf("%c", &temp1->val);
        temp2 ->next = temp1;
        temp1->next = NULL;
        temp2 = temp2->next;
    }
    return head;
}




// Do not change anything below this line

int main(){
	int n;
	scanf("%d\n",&n);
	Node* head=take_input(n);
	printList(head);
	if(isPalindrome(head)) printf("Special String\n");
	else printf("Not a special string\n");

}