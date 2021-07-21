/*student management system using file handling*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
void insert_record();//declaration for adding a student in the record
void display_record();//declaration for displaying the list of students
void search_recordG();//declaration for searching the record of a student by group
void search_recordR();//declaration for searching the record of a student by rollno
void delete_recordR();//declaration for deleting a student record by rollno
void delete_recordN();//declaration for deleting a student record by name
void menu();
struct Student_details
{
	int rno;//roll of the student
	char name[20];//name of the student
	char group[5];//group of the student
	char phno[10];//phone number of the student
	char email[20];//emailid of the student
};
struct Student_details s;
FILE *fp,*fp1;
int main()
{
    char p[20]="Aditya@123",password[20];
	int k;
//	clrscr();
	fflush(stdin);
	printf("enter password:  ");
	scanf("%s",password);
	fflush(stdin);
	k=strcmp(p,password);
	if(k==0)
	{
		printf("valid\n");
		printf("\nYOU HAVE SUCCESSFULLLY ENTERED !!");
		//getch();
		menu();
	}
	else
	printf("Try Again!!!");
return 0;
}

void menu()
{
	int a;
	//clrscr();
	fflush(stdin);
	do
	{
	//clrscr();
	fflush(stdin);
	printf("\t\n\t\t**************************************");
	printf("\n\t\tWELCOME TO STUDENT MANAGEMENT SYSTEM");
	printf("\t\n\t\t**************************************");
	printf("\n\n\t\t`````````MENU`````````");
	printf("\n\t\t\t1.Insert record");
	printf("\n\t\t\t2.Display record");
	printf("\n\t\t\t3.Search record by group");
	printf("\n\t\t\t4.Search record by rollno");
	printf("\n\t\t\t5.Delete record by rollno");
	printf("\n\t\t\t6.Delete record by name");
	printf("\n\t\tEnter your choice:\n");
	scanf("%d",&a);
	fflush(stdin);
	switch(a)
		{
		case 1:
		printf("\n\t\t\tInserting a student record");
			insert_record();
			fflush(stdin);
			break;
		case 2:
		printf("\n\t\t\tDisplay the student list");
			display_record();
			fflush(stdin);
			break;
		case 3:printf("\n\n\t\tSearch by group");
			search_recordG();
			fflush(stdin);
			break;
		case 4:printf("\n\t\t\tSearch by rollno");
			search_recordR();
			fflush(stdin);
			break;
		case 5:printf("\n\t\t\t Delete the record by rollno");
			delete_recordR();
			fflush(stdin);
			break;
		case 6:printf("\n\t\t\t Delete the record by name");
			delete_recordN();
			fflush(stdin);
			break;
		default:printf("\n\t\t\tInvalid choice");
	    }
	} while(a!=6);

}
void insert_record()
{
	fp=fopen("sms.txt","ab+");
//	clrscr();
printf("\n\n\n\n");
fflush(stdin);
	printf("\t\n****ENTER NEW STUDENT DATA****");
	printf("\n Enter roll number :");
	scanf("%d",&s.rno);
	printf("\n Enter name        :");
	scanf("%s",s.name);
	printf("\n Enter group       :");
	scanf("%s",s.group);
	printf("\n Enter phone number :");
	scanf("%s",s.phno);
	printf("\n Enter email-id :");
	scanf("%s",s.email);
	fwrite(&s,sizeof(s),1,fp);
	printf("\n\n\t STUDENT RECORD INSERTED SUCCESSFULLY!!!!");
	fclose(fp);
	printf("\n done");
	getch();
}
void display_record()
{
	fp=fopen("sms.txt","rb");
	//clrscr();
	fflush(stdin);
	printf("\n\n\n\t\t\tSTUDENTS DETAILS");
	printf("\n\t\tRollno\t\tName\t\tGroup\t\t\tPhone\t\t\tEmail-id");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		printf("\n\t\t%d\t\t%s\t\t%s\t\t\t%s\t\t%s\t\t",s.rno,s.name,s.group,s.phno,s.email);
	}
	fclose(fp);
	printf("\n\n\nenter any key");
getch();
}
void search_recordG()
{
	char gp[10],flag=0;
	fp=fopen("sms.txt","rb+");
	//clrscr();
	fflush(stdin);
	printf("\nenter student group you want to search :");
	gets(gp);
	printf("\n\n Contact list who are in   %s \n",gp);
	printf("\n-------------------------------------------------------");
	printf("\n\t\trollno\t\tname\t\tgroup\t\tphno\t\t\temail");
	printf("\n-------------------------------------------------------\n");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
	  if(strcmp(gp,s.group)==0)
	  {
		flag=1;
		printf("\n\t\t%d\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t",s.rno,s.name,s.group,s.phno,s.email);
	   }
	}
	if(flag ==0)
	{
	//	clrscr();
	fflush(stdin);
		printf("No such group in the record!!!");
	}

	fclose(fp);
       getch();
}
void search_recordR()
{
	int roll,flag=0;
	fp=fopen("sms.txt","rb");
	printf("\n\nEnter student rollno you want to search :");
	scanf("%d",&roll);
	fflush(stdin);
	printf("\n--------------------------------------------------------------------");
	printf("\n\t\trollno\t\tname\t\tgroup\t\tphno\t\t\temail");
	printf("\n--------------------------------------------------------------------\n");
	while(fread(&s,sizeof(s),1,fp)>0&&flag==0)
	{
		if(s.rno==roll)
		{
		flag=1;
		fflush(stdin);
		printf("\n\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s",s.rno,s.name,s.group,s.phno,s.email);
	    }
	}
	if(flag==0)
	{
	      //clrscr();
	      fflush(stdin);
		printf("No such record found!!");
	}
	fclose(fp);
getch();
}
void delete_recordR()
{
	int roll,flag=0;
	printf("\n\t\t\tEnter roll no you want to delete:	\n");
	scanf("%d",&roll);
	fflush(stdin);
	fp=fopen("sms.txt","rb+");
	fp1=fopen("sms1.txt","wb+");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		if(s.rno==roll)
		{
			flag=1;
			break;
		}
	}
	fclose(fp);
	fp=fopen("sms.txt","rb+");
	if(flag)
	{
		while(fread(&s,sizeof(s),1,fp)==1)
		{
			if(s.rno!=roll)
			fwrite(&s,sizeof(s),1,fp1);		
		}
	fclose(fp);
	fclose(fp1);
	remove("sms.txt");
	rename("sms1.txt","sms.txt");
	printf("Record with rollno: %d has successfully deleted>>>...",roll);
	getch();
	}
	else
	{
	fclose(fp);
	fclose(fp1);
	printf("\nRecord is not found....!!!!");
	getch();	
	}
}
void delete_recordN()
{
	char na[20],flag=0;
	printf("\nEnter student name you want to delete:	\n");
	gets(na);
	fflush(stdin);
	fp=fopen("sms.txt","rb+");
	fp1=fopen("sms1.txt","wb+");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		if(stricmp(na,s.name)==0)
		{
			flag=1;
			break;
		}
	}
	fclose(fp);
	fp=fopen("sms.txt","rb+");
	if(flag)
	{
		while(fread(&s,sizeof(s),1,fp)==1)
		{
			if(stricmp(s.name,na)!=0)
			fwrite(&s,sizeof(s),1,fp1);		
		}
	fclose(fp);
	fclose(fp1);
	remove("sms.txt");
	rename("sms1.txt","sms.txt");
	printf("\nRecord with name %s has been successfully deleted>>>...",na);
	getch();
	
	}
	else
	{
	fclose(fp);
	fclose(fp1);
	printf("\nRecord is not found....!!!");
	getch();	
	}
}

