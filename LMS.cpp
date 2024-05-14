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
void writestudent()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);//write and append data
	do{
		 system("CLS");
		st.createstudent();
		fp.write((char*)&st,sizeof(student));//size of class
		cout<<"\n\nDo you want to add more record...(y/n?) ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

 void displayalls()
 {
	  system("CLS");
	 fp.open("student.dat",ios::in);//read mode
	 if(!fp)
	 {
		 cout<<"File Could Not Be Open";
		 getch();
		 return;//press any key and return
	 }
	 cout<<"\n\n\t\tStudent List\n\n";
	 cout<<"==================================================================\n";
	 cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
	 cout<<"==================================================================\n";
	 while(fp.read((char*)&st,sizeof(student)))
	 {
		 st.report();
	 }
	 fp.close();
	 getch();
 }
  void displayallb()
 {
	  system("CLS");
	 fp.open("book.dat",ios::in);//read mode
	 if(!fp)
	 {
		 cout<<"File Could Not Be Open";
		 getch();
		 return;//press any key and return
	 }
	 cout<<"\n\n\t\tBook List\n\n";
	 cout<<"==================================================================\n";
	 cout<<"\tBook No."<<setw(20)<<"Book Name"<<setw(25)<<"Book Author\n";
	 cout<<"==================================================================\n";
	 while(fp.read((char*)&bk,sizeof(book)))
	 {
		 bk.report();
	 }
	 fp.close();
	 getch();
 }
void bookissue()
 {
	 char sn[6],bn[6];
	 int found=0,flag=0;
	  system("CLS");
	 cout<<"\n\nBOOK ISSUE...";
	 cout<<"\n\n\tEnter Admission no.";
	 cin>>sn;
	 fp.open("student.dat",ios::in|ios::out);
	 fp1.open("book.dat",ios::in|ios::out);
	 while(fp.read((char*)&st,sizeof(student))&& found==0)
	 {
		 if(strcmpi(st.retadmno(),sn)==0)//compare admsn no.
		 {
			 found=1;
			 if(st.rettoken()==0)//if book not issued
			 {
				 cout<<"\n\n\tEnter The Book No.";
			 cin>>bn;
			  while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			  {
				   if(strcmpi(bk.retbno(),bn)==0)//compare book no.
		             {
			          flag=1;
					  st.addtoken();
					  st.getstbno(bk.retbno());//pass book no.
					  int pos=-1*sizeof(st);
					  fp.seekg(pos,ios::cur);
					  fp.write((char*)&st,sizeof(student));
					  cout<<"\n\n\tBook Issued Successfully\n\n";
					  
					
			  }
		 }
		 if(flag==0) {
			 cout<<"Book No. Does Not Exists";
		 } 
	 } 
	 
	 else
	 {	 
		 cout<<"You Have Not Returned The Last Book"; 
	 }
	 }
 }
 if(found==0)
 {
	 cout<<"Student Record Not Exists.";
 }
 getch();
 fp.close();
 fp1.close();
 }
 
 void bookdeposit()
 {
	 char sn[6],bn[6];
	 int found=0,flag=0,day,fine;
	  system("CLS");
	 cout<<"\n\nBOOK DEPOSIT...";
	 cout<<"\n\n\tEnter Admission no. Of Student";
	 cin>>sn;
	 fp.open("student.dat",ios::in|ios::out);
	 fp1.open("book.dat",ios::in|ios::out);
	 while(fp.read((char*)&st,sizeof(student))&& found==0)
	 {
		 if(strcmpi(st.retadmno(),sn)==0)//compare admsn no.
		 {
			 found=1;
			 if(st.rettoken()==1)//if book issued
			 {
				 while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			  {
				   if(strcmpi(bk.retbno(),st.retstbno())==0)
		             {
			          flag=1;
					  bk.showbook();
					  st.resettoken();
					 
					  int pos=-1*sizeof(st);
					  fp.seekg(pos,ios::cur);
					  fp.write((char*)&st,sizeof(student));
					  cout<<"\n\n\tBook Deposited Successfully";
			  }
		 }
		 if(flag==0)
		 {
			 cout<<"Book No. Does Not Exists";
		 } 
	 } 
	 
	 else
	 {
		 cout<<"No Book Issued"; 
	 }
	 }
 }
 if(found==0){
	 cout<<"Student Record Not Exists..."; 
 }
 getch();
 fp.close();
 fp1.close();
 }
 
void start()
{  system("CLS");
cout<<"\n\n\n\n\t\t LIBRARY \t MANAGEMENT \t SYSTEM";
cout<<"\n\nBy: \n\n 23CS052 DHAIRYATI PANDYA\n 23CS051 PARAM PAMBHAR\n 23CS059 DEVARSHI PATEL";
cout<<" \n\n Please press Enter."; 
getch();
}
void adminmenu()
{
	 system("CLS");
	int ch2;
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\n\t2.DISPLAY ALL STUDENT RECORD";
	cout<<"\n\n\n\t3.CREATE BOOK";
	cout<<"\n\n\n\t4.DISPLAY ALL BOOKS";
	cout<<"\n\n\n\t5.BACK TO MAIN MENU";
	cout<<"\n\n\n\tPLEASE ENTER YOUR CHOICE(1-5)";
	cin>>ch2;
	switch(ch2)
	{
		case 1: writestudent();
		break;
		case 2: displayalls();
		break;
		break;
		case 3:writebook();
		break;
		case 4:displayallb();
		break;
		case 5:
		return;
		default:
		cout<<"Invalid choice"; 
	}
	adminmenu();
} 
int main(){ 
char ch;
 system("CLS");
start();
do{
	 system("CLS");
	cout<<"\n\n\n\t MAIN MENU";
	cout<<"\n\n\n\t1 BOOK ISSUE";
	cout<<"\n\n\n\t2 BOOK DEPOSIT";
	cout<<"\n\n\n\t3 ADMINISTRATOR MENU"; 
	cout<<"\n\n\n\t4 EXIT";
	cout<<"\n\n\n\t PLEASE SELECT YOUR OPTION(1-4)";  
	ch=getche();
	switch(ch)
	{ case '1': bookissue(); 
	  break;
	  case '2': bookdeposit();
	  break;
	  case '3': adminmenu();
	  break;
	  case '4': 
	  exit(0); 
	  break;
	  default:
	  cout<<"INVALID CHOICE"; 
	  
	}         
}while(ch!=4 ); 
}
