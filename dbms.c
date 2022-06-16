#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person 
{
    int id;
    char name[20];
    char branch[20];
};

int searchId(int id)
{
    FILE *file;
    file = fopen ("person.txt", "a+");

    struct person input;
    // read file contents till end of file
    while(fscanf(file, "%d %s %s\n", &input.id, input.name, input.branch)!=EOF)
    {
        if(id == input.id)
            return 1;
    }
    return 0;
}

void insertfn()
{
    FILE *filE;
    printf("Entered the insert Function \n");
    // open file for writing
    filE = fopen ("person.txt", "a+");
    struct person ip;
    int y;
    struct person* ptr = &ip;
    printf("Enter id : ");
    scanf("%d",&y);
    while(searchId(y)==1)
    {
        printf("The id already exists please try again\n");
        printf("Enter id : ");
        scanf("%d",&y);
    }
    ptr->id = y;
    printf("Enter name : ");
    scanf("%s", ptr->name);
    printf("Enter branch : ");
    scanf("%s", ptr->branch);
    fprintf(filE, "%d %s %s\n", ptr->id,ptr->name,ptr->branch);
    if(fwrite != 0) 
        printf("contents to file written successfully !\n");
    else 
        printf("error writing file !\n");
    // close file
    fclose (filE);
}

void modstud()
{
    FILE *file,*file_temp;
    struct person input;
      
    // Open person.dat for reading
    file = fopen ("person.txt", "a+");
    file_temp = fopen("person_temp.txt","a+");
    if (file == NULL)
    {
        fprintf(stderr, "\nEmpty file\n");
        exit (1);
    }
    printf("Enter Student ID to modify student details : ");
    int y,z;
    scanf("%d",&y);
    z = y;
    // read file contents till end of file
    while(fscanf(file, "%d %s %s\n", &input.id, input.name, input.branch)!=EOF)
    {
        if(y == input.id)
        {
            fflush(stdin);
            printf("\nEnter student name: ");                                               
            scanf(" %s", input.name);

            printf("\nEnter student branch: ");                                               
            scanf("%s", input.branch);
            y++;
        }
        fprintf(file_temp, "%d %s %s\n", input.id, input.name, input.branch);
    }
    fclose(file); 
    fclose(file_temp);
    remove("person.txt");
    rename("person_temp.txt", "person.txt");

    if(z==y)
    {
        printf("Student not found\n");
    }
}

void deletefn()
{
    FILE *file,*file_temp;
    struct person input;
      
    // Open person.dat for reading
    file = fopen ("person.txt", "r+");
    file_temp = fopen("person_temp.txt","a+");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    int y,z;
    printf("Enter Student ID to be deleted : ");
    scanf("%d",&y);
    z = y;
    // read file contents till end of file
    while(fscanf(file, "%d %s %s\n", &input.id, input.name, input.branch)!=EOF)
    {
        if(y != input.id)
        {
            fprintf(file_temp, "%d %s %s\n", input.id, input.name, input.branch);
        }
        else
        {
            y++;
        }
    }
    if(z==y)
    {
        printf("Student not found\n");
    }
    fclose(file); 
    fclose(file_temp);
    remove("person.txt");
    rename("person_temp.txt", "person.txt");
}

void srchbrn()
{
    FILE *filE;
    struct person input;
      
    // Open person.dat for reading
    filE = fopen ("person.txt", "a+");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter the branch name\n");
    char x[20];
    scanf("%s",&x);
    int y = 0;
    // read file contents till end of file
    while(fscanf(filE, "%d %s %s\n", &input.id, input.name, input.branch)!=EOF)
    {
        if(!strcmp(x,input.branch))
        {
            printf ("id = %d name = %s branch = %s\n", input.id,input.name,input.branch);
            y++;
        }
    }
    if(y==0)
    {
        printf("No students found\n");
    }
    // close file
    fclose (filE);
}

void srchname()
{
    FILE *filE;
    struct person input;
      
    // Open person.dat for reading
    filE = fopen ("person.txt", "a+");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter the student name\n");
    char x[20];
    scanf("%s",&x);
    int y = 0;
    // read file contents till end of file
    while(fscanf(filE, "%d %s %s\n", &input.id, input.name, input.branch)!=EOF)
    {
        if(!strcmp(x,input.name))
        {
            printf ("id = %d name = %s branch = %s\n", input.id,input.name,input.branch);
            y++;
            break;
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
    printf("1. Insert 10 students in the student database.\n2. Modify the NAME or BRANCH (CSE, EE, and ECE) of the student.\n3. Delete the student using the Student ID.\n4. Search the list of students using BRANCH.\n5. Search the student by their NAME.\n6.Exit\n");
    int x = 0;
    while(x!=6)
    {
        printf("Enter a number : ");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            {
                for(int i=0;i<1;i++)
                {
                    insertfn();
                }
                break;
            }
            case 2:
            {
                modstud();
                break;
            }
            case 3:
            {
                deletefn();
                break;
            }
            case 4:
            {
                srchbrn();
                break;
            }
            case 5:
            {
                srchname();
                break;
            }
            case 6:
            {
                break;
            }
            default:
            {
                printf("\nInvalid option!");
            }
        }
    }
    return 0;
}
