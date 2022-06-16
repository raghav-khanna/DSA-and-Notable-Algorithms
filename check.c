#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define tot 300

struct person 
{
    int id,DBMS,DS,C,TOTAL;
    float PERCENTAGE;
    char branch[20];
    // char name[20];
};

struct personReal
{
  int id;
  char name[20];
  char branch[20];
};

int searchId(int id)
{
    FILE *file;
    file = fopen ("person.txt", "a+");
    if (NULL != file) {
      fseek (file, 0, SEEK_END);
      int size = ftell(file);

      if (0 == size) {
          printf("Person File is empty\n");
          return 0;
      }
    }
    // fseek(file, 0, SEEK_SET); 
    struct personReal stu;
    // read file contents till end of file
    while(fscanf(file, "%d %s %s\n", &stu.id,stu.branch,stu.name)!=EOF);          
    {
      printf("Currently on Student ID [Person File] - %d\n", stu.id);
        if(id == stu.id)
            return 1;
    }
    return 0;
}

int searchIdMarks(int id)
{
    FILE *file;
    file = fopen ("marks.txt", "a+");
    if (NULL != file) {
      fseek (file, 0, SEEK_END);
      int size = ftell(file);

      if (0 == size) {
          // printf("Marks File is empty\n");
          return 0;
      }
    }
    // rewind(file);
    struct person stu;
    // read file contents till end of file
    while(fscanf(file, "%d %s %d %d %d %d %f\n", &stu.id,stu.branch,&stu.DBMS, &stu.DS, &stu.C, &stu.TOTAL, &stu.PERCENTAGE)!=EOF);          
    {
      printf("Currently on Student ID [Marks File] - %d\n", stu.id);

        if(id == stu.id)
            return 1;
    }
    return 0;
}
    
char* searchIdBranch(int id)
{
    FILE *file;
    file = fopen ("person.txt", "a+");
    fseek(file, 0, SEEK_SET); 
    struct personReal input;
    // read file contents till end of file
    while(fscanf(file, "%d %s %s\n", &input.id, input.name, input.branch)!=EOF)
    {
        if(id == input.id){
            char *branch = malloc(sizeof(char)*20);
            strcpy(branch,input.branch);
            return branch;
        }
    }
    return 0;
}


void insertfn()
{
    FILE *filE, *marks;
      
    // open file for writing
    filE = fopen ("marks.txt", "a+");

    struct person ip;
    int y;
    struct person* ptr = &ip;
    printf("Enter id : ");
    scanf("%d",&y);
    // printf("Starting!!\n");
    while(searchId(y)==0)
    {
        printf("You entered %d and function returned [PERSON] %d\n",y,searchId(y));
        printf("The Student with this ID doesn't exist\n");
        printf("Enter id : ");
        scanf("%d",&y);
        if(y==-1) return;
    }

    while(searchIdMarks(y)==1)
    {
        printf("You entered %d and function returned [MARKS] %d\n",y,searchId(y));

        printf("The Student with this ID already exists in marks file. Try another \n");
        printf("Enter id : ");
        scanf("%d",&y);
        if(y==-1) return;

    }
    // printf("ID Exists!!\n");
    ptr->id = y;
    printf("Enter marks of DBMS : ");
    scanf("%d",&y);
    while(y<0 || y>100)
    {
        printf("Invalid Marks,Please enter again\n");
        scanf("%d",&y);
    }
    ptr->DBMS = y;
    printf("Enter marks of DS : ");
    scanf("%d",&y);
    while(y<0 || y>100)
    {
        printf("Invalid Marks,Please enter again\n");
        scanf("%d",&y);
    }
    ptr->DS = y;
    printf("Enter marks of C : ");
    scanf("%d",&y);
    while(y<0 || y>100)
    {
        printf("Invalid Marks,Please enter again\n");
        scanf("%d",&y);
    }
    ptr->C = y;
    ptr->TOTAL = ptr->C + ptr->DBMS + ptr->DS;
    ptr->PERCENTAGE = (ptr->C + ptr->DBMS + ptr->DS)/3.00;
    printf("Percentage is %f\n",ptr->PERCENTAGE);

    strcpy(ptr->branch, searchIdBranch(ptr->id));

    fprintf(filE, "%d %s %d %d %d %d %f\n", ptr->id,ptr->branch,ptr->DBMS,ptr->DS,ptr->C,ptr->TOTAL,ptr->PERCENTAGE);
    if(fwrite != 0) 
        printf("contents to file written successfully !\n");
    else 
        printf("error writing file !\n");
    // close file
    fclose (filE);
}

void update()
{
    struct person stu;                                                           
    FILE *fp,*fp_temp; 
    int id,y, status=0;                                                                    
    fp = fopen("person.txt", "a+");  
    fp_temp = fopen("person_temp.txt", "a+");
    if(fp == NULL)                                                                
    {                                                                             
        printf("\nStudent details does not exists!");                                           
    }                                                                             
    else                                                                          
    {
        printf("\nEnter student id: ");
        scanf("%d", &id);
                                        
        while(fscanf(fp_temp, "%d %s %d %d %d %d %d\n", &stu.id,stu.branch,&stu.DBMS,&stu.DS,&stu.C,&stu.TOTAL,&stu.PERCENTAGE)!=EOF);          
        { 
            if(id == stu.id)
            {
                fflush(stdin);
                printf("Enter marks of DBMS : ");
                scanf("%d",&y);
                while(y<0 || y>100)
                {
                    printf("Invalid Marks,Please enter again\n");
                    scanf("%d",&y);
                }
                stu.DBMS = y;
                printf("Enter marks of DS : ");
                scanf("%d",&y);
                while(y<0 || y>100)
                {
                    printf("Invalid Marks,Please enter again\n");
                    scanf("%d",&y);
                }
                stu.DS = y;
                printf("Enter marks of C : ");
                scanf("%d",&y);
                while(y<0 || y>100)
                {
                    printf("Invalid Marks,Please enter again\n");
                    scanf("%d",&y);
                }
                stu.C = y;
                stu.TOTAL = stu.C + stu.DBMS + stu.DS;
                stu.PERCENTAGE = ((stu.C + stu.DBMS + stu.DS)/300)*100;
                y++;
            }

            fprintf(fp_temp, "%d %s %d %d %d %d %d\n", stu.id,stu.branch,stu.DBMS,stu.DS,stu.C,stu.TOTAL,stu.PERCENTAGE);
            status = 1;
            
        }                                                                          
        fclose(fp); 
        fclose(fp_temp);
        remove("person.txt");
        rename("person_temp.txt", "person.txt");
    }                 
    if(status == 0)
    {
    printf("\nStudent Id does not exists!");
    }              
}

void deletefn()                                                               
{                                                                               
    struct person stu;                                                           
    FILE *fp, *fp_temp;                                                                     
    int id;                                                             
    fp = fopen("person.txt", "r+");                                   
    fp_temp = fopen("person_temp.txt", "a+");
    if(fp == NULL)                                                                
    {                                                                             
        printf("\nStudent details does not exists!");                             
    }                                                                             
    else                                                                          
    {                                                                             
        printf("\nEnter student id: ");                                            
        scanf("%d", &id);
        while(fscanf(fp_temp, "%d %s %d %d %d %d %d\n", &stu.id,stu.branch,&stu.DBMS,&stu.DS,&stu.C,&stu.TOTAL,&stu.PERCENTAGE)!=EOF);          
        {                                                           
            if(id != stu.id)                                                         
            { 
                fprintf(fp_temp, "%d %s %d %d %d %d %d\n", stu.id,stu.branch,stu.DBMS,stu.DS,stu.C,stu.TOTAL,stu.PERCENTAGE);
            }                                                                       
        }                                                                            
        fclose(fp);                                                                
        fclose(fp_temp);
        remove("person.txt");
        rename("person_temp.txt", "person.txt");
    }                                                                             
}

void fn4()
{
    FILE *filE;
    struct person stu;
      
    // Open person.dat for reading
    filE = fopen ("person.txt", "a+");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter the student ID : ");
    int x;
    scanf("%d",&x);
    int y = 0;
    // read file contents till end of file
    while(fscanf(filE, "%d %s %d %d %d %d %d\n", &stu.id,stu.branch,&stu.DBMS,&stu.DS,&stu.C,&stu.TOTAL,&stu.PERCENTAGE)!=EOF);          
    {
        if(x == stu.id)
        {
            printf ("id = %d DBMS = %d DS = %d C = %d TOTAL = %d PERCENTAGE = %d \n", stu.id,stu.DBMS,stu.DS,stu.C,stu.TOTAL,stu.PERCENTAGE);
            y++;
        }
    }
    if(y==0)
    {
        printf("Such student does not exist\n");
    }
    // close file
    fclose (filE);
}

void fn5()
{
    FILE *filE;
    struct person stu;
      
    // Open person.dat for reading
    filE = fopen ("person.txt", "a+");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter the threshold percentage : ");
    int x;
    scanf("%d",&x);
    int y = 0;
    // read file contents till end of file
    while(fscanf(filE, "%d %s %s\n", &stu.id, stu.DBMS, stu.DS, stu.C, stu.TOTAL, stu.PERCENTAGE)!=EOF)
    {
        if(stu.PERCENTAGE>x)
        {
            printf ("id = %d DBMS = %d DS = %d C = %d TOTAL = %d PERCENTAGE = %d \n", stu.id,stu.DBMS,stu.DS,stu.C,stu.TOTAL,stu.PERCENTAGE);
            y++;
        }
    }
    if(y==0)
    {
        printf("Such student does not exist\n");
    }
    // close file
    fclose (filE);
}

void fn6()
{
    FILE *filE;
    struct person stu;
      
    // Open person.dat for reading
    filE = fopen ("person.txt", "a+");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter the threshold percentage : ");
    int x;
    scanf("%d",&x);
    char z[20];
    printf("Enter the branch name : ");
    scanf("%s",&z);
    int y = 0;
    // read file contents till end of file
    while(fscanf(filE, "%d %s %s\n", &stu.id, stu.DBMS, stu.DS, stu.C, stu.TOTAL, stu.PERCENTAGE)!=EOF)
    {
        if(stu.PERCENTAGE>x && strcmp(z,stu.branch)==0)
        {
            printf ("id = %d DBMS = %d DS = %d C = %d TOTAL = %d PERCENTAGE = %d \n", stu.id,stu.DBMS,stu.DS,stu.C,stu.TOTAL,stu.PERCENTAGE);
            y++;
        }
    }
    if(y==0)
    {
        printf("Such student does not exist\n");
    }
    // close file
    fclose (filE);
}

int main ()
{
    printf("1. Insert marks of all the registered students.\n2. Updating marks.\n3. Deletion of a student record.\n4. Show the marks list.\n5. Search the students with PERCENTAGE above a threshold.\n6. Search the students of a particular BRANCH with PERCENTAGE above a threshold.\n");
    int x = 0;
    while(x!=7)
    {
        printf("Enter a number\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            {
                insertfn();
                break;
            }
            case 2:
            {
                update();
                break;
            }
            case 3:
            {
                deletefn();
                break;
            }
            case 4:
            {
                fn4();
                break;
            }
            case 5:
            {
                fn5();
                break;
            }
            case 6:
            {
                fn6();
                break;
            }
        }
    }
    return 0;
}