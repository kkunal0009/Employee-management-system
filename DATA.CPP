#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>

using namespace std;
struct employee
{
  long code;
  char name[50];
  char designation[50];
  long salary;
  int d,m,y;
};
void start()
{
  //clrscr();
  cout<<"\n\n\n\n\n";
  cout<<"\t0            0   00000\n";
  cout<<"\t 0          0    0   0\n";
  cout<<"\t  0   00   0     00000\n";
  cout<<"\t   0 0  0 0      0   0\n";
  cout<<"\t    0    0       00000\n";

  cout<<"\n\n\t\tpress enter";
  cin.ignore();
}

void date(int &d,int &m,int &y)
{
  cin>>d>>m>>y;
  int q=0;
  if((y>=1000)&&(y<=10000))
  {
	if((m>0)&&(m<13))
	{
		if((y%4==0)&&(m==2)&&(d>0)&&(d<30))
		q=1;
		else if((y%4!=0)&&(m==2)&&(d>0)&&(d<29))
		q=1;
		else if((m%2==0)&&(d>0)&&(d<31))
		q=1;
		else if((m%2!=0)&&(d>0)&&(d<32))
		q=1;
	}
  }

  if(q==0)
  {
  cout<<"invalid date...please write again...\n";
  date(d,m,y);
  }
}

void input()
{
  ofstream f2;
  f2.open("rw.bat",ios::binary);
  ifstream f1;
  f1.open("hel.bat",ios::binary);
  employee a;

  while(f1)
  {
	f1.read((char*)&a,sizeof(a));
	f2.write((char*)&a,sizeof(a));
  }

  cout<<"enter code\n";
  cin>>a.code;
  cout<<"enter name\n";
  gets(a.name);
  cout<<"enter designation\n";
  gets(a.designation);
  cout<<"enter salary\n";
  cin>>a.salary;
  cout<<"enter dob\n";
  date(a.d,a.m,a.y);

  f2.write((char*)&a,sizeof(a));

  cout<<"data added\n";
  f1.close();
  f2.close();

  remove("hel.bat");
  rename("rw.bat","hel.bat");

}

void show()
{
  employee a;
  ifstream f2("hel.bat",ios::binary);
  f2.read((char*)&a,sizeof(a));
  while(f2)
  {
    cout<<"\ncode is";
    cout<<"\n"<<a.code<<"\n";
    cout<<"name is\n";
    puts(a.name);
    cout<<"\ndesignation is\n";
    puts(a.designation);
    cout<<"\nsalary is\n";
    cout<<a.salary;
    cout<<"\ndob is\n";
    cout<<a.d<<"/"<<a.m<<"/"<<a.y;

    f2.read((char*)&a,sizeof(a));
  }
  f2.close();
}

void edit()
{
  int i;
  cout<<"enter id\n";
  cin>>i;
  employee a;
  int z,x=0;
  ifstream f2("hel.bat",ios::binary);
  ofstream f3;
  f3.open("rz.bat",ios::binary);

  f2.read((char*)&a,sizeof(a));
  while(f2)
  {
    //f2.read((char*)&a,sizeof(a));
    if((a.code==i)&&(x<1))
    {
    //clrscr();
    cout<<"\ncode is";
    cout<<"\n"<<a.code<<"\n";
    cout<<"name is\n";
    puts(a.name);
    cout<<"\ndesignation is\n";
    puts(a.designation);
    cout<<"\nsalary is\n";
    cout<<a.salary;
    cout<<"\ndob is\n";
    cout<<a.d<<"/"<<a.m<<"/"<<a.y;
    cout<<"\nenter field to edit....\n";
    cout<<"1.name\n2.designation\n3.salary\n4.dob\n5.exit\n";
    cin>>z;

    if(z==1)
    {
     gets(a.name);;
    }
    else if(z==2)
    {
     gets(a.designation);
    }
    else if(z==3)
    {
     cin>>a.salary;
    }
    else if(z==4)
    {
     date(a.d,a.m,a.y);
    }
    ++x;
    }
    f3.write((char*)&a,sizeof(a));
    f2.read((char*)&a,sizeof(a));
  }
  if(x==0)
  {cout<<"sorry...no such record found"; }
  f2.close();
  f3.close();

   remove("hel.bat");
  rename("rz.bat","hel.bat");
 }

int main()
{
 start();
 //clrscr();
 int g;
 cout<<"choose 1 option\n";
 cout<<"1.add new one\n";
 cout<<"2.edit/see previous\n";
 cout<<"3.view all\n";
 //cout<<"4.delete the record\n";
 cout<<"0.exit\n";
 cin>>g;
 //clrscr();

 if(g==1)
 {
   input();
 }
 else if(g==2)
 {
    edit();
 }
 else if(g==3)
 {
   show();
 }
 getch();
}
