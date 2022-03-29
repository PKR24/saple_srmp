#include<stdio.h>
#include"conio.h"
#include<stdlib.h>
#include"windows.h"
#include<string.h>
#include"menu.h"
int main(int argc,char **argv)
{
    //gotoxy(15,8);
    printf("<--:Student Record Management System:-->\n");
    printf("Press any key to continue.\n");
    gotoxy(19,15);
    getch();
    menu();
    return 0;
}
