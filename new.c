#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person 
{
    int id,DBMS,DS,C,TOTAL;
    float PERCENTAGE;
    char branch[20];
};

void insertfn()
{                                                                               
  struct person stu;  
  FILE *fp;
  char ch;
  int x,y;
  fp = fopen("marks.txt", "a+");
 
  
  printf("\nEnter student id in integers : ");
  begin:
  
  scanf("%d", &stu.id);
  y=0;
  x=stu.id;
   while(fscanf(fp, "%d %s %d %d %d %d %f \n", &stu.id,stu.branch,&stu.DBMS ,&stu.DS ,&stu.C ,&stu.TOTAL,&stu.PERCENTAGE)!=EOF)                                    
     { 
       if(x==stu.id)
       {                                                                         
         printf("\nEntered id is alreardy present, please enter again ");                        
         y=1;
         break;
         
       }
     }

 if(y==1){
     goto begin;
 }
 
 printf("\nEnter student branch: ");                                               
 scanf("%s", stu.branch);
 
 printf("\nEnter student marks in DBMS under 100 : ");
  
 scanf("%d", &stu.DBMS);
 
 printf("\nEnter student marks in DS under 100: ");
  
 scanf("%d", &stu.DS);
 
 printf("\nEnter student marks in C under 100: ");
  
 scanf("%d", &stu.C);
 
 stu.TOTAL=(stu.DBMS + stu.DS + stu.C);
 stu.PERCENTAGE= stu.TOTAL/3;



 fprintf(fp, "\n%d %s %d %d %d %d %f \n", x,stu.branch,stu.DBMS ,stu.DS ,stu.C ,stu.TOTAL,stu.PERCENTAGE);
 
  fclose(fp);
  printf("\nStudent details is written successfully!\n");
}

void update()
{
    struct person stu;                                                           
    FILE *fp,*fp_temp; 
    int id, status=0;                                                                    
    fp = fopen("marks.txt", "a+");  
    fp_temp = fopen("marks_temp.txt", "a+");
    if(fp == NULL)                                                                
    {                                                                              
        printf("\nStudent details does not exists!");                                           
    }                                                                             
    else                                                                          
    {
        printf("\nEnter student id: ");
        scanf("%d", &id);
                                   
        while(fscanf(fp,"%d %s %d %d %d %d %f \n", &stu.id,stu.branch,&stu.DBMS ,&stu.DS ,&stu.C ,&stu.TOTAL,&stu.PERCENTAGE)!=EOF)                                    
        { 
            if(id == stu.id)
            {                                                                         
    
                fflush(stdin);
       
                printf("\nEnter student marks in DBMS under 100 : ");
  
                 scanf("%d", &stu.DBMS);
 
                printf("\nEnter student marks in DS under 100: ");
  
                scanf("%d", &stu.DS);
 
                printf("\nEnter student marks in C under 100: ");
  
                scanf("%d", &stu.C);
 
                stu.TOTAL=(stu.DBMS + stu.DS + stu.C);
                stu.PERCENTAGE= (float)stu.TOTAL/3.0;
                status = 1;

            }

            fprintf(fp_temp, "\n%d %s %d %d %d %d %f \n", stu.id,stu.branch,stu.DBMS ,stu.DS ,stu.C ,stu.TOTAL,stu.PERCENTAGE);                                   ;
       
        }                                                                          
        fclose(fp); 
        fclose(fp_temp);
        remove("marks.txt");
        rename("marks_temp.txt", "marks.txt");
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
  int id, status=0;                                                             
  fp = fopen("marks.txt", "r+");                                   
  fp_temp = fopen("marks_temp.txt", "a+");
  if(fp == NULL)                                                                
  {                                                                             
    printf("\nStudent details does not exists!");                             
  }                                                                             
  else                                                                          
  {                                                                             
     printf("\nEnter student id: ");                                            
     scanf("%d", &id);
     while(fscanf(fp, "%d %s %d %d %d %d %f \n", &stu.id,stu.branch,&stu.DBMS ,&stu.DS ,&stu.C ,&stu.TOTAL,&stu.PERCENTAGE)!=EOF)                                    
     {                                                           
      if(id != stu.id)                                                         
      { 
        fprintf(fp_temp, "\n%d %s %d %d %d %d %f \n", stu.id,stu.branch,stu.DBMS ,stu.DS ,stu.C ,stu.TOTAL,stu.PERCENTAGE);
      }        
      else
      {
         status =1;
      }                                                                
     }                                                               
     if(status == 1)                                                               
     {                                                                             
      printf("\nStudent  detail is deleted for student id : %d\n", id);         
     }             
     fclose(fp);                                                                
     fclose(fp_temp);
     remove("marks.txt");
     rename("marks_temp.txt", "marks.txt");
  }                                                                             
}

void shwmarks()
{
    struct person stu;                                                           
    FILE *fp; 
    int status=0;   
    int per;
    fp = fopen("marks.txt", "a+");                                   
    if(fp == NULL)                                                                
    {                                                                             
        printf("\nStudent details does not exists!");                                           
    }                                                                             
    else                                                                          
    {
        printf("\nEnter student id : ");
        scanf("%d", &per);
        
        printf("\nstudent id\tstudent branch\tstudent DBMS\tstudent DS\tstudent C\tstudent TOTAL\tstudent PERCENT");
        
        while(fscanf(fp, "%d %s %d %d %d %d %f \n", &stu.id,stu.branch,&stu.DBMS ,&stu.DS ,&stu.C ,&stu.TOTAL,&stu.PERCENTAGE)!=EOF)                                 
        { 
        if(per==stu.id)
            {                                                                         
                printf("\n%d\t %s\t %d\t %d\t %d\t %d\t %f \n", stu.id,stu.branch,stu.DBMS ,stu.DS ,stu.C ,stu.TOTAL,stu.PERCENTAGE);                        
                status = 1;
                break;
            }
        }                                                                          
        fclose(fp);                                                                
    }                 
    if(status == 0)
    {
    printf("\nStudent name does not exists!");
    }
}

void abvthresh()
{
    struct person stu;                                                           
    FILE *fp; 
    int status=0;   
    int per;
    fp = fopen("marks.txt", "a+");                                   
    if(fp == NULL)                                                                
    {                                                                             
        printf("\nStudent details does not exists!");                                           
    }                                                                             
    else                                                                          
    {
        printf("\nEnter percent threshold: ");
        scanf("%d", &per);
        
        printf("\nstudent id\tstudent branch\tstudent DBMS\tstudent DS\tstudent C\tstudent TOTAL\tstudent PERCENT");
        
        while(fscanf(fp, "%d %s %d %d %d %d %f \n", &stu.id,stu.branch,&stu.DBMS ,&stu.DS ,&stu.C ,&stu.TOTAL,&stu.PERCENTAGE)!=EOF)                                 
        { 
        if(per<stu.PERCENTAGE)
            {                                                                         
                printf("\n%d\t %s\t %d\t %d\t %d\t %d\t %f \n", stu.id,stu.branch,stu.DBMS ,stu.DS ,stu.C ,stu.TOTAL,stu.PERCENTAGE);                        
                status = 1;
            }
        }                                                                          
        fclose(fp);                                                                
    }                 
    if(status == 0)
    {
    printf("\nStudent name does not exists!");
    }
}

void abvthreshBrn()
{
    struct person stu;                                                           
    FILE *fp; 
    int status=0;   
    int per;
    char branch[20];
    fp = fopen("marks.txt", "a+");                                   
    if(fp == NULL)                                                                
    {                                                                             
        printf("\nStudent details does not exists!");                                           
    }                                                                             
    else                                                                          
    {
        printf("\nEnter percent threshold: ");
        scanf("%d", &per);
        printf("\nEnter branch ");
        scanf("%s", branch);
        printf("\nstudent id\tstudent branch\tstudent DBMS\tstudent DS\tstudent C\tstudent TOTAL\tstudent PERCENT");
        
        while(fscanf(fp, "%d %s %d %d %d %d %f \n", &stu.id,stu.branch,&stu.DBMS ,&stu.DS ,&stu.C ,&stu.TOTAL,&stu.PERCENTAGE)!=EOF)                                 
        { 
        if(per<stu.PERCENTAGE  && !strcmp(stu.branch,branch) )
            {                                                                         
                printf("\n%d\t %s\t %d\t %d\t %d\t %d\t %f \n", stu.id,stu.branch,stu.DBMS ,stu.DS ,stu.C ,stu.TOTAL,stu.PERCENTAGE);                        
                status = 1;
            }
        }                                                                          
        fclose(fp);                                                                
    }                 
    if(status == 0)
    {
    printf("\nStudent name does not exists!");
    }
}

void showall() 
{                                                                               
  struct person stu;                                                           
  FILE *fp;                                                                     
  fp = fopen("marks.txt", "a+");                                   
  if(fp == NULL)                                                                
  {                                                                             
    printf("\nStudent details does not exists!");                             
  }                                                                             
  else                                                                          
  {                                                                             
     printf("\nstudent id\tstudent branch\tstudent DBMS\tstudent DS\tstudent C\tstudent TOTAL\tstudent PERCENT");                               
     while(fscanf(fp,"%d %s %d %d %d %d %f \n", &stu.id,stu.branch,&stu.DBMS ,&stu.DS ,&stu.C ,&stu.TOTAL,&stu.PERCENTAGE)!=EOF)                                    
         
     { 
      printf("\n%d\t %s\t %d\t %d\t %d\t %d\t %f \n", stu.id,stu.branch,stu.DBMS ,stu.DS ,stu.C ,stu.TOTAL,stu.PERCENTAGE);                                   
                             
     }                                                                          
     fclose(fp);                                                                
  }                                                                             
}  

int main ()
{
    printf("1. Insert marks of all the registered students.\n2. Updating marks.\n3. Deletion of a student record.\n4. Show the marks list.\n5. Search the students with PERCENTAGE above a threshold.\n6. Search the students of a particular BRANCH with PERCENTAGE above a threshold.\n");
    int x = 0;
    while(x!=8)
    {
        printf("Enter a number\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            {
                // for(int i = 0;;i<10;i++)
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
                shwmarks();
                break;
            }
            case 5:
            {
                abvthresh();
                break;
            }
            case 6:
            {
                abvthreshBrn();
                break;
            }
            case 7:
            {
                showall();
            }
        }
    }
    return 0;
}