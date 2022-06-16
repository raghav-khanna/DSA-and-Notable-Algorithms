#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct person 
{
    int id;
    char name[20];
    char branch[20];
};

int searchId(int id)
{
    FILE *file;
    file = fopen ("person.dat", "w");

    struct person input;
    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, file))
    {
        if(id == input.id)
            return 1;
    }
    return 0;
}

void insertfn()
{
    FILE *filE;
      
    // open file for writing
    filE = fopen ("person.dat", "w");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }
  
    struct person ip[10];
    char x[20];
    int y;
    for(int i=0;i<1;i++)
    {
        struct person* ptr = &ip[i];
        printf("Enter id : ");
        scanf("%d",&y);
        if(searchId(y)==1)
        {
            printf("This id already exists\n");
            i--;
            continue;
        }
        ptr->id = y;
        printf("Enter name : ");
        cin>>ptr->name;
        printf("Enter branch : ");
        cin>>ptr->branch;
        fwrite (ptr, sizeof(struct person), 1, filE);
    }
      
    if(fwrite != 0) 
        printf("contents to file written successfully !\n");
    else 
        printf("error writing file !\n");
    // close file
    fclose (filE);
}

void modstud()
{
    FILE *filE;
    struct person input;
      
    // Open person.dat for reading
    filE = fopen ("person.dat", "r");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter Student ID to be modified\n");
    int y,z;
    scanf("%d",&y);
    z = y;
    char x[20];
    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, filE))
    {
        if(y == input.id)
        {
            struct person* ptr = &input;
            input.id = y;
            printf("Enter name :\n");
            cin>>ptr->name;
            printf("Enter branch :\n");
            cin>>ptr->branch;
            fwrite (&input, sizeof(struct person), 1, filE);
            y++;
            break;
        }
    }
    if(z==y)
    {
        printf("Student not found\n");
    }
    // close file
    fclose (filE);
}

void deletefn()
{
    FILE *filE;
    struct person input;
      
    // Open person.dat for reading
    filE = fopen ("person.dat", "r");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter Student ID to be delted\n");
    int y,z;
    scanf("%d",&y);
    z = y;
    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, filE))
    {
        if(y == input.id)
        {
            struct person* ptr = &input;
            free(ptr);
            y++;
            break;
        }
    }
    if(z==y)
    {
        printf("Student not found\n");
    }
    // close file
    fclose (filE);
}

void srchbrn()
{
    FILE *filE;
    struct person input;
      
    // Open person.dat for reading
    filE = fopen ("person.dat", "r");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter the branch name\n");
    char x[20];
    // cin.getline(x,20);
    cin>>x;
    int y = 0;
    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, filE))
    {
        if(x == input.branch)
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
    filE = fopen ("person.dat", "r");
    if (filE == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Enter the student name\n");
    char x[20];
    // cin.getline(x,20);
    cin>>x;
    int y = 0;
    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, filE))
    {
        if(x == input.name)
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
        }
    }
    return 0;
}