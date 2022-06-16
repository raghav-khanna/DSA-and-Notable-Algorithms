#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    int ID;
    char Name[20];
    char Branch[10];
};
struct life
{
    int id;
    float mark_total[5];
};

int menue()
{

    int choice;
    printf("\n***************************Menue*********************************\n");
    printf("1-To Enter the record of a student\n");
    printf("2-To modify data of a student\n");
    printf("3-Delete the student details By ID\n");
    printf("4-Search students by Branch\n");
    printf("5-Search Student by Name\n");
    printf("6-To exit the programm\n");
    printf("7-To maintain the student Marks record\n");
    scanf("%d", &choice);
    return choice;
}
int search_id(int id)
{
    FILE *p;
    p = fopen("student_details.txt", "r");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct student st;
    while (fread(&st, sizeof(struct student), 1, p))
    {
        if (st.ID == id)
        {
            fclose(p);
            return st.ID;
        }
    }
    fclose(p);
    return 0;
}

void delete_ById()
{
    FILE *p;
    p = fopen("student_details.txt", "r");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct student st;
}

struct student details()
{
    int num;
    struct student st;
    printf("Enter Id name and branch\n");
    scanf("%d %s %s", &st.ID, st.Name, st.Branch);
    if (search_id(st.ID))
    {
        printf("^^^^^^^^^^^^^^ERRORRR^^^^^^^^^^^^^\n   This ID is already registerd\n Enter the details Again\n");
        st = details();
    }

    return st;
}

void entery_register()
{
    FILE *p;
    p = fopen("student_details.txt", "a");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct student st;
    st = details();
    fwrite(&st, sizeof(struct student), 1, p);
    fclose(p);
    return;
}

void show()
{
    FILE *pt;
    pt = fopen("student_details.txt", "r");
    struct student st;
    while (fread(&st, sizeof(struct student), 1, pt))
        printf("ID---> %d Name---->%s Branch---->%s\n", st.ID, st.Name, st.Branch);
    fclose(pt);
}

void modify_data()
{
    struct student st;
    int num, n;
    FILE *pt;
    pt = fopen("student_details.txt", "r+");
    while (fread(&st, sizeof(struct student), 1, pt) == 1)
    {
        printf("\nID-> %d Name-> %s Branch-> %s\n", st.ID, st.Name, st.Branch);
        printf("\nTo Modify this data press  <<1>> to Continue press <<2>>\n");
        scanf("%d", &num);
        if (num == 1)
        {
            printf("To modify name press << 1 >> \nFor branch press <<2>> \nFor Both <<3>>  \n");
            scanf("%d", &n);
            fseek(pt, -sizeof(struct student), SEEK_CUR);
            if (n == 1)
            {
                printf("Enter the Name:- ");
                scanf("%s", st.Name);
            }
            if (n == 2)
            {
                printf("Enter the Branch:- ");
                scanf("%s", st.Branch);
            }
            if (n == 3)
            {
                printf("Enter the Name:- ");
                scanf("%s", st.Name);
                printf("Enter the Branch:- ");
                scanf("%s", st.Branch);
            }
            fwrite(&st, sizeof(struct student), 1, pt);
        }
    }
    fclose(pt);
    return;
}

void search_ByName()
{
    FILE *p;
    char n[20];
    p = fopen("student_details.txt", "r");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct student st;
    printf("\nEnter the name you want to search:-  ");
    scanf("%s", n);
    while (fread(&st, sizeof(struct student), 1, p))
    {
        if (strcmp(st.Name, n) == 0)
        {
            printf("ID---> %d Name---->%s Branch---->%s\n", st.ID, st.Name, st.Branch);
        }
    }
    //  printf("\nNot Found any perion with that name\n");
    fclose(p);
    return;
}
void search_ByBranch()
{
    FILE *p;
    char name[20];
    p = fopen("student_details.txt", "r");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct student st;
    printf("\nEnter the Branch you want to search:-  ");
    scanf("%s", name);
    while (fread(&st, sizeof(struct student), 1, p))
    {
        if (strcmp(st.Branch, name) == 0)
        {
            printf("ID---> %d Name---->%s Branch---->%s\n", st.ID, st.Name, st.Branch);
        }
    }
    // printf("\nNot Found any perion with that name\n");
    fclose(p);
    return;
}

int men()
{
    int num;
    printf("\n**********************************Menue************************\n");
    printf("1-Insert Marks of all the registerd student \n");
    printf("2-Update marks\n");
    printf("3-Delete record\n");
    printf("4-Get marks by student ID\n");
    printf("5-Student with Threshold percentage\n");
    printf("6-Student of particular branch with per above threshold\n");
    printf("7-Exit the programm\n");
    scanf("%d", &num);
    return num;
}

void insert_marks()
{
    int id;
    printf("Enter the Student Id ");
    scanf("%d", &id);
    if (search_id)
    {
        FILE *pt;
        pt = fopen("marsks.txt", "a");
        if (pt == NULL)
        {
            printf("Eroor");
            exit(0);
        }
        struct life li;
        li.id = id;
        printf("\nEnter the  marks of DBMS  DS C int exact same order\n");
        scanf("%f %f %f", &li.mark_total[0], &li.mark_total[1], &li.mark_total[2]);
        li.mark_total[3] = li.mark_total[0] + li.mark_total[1] + li.mark_total[2];
        li.mark_total[4] = li.mark_total[3] / 3;
        fwrite(&li, sizeof(struct life), 1, pt);
        fclose(pt);
    }
    else
    {
        printf("\nId you entered is not present in the student record\n");
    }
}
int marks_udate_choice()
{
    int num;
    printf("\nFor updating DBMS marks press <<1>>\n For updating DS marks press <<2>>\nFor updating C marks press <<3>>\n ");
    printf("\nTo continue press <<4>>\n");
    scanf("%d", &num);
    return num;
}
void update_marks()
{
    int i, num;
    struct life li;
    FILE *pt;
    pt = fopen("marska.txt", "r+");
    printf("\nEnter the student ID you want to update marks off:-  ");
    scanf("%d", &i);

    if (search_id(i))
    {
        while (fread(&li, sizeof(struct life), 1, pt))
        {
            if (li.id == i)
            {
                while (1)
                {
                    fseek(pt, -sizeof(struct life), SEEK_CUR);
                    printf("\nCurret data DBMS-->%f DS-->%f C-->%f marks Total-->%f percentage-->%f", li.mark_total[0], li.mark_total[1], li.mark_total[2], li.mark_total[3], li.mark_total[4]);
                    num = marks_udate_choice();
                    switch (num)
                    {
                    case 1:
                        printf("\nEnter the new DBMS marks\n");
                        scanf("%f", &li.mark_total[0]);
                        break;
                    case 2:
                        printf("\nEnter the new DS marks\n");
                        scanf("%f", &li.mark_total[1]);
                        break;
                    case 3:
                        printf("\nEnter the new C marks\n");
                        scanf("%f", &li.mark_total[2]);
                        break;
                    case 4:
                        printf("!!!!Eureka!!!!\n Updation Complete\n");
                        break;
                    default:
                        printf("\nWrong choice\n");
                        break;
                    }
                    if (num == 4)
                    {
                        li.mark_total[3] = li.mark_total[0] + li.mark_total[1] + li.mark_total[2];
                        li.mark_total[4] = li.mark_total[3] / 3;
                        fwrite(&li, sizeof(struct life), 1, pt);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\n Student with entered id is not present\n");
    }
    fclose(pt);

    return;
}
void marsks_ByID()
{
    int id;
    printf("\nEnter the Id\n");
    scanf("%d", &id);
    FILE *p;
    p = fopen("marsks.txt", "r");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct life st;
    while (fread(&st, sizeof(struct life), 1, p))
    {
        if (st.id == id)
        {
            printf("\nStudent details ID-->%d DBMS-->%f DS-->%f C-->%f marks Total-->%f percentage-->%f", st.id, st.mark_total[0], st.mark_total[1], st.mark_total[2], st.mark_total[3], st.mark_total[4]);
            fclose(p);
            return;
        }
    }
    printf("\nNo data has been found\n");
    fclose(p);
    return;
}
void thresh(float per)
{
    FILE *p;
    p = fopen("marsks.txt", "r");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct life st;
    while (fread(&st, sizeof(struct life), 1, p))
    {
        if (st.mark_total[4] >= per)
        {
            printf("\nStudent details ID-->%d DBMS-->%f DS-->%f C-->%f marks Total-->%f percentage-->%f\n", st.id, st.mark_total[0], st.mark_total[1], st.mark_total[2], st.mark_total[3], st.mark_total[4]);
        }
    }
    //  printf("\nNo data has been found\n");
    fclose(p);
    return;
}
void par_bar()
{
    float per;
    char ch[10];
    printf("\nEnter the Branch and threshold percenatge\n");
    scanf("%s %f",ch,&per);
    FILE *p;
    FILE * pt;
    p = fopen("marsks.txt", "r");
    pt = fopen("student_details.txt", "r");
    // if (p == NULL || pt==NULL)
    // {
    //     printf("Eroor");
    //     exit(0);
    // }
    struct life st;
    struct student li;
    while (fread(&st, sizeof(struct life), 1, p) && fread(&li, sizeof(struct student), 1, pt))
    {
        if ((st.mark_total[4] >= per) && (strcmp(li.Branch, ch) == 0))
            {

                printf("\nStudent details ID---> %d Name---->%s Branch---->%s\n", li.ID, li.Name, li.Branch);
                printf("\n DBMS-->%f DS-->%f C-->%f Total-Marks-->%f percentage-->%f\n", st.mark_total[0], st.mark_total[1], st.mark_total[2], st.mark_total[3], st.mark_total[4]);
            }
    }
    //  printf("\nNo data has been found\n");
    fclose(p);
    fclose(pt);
    return;
}

void delete_marks()
{
    int id;
    printf("Enter the of which you want to delete Record");
    scanf("%d", &id);
    FILE *pt;
    struct student li;
    pt = fopen("student_details.txt", "r+");
    if (pt == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    while (fread(&li, sizeof(struct student), 1, pt) == 1)
    {
        if (li.ID == id)
        {
            fseek(pt, -sizeof(struct student), SEEK_CUR);
            li.ID = 0;
            memset(li.Name, 0, (sizeof(li.Name) / sizeof(li.Name[0])));
            memset(li.Branch, 0, (sizeof(li.Branch) / sizeof(li.Branch[0])));
            fwrite(&li, sizeof(struct student), 1, pt);
            break;
        }
    }
    fclose(pt);
    FILE *p;
    p = fopen("marsks.txt", "r+");
    if (p == NULL)
    {
        printf("Eroor");
        exit(0);
    }
    struct life st;
    while (fread(&st, sizeof(struct life), 1, p) == 1)
    {
        if (st.id == id)
        {
            fseek(p, -sizeof(struct life), SEEK_CUR);
            st.id = 0;
            st.mark_total[0] = 0;
            st.mark_total[1] = 0;
            st.mark_total[2] = 0;
            st.mark_total[3] = 0;
            st.mark_total[4] = 0;
            fwrite(&st, sizeof(struct life), 1, pt);
            break;
        }
    }
    fclose(p);
    return;
}

void marks()
{
    int num;
    float per;
    while (1)
    {
        num = men();
        switch (num)
        {
        case 1:
            insert_marks();
            break;
        case 2:
            update_marks();
            break;
        case 3:
            delete_marks();
            break;
        case 4:
            marsks_ByID();
            break;
        case 5:
            printf("\nEnter the threshold percentage\n");
            scanf("%f", &per);
            thresh(per);
            break;
        case 6:
            par_bar();
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }

    return;
}

int main()
{

    while (1)
    {
        int num = menue();
        switch (num)
        {
        case 1:
            entery_register();
            break;
        case 2:
            modify_data();
            break;
        case 3:
            delete_marks();
            break;
        case 4:
            search_ByBranch();
            break;
        case 5:
            search_ByName();
            break;
        case 6:
            exit(0);
            break;
        case 7:
            marks();
            break;
        default:
            show();
            // printf("\nWrong Choice");
            break;
        }
    }
}