/*
   LIBRARY MANAGEMENT SYSTEM
By:
   23CS052 DHAIRYATI PANDYA
   23CS051 PARAM PAMBHAR
   23CS059 DEVARSHI PATEL
*/
#include <iostream>
#include<conio.h>
#include<iomanip>//input-output manipulator
#include<stdlib.h> 
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>

using namespace std;
class book
{
	char bno[6];//bookno.
	char bname[50];//bookname
	char aname[20];//authorname

	public:
	void createbook()
	{
		cout<<"\n* * * NEW BOOK ENTRY * * *\n";
		cout<<"\nENTER BOOK NO. : ";
		cin>>bno;
		cout<<"\nENTER BOOK NAME : ";
		cin>>bname;//enables enter with space
		cout<<"\nENTER AUTHOR NAME : ";
		cin>>aname;
		cout<<"\n\n\nBook Created.";
	}
	void showbook()
	{
		cout<<"\nBook Number: "<<bno;
		cout<<"\nBook Name: ";
		cout<<bname;
		cout<<"\nBook Author Name: ";
		cout<<aname;
	}
	void modifybook()
	{
		cout<<"\nBook Number: "<<bno;
		cout<<"\nModify Book Name :";
		cin>>bname;
		cout<<"\nModify Author's Name :";
		cin>>aname;
		
	}
	
	char* retbno()//string return
	{
		return bno;
	
	}
	void report()
	{
		cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
	}
};//class ends here
class student
{
	char admno[6];//admission no.
	char name[20];
	char stbno[6];// student book no 
	int token;//total book of student
	public:
	void createstudent()
	{
		 system("CLS");
		cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The Admission No. : ";
		cin>>admno;
		cout<<"Enter The Student Name : ";
		cin>>name;
		token=0;
		stbno[0]='\0';
		cout<<"\n\nStudent Record Created...";
	}
	void showstudent()
	{
		cout<<"\nAdmission Number : "<<admno;
		cout<<"\nStudent Name : ";
		cout<<name;
		cout<<"\nNo. of Books Issued : "<<token;
		if(token==1)
		{
			cout<<"\nBook Number: "<<stbno;
		}
	}
	void modifystudent()
	{
		cout<<"\nAdmission No. : "<<admno;
		cout<<"\nModify Student Name : ";
		gets(name);
	}
	char* retadmno()
	{
		return admno;
	}
	char* retstbno()
	{
		return stbno;
	}
	int rettoken()
	{
		return token;
	}
	void addtoken()
	{
		token=1;
	}
	void resettoken()
	{ 
	token=0;
	}
	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}
	void report()
	{
		cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl ;
	}
};//class ends here
fstream fp,fp1;//object
book bk;//book class object
student st;//student class object

void writebook()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);//write and append data
	do{
		 system("CLS");
		bk.createbook();
		fp.write((char*)&bk,sizeof(book));//size of class
		cout<<"\n\nDo you want to add more record...(y/n?) ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
