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
