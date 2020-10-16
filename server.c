#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#include"dbms.h"





//----printing character ch at n times ------



void printChar(char ch,int n)

{

    while(n--)

    {

        putchar(ch);

    }

}



//-----Printing Head Line of the program -----



void printHead()

{

    

    printf("\n\n\t");

    printChar('=',16);

    printf("[STUDENT] [INFORMATION] [SYSTEM]");

    printChar('=',16);

    printf("\n");

}





// ==========ADDING NEW RECORD==========================



void add(FILE * fp)

{

    printHead();

    char another='y';

    Student s;

    

    

    fseek(fp,0,SEEK_END);

    while(another=='y'||another=='Y')

    {

        

        printf("\n\n\t\tEnter SRN of Student\t");

        fflush(stdin);

        scanf("%s",s.srn );

        

        printf("\n\n\t\tEnter Full Name of Student\t");

        fflush(stdin);

        scanf("%s",s.name);

        

        printf("\n\n\t\tEnter Branch\t");

        fflush(stdin);

        scanf("%s",s.branch);

        

        printf("\n\n\t\tENTER PHYSICS CYCLE MARKS:\n\t");

        printf("\n\n\t\tEnter CS Marks \t\t");

        scanf("%f",&s.marks[0]);

        printf("\n\n\t\tEnter CS LAB Marks \t");

        scanf("%f",&s.marks[1]);

        printf("\n\n\t\tEnter EEE Marks \t");

        scanf("%f",&s.marks[2]);

        printf("\n\n\t\tEnter MATH Marks \t");

        scanf("%f",&s.marks[3]);

        printf("\n\n\t\tEnter MECH Marks \t");

        scanf("%f",&s.marks[4]);

        printf("\n\n\t\tEnter CAD LAB Marks \t");

        scanf("%f",&s.marks[5]);

        printf("\n\n\t\tEnter PHY Marks \t");

        scanf("%f",&s.marks[6]);

        printf("\n\n\t\tEnter PHY LAB Marks \t");

        scanf("%f",&s.marks[7]);

        

        printf("\n\n\t\tENTER CHEM CYCLE MARKS:\n\t");

        printf("\n\n\t\tEnter CS Marks \t");

        scanf("%f",&s.marks[8]);

        printf("\n\n\t\tEnter CS LAB Marks \t");

        scanf("%f",&s.marks[9]);

        printf("\n\n\t\tEnter ECE Marks \t");

        scanf("%f",&s.marks[10]);

        printf("\n\n\t\tEnter MATH Marks \t");

        scanf("%f",&s.marks[11]);

        printf("\n\n\t\tEnter CIVIL Marks \t");

        scanf("%f",&s.marks[12]);

        printf("\n\n\t\tEnter BIOTECH Marks \t");

        scanf("%f",&s.marks[13]);

        printf("\n\n\t\tEnter CHEM Marks \t");

        scanf("%f",&s.marks[14]);

        printf("\n\n\t\tEnter CHEM LAB Marks \t");

        scanf("%f",&s.marks[15]);

        

        s.sgpa[0]=(((s.marks[0]/10)*4)+((s.marks[1]/10)*1)+((s.marks[2]/10)*4)+((s.marks[3]/10)*4)+((s.marks[4]/10)*4)+((s.marks[5]/10)*2)+((s.marks[6]/10)*4)+((s.marks[7]/10)*1))/24;

        s.sgpa[1]=(((s.marks[8]/10)*4)+((s.marks[9]/10)*1)+((s.marks[10]/10)*4)+((s.marks[11]/10)*4)+((s.marks[12]/10)*4)+((s.marks[13]/10)*2)+((s.marks[14]/10)*4)+((s.marks[15]/10)*1))/24;

        s.cgpa=(s.sgpa[0]+s.sgpa[1])/2;

        

        fwrite(&s,sizeof(s),1,fp);

        

        printf("\n\n\t\tWant to enter another student info (Y/N)\t");

        fflush(stdin);

        scanf(" %c",&another);

    }

}





//===================DELETING A RECORD FROM LIST ============

FILE * del(FILE * fp)

{

    printHead();

    

    Student s;

    int flag=0,siz=sizeof(s);

    char tempRoll[14];

    FILE *ft;

    

    if((ft=fopen("temp.txt","wb+"))==NULL)

    {

        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");

        //system("pause");

        return fp;

    }

    

    printf("\n\n\tEnter SRN of Student to Delete the Record");

    printf("\n\n\t\t\tSRN : ");

    scanf("%s",tempRoll);

    

    rewind(fp);

    

    

    while((fread(&s,siz,1,fp))==1)

    {

        if(strcmp(s.srn,tempRoll)==0)

        { flag=1;

            printf("\n\tRecord Deleted for");

            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%s\n\t",s.name,s.branch,s.srn);

            continue;

        }

        

        fwrite(&s,siz,1,ft);

    }

    

    

    fclose(fp);

    fclose(ft);

    

    remove("studentInfo.txt");

    rename("temp.txt","studentInfo.txt");

    

    if((fp=fopen("studentInfo.txt","rb+"))==NULL)

    {

        printf("ERROR");

        return  NULL;

    }

    

    if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

    

    printChar('-',65);

    printf("\n\t");

    //system("pause");

    return fp;

}





//===========MODIFY A RECORD ===========================



void modify(FILE * fp)

{

    printHead();

    

    Student s;

    int flag=0,siz=sizeof(s);

    char tempRoll[14];

    

    printf("\n\n\tEnter SRN of Student to MODIFY the Record : ");

    scanf("%s",tempRoll);

    

    rewind(fp);

    

    while((fread(&s,siz,1,fp))==1)

    {

        if(strcmp(s.srn,tempRoll)==0)

        {flag=1;

            break;

        }

    }

    

    if(flag==1)

    {

        fseek(fp,-siz,SEEK_CUR);

        printf("\n\n\t\tRECORD FOUND");

        printf("\n\n\t\tEnter New Data for the Record");

        

        printf("\n\n\t\tEnter Full Name of Student\t");

        fflush(stdin);

        scanf("%s",s.name);

        

        printf("\n\n\t\tEnter Branch\t");

        fflush(stdin);

        scanf("%s",s.branch);

        

        printf("\n\n\t\tENTER PHYSICS CYCLE MARKS:\n\t");

        printf("\n\n\t\tEnter CS Marks \t\t");

        scanf("%f",&s.marks[0]);

        printf("\n\n\t\tEnter CS LAB Marks \t");

        scanf("%f",&s.marks[1]);

        printf("\n\n\t\tEnter EEE Marks \t");

        scanf("%f",&s.marks[2]);

        printf("\n\n\t\tEnter MATH Marks \t");

        scanf("%f",&s.marks[3]);

        printf("\n\n\t\tEnter MECH Marks \t");

        scanf("%f",&s.marks[4]);

        printf("\n\n\t\tEnter CAD LAB Marks \t");

        scanf("%f",&s.marks[5]);

        printf("\n\n\t\tEnter PHY Marks \t");

        scanf("%f",&s.marks[6]);

        printf("\n\n\t\tEnter PHY LAB Marks \t");

        scanf("%f",&s.marks[7]);

        

        printf("\n\n\t\tENTER CHEM CYCLE MARKS\n\t");

        printf("\n\n\t\tEnter CS Marks \t\t");

        scanf("%f",&s.marks[8]);

        printf("\n\n\t\tEnter CS LAB Marks \t");

        scanf("%f",&s.marks[9]);

        printf("\n\n\t\tEnter ECE Marks \t");

        scanf("%f",&s.marks[10]);

        printf("\n\n\t\tEnter MATH Marks \t");

        scanf("%f",&s.marks[11]);

        printf("\n\n\t\tEnter CIVIL Marks \t");

        scanf("%f",&s.marks[12]);

        printf("\n\n\t\tEnter BIOTECH Marks \t");

        scanf("%f",&s.marks[13]);

        printf("\n\n\t\tEnter CHEM Marks \t");

        scanf("%f",&s.marks[14]);

        printf("\n\n\t\tEnter CHEM LAB Marks \t");

        scanf("%f",&s.marks[15]);

        

        s.sgpa[0]=(((s.marks[0]/10)*4)+((s.marks[1]/10)*1)+((s.marks[2]/10)*4)+((s.marks[3]/10)*4)+((s.marks[4]/10)*4)+((s.marks[5]/10)*2)+((s.marks[6]/10)*4)+((s.marks[7]/10)*1))/24;

        s.sgpa[1]=(((s.marks[8]/10)*4)+((s.marks[9]/10)*1)+((s.marks[10]/10)*4)+((s.marks[11]/10)*4)+((s.marks[12]/10)*4)+((s.marks[13]/10)*2)+((s.marks[14]/10)*4)+((s.marks[15]/10)*1))/24;

        s.cgpa=(s.sgpa[0]+s.sgpa[1])/2;

        

        fwrite(&s,sizeof(s),1,fp);

    }

    

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    

    printf("\n\n\t");

    //system("pause");

    

}





//====================DISPLAY THE LIST =================

void displayList(FILE * fp)

{   printHead();

    Student s;

    int siz=sizeof(s);

    

    rewind(fp);

    

    while((fread(&s,siz,1,fp))==1)

    {

        printf("\n\t\tSRN : %s",s.srn);

        printf("\n\t\tNAME : %s",s.name);

        printf("\n\n\t\tBRANCH : %s",s.branch);

        printf("\n\n\tMarks: ");

        

        printf("\n\n\tPHY cycle marks\n\t");

        printf("\n\n\t\tCS Marks: \t");

        printf("%.2f",s.marks[0]);

        printf("\n\n\t\tCS LAB Marks: \t");

        printf("%.2f",s.marks[1]);

        printf("\n\n\t\tEEE Marks \t");

        printf("%.2f",s.marks[2]);

        printf("\n\n\t\tMATH Marks \t");

        printf("%.2f",s.marks[3]);

        printf("\n\n\t\tMECH Marks \t");

        printf("%.2f",s.marks[4]);

        printf("\n\n\t\tCAD LAB Marks \t");

        printf("%.2f",s.marks[5]);

        printf("\n\n\t\tPHY Marks \t");

        printf("%.2f",s.marks[6]);

        printf("\n\n\t\tPHY LAB Marks \t");

        printf("%.2f",s.marks[7]);

        

        printf("\n\n\tCHEM cycle marks\n\t");

        printf("\n\n\t\tCS Marks \t");

        printf("%.2f",s.marks[8]);

        printf("\n\n\t\tCS LAB Marks \t");

        printf("%.2f",s.marks[9]);

        printf("\n\n\t\tECE Marks \t");

        printf("%.2f",s.marks[10]);

        printf("\n\n\t\tMATH Marks \t");

        printf("%.2f",s.marks[11]);

        printf("\n\n\t\tCIVIL Marks \t");

        printf("%.2f",s.marks[12]);

        printf("\n\n\t\tBIOTECH Marks \t");

        printf("%.2f",s.marks[13]);

        printf("\n\n\t\tCHEM Marks \t");

        printf("%.2f",s.marks[14]);

        printf("\n\n\t\tCHEM LAB Marks \t");

        printf("%.2f",s.marks[15]);

        

        printf("\n\t\tSGPA PHY SEM : %.2f",s.sgpa[0]);

        printf("\n\t\tSGPA CHEM SEM : %.2f",s.sgpa[1]);

        printf("\n\t\tCGPA : %.2f \n",s.cgpa);

        

        printChar('-',65);

    }

    printf("\n\n\n\t");

    printChar('*',65);

    printf("\n\n\t");

    //system("pause");

}



//==================== SEARCH AND DISPLAY =================



void searchRecord(FILE *fp)

{printHead();

    

    int flag,siz;

    char tempRoll[14];

    Student s;

    char another='y';

    

    siz=sizeof(s);

    

    while(another=='y'||another=='Y')

    {

        printf("\n\n\tEnter SRN of Student to search the record : ");

        scanf("%s",tempRoll);

        

        rewind(fp);

        

        while((fread(&s,siz,1,fp))==1)

        {

            if(strcmp(s.srn,tempRoll)==0)

            {flag=1;

                break;

            }

        }

        

        if(flag==1)

        {

            printf("\n\t\tSRN : %s",s.srn);

            printf("\n\t\tNAME : %s",s.name);

            printf("\n\n\t\tBRANCH : %s",s.branch);

            printf("\n\n\tMarks: ");

            

            printf("\n\n\tPHY cycle marks\n\t");

            printf("\n\n\t\tCS Marks: \t");

            printf("%.2f",s.marks[0]);

            printf("\n\n\t\tCS LAB Marks: \t");

            printf("%.2f",s.marks[1]);

            printf("\n\n\t\tEEE Marks \t");

            printf("%.2f",s.marks[2]);

            printf("\n\n\t\tMATH Marks \t");

            printf("%.2f",s.marks[3]);

            printf("\n\n\t\tMECH Marks \t");

            printf("%.2f",s.marks[4]);

            printf("\n\n\t\tCAD LAB Marks \t");

            printf("%.2f",s.marks[5]);

            printf("\n\n\t\tPHY Marks \t");

            printf("%.2f",s.marks[6]);

            printf("\n\n\t\tPHY LAB Marks \t");

            printf("%.2f",s.marks[7]);

            

            printf("\n\n\tCHEM cycle marks\n\t");

            printf("\n\n\t\tCS Marks \t");

            printf("%.2f",s.marks[8]);

            printf("\n\n\t\tCS LAB Marks \t");

            printf("%.2f",s.marks[9]);

            printf("\n\n\t\tECE Marks \t");

            printf("%.2f",s.marks[10]);

            printf("\n\n\t\tMATH Marks \t");

            printf("%.2f",s.marks[11]);

            printf("\n\n\t\tCIVIL Marks \t");

            printf("%.2f",s.marks[12]);

            printf("\n\n\t\tBIOTECH Marks \t");

            printf("%.2f",s.marks[13]);

            printf("\n\n\t\tCHEM Marks \t");

            printf("%.2f",s.marks[14]);

            printf("\n\n\t\tCHEM LAB Marks \t");

            printf("%.2f",s.marks[15]);

            

            printf("\n\t\tSGPA PHY SEM : %.2f",s.sgpa[0]);

            printf("\n\t\tSGPA CHEM SEM : %.2f",s.sgpa[1]);

            printf("\n\t\tCGPA : %.2f \n",s.cgpa);

            

            printChar('-',65);

            

        }

        else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

        

        

        printf("\n\n\t\tWant to enter another search (Y/N)");

        fflush(stdin);

        another=getchar();

    }

}
