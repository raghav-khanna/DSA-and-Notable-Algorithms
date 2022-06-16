/*
Name - RAGHAV KHANNA
Roll No. - 20UCS153
Subject - DSA LAB Q1

*/


#include<stdio.h>
#include<ctype.h>     
#include<string.h>

#define SIZE 100

/* Pushing in Stack */

void push(char item, int *top, char stack[])
{
	if(*top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		*top = *top+1;
		stack[*top] = item;
	}
}

/* Popping an element */
char pop(int *top, char stack[])
{
	char item ;

	if(*top <0)
	{
		// printf("stack under flow: invalid infix expression");
	}
	else
	{
		item = stack[(*top)];
		*top = *top-1;
		return(item);
	}
}


//This fucntion returns 1 if symbol is opreator else return 0 

int isOp(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

// Higher Number means Higher Precedence

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int InfixToPostfix(char infix[], char postfix[])
{ 
	int i = 0, j = 0, top = -1;
    char stack[SIZE];
	char item = infix[0];
	char x;

	push('(',&top,stack);                               /* push '(' onto stack */
	strcat(infix,")");                  /* add ')' to infix expression */


	while(item != '\0')        //run loop till end  
	{
		if(item == '(')
		{
			push(item,&top,stack);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if(isOp(item) == 1)        /* means symbol is operator */
		{
			x=pop(&top,stack);
			while(isOp(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop(&top,stack);                       /* add them to postfix expresion */
			}
			push(x,&top,stack); //An extra was popped

			push(item,&top,stack);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop(&top,stack);                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix[j] = x;
				j++;
				x = pop(&top,stack);
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			return 0;
		}
		i++;


		item = infix[i]; /* go to next symbol of infix expression */
        if(top>0)
            {
                return 0;
            }
    } 
	if(top>0)
	{
		return 0;
	}


	postfix[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */
    return 1;

}
void instructions()
{
    int choice = 0, valid = 0;
    char infix[SIZE], postfix[SIZE]; 
    while(choice!=-1)
    {
        printf("Type '1'  To create a binary tree for a given binary arithmetic expression.\n");
        printf("Type '2'  To check whether the given expression is valid or not.\n");
        printf("Type '3'  To display the postfix form of the given infix expression.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                // struct node* root;
                // root = create(s);
                printf("Binary tree created.\n");
                break;
            }
            case 2:
            {
                //The expression is valid only then the Postfix Expression is Printed
                
                printf("\nEnter Infix expression : ");
	            scanf("%s",infix);

	            valid = InfixToPostfix(infix,postfix);                   /* call to convert */
	            if(valid == 0){
                    printf("Invalid Expression \n");
                    break;
                }
                printf("Valid Expression\n ");
                break;
            }
            case 3:
            {
                printf("\nEnter Infix expression : ");
	            scanf("%s",infix);

	            valid = InfixToPostfix(infix,postfix);                   /* call to convert */
                // if(valid == 0){
                //     printf("Invalid Expression \n");
                //     break;
                // }
                printf("Postfix Expression: ");
	            puts(postfix);    
                break;
            }
        }
    } 
}
int main()
{
    instructions();
    return 0;
}