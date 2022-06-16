#include <fstream>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<Windows.h>
#include<cstring>


using namespace std;

class student{
	char book_name[20];
	char author_name[20];
	char issue_name[20];
	char avail;
	int sr_no;
	public:
	void getdata();
	void showdata();
	void store();
	void read(char);
	void search(int);
	void deletedata(int);
	void updatedata(int);
	void avail_change(int,char);
	void std_read();
	public:
	student(){
		strcpy(book_name,"No Name");
		strcpy(author_name,"No Name");
		strcpy(issue_name,"No Name");
		avail = 'F';
		sr_no = 0;
	}
};

void student::getdata(){
	cout<<"Enter the name of the book: ";
	gets(book_name);
	cout<<"Enter the name of the author: ";
	gets(author_name);
	avail = 'T';
	cout<<"Enter the Sr. No. ";
	cin>>sr_no;
	store();
}

void student::showdata(){
	cout<<"\t|"<<sr_no<<" |\t "<<book_name<<"\t |   "<<author_name<<"   |     "<<avail<<"      |"<<endl;
}

void student::std_read(){
	cout<<"\t|"<<sr_no<<" |\t "<<book_name<<"\t | "<<author_name<<"   | ";
	if(avail=='T'){
	    cout<<"Available  "<<endl;
	}else{
	    cout<<"Issued by - "<<issue_name<<endl;
	}
}

void student::store(){
	if(sr_no == 0)
	exit(1);
	ofstream fout;
	fout.open("File_2.txt",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}

void student::read(char ch='N'){
	ifstream fin("File_2.txt",ios::in|ios::binary);
	if(!fin)
	exit(1);
	fin.read((char*)this,sizeof(*this));
	while(fin){
		if(ch=='S'||ch=='N'){
		showdata();
		}else if(ch=='A'){
		std_read();
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}

void student::search(int id){
	ifstream fin("File_2.txt",ios::in|ios::binary);
	char getname[20];
	cout<<"Enter the name of the book to be searched ";
	gets(getname);
	if(!fin)exit(1);
	fin.read((char*)this,sizeof(*this));
	while(fin){
		if(id==sr_no){
			showdata();
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}

void student::deletedata(int id){
       ifstream fin;
       fin.open("File_2.txt",ios::in|ios::binary);
       ofstream fout;
       fout.open("Temp_file.txt",ios::out|ios::binary);
       if(!fin)exit(1);
       int ctr = 0;
       fin.read((char*)this,sizeof(*this));
       while(fin){
		if(!(id==sr_no))
			fout.write((char*)this,sizeof(*this));
		   else{
			ctr++;
		   }
		   fin.read((char*)this,sizeof(*this));
		}
		if(!ctr){
			cout<<"Record not found";
			getch();
		}
		fin.close();
		fout.close();
		remove("File_2.txt");
		rename("Temp_file.txt","File_2.txt");

}

void student::updatedata(int id){
	fstream fin("File_2.txt",ios::in|ios::out|ios::binary);
	fin.seekg(0);
	int f = 0;
	fin.read((char*)this,sizeof(*this));
	while(fin){
		if(id==sr_no){
		      cout<<"Enter the changed name of the book ";
		      gets(book_name);
		      cout<<"Enter the changed name of the author ";
		      gets(author_name);
		      f++;
		      fin.seekg(fin.tellp() - sizeof(*this));
		      fin.write((char*)this,sizeof(*this));
		      break;
		}else{
			fin.read((char*)this,sizeof(*this));

		}
	}
	if(f){
		cout<<"Book updated ";
	}else{
		cout<<"Wrong Serial Number";
	}
	fin.close();
}

void student::avail_change(int id,char state){
	fstream fin("File_2.txt",ios::in|ios::out|ios::binary);
	fin.seekg(0);
	char name[20];

	int flag=0;
	fin.read((char*)this,sizeof(*this));
	while(fin){
		if(id == sr_no){ flag=1;
			if(avail=='T'&&state=='T'){
				cout<<"Enter your name ";
				gets(name);
				strcpy(issue_name,name);
				avail = 'F';
				cout<<"Your book has been issued ";
				fin.seekg(fin.tellp() - sizeof(*this));
				fin.write((char*)this,sizeof(*this));
				break;

			}else if(avail == 'F' && state=='T'){
				cout<<"Book not available";

			}
			if(state=='F'&&avail=='F'){
				strcpy(issue_name,NULL);
				avail = 'T';
				fin.seekg(fin.tellp() - sizeof(*this));
				fin.write((char*)this,sizeof(*this));
				break;
			}else{
				cout<<"\nBook not issued";
				break;
			}
		}else{
			fin.read((char*)this,sizeof(*this));
		}
	}
	if (!flag){
	 cout<<"Book not found";
	}
	fin.close();
}



char user[] = {"School"};
char pass[15] = {"786"};

void border();
void first_page();
void menu();
void student_func();
void book_issue();
void update();
void admin();
void log_check();
void book_deposit();
void std_rec();
void change_pass();
void add_rec();
void delete_records();

void main(){
	clrscr();
	first_page();

	getch();
}

void first_page(){
	border();
	gotoxy(22,10);
	cout<<"Library Management System"<<endl;
	gotoxy(21,14);
	cout<<"Made by:RAGHAV KHANNA,ARYAN RASTOGI,ANURAJ AGARWAL"<<endl;
	gotoxy(21,16);
	cout<<"Enter any key to continue ";
	getch();
	menu();
}

void border(){
	clrscr();
	int i;
	for(i=0;i<40;++i)
	{cout<<"*-";
	}
	cout<<"\n";
       for(int j=0;j<20;j++)
       {
	cout<<"*-";
	for(i=0;i<74;i++)
	{
	cout<<" ";
	}
	 cout<<"*-\n";
	 }
	 for(i=0;i<40;i++)
	 {
	 cout<<"*-";
	}
	cout<<"\n";
}

void menu(){
	border();
	gotoxy(8,4);
	cout<<"||          ||  ||||||||||   ||        | |            |"<<endl;
	gotoxy(8,5);
	cout<<"|  |       | |  |            | |       | |            |"<<endl;
	gotoxy(8,6);
	cout<<"|    |   |   |  |            |  |      | |            |"<<endl;
	gotoxy(8,7);
	cout<<"|      |     |  |            |   |     | |            |"<<endl;
	gotoxy(8,8);
	cout<<"|            |  |||||||      |    |    | |            |"<<endl;
	gotoxy(8,9);
	cout<<"|            |  |            |     |   | |            |"<<endl;
	gotoxy(8,10);
	cout<<"|            |  |            |      |  |  |          | "<<endl;
	gotoxy(8,11);
	cout<<"|            |  |            |       | |   |        |  "<<endl;
	gotoxy(8,12);
	cout<<"|            |  ||||||||||   |        ||    ||||||||   "<<endl;

	gotoxy(28,14);
	cout<<"1 - Administrator"<<endl;
	gotoxy(28,16);
	cout<<"2 - Student"<<endl;
	gotoxy(28,18);
	cout<<"3 - Exit"<<endl;
	gotoxy(28,20);
	cout<<"Choose an account"<<endl;
	int ch;
	gotoxy(28,22);
	cin>>ch;
	if(ch==1)
	admin();
	else if(ch==2)
	student_func();
	else if(ch==3)
	exit(0);
	else{
	cout<<"Please enter a valid choice";
	menu();
	}
}


void student_func(){
	  border();
	  gotoxy(35,11);
	  std:
			cout<<"Menu"<<endl;
			gotoxy(28,14);
			cout<<"1 - Book Issue"<<endl;
			gotoxy(28,16);
			cout<<"2 - Book Deposit"<<endl;
			gotoxy(28,18);
			cout<<"3 - Main Menu"<<endl;
			gotoxy(28,20);
			cout<<"Choose any one option"<<endl;
			int ch;
			gotoxy(28,22);
			cin>>ch;
			if(ch==1){
			book_issue();
			goto std;
		       }else if(ch==2){
			book_deposit();
			goto std;
			}else if(ch==3){
			menu();
			goto std;
			}else{
			cout<<"Please enter a valid choice";
			getch();
			student_func();
		      }
}


void book_issue(){
	clrscr();
	student stud;
	cout<<"|  Sr. No. | \t Book's Name \t |   Author's Name   | Availabitlity |"<<endl ;
	stud.read('S');
	int id;
	cout<<"\n\nChoose any book ";
	cin>>id;
	stud.avail_change(id,'T');

	cout<<"\nEnter any key to return ";
	getch();
	student_func();

}

void update(){

	student stud;
	clrscr();
	stud.read('A');
	cout<<"Enter the Sr. No. of the book to be updated ";
	int id;
	cin>>id;
	stud.updatedata(id);
	cout<<"\nEnter any key to return to the previous menu";
	getch();
}

void delete_records(){
	student stud;
	clrscr();
	stud.read('A');
	cout<<"Enter the Sr. No. of the book to be deleted ";
	int id;
	cin>>id;
	stud.deletedata(id);
	cout<<"\nEnter any key to return to the previous menu";
	getch();
}

void admin(){
	 border();
	 int no;
	 log_check();
	 ad:
	 clrscr();
	 gotoxy(30,9);
	 cout<<"Administrator Menu"<<endl;
	 gotoxy(28,11);
	 cout<<"1 - Add Records"<<endl;
	 gotoxy(28,13);
	 cout<<"2 - Student Records"<<endl;
	 gotoxy(28,15);
	 cout<<"3 - Change Password"<<endl;
	 gotoxy(28,17);
	 cout<<"4 - Update Records"<<endl;
	 gotoxy(28,19);
	 cout<<"5 - Delete Records"<<endl;
	 gotoxy(28,21);
	 cout<<"6 - Log out"<<endl;
	 gotoxy(28,23);
	 cout<<"Choose any appropriate number"<<endl;
	 gotoxy(28,25);
	 cin>>no;
	 switch(no){
		case 1:
		add_rec();
		goto ad;
		break;
		case 2:
		std_rec();
		goto ad;
		break;
		case 3:
		change_pass();
		goto ad;
		break;
		case 4:
		update();
		goto ad;
		break;
		case 5:
		delete_records();
		goto ad;
		break;
		case 6:
		menu();
		default:
		cout<<"Inappropriate choice, Press any key to choose again";
		getch();
		goto ad;

	 }

}

void add_rec(){
	clrscr();
	student stud;
	stud.getdata();
	getch();

}

void log_check(){
      border();
      char checkU[15];
      char checkP[15];
      char ch;
      gotoxy(28,11);
      cout<<"Enter the Username "<<endl;
      gotoxy(28,12);
      gets(checkU);
      gotoxy(28,14);
      cout<<"Enter the Password "<<endl;
      gotoxy(28,15);
      int i = 0;
      while(i<15){
	ch = getch();
	if(isalnum(ch)){
	     checkP[i] = ch;
	     cout<<"*";
	     i++;
	}
	if(ch == '\b' && i>=1){
		cout<<"\b \b";
		i--;
	}
	if(ch == '\r'){
		checkP[i] = '\0';
		break;
	}

      }
      if(!(strcmp(checkU,user)) && !(strcmp(checkP,pass))){
      clrscr();
      }else{
	cout<<"\nWrong Details.\n Press 1 to get to main menu or any other \ncharacter to again enter the  details";
	char ch;
	cin>>ch;

	if(ch=='1')
	menu();
	else
	admin();
      }
}

void book_deposit(){
	clrscr();
	student stud;
	stud.read('S');
	int id,fine=0;
	cout<<"Enter the Sr. No. of the book  to be deposited";
	cin>>id;
	cout<<"Enter the no. of days you had the book ";
	int days;
	cin>>days;
	if(days>7){
		fine += 4*(days/7);
	}
	cout<<"Your fine is "<<fine<<" Rs."<<endl;
	cout<<"Enter any key to continue";
	stud.avail_change(id,'F');
	cout<<"Your book has been deposited. Press any key to return ";
	getch();
	student_func();
	}


void std_rec(){
	clrscr();
	student std;
	std.read('A');
	getch();
}

void change_pass(){
	border();
	char checkP[15];
	char ch;
	gotoxy(20,11);
	cout<<"Enter the old password: "<<endl;
	gotoxy(20,13);
	int i = 0;
	while(i<15){
	ch = getch();
	if(isalnum(ch)){
	     checkP[i] = ch;
	     cout<<"*";
	     i++;
	}else if(ch == '\b' && i>=1){
		cout<<"\b \b";
		i--;
	}else if(ch == '\r'){
		checkP[i] = '\0';
		break;
	}

      }
      if(!(strcmp(checkP,pass))){
	gotoxy(20,16);
	cout<<"Enter the new password: ";
	gotoxy(20,18);
	gets(pass);
	gotoxy(20,20);
	cout<<"Your password has been changed";
	gotoxy(20,22);
	cout<<"Press any key to return";

	getch();

      }else{
       gotoxy(20,20);
	cout<<"Wrong password...Enter any key to return";
	getch();

      }
}



