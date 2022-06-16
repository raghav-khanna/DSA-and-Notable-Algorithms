#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node* next;
};

void push(struct node **head, char x)
{
    
    struct node* ptr = *head;
    struct node* temp = (struct node*) malloc(sizeof(struct node));
 
    temp -> data  = x;
 
    temp -> next = ptr;
 
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

char peek(struct node *head)
{
    // printf("%d",head->data);
    return head->data;
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

//Infix to Postfix

int isOperator(char ch){
    //Return 1 if true else 0
    if(ch == '+' ) return 1;
    if(ch == '-') return 1;
    if(ch == '*') return 1;
    if(ch == '/') return 1;
    if(ch == '^') return 1;
    return 0;
}

int precedence(char ch){
    if(ch == '^') return 4;
    if(ch == '*' || ch == '/') return 3;
    if(ch == '+' || ch == '-') return 2;
}

int isHigher(char top, char infix){
    //Return 1 if top is of Higher Precedence than infix
    if(top == infix == '^') return 0;
    if(precedence(top) >= precedence(infix)) return 1;
    return 0;
}


int convert(char infix[100],char postfix[100]){
    //Returns Zero iff the expression is not balanced
    int i = 0,j=0;
    // char ch;
    struct node *top = NULL;
    while(infix[i] != '\0'){
        //If it's an opening bracket, push in the stack
        if(infix[i] == '('){
            push(&top,infix[i]);
            i++;
            continue;
        }
        //If it's an operand, place in postfix array
        if( isalnum(infix[i]) ){
            if(infix[i+1] == '\0'){
                postfix[j] = infix[i];
                // printf("%c in Postfix now \n",infix[i]);
                j++;
                while(top != NULL && peek(top) != '('){
                    char ch = peek(top);
                    postfix[j] = ch;
                    j++;
                    pop(&top);
                }
                i++;
                continue;
            }
            postfix[j] = infix[i];
            printf("%c in Postfix now \n",infix[i]);
            i++;
            j++;
            continue;
        }
        //If it's an Operator, then first pop the operators of Higher Precedence (if any) then push this operator
        if( isOperator(infix[i]) ){
            while( top != NULL && peek(top) != '(' && isHigher(peek(top),infix[i])){
                char ch = peek(top);
                postfix[j] = ch;
                // printf("%c in Postfix now \n",ch);
                j++;
                pop(&top);
            }
            push(&top,infix[i]);
            i++;
            continue;
        }

        //If it's a Closing Bracket, then pop elements till you find and opening bracket

        if( infix[i] == ')' ){
            while( peek(top) != '(' && top != NULL){
                char ch = peek(top);
                postfix[j] = ch;
                // printf("%c in Postfix now \n",ch);
                j++;
                pop(&top);
                if(top == NULL){
                    printf("Not a Balanced Expression\n");
                    return 0;
                }

            }
            pop(&top);
            i++;
            continue;
        }

    }
    if(top != NULL){
        printf("Not a Balanced Expression\n");
        return 0;
    }
    postfix[j] = '\0';
    return 1;
}

void main()
{
    char infix[100],postfix[100];
    printf("Please Enter the Infix Expression - ");
    scanf("%s",infix);
    if(convert(infix,postfix))
        printf("The converted Postfix Expression is %s\n",postfix);
}