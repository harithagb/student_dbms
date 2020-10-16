#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"dbms.h"

//Function prototypes:
void add(FILE * fp); //to add to list
FILE * del(FILE * fp);//to delete from list
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void printHead();//printing head line for each screen

int main()
{
    FILE * fp;
    Student s;
    int option;
    char another;
    
    if((fp=fopen("studentInfo.txt","rb+"))==NULL)
    {
        if((fp=fopen("studentInfo.txt","wb+"))==NULL)
        {
            printf("can't open file");
            return 0;
        }
    }
    while(1)
    {
        printHead();
        printf("\n\t");
        printChar('-',64);
        printf("\n\n\t\t\t1. ADD Student");
        printf("\n\n\t\t\t2. DELETE Student");
        printf("\n\n\t\t\t3. MODIFY Student");
        printf("\n\n\t\t\t4. DISPLAY Student LIST");
        printf("\n\n\t\t\t5. Search Record");
        printf("\n\n\t\t\t0. EXIT");    
        printf("\n\n\t\tEnter Your Option :--> ");
        scanf("%d",&option);       

        switch(option)
        {
            case 0: return 1;
                break;

            case 1: add(fp);
                break;

            case 2: fp=del(fp);
                break;

            case 3: modify(fp);
                break;

            case 4: displayList(fp);
                break;

            case 5: searchRecord(fp);
                break;

            default: printf("\n\t\tYou Pressed wrong key");
                printf("\n\t\tProgram terminated");
                exit(0);  

        }
    }
    return 1;
}

