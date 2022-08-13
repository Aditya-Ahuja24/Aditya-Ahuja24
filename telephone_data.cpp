#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
/*
Write an interactive menu driven program to define a class Tele
which contains Name, Address and Telephone no and member functions
to read and show the data members. Also write functions to:
(a)Write objects to the binary file "Tele.dat"
(b)Display all objects from the binary  file "Tele.dat"


*/


class tele
{       private:
	char name[30];
	char address[30];
	char teleph[11];
	public:
	void write(int j);
	void disp(int j);
	void file_write();
	void file_disp();

}a;

void line(char ch)
{
   for(int i=0;i<80;++i)
   cout<<ch;
 //  cout<<endl;

}
void tele::write(int j)     //data input
{

      cout<<"Name"<<j<<":";
      gets(name);
      cout<<"Address"<<j<<":";
      gets(address);
      cout<<"Phone"<<j<<":";
      gets(teleph);

}

void tele::disp(int j)      //data output
{
     cout<<"Name"<<j<<":"<<name<<endl;
     cout<<"Address"<<j<<":"<<address<<endl;
     cout<<"Phone"<<j<<":"<<teleph<<endl;

}

void tele::file_write()     //writing into file
{               int n,i,j;
		ofstream infile("tele.dat",ios::binary|ios::app);
		cout<<"Enter number of objects:";
		cin>>n;
				for(i=0,j=1;i<n;++i,j++)
				{
				  a.write(j);
				  infile.write((char*)&a,sizeof(a));
				  cout<<endl;
				}
		infile.close();
		line('±');
}

void tele:: file_disp()	    //displaying from file
{               int j=0;
		ifstream outfile("tele.dat",ios::binary);
		outfile.read((char*)&a,sizeof(a));
				while(!outfile.eof())
				{  j++;
				   a.disp(j);
				   outfile.read((char*)&a,sizeof(a));
				   cout<<endl;
				}
		  outfile.close();
		  line('±');
}
void main()
{       clrscr();
	char ch2;
	line('±');
	int n,cho,I,j;


	cout<<"\t\tFILE WRITING"<<endl;
	 line('*');
	 cout<<endl;
	cout<<"1.Write objects \t 2.Display objects"<<endl;
	cout<<"3.Exit"<<endl<<endl;
	  line('*');
	  cout<<endl;
		do
		{
		cout<<"Enter your choice:";
		cin>>cho;
		cout<<endl;
		line('*');
			if(cho==1)        //writing into file
			{
				a.file_write();
			}
			else if(cho==2)    //displaying from file
			{
				   a.file_disp();
			}

			else if(cho==3)
			exit(0);
			  cout<<"Do you want to continue?";
		cin>>ch2;
			   }
		while(ch2!='n');

	getch();
}





 
