#include<dos.h>
#include<iostream.h>
#include<stdio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<fstream.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>

void mainmenu();
void libmenu();
void stumenu();
fstream fs,ft,fb;
class student
{
	long admno;
	int std;
	char name[20];
	int booktaken;
	long stbcode;
public: void getdata()
	{
		cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter admission no. ";
		cin>>admno;
		cout<<"\n\nEnter Name of The Student ";
		gets(name);
		cout<<"\n\nEnter Your Class";
		cin>>std;
		booktaken=0;
	 }
	void modify_data(long a)
	{
		admno=a;
		cout<<"\nModify Student\n";
		cout<<"\n\nEnter Name of The Student ";
		gets(name);
		cout<<"\n\nEnter Your Class";
		cin>>std;
		booktaken=0;
	}
	void getstbno(long t)
	{
		stbcode=t;
	}
	long retstbno()
	{
	return stbcode;
	}
	char* retname()
	{
	return name;
	}

	long retadmno()
	{

		return admno;
	}
	int retstd()
	{
		return std;
	}
	int retbooktaken()
	{
		return booktaken;
	}

	void addbooktaken()
	{
	booktaken=1;
	}

	void delbooktaken()
	{
	booktaken=0;
	}

	void showdata()
	{cout<<"\t"<<admno<<setw(30)<<name<<setw(10)<<std<<setw(20)<<booktaken<<endl;}

};




class book
{
	public:
	long bcode;
	char bname[50];
	char authour[20];
	char genre[20];
	int price;
	void create_book()
	{

		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The Book Code.";
		cin>>bcode;
		if(bcode==0)
		{
		 cout<<"Book code can't be zero";
		 getch();
		 create_book();
		}
		cout<<"\n\nEnter Name of The Book ";
		gets(bname);
		cout<<"\n\nEnter Author's Name ";
		gets(authour);
		cout<<"\n\nEnter Genre of Book ";
		gets(genre);
		cout<<"\n\nEnter Price of Book ";
		cin>>price;
	}
	void modify_book(long a)
	{              bcode=a;
	cout<<"\nModify Book...\n";
		cout<<"\n\nEnter Name of The Book ";
		gets(bname);
		cout<<"\n\nEnter Author's Name ";
		gets(authour);
		cout<<"\n\nEnter Genre of Book ";
		gets(genre);
		cout<<"\n\nEnter Price of Book ";
		cin>>price;
	}

	void show_book()
	{
	 cout<<setw(5)<<bcode<<setw(15)<<bname<<setw(17)<<authour<<setw(14)<<genre<<setw(7)<<price<<endl;
	}
	char* retbname()
	{
	 return bname;
	}
	long retbcode()
	{
	 return bcode;
	}



};

book b1;
student st;

void dispbook();
void rbeep()
{
 cout<<(char)7;
 sound(20000);
 delay(200);
 nosound();

}
void wbeep()
{
		      sound(1500);
		      delay(200);
		      sound(700);
		      delay(100);
		      nosound();

}
void addbook()
{

	char ch='y';
	fs.open("book123.dat",ios::app|ios::out);
	fs.seekp(0,ios::end);
	while(ch=='y'||ch=='Y')
	{        	clrscr();
		int gdrive=EGA,gmode=EGAHI,errorcode;
		initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
		setbkcolor(1);
		b1.create_book();
		fs.write((char*)&b1,sizeof(book));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}
	cout<<"Book record created!! ";
	fs.close();
	cout<<"\n\tWant to View Book list...(y/n?)";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	 dispbook();
}
void dispbook()
{
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(1);
		fs.open("book123.dat",ios::in);
		fs.seekg(0);
		if(!fs)
		{
			cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
			getch();
		}
		cout<<"\n\n\t\tBOOK LIST\n\n";
		cout<<setw(10)<<"Book Code"<<setw(10)<<"Name"<<setw(15)<<"Authour"<<setw(15)<<"Genre"<<setw(10)<<"Price\n";
	while(fs.read((char*)&b1,sizeof(book)))
		{
			b1.show_book();
		}

	fs.close();
	getch();
}
void searchb();
void sbookname()
{
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(4);
	char sname[50],a;
	int i=-1;
	cout<<"Enter the name of book you want to search : ";
	gets(sname);
	fs.open("book123.dat",ios::in);
	fs.seekg(0);
	while(fs.read((char*)&b1,sizeof(book)))
	{
		if(strcmp(b1.bname,sname)==0)
		{
			cout<<setw(10)<<"Book Code"<<setw(10)<<"Name"<<setw(15)<<"Authour"<<setw(15)<<"Genre"<<setw(10)<<"Price\n";
		  b1.show_book();
		  i=1 ;
		  getch();
		}
	}
	if(i==-1)
		{
		  cout<<"Entered Book name Can't be found \n";
		  cout<<"Want to try again..(y/n?) ";
		  cin>>a;
		  if(a=='y'||a=='Y')
		   sbookname();
		  else
		   searchb();
		}

	     fs.close();
	     getch();
}
void sbookcode()
{
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(4);
	char a;
	int i=-1,c;
	cout<<"Enter the code of book you want to search : ";
	cin>>c;
	fs.open("book123.dat",ios::in);
	fs.seekg(0);
	while(fs.read((char*)&b1,sizeof(book)))
	{
		if(c==b1.bcode)
		{
		cout<<setw(10)<<"Book Code"<<setw(10)<<"Name"<<setw(15)<<"Authour"<<setw(15)<<"Genre"<<setw(10)<<"Price\n";
		  b1.show_book();
		  i=1 ;
		  getch();
		}
	}
	if(i==-1)
		{
		  cout<<"Entered Book code Can't be found \n";
		  cout<<"Want to try again..(y/n?) ";
		  cin>>a;
		  if(a=='y'||a=='Y')
			  sbookcode();
		  else
			  searchb();
	       }
	     fs.close();
	     getch();
}
void password();
void searchb()
	{       int a;
		clrscr();
		int gdrive=EGA,gmode=EGAHI,errorcode;
		initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
		setbkcolor(4);
		char pass[10];
		cout<<"\n\nSELECT YOUR OPTION ";
		cout<<"\n\n1.Search Book by Name ";
		cout<<"\n\n2.Search Book by Code ";
		cout<<"\n\n3.Return to Student Menu ";
		cout<<"\n\n4.Return to Librarian Menu ";
		cout<<"\n\nEnter your option : " ;
		cin>>a;
		switch(a)
		{
		   case 1: sbookname();
		    searchb();
		    break;
		   case 2: sbookcode();
		    searchb();
		    break;
		   case 3: stumenu();
		    break;
		   case 4:password();
		    break;
		   default:cout<<"Wrong Choice !!";searchb();
		    break;
		}

	}

void delbook()
{       long c;
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(1);
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\nEnter the code of book you want to delete: ";
	cin>>c;
	fs.open("book123.dat",ios::in|ios::out);
	ft.open("Temp.dat",ios::out);
	fs.seekg(0,ios::beg);
	while(fs.read((char*)&b1,sizeof(book)))
	{
	 if(b1.retbcode()!=c)
		{
			ft.write((char*)&b1,sizeof(book));
		}
	}
	ft.close();
	fs.close();
	remove("book123.dat");
	rename("Temp.dat","book123.dat");
	cout<<"Book Deleted!!";

	getch();
}

void modbook()
{       long c;
	int i=-1;
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(1);
	cout<<"\n\n\n\tMODIFY BOOK ...";
	cout<<"\nNOTE:If you don't know book code \t Enter 0 to see book list \nEnter the code of book you want to modify: ";
	cin>>c;
	if(c==0)
	{
	dispbook();
	modbook();
	}
	fs.open("book123.dat",ios::in|ios::out);
	ft.open("Temp.dat",ios::out);
	fs.seekg(0,ios::beg);
	while(fs.read((char*)&b1,sizeof(book)))
	{
		if(b1.retbcode()==c)
		{
			b1.modify_book(c);
			ft.write((char*)&b1,sizeof(book));
			i=1;
		}
		else
		ft.write((char*)&b1,sizeof(book));
	}

	ft.close();
	fs.close();
	remove("book123.dat");
	rename("Temp.dat","book123.dat");
	if(i==-1)
       {	cout<<"Book not found ";
	libmenu();
	}
	else
	cout<<"Book modified!!";

	getch();
}



void add_stu()
	{
		clrscr();
		int gdrive=EGA,gmode=EGAHI,errorcode;
		initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
		setbkcolor(6);
		char ch;
	fs.open("stud.dat",ios::app|ios::out);
	fs.seekp(0,ios::end);
	do
	{
		st.getdata();
		fs.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fs.close();

		cout<<"\n\nStudent Record Created..";
	}

void show_stu()
	{
		clrscr();
		int gdrive=EGA,gmode=EGAHI,errorcode;
		initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
		setbkcolor(6);
		fs.open("stud.dat",ios::in);
		fs.seekg(0);
		if(!fs)
		{
			cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
			getch();
			fs.close();
			return;
		}
		cout<<"\n\n\t\tSTUDENT LIST\n\n";
		cout<<"\tAdmission No."<<setw(20)<<"Name"<<setw(10)<<"Class"<<setw(20)<<"Book Issued\n";


	while(fs.read((char*)&st,sizeof(student)))
		{
			st.showdata();
		}

	fs.close();
	getch();

	}

void show_stuclass()
	{
		clrscr();
		int gdrive=EGA,gmode=EGAHI,errorcode;
		initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
		setbkcolor(6);
	  int a,i=-1;
	cout<<"Enter Class whose list you want to view (Class6-12) : ";
	cin>>a;
		clrscr();
		gdrive=EGA,gmode=EGAHI,errorcode;
		initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
		setbkcolor(6);
		fs.open("stud.dat",ios::in);
		fs.seekg(0);
		cout<<"\n\n\t\tSTUDENT LIST\n\n";
		cout<<"\tAdmission No."<<setw(20)<<"Name"<<setw(10)<<"Class"<<setw(20)<<"Book Issued\n";


	while(fs.read((char*)&st,sizeof(student)))
		{       if(a==st.retstd())
			{
			st.showdata();
			i=1;
			}
		}

	fs.close();
	if(i==-1)
	{
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(6);
	cout<<"\n\nNo data Availiable for this Class " ;
	sleep(2);
	stumenu();
	}
	getch();
	}

void show_stuissue()
	{ clrscr();  clrscr();
int gdrive=EGA,gmode=EGAHI,errorcode;
initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
setbkcolor(6);
	  int i=-1;

		fs.open("stud.dat",ios::in);
		fs.seekg(0);
		cout<<"\n\n\t\tSTUDENT LIST\n\n";
		cout<<"\tAdmission No."<<setw(20)<<"Name"<<setw(10)<<"Class"<<setw(20)<<"Book Issued\n";


	while(fs.read((char*)&st,sizeof(student)))
		{       if(st.retbooktaken())
			{
			st.showdata();
			i=1;
			}
		}

	fs.close();
	if(i==-1)
	{
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(6);
	cout<<"\n\nNo Students have issued books " ;
	}
	getch();
	}


void del_stu()
{       long c;
	clrscr();
	clrscr();
int gdrive=EGA,gmode=EGAHI,errorcode;
initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
setbkcolor(6);
	cout<<"\n\n\n\tDELETE STUDENT ...";
	cout<<"\nEnter Admission no. of student you want to delete: ";
	cin>>c;
	if(c==0)
	{
	show_stu();
	del_stu();
	}
	fs.open("stud.dat",ios::in|ios::out);
	ft.open("Temp.dat",ios::out);
	fs.seekg(0,ios::beg);
	while(fs.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()!=c)
		{
			ft.write((char*)&st,sizeof(student));
		}

	}

	ft.close();
	fs.close();
	remove("stud.dat");
	rename("Temp.dat","stud.dat");
	cout<<"Student Deleted!!";
	getch();
}


void mod_stu()
{       long c;
	int i=-1;
	clrscr();
	clrscr();
int gdrive=EGA,gmode=EGAHI,errorcode;
initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
setbkcolor(6);
	cout<<"\n\n\n\tMODIFY STUDENT ...";
	cout<<"\nNOTE:If admission no. is not known \t Enter 0 to see student list \nEnter Admission no. of student you want to modify: ";
	cin>>c;
	if(c==0)
	{
	show_stu();
	mod_stu();
	}
	fs.open("stud.dat",ios::in|ios::out);
	ft.open("Temp.dat",ios::out);
	fs.seekg(0,ios::beg);
	while(fs.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()==c)
		{
			st.modify_data(c);
			ft.write((char*)&st,sizeof(student));
			i=1;
		}
		else
		ft.write((char*)&st,sizeof(student));
	}

	ft.close();
	fs.close();
	remove("stud.dat");
	rename("Temp.dat","stud.dat");
	if(i==-1)
       {	cout<<"Student not found ";
	libmenu();
	}
	else
	cout<<"Student modified!!";

	getch();
}

void findadmno()
{       clrscr();
clrscr();
int gdrive=EGA,gmode=EGAHI,errorcode;
initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
setbkcolor(6);
	char nm[20],a; int i=-1;
	fs.open("stud.dat",ios::in);
	fs.seekg(0);
	cout<<"Enter Your  Name:  ";
	gets(nm);
	    while(fs.read((char*)&st,sizeof(student)))
		{
			if(strcmp(st.retname(),nm)==0)
		       {
			cout<<"Your admission number is  " ;
		       cout<<st.retadmno();
			i=1;
			getch();
		       }
		}
		fs.close();
	      if(i==-1)
	      {
	      cout<<"Name not found :(\nWant to Try Again..(y/n?)  ";
	      cin>>a;
	      if(a=='y'||a=='Y')
	      {
	       findadmno();
	      }
	      getch();
	      }

}

void change_pass()
{
  clrscr();
  int gdrive=EGA,gmode=EGAHI,errorcode;
  initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
  setbkcolor(2);
  char newp[20];
  cout<<"Enter new password   ";
  gets(newp);

     fs.open("password.dat",ios::out);
     fs<<newp<<'\n';
     fs.close();
}

void password()
{
 clrscr();
 int gdrive=EGA,gmode=EGAHI,errorcode;
 initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
 setbkcolor(2);
 char p[20];
 cout<<"\n\n\t\tEnter the Password  ";
 gets(p);
      fs.open("password.dat",ios::in);
      char pass[20];
      fs.seekg(0);
      fs>>pass;
      cout<<"\n\n\t";

      for(int i=8;i<70;i++)
      {
       textcolor(GREEN);
       printf("%c",987)    ;
       delay(20) ;
      }
		if(strcmp(pass,p)==0)
		      {  fs.close();
			 libmenu();
			 getch();
		      }
	       else
		    {
		      cout<<"\n\t\t\tWRONG PASSWORD  ";
		      getch();
		      fs.close();
		      mainmenu();
		    }
}



void book_issue()
{
	long sn,bn;
	int found=0,found2=0;
	clrscr();
	int gdrive=EGA,gmode=EGAHI,errorcode;
	initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
	setbkcolor(1);
	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's admission no.";
	cin>>sn;
	fs.open("stud.dat",ios::in|ios::out);
	fb.open("book123.dat",ios::in|ios::out);
	fs.seekg(0);
	fb.seekg(0);
	while(fs.read((char*)&st,sizeof(student)) && found==0)
	{
		if(st.retadmno()==sn)
		{
			found=1;
			if(!st.retbooktaken())
			{
				cout<<"\n\n\tEnter the book no. ";
				cin>>bn;
				while(fb.read((char*)&b1,sizeof(book))&& found2==0)
				{
					if(b1.retbcode()==bn)
					{
							cout<<"Student Name :  ";
							cout<<st.retname();
							cout<<"\nBook Name :  ";
							cout<<b1.retbname();
							found2=1;
								st.addbooktaken();
								st.getstbno(b1.retbcode());
						int pos=-1*sizeof(st);
						fs.seekp(pos,ios::cur);
						fs.write((char*)&st,sizeof(student));
							cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write the current date ";

					}
				}
				if(found2==0)
					cout<<"Book code does not exist";
			}
			else
				cout<<"You have already issued a book\nReturn it to issue this book";

		}
	}
	if(found==0)
		cout<<"Student record not exist...";
	getch();
	fs.close();
	fb.close();
}
void book_deposit()
{
    long sn,bn;
    int found=0,found2=0,day,fine;
    clrscr();
    int gdrive=EGA,gmode=EGAHI,errorcode;
    initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
    setbkcolor(1);
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter student's admission no.";
    cin>>sn;
    fs.open("stud.dat",ios::in|ios::out);
    fb.open("book123.dat",ios::in|ios::out);
    while(fs.read((char*)&st,sizeof(student)) && found==0)
       {
	    if(st.retadmno()==sn)
	    {
		    found=1;
		    if(st.retbooktaken()==1)
		    {
			while(fb.read((char*)&b1,sizeof(book))&& found2==0)
			{
			   if(b1.retbcode()==st.retstbno())
			{       cout<<"\nStudent Name : ";
				cout<<st.retname();
				cout<<"\nBook Name : ";
				cout<<b1.retbname();
				found2=1;
				cout<<"\n\nBook deposited in no. of days";
				cin>>day;
				if(day>15)
				{
				   fine=(day-15)*1;
				   cout<<"\n\nFine has to deposited Rs. "<<fine;
				}
					st.delbooktaken();
					int pos=-1*sizeof(st);
					fs.seekp(pos,ios::cur);
					fs.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully";
			}
		    }
		  if(found2==0)
		    cout<<"Book code does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0)
	cout<<"Student record not exist...";
	getch();
  fs.close();
  fb.close();
  }

void edit_stu()
{
 int a;
 clrscr();
 int gdrive=EGA,gmode=EGAHI,errorcode;
 initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
 setbkcolor(6);
 cout<<"\n\n\t\t\tEDIT STUDENT MENU\n\n";
 cout<<"SELECT ANY OPTION \n\n\n";
 cout<<"1.ADD STUDENT\n\n" ;
 cout<<"2.DELETE STUDENT\n\n";
 cout<<"3.MODIFY STUDENT\n\n";
 cout<<"4.VIEW STUDENT LIST\n\n";
 cout<<"0.BACK TO MAIN MENU\n\n";
 cout<<"ENTER YOUR CHOICE    " ;
 cin>>a;
   switch(a)
    {
      case 1:add_stu();
      edit_stu();
      break;
      case 2:del_stu();
      edit_stu();
      break;
      case 3:mod_stu();
      edit_stu();
      break;
      case 4:show_stu();
      edit_stu();
      break;
      case 0:libmenu();
      default:cout<<"wrong choice :( ";
      getch(); edit_stu();
    }
}


void edit_book()
{
 int a;
 clrscr();
 int gdrive=EGA,gmode=EGAHI,errorcode;
 initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
 setbkcolor(1);
 cout<<"\n\n\t\t\tEDIT BOOK MENU\n\n";
 cout<<"SELECT ANY OPTION \n\n\n";
 cout<<"1.ADD BOOK\n\n" ;
 cout<<"2.DELETE BOOK\n\n";
 cout<<"3.MODIFY BOOK\n\n";
 cout<<"4.VIEW BOOK LIST\n\n";
 cout<<"0.BACK TO MAIN MENU\n\n";
 cout<<"ENTER YOUR CHOICE    " ;
 cin>>a;
   switch(a)
    {
      case 1:addbook();
      edit_book();
      break;
      case 2:delbook();
      edit_book();
      break;
      case 3:modbook();
      edit_book();
      break;
      case 4:dispbook();
      edit_book();
      break;
      case 0:libmenu();
      default:cout<<"wrong choice :( ";
      getch(); edit_book();
    }
}




void stumenu()
{
 int a;
 clrscr();
int gdrive=EGA,gmode=EGAHI,errorcode;
initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
setbkcolor(6);
 cout<<"\n\n\t\t\tWELCOME    STUDENTS\n\n";
 cout<<"SELECT ANY OPTION \n\n\n";
 cout<<"1.VEIW STUDENT LIST\n\n" ;
 cout<<"2.VEIW YOUR CLASS LIST\n\n";
 cout<<"3.VIEW BOOK LIST\n\n";
 cout<<"4.FIND YOUR ADMISSION NO.\n\n";
 cout<<"5.SEARCH BOOK\n\n";
 cout<<"0.BACK TO MAIN MENU\n\n";
 cout<<"ENTER YOUR CHOICE    " ;
 cin>>a;
   switch(a)
    {
      case 1:show_stu();
      stumenu();
      break;
      case 2:show_stuclass();
      stumenu();
      break;
      case 3: dispbook();
      stumenu();
      break;
      case 4:findadmno();
      stumenu();
      break;
      case 5:searchb();
      stumenu();
      break;
      case 0:mainmenu();
      default:cout<<"wrong choice :( ";getch(); stumenu();
    }
}
void libmenu()
{
 clrscr();
 int gdrive=EGA,gmode=EGAHI,errorcode;
 initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
 setbkcolor(1);
 int q;
 cout<<"\n\n\t\t\t\tWELCOME   LIBRARIAN\n\n";
 cout<<"SELECT ANY OPTION:- ";
 cout<<"\n\n1.VIEW STUDENT LIST";
 cout<<"\n\n2.VIEW STUDENTS WITH BOOK ISSUED";
 cout<<"\n\n3.EDIT STUDENT LIST";
 cout<<"\n\n4.VIEW BOOK LIST";
 cout<<"\n\n5.EDIT BOOK LIST" ;
 cout<<"\n\n6.ISSUE BOOK";
 cout<<"\n\n7.DEPOSIT BOOK";
 cout<<"\n\n8.CHANGE YOUR PASSWORD";
 cout<<"\n\n0.RETURN TO MAIN-MENU";
 cout<<"\n\n Enter your Option : ";
 cin>>q;
 switch(q)
 {
  case 0: mainmenu();
   break;
  case 1: show_stu();
   libmenu();
   break;
   case 2: show_stuissue();
   libmenu();
   break;
  case 3:edit_stu();
   libmenu();
   break;
  case 4: dispbook();
  libmenu();
   break;
  case 5:edit_book();
  libmenu();
   break;
   case 6: book_issue();
   libmenu();
   break;
   case 7: book_deposit();
   libmenu();
   break;
  case 8: change_pass();
   libmenu();
   break;
  default: cout<<"Plese Enter a correct option!!";
  getch();
  libmenu();
   break;
 }
}
void mainmenu()
{
clrscr();
int gdrive=EGA,gmode=EGAHI,errorcode;
initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
setbkcolor(2);
cout<<"\n\t\t\tSHALINI     CONVENT     SCHOOL\n";
cout<<"\n\t\t\t\tLIBRARY   MANAGEMENT\n\n\n";
int i;
char pass[10];
	cout<<"\n\t\t>>Please Choose Any Option To login \n";
	cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t0.Close Application\n";
	cout<<"\n\t\tEnter your choice : ";
	cin>>i;
	switch(i)
	{
	 case 1: stumenu();
	  break;
	 case 2: password();
	  break;
	 case 0: exit(0);
	  break;
	 case 567: change_pass();
	  mainmenu();
	  break;
	 default:   cout<<"\n\t\tPlease enter correct option :(";
	    wbeep();
	    getch();
	    mainmenu();
	    break;


}}
void main ()
{          clrscr();
int gdrive=EGA,gmode=EGAHI,errorcode;
initgraph(&gdrive,&gmode,"C:\\TC\\BGI") ;
setbkcolor(BLUE);
mainmenu();
getch();
}
