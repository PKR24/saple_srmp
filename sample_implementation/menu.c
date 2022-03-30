#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};
void menu()
{
    int choice;
    system("cls");
    printf("<--:MENU:-->");
    printf("Enter appropriate number to perform following task.");
    printf("1 : Add Record.");
    printf("2 : View Record.");
    printf("3 : Search Record.");
    printf("4 : Modify Record.");
    printf("5 : Delete.");
    printf("6 : Exit.\n");
    printf("\n");
    printf("Enter your choice.\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        printf("<--:ADD RECORD:-->");
        printf("Enter details of student.");
        printf("Enter Name : ");
//        gets(std.name);///???
        fgets(std.name);
        printf("Enter Mobile Number : ");
        fgets(std.mobile);
        printf("Enter Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        printf("Enter Course : ");
//        gets(std.course);///???
        fgets(std.course);
        printf("Enter Branch : ");
        fgets(std.branch);
//        gotoxy(10,12);
//        printf("Enter Father's Name : ");
//        gets(std.fathername);
        fwrite(&std,sizeof(std),1,fp);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
        another = getchar();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    printf("Press any key to continue.");
    getchar();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    printf("<--:VIEW RECORD:-->");
    printf("S.No   Name of Student       Mobile No   Roll No  Course      Branch");
    printf("--------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        printf("%-7d%-22s%-12s%-9d%-12s%-12s",i,std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    printf("Press any key to continue.");
    getchar();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    printf("<--:SEARCH RECORD:-->");
    printf("Enter name of student : ");
    fflush(stdin);
    fgets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            printf("Name : %s",std.name);
            printf("Mobile Number : %s",std.mobile);
            printf("Roll No : %d",std.rollno);
            printf("Course : %s",std.course);
            printf("Branch : %s",std.branch);
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getchar();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    printf("<--:MODIFY RECORD:-->");
    printf("Enter name of student to modify: ");
    fflush(stdin);
    fgets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            printf("Enter name: ");
            fgets(std.name);
            printf("Enter mobile number : ");
            fgets(std.mobile);
            printf("Enter roll no : ");
            scanf("%d",&std.rollno);
            printf("Enter Course : ");
            fflush(stdin);
            fgets(std.course);
            printf("Enter Branch : ");
            fflush(stdin);
            fgets(std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getchar();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    printf("<--:DELETE RECORD:-->");
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    fgets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("Press any key to continue.");
    getchar();
    menu();
}
/*void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
*/
