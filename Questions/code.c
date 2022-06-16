#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


//Structure For Creating Word Tokens
struct token
{
    int num;
    char *word[70];
};

//Structure for Hash-Map
struct freqtoken
{
    int count;
    char *words;
    struct freqtoken* next;
};

struct token* Create_Token(struct token* head,char para[])
{
   struct token *temp = (struct token*)malloc(sizeof(struct token));
   char x[70][20];
   int a = 0,c = 0, num = 0, n = strlen(para), i = 0;
   for( ; i < n ; i++)
   {
       if(isalpha(para[i]))
        {
            //Inserting in x only if it's a letter
            x[a][c] = tolower(para[i]);
            c++;
        }
        else if(para[i] != 39 && (para[i] = ' ' || i == n-1))
       {
           //Inserting NULL at the end of the word
           x[a][c] = '\0';
        //    printf("%s - Done!!\n",x[a]);
           a++;
           c = 0;
           continue;
       }
   }
   num = a;
   a = 0;
   for(i = 0;i<num;i++)
   {
       int r = strlen(x[i]);
       if(r>1 || (strcmp(x[i],"a") == 0))
       {
            temp->word[a] = (char*)malloc(sizeof(char)*strlen(x[i]));
            strcpy(temp->word[a],x[i]);
            // printf("%dth Word done!!\n",a);
            // printf("%s\n",temp->word[a]);
            a++;
       }
       
   }
   temp->num = a;
   head = temp;
   return head;
}


//Checking the Count
int check_count(struct freqtoken *head,char *x)
{
    struct freqtoken *ptr = head;
   while (ptr != NULL ) 
   {
    //    printf("%s is being compared with %s\n",ptr->words,x);
       if(strcmp(ptr->words,x) == 0)
       {
        //    printf("%s is found. Returning it's count - %d\n",ptr->words,ptr->count);
           return ptr->count;
       }
       ptr = ptr->next;
   }
   return 0;
}

int Find_Articles_words(struct freqtoken *head1,struct freqtoken *head2)
{
    int x = 0;
    // Counting the number of Articles
    x = x + check_count(head1,"a") + check_count(head1,"an") + check_count(head2,"the");
    return x;
}

void init_table(struct freqtoken* ptr[]){
    for(int i = 0; i<26; i++){
        ptr[i] = NULL;
    }
    //Table is Empty
    return;
}


// void Display_Most_Rare_words( );

// void Display_Most_freq_words( );


//Inserting in Hash Map
struct freqtoken* insert(char word[],struct freqtoken* ptr){

    struct freqtoken* t;
    t = (struct freqtoken*) malloc(sizeof(struct freqtoken));

    if(ptr == NULL){
        
        t->words = (char *)malloc(sizeof(char)*(strlen(word)));
        strcpy(t->words, word);
        t->next = NULL;
        t->count = 1;
        ptr = t;

    }else{
        // printf("Word present - %s\n",ptr->words);
        // printf("Collision for word - %s\n",word);
        struct freqtoken* temp = ptr;
        struct freqtoken* prev = NULL;
        while(temp != NULL){
            // printf("Comparing %s to %s\n",word,temp->words);
            if(strcmp(temp->words,word)==0){
                // printf("Found DUPLICATES\n");
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        // if(prev != NULL)
        //     printf("Insertion to be done after - %s\n",prev->words);
        // else   
        //     printf("Prev is Null\n");
        if(temp == NULL){
            // printf("Insertion to be done after - %s\n",prev->words);
            t->words = (char *)malloc(sizeof(char)*(strlen(word)));
            strcpy(t->words, word);
            t->next = NULL;
            t->count = 1;
            prev->next = t;
            // printf("Insertion done after %s \n",prev->words);
        }else{
            temp->count++;
            // printf("Count of %s is incremented to %d\n",temp->words,temp->count);
        }
    }
    return ptr;
}

void printHashmap(struct freqtoken* m[]){
    struct freqtoken* temp;
    int i = 0;
    printf("_______________Printing the Hash Table_______________\n");
    while(i<26){
        temp = m[i];
        printf("%d - ",i);
        if(temp==NULL) printf("--------------------");
        while(temp != NULL){
            printf(" %s -> ",temp->words);
            temp = temp->next;
        }
        printf("   NULL");
        printf("\n");
        i++;
    }
}

void create_hashmap(struct token* head, struct freqtoken *m[]){
    //Creating an array of pointers of type Freqtoken
    for(int i=0; i<(head->num); i++){
        // if(strlen(head->word[i]) == 0) continue;
        int index = head->word[i][0] % 26;
        // printf("Word is %s. Index is %d \n",head->word[i],index);

        m[index] = insert(head->word[i],m[index]);
        // printf("___________INSERTION DONE__________\n");
        // printf("i = %d and head->num = %d\n",i,head->num);
    }
    // printf("___________________COMPLETED_______________\n");
    //Passing Pointers to 'a' and 't' for finding a,an and the

}

void Remove_Numerals(){
    //Numerals were already removed while creating Tokens
    return;
}

int main()
{
    char para1[] = "India's and an an an a the the the the about apple.";
    char para2[] = "The speed, scale and substance of this change are unprecedented, even unpredictable. Yet, one thing is absolutely predictable: India’s time has come. Destiny and Drive are making the 21st century’s favourite nation ready for a great leap forward.";
    char para3[] = "India stands at the doorstep of prosperity that is both significant and inclusive, and of delivering all-round human development through the democratic route. With faith in our potential, confidence in our collective capabilities, and unity in action, we can exceed the world’s expectations.";
    char para4[] = "My source of optimism is our recent past. In 1991, India showed foresight and courage in changing both the direction and determinants of its economy. The government placed the private sector also at the commanding heights of the national economy, which the public sector had occupied for the previous four decades.";
    char para5[] = "It ended the license-quota raj, liberalised trade and industrial policies, and freed up capital markets and the financial sector. These reforms liberated India’s entrepreneurial energy."; 
   
    struct token *head1 = NULL;
    struct token *head2 = NULL;
    struct token *head3 = NULL;
    struct token *head4 = NULL;
    struct token *head5 = NULL;
    
    //Creating Token for each Para
    
    head1 = Create_Token(head1,para1);
    head2 = Create_Token(head2,para2);
    head3 = Create_Token(head3,para3);
    head4 = Create_Token(head4,para4);
    head5 = Create_Token(head5,para5);

    printf("Tokens Created\n");

    //Removing The Numerals
    
    Remove_Numerals();

    //Comment out for creating the Hash Map
    struct freqtoken *m[26];
    init_table(m);
    create_hashmap(head1,m);
    create_hashmap(head2,m);
    create_hashmap(head3,m);
    create_hashmap(head4,m);
    create_hashmap(head5,m);

    printf("----------------Finding Articles--------------\n");
    int Articles = Find_Articles_words(m[19],m[12]);
    printf("Number of Articles = %d\n",Articles);
    printf("------------------------------\n");

    printHashmap(m);
    
    printf("Hash Map Created\n");
    
    
    
    return 1;
}