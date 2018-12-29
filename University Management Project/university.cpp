//PROJECT OF UNIVERSITY MANAGMENT SYSTEM

//Decleration of header files

#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<iomanip.h>
#include<graphics.h>
typedef char option[45];
const int row=10,col=10;
int scan;	//To hold the special character for moving the prompt in menu
int ascii;
//To display the main menu options
option a[]={
		"1.ENTRY",
		"2.DISPLAY",
		"3.ENQUIRY",
		"4.MODIFICATION",
		"5.PERFORMANCE",
		"6.EXIT",
	};
//To display the ENTRY menu option.
option b[]={
		"1.COLLEGE",
		"2.STUDENT",
		"3.EXAM FORM",
		"4.EXAM SCHEDULE",
		"5.RESULT",
		"6.BACK TO PREVIOUS MENU",
	};
//To display the DISPLAY menu option
option c[]={
		"1.COLLEGE",
		"2.STUDENT",
		"3.EXAM FORM",
		"4.EXAM SCHEDULE",
		"5.RESULT",
		"6.BACK TO PREVIOUS MENU",
	};
//To display the ENQUIRY menu option
option d[]={
		"1.COLLEGE",
		"2.STUDENT",
		"3.BACK TO PREVIOUS MENU",
	};
//To display the MODIFICATION menu option
option e[]={
		"1.COLLEGE",
		"2.STUDENT",
		"3.BACK TO PREVIOUS MENU",
	};
//To display the PERFORMANCE menu option
option f[]={
		"1.FOUNDATION",
		"2.BACK TO PREVIOUS MENU",
	   };
//Function used for screening
class main_menu
{
	private:
		int j,done;
	public:
		void normal(int x,int y,char *str);
		void reverse(int x,int y,char *str);
		void box(int x1,int y1,int x2,int y2);
		char menu();
		void control_menu();
		void entry_menu();
		char e_menu();
		void display_menu();
		char d_menu();
		void enquiry_menu();
		char enqu_menu();
		void modification_menu();
		char mod_menu();
		void performance_menu();
		char perform_menu();
		void help(void);
		void first_screen(void);

};
/*Class member for drawing boxes*/
class shape
{
	public:
		void line_hor(int,int,int,char);
		void line_ver(int,int,int,char);
		void box(int,int,int,int,char);
};
//class contain all the information of college
class college
{
	public:
		void new_college(void);	//function for entering information of a new college
		void display_list(void);	//function for displaying all the colleges and their information
		void college_enquiry(void);     	//function for enquirying about a particular college
		void college_modification(void);	//function for modifying the college details
		void clear(int,int);			//function for performing screen clear function
		int found_college(int);			//function to find the college in college.dat
		char *return_name(int);			//function for validation entry of college name
		char *return_loc(int);			//function for validiation entry of college location
		char *return_str(int);			//function for validation entry of college stream
		char *return_degI(int);			//function for validation entry of college degree(b.a/b.sc/b.com)
		char *return_degII(int);		//function for validation entry of college degree(m.a/m.sc)
		void display(int);			//function for displaying college information
		void modify_college(int,char [],char [],char [],char [],char []);	//funcion for college modification
		int last_collid(void);			//function to find the last college id in college.dat
		int recordno(int);			//function to find the record number in college.dat
	private:
		  void add_to_file(int,char [],char [],char[],char[],char[]);	//function to add record
		  void box_for_display(int);		//function to draw box
		  void box_for_enquirycollege(int);	//function to draw box
		  int coll_id;
		  char coll_name[30],coll_loc[30],coll_str[30],coll_degI[30],coll_degII[30];
};
class student
{
	public:
		void new_student(void);		//function for entreing information of new student
		void display_list(void);	//function to display student details
		void enquiry_student(void);	//function to display particular student detail
		void student_modification(void);//function to modify student information
		void clear(int,int);		//function for clearing screen
		int found_student(int);		//function to find the student in student.dat
		char *return_name(int);		//function for validation entry of student name
		void examdisplay(int,int);	//function to display information
		void resultdisplay(int);        //function to display information
		char *return_fname(int);	//function for validation entry of student father name
		char *return_address(int);      //function for validation entry of address
		char *return_stream(int);	//function for validation entry of stream
		char *return_city(int);		//function for validation entry of city
		char *return_state(int);	//function for validation entry of state
		char *return_zip(int);	        //function for validation entry of zip
		char *return_contact(int);	//function for validation entry of contact number
		char *return_code(int);		//function for validation entry of std code
		char *return_degree(int);	//function for validation entry of degree
		void display(int);		//function to display
		//function to modify the student details
		void modify_student(int,char[],char[],char[],char[],char[],char[],char[]);
		int last_stuid(void);		//function to find the last student id in student.dat
		int recordno(int);		//function to find the record number in student.dat
	private:
		//function to add record
		void add_to_file(int,char[],char[],char[],char[],char[],char[],char[],char[],char[],char[]);
		void box_for_display(int);	//function to draw box
		void box_for_enquirystudent(int);//function to draw box
		int stu_id;
		char stu_name[30],stu_fname[30],stu_add[30],stu_city[30],stu_state[30],stu_zip[30],stu_contact[30],stu_code[30],stu_strm[30],stu_deg[30];
};
class examinfo
{
	public:
		void exam_formentry();		//function for the form fill up
		void exam_scheduleentry(void);	//function for the entry of the schedule
		void display_list(void);	//function to display
		void display_schedulelist(void);//function to display
		void result_entry(void);	//function for the entry of the result
		void resultdisplay_list(void);	//function for the result display
		char *return_degname(int);	//function for the valid entry of degree
		int last_examformid(void);	//function to find the last id
		void clear(int,int);		//function for clearing screen
		void display(int);		//function to display
		//function to add record
		void add_to_file_form(int,int,char[],char[],char[],char[],char[]);
		//function to add record
		void add_to_filebaI(int,char[],char[],int,int,int,int,int);
		//function to add record
		void add_to_filebaII(int,char[],char[],int,int,int,int,int);
		//function to add record
		void add_to_filebaIII(int,char[],char[],int,int,int,int,int);
		//function to add record
		void add_to_filemaI(int,char[],char[],int,int,int,int,int,int,int,int);
		//function to add record
		void add_to_filemaII(int,char[],char[],int,int,int,int,int,int,int,int);
	private:
		char stu_deg[30],stu_name[30],stu_fname[30],stu_add[30],stu_strm[30],sd1[30],ed1[30],sm1[30],em1[30],sy1[30],ey1[30],deg[30];
		int stu_id,examform_id,hp1,hp2,hp3,hp4,hp5,hp6,hp7,hp8,s1,s2,com,gk;
		int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16;
		//function to add record
		void add_to_file_schedule(char[],char[],char[],char[],char[],char[],char[]);
};
class performance
{
	public:
		void foundation(void);
};
/*Function to display all the menu prompt message from the pointer array
of option a[]*/
void main_menu::normal(int x,int y,char *str)
{
	gotoxy(x,y);
	cprintf("%s",str);
}
//Function to move the cursor in the menu prompt with reverse video color
void main_menu::reverse(int x,int y,char *str)
{
	textcolor(5+143);
	textbackground(WHITE);
	gotoxy(x,y);
	cprintf("%s",str);
	textcolor(GREEN);
	textbackground(BLACK);
}
void main_menu::box(int x1,int y1,int x2,int y2)
{
	for(int col=x1;col<x2;col++)
	{
		gotoxy(col,y1);
		cprintf("%c",196);
		gotoxy(col,y2);
		cprintf("%c",196);
	}
	for(int row=y1;row<y2;row++)
	{
		gotoxy(x1,row);
		cprintf("%c",179);
		gotoxy(x2,row);
		cprintf("%c",179);
	}
	gotoxy(x1,y1);
	cprintf("%c",218);
	gotoxy(x1,y2);
	cprintf("%c",192);
	gotoxy(x2,y1);
	cprintf("%c",191);
	gotoxy(x2,y2);
	cprintf("%c",217);
}
char main_menu::menu()
{
	clrscr();
	textcolor(22);
	box(20,6,65,20);
	box(18,4,67,22);
	textcolor(5+143);
	gotoxy(28,5);
	textbackground(BLUE);
	cprintf("UNIVERSITY MANAGEMENT SYSTEM");
	textbackground(BLACK);
	textcolor(22);
	for(int i=1;i<6;i++)
		normal(32,i+10,a[i]);
	reverse(32,10,a[0]);
	i=done=0;
	_setcursortype(_NOCURSOR);//change the cursor type
	do
	{
		int key=getch();
		switch(key)
		{
					case 72:
						normal(32,i+10,a[i]);
						i--;
						if(i==-1)
						i=5;
						reverse(32,i+10,a[i]);
						break;
					case 80:
						normal(32,i+10,a[i]);
						i++;
						if(i==6)
						i=0;
						reverse(32,i+10,a[i]);
						break;
			case 13:
				done=1;
		}
	}
	while(!done);
	_setcursortype(_NOCURSOR);
	return(i+49);
}
/*The function main_menu() is used to display the main menu of university managment system.
This function uses 6 main options and each has its specific purposes for maintaining
the university.In this menu,the user can avail the facilities by pressing any number
from 1 to 5 and in case he presses any other key the prompt will come back from menu to the
source promgram or it is better to press '0' to exit from the menu.other than 0 and 1...5
if you press any other key the university managment system do not response till you press a valid number
*/
void main_menu::control_menu()
{
	char choice;
	do
	{
		choice=menu();
		clrscr();
		switch(choice)
		{
			case '1': box(3,1,75,24);
				  box(5,2,73,23);
				  gotoxy(7,4);
				  entry_menu();		//sub menu of main menu
				  break;
			case '2': box(3,1,75,24);
				  box(5,2,73,23);
				  gotoxy(7,5);
				  display_menu();	//sub menu of main menu
				  break;
			case '3': box(3,1,75,24);
				  box(5,2,73,23);
				  gotoxy(7,6);
				  enquiry_menu();	//sub menu of main menu
				  break;
			case '4': box(3,1,75,24);
				  box(5,2,73,23);
				  gotoxy(7,8);
				  modification_menu();	//sub menu of main menu
				  break;
			case '5': box(3,1,75,24);
				  box(5,2,73,23);
				  gotoxy(7,9);
				  performance_menu();	//sub menu of main menu
				  break;
			case '6': exit(0);
		}
    }while(choice!=5);
}
/*design of entry menu:- This function is used to return the cursor position to the entry menu function where the menu prompt is valid(design function)*/
char main_menu::e_menu()
{
	clrscr();
	textcolor(22);
	box(25,6,65,20);
	box(23,4,67,22);
	textcolor(5+143);
	gotoxy(34,5);
	textbackground(GREEN);
	cprintf("ENTRY MENU");
	textcolor(22);
	textbackground(BLACK);
	for(int i=1;i<6;i++)
		normal(32,i+10,b[i]);
	reverse(32,10,b[0]);
	i=done=0;
	_setcursortype(_NOCURSOR);	//change the cursor
	do
	{
		int key=getch();
		switch(key)
		{
					case 72:
						normal(32,i+10,b[i]);
						i--;
						if(i==-1)
						i=5;
						reverse(32,i+10,b[i]);
						break;
					case 80: normal(32,i+10,b[i]);
						 i++;
						 if(i==6)
						 i=0;
						 reverse(32,i+10,b[i]);
						 break;
			case 13:
				done=1;
		}
	}while(!done);
	_setcursortype(_NOCURSOR);
	return(i+49);
}
/*Function for entry menu with open college,student,examform,schedule and result sub-menu.This is one of the submenu which manages
five basic operations such as:
	-New College
	-New Student
	-Exam Form
	-Exam Schedule
	-Result
while entering new college information college name,address,streem,degree are asked to enter
student menu provides information to add that are nessary.*/
void main_menu::entry_menu()
{
	char choice;
	student stu;
	college coll;
	examinfo einfo;
	do
	{
		choice=e_menu();
		clrscr();
		switch(choice)
		{
			case '1':
				 box(3,1,75,24);
				 box(5,2,73,23);
				  _setcursortype(_NORMALCURSOR);
				  gotoxy(7,4);
				 coll.new_college();	//sub menu of entry menu
				 break;
			case '2':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 gotoxy(7,5);
				 stu.new_student();	//sub menu of entry menu
				 break;
			 case '3':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 gotoxy(7,6);
				 einfo.exam_formentry();	//sub menu of entry menu
				 break;
			case '4':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 gotoxy(7,7);
				 einfo.exam_scheduleentry();	//sub menu of entry menu
				 break;
			case '5':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 gotoxy(7,8);
				 einfo.result_entry();	//sub menu of entry menu
				 break;
			case '6':
				 return ;
		}
	}while(choice!=5);
}
/*design of display menu:-This function is used to return the cursor poisition to the display menu function where the menu prompt is valid(design part)*/
char main_menu::d_menu()
{
	clrscr();
	textcolor(22);
	box(25,6,65,20);
	box(23,4,67,22);
	textcolor(5+143);
	gotoxy(34,5);
	textbackground(GREEN);
	cprintf("DISPLAY MENU");
	textcolor(22);
	textbackground(BLACK);
	for(int i=1;i<6;i++)
		normal(32,i+10,c[i]);
	reverse(32,10,c[0]);
	i=done=0;
	_setcursortype(_NOCURSOR);	//change the cursor type
	do
	{
		int key=getch();
		switch(key)
		{
					case 72:
						normal(32,i+10,c[i]);
						i--;
						if(i==-1)
						i=5;
						reverse(32,i+10,c[i]);
						break;
					case 80: normal(32,i+10,c[i]);
						 i++;
						 if(i==6)
						 i=0;
						 reverse(32,i+10,c[i]);
						 break;
			case 13:
				done=1;
		}
	}while(!done);
	_setcursortype(_NOCURSOR);
	return(i+49);
}
/*Function for display menu with college, student, exam form, exam schedule, and result.This is one of the sub menu which manages
five operations such as:
	-College
	-Student
	-Exam Form
	-Exam Schedule
	-Result
while displaying records it displays all the records that were enterd in the entry section and
extract this information from their particulat database files*/
void main_menu::display_menu()
{
	char choice;
	college coll;
	student stu;
	examinfo einfo;
	do
	{
		choice=d_menu();
		clrscr();
		switch(choice)
		{
			case '1':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 coll.display_list();	//sub menu of display menu
				 getch();
				 break;
			case '2':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 stu.display_list();	//sub menu of display menu
				 getch();
				 break;
			 case '3':
				 box(3,1,75,24);
				 box(5,2,73,23);
				  _setcursortype(_NORMALCURSOR);
				 einfo.display_list();	//submenu of display menu
				 getch();
				 break;
			case '4':
				 box(3,1,75,24);
				 box(5,2,73,23);
				  _setcursortype(_NORMALCURSOR);
				 einfo.display_schedulelist();	//sub menu of dispalay menu
				 getch();
				 break;
			case '5':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 einfo.resultdisplay_list();	//sub menu of display menu
				 getch();
				 break;
			case '6':
				 return;
		}
	}while(choice!=5);
}
/*design of enquiry menu:-This function is used to return the cursor position to the enquiry menu function where the menu prompt is valid(design function)*/
char main_menu::enqu_menu()
{
	clrscr();
	textcolor(22);
	box(25,6,65,20);
	box(23,4,67,22);
	textcolor(5+143);
	gotoxy(34,5);
	textbackground(GREEN);
	cprintf("ENQUIRY MENU");
	textcolor(22);
	textbackground(BLACK);
	for(int i=1;i<3;i++)
		normal(32,i+10,d[i]);
	reverse(32,10,d[0]);
	i=done=0;
	_setcursortype(_NOCURSOR);	//change the cursor type
	do
	{
		int key=getch();
		switch(key)
		{
					case 72:
						normal(32,i+10,d[i]);
						i--;
						if(i==-1)
						i=2;
						reverse(32,i+10,d[i]);
						break;
					case 80: normal(32,i+10,d[i]);
						 i++;
						 if(i==3)
						 i=0;
						 reverse(32,i+10,d[i]);
						 break;

			case 13:
				done=1;
		}
	}while(!done);
	_setcursortype(_NOCURSOR);
	return(i+49);
}
/*This function is used for the enwuiry of aparticular college or student
This function asks the user to enter id of the college or student for which
they want to enquir about*/
void main_menu::enquiry_menu()
{
	char choice;
	college coll;
	student stu;
	examinfo einfo;
	do
	{
		choice=enqu_menu();
		clrscr();
		switch(choice)
		{
			case '1':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 coll.college_enquiry();	//Sub menu of Enquiry
				 getch();
				 break;
			case '2':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 stu.enquiry_student();		//sub menu of Enquiry
				 getch();
				 break;
			case '3':
				 return;
		}
	}while(choice!=5);
}
/*design of modify menu:-This function is used to return the cursor position to the modify menu function where the menu prompt is valid(design function)*/
char main_menu::mod_menu()
{
	clrscr();
	textcolor(22);
	box(25,6,65,20);
	box(23,4,67,22);
	textcolor(5+143);
	gotoxy(34,5);
	textbackground(GREEN);
	cprintf("MODIFICATION MENU");
	textcolor(22);
	textbackground(BLACK);
	for(int i=1;i<3;i++)
		normal(32,i+10,e[i]);
	reverse(32,10,e[0]);
	i=done=0;
	_setcursortype(_NOCURSOR);
	do
	{
		int key=getch();
		switch(key)
		{
					case 72:
						normal(32,i+10,e[i]);
						i--;
						if(i==-1)
						i=2;
						reverse(32,i+10,e[i]);
						break;
					case 80: normal(32,i+10,e[i]);
						 i++;
						 if(i==3)
						 i=0;
						 reverse(32,i+10,e[i]);
						 break;

			case 13:
				done=1;
		}
	}while(!done);
	_setcursortype(_NOCURSOR);
	return(i+49);
}
/*This function is used to modify the information of the college or student.
This function asks for the college or student id for modification.First it
shows the old record and then asks the user "Do You Want To Modify(Y/N).If
the user press yes it ask the user to enter the new information and then
saves it in their particular data files*/
void main_menu::modification_menu()
{
	char choice;
	college coll;
	student stu;
	examinfo einfo;
	do
	{
		choice=mod_menu();
		clrscr();
		switch(choice)
		{
			case '1':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 coll.college_modification();	//sub menu of modification
				 break;
			case '2':
				 box(3,1,75,24);
				 box(5,2,73,23);
				 _setcursortype(_NORMALCURSOR);
				 stu.student_modification();	//sub menu ofmodification
				 break;
			 case '3':
				  return;
		}
	}while(choice!=3);
}
/*design of perform menu:-This function is used to return the cursor position to the performance menu function where the menu prompt is valid(design function)*/
char main_menu::perform_menu()
{
	clrscr();
	textcolor(22);
	box(25,6,65,20);
	box(23,4,67,22);
	textcolor(5+143);
	gotoxy(34,5);
	textbackground(GREEN);
	cprintf("PERFORMANCE MENU");
	textcolor(22);
	textbackground(BLACK);
	for(int i=1;i<2;i++)
		normal(32,i+10,f[i]);
	reverse(32,10,f[0]);
	i=done=0;
	_setcursortype(_NOCURSOR);
	do
	{
		int key=getch();
		switch(key)
		{
					case 72:
						normal(32,i+10,f[i]);
						i--;
						if(i==-1)
						i=1;
						reverse(32,i+10,f[i]);
						break;
					case 80: normal(32,i+10,f[i]);
						 i++;
						 if(i==2)
						 i=0;
						 reverse(32,i+10,f[i]);
						 break;
			case 13:
				done=1;
		}
	}while(!done);
	_setcursortype(_NOCURSOR);
	return(i+49);
}
/*This function dispalys the performance of the university such as
	- Foundation
	-Annual Report
*/
void main_menu::performance_menu()
{
	char choice;
	performance perf;
	do
	{
		choice=perform_menu();
		clrscr();
		switch(choice)
		{
			case '1':
				 box(2,1,77,24);
				 box(3,2,75,23);
				 _setcursortype(_NORMALCURSOR);
				 perf.foundation();
				 getch();
				 break;
			 case '2':
				   return;
		}
	}while(choice!=2);
}
/* function to draw horizontal line.This public function draws one horizontal line at a time*/
void shape::line_hor(int coloumn1,int coloumn2,int row,char c)
{
	for(coloumn1;coloumn1<=coloumn2;coloumn1++)
	{
		gotoxy(coloumn1,row);
		cout<<c;
	}
}

/*function to draw vertical line.this public function draws one vertical line at a time.*/
void shape::line_ver(int row1,int row2,int coloumn,char c)
{
	for(row1;row1<=row2;row1++)
	{
		 gotoxy(coloumn,row1);
		 cout<<c;
	}
}

/*Function for drawing box.This function draws a box for menus*/
void shape::box(int coloumn1,int row1,int coloumn2,int row2,char c)
{
	char ch=218;
	char c1,c2,c3,c4;
	char l1=196,l2=179;
	if(c==ch)
	{
		c1=218;
		c2=191;
		c3=217;
		c4=217;
		l1=196;
		l2=179;
	}
	else
	{
		c1=c;
		c2=c;
		c3=c;
		c4=c;
		l1=c;
		c2=c;
	}
	gotoxy(coloumn1,row1);
	cout<<c1;
	gotoxy(coloumn2,row1);
	cout<<c2;
	gotoxy(coloumn1,row2);
	cout<<c3;
	gotoxy(coloumn2,row2);
	cout<<c4;
	coloumn1++;
	coloumn2--;
	line_hor(coloumn1,coloumn2,row1,l1);//Horizontal lines
	line_hor(coloumn1,coloumn2,row1,l1);
	coloumn1--;
	coloumn2++;
	row1++;
	row2--;
	line_ver(row1,row2,coloumn1,l2);//vertical line
	line_ver(row1,row2,coloumn2,l2);
}
/* Function to display help about this project.This help function is the second screen output display to know about the menu options
and about the banking project*/
void main_menu::help(void)
{
	clrscr();
	setbkcolor(7);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(20,20,"THIS PROJECT CAN KEEP RECORD OF COLLEGE,STUDENT,RESULT & EXAM");//60,100 //30 is good cheak it properly
	delay(2);
	outtextxy(20,50,"THIS PROJECT IS CAPABLE OF HOLDING ANY NO OF COLLEGE & STUDENT");
	delay(2);
	outtextxy(20,80,"-IN MAIN MENU FIRST OPTION IS ENTRY OPTION IN WHICH YOU CAN");
	delay(2);
	outtextxy(20,110,"ENTER THE DETAILS OF COLLEGE, STUDENT, EXAM AND RESULT");//60,160
	delay(2);
	outtextxy(27,140,"-SECOND OPTION IS DISPLAY OPTION WHICH DISPLAYS ALL THE");
	delay(2);
	outtextxy(25,170,"DETAILS OF COLLEGE, STUDENT, EXAM AND RESULT ACCORDING TO");
	delay(2);
	outtextxy(20,200,"THE CHOICE OF THE USER.");
	delay(2);
	outtextxy(20,230,"-THIRD OPTION IS ENQUIRY OPTION IN WHICH USER CAN ENQUIRED");
	delay(2);
	outtextxy(25,260,"ABOUT COLLEGES,STUDENTS,EXAM SCHEDULES.");
	delay(2);
	outtextxy(25,290,"-FOURTH OPTION IS MODIFICATION OPTION IN WHICH USER CAN MODIFY");
	delay(2);
	outtextxy(30,320,"ABOUT COLLEGE,STUDENT,EXAM SCHEDULES,RESULTS ACCORDING");
	delay(2);
	outtextxy(30,350,"TO USER CHOICE");
	delay(2);
	outtextxy(30,380,"-FIFTH OPTION IS PERFORMNACE OPTION IN WHICH USER CAN KNOW");
	setbkcolor(12);
	delay(2);
	settextstyle(7,HORIZ_DIR,4);
	outtextxy(50,420,"PRESS ANY KEY TO CONTINUE............");
	getch();
	clrscr();
	setbkcolor(7);
	settextstyle(2,HORIZ_DIR,6);
	delay(2);
	outtextxy(3,20,"THE ANNUAL REPORT AND FOUNDATION OF UNIVERSITY");
	delay(2);
	outtextxy(3,50,"-FIFTH OPTION IS EXIT, FINALLY USER CAN EXIT FROM THE PROJECT");
	delay(2);
	outtextxy(9,340,"NOTE:-YOU CAN PERFORM YOUR WORK AND CHOOSE A OPTION");
	delay(2);
	outtextxy(65,370,"AND TRAVERSES THROUGH THE ARROW KEYS");
	setbkcolor(12);
	delay(2);
	settextstyle(7,HORIZ_DIR,4);
	outtextxy(50,420,"PRESS ANY KEY TO CONTINUE............");
	getch();

}

/*This is the first screen output display to welcome to University Managemnt System and give personal details that is
project devloper name,course and reg.no.*/
void main_menu::first_screen(void)
{
	clrscr();
	setbkcolor(7);
	settextstyle(7,HORIZ_DIR,3);
	outtextxy(20,20,"WELCOME TO UNIVERSITY MANAGMENT SYSTEM");
	setcolor(30);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(60,100,"DEVLOPED BY:- MONIKA DUGAR");
	delay(2);
	outtextxy(60,130,"     COURSE:- DOEACC 'A' LEVEL");
	delay(2);
	outtextxy(60,160,"     REG.NO:- 494837");
	setbkcolor(12);
	settextstyle(7,HORIZ_DIR,4);
	outtextxy(50,420,"PRESS ANY KEY TO CONTINUE............");
	getch();

}
/*Function for creating a new college.This is a very important function which is used used to create new college with
all the details of the college.This function uses member functions like last_collid(),add_to_file(),delete_account etc.
The last_collid() function will create automatically a new college id number after cheaking from the "COLLEGE.dat" file.
Here the college id numbers start from 1 onwards if it is the first record.Also in this function the validation cheaking
occurs to the name,address,stream and degree.At the time of validation cheaking the name,
address,stream and degree should not blank and sholud not more than the specified length.*/
void college::new_college(void)
{
	char ch;
	int i,valid;
	clrscr();
	college coll;
	shape s;
	s.box(2,1,79,25,318);
	s.box(25,2,54,4,219);
	gotoxy(65,2);
	cout<<"<0>=EXIT";
	gotoxy(3,3);
	for(i=1;i<=76;i++)
		cprintf(" ");
	textbackground(BLACK);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	gotoxy(30,3);
	_setcursortype(_NOCURSOR);//changes cursor type
	cprintf("COLLEGE-ENTRY");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	getch();
	int d1,m1,y1;
	struct date d;
	getdate(&d);	//For extracting system date
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	int coll_id;
	coll_id=coll.last_collid();
	coll_id++;
	char coll_name[30],coll_loc[30],coll_str[30],coll_degI[30],coll_degII[30];
	_setcursortype(_NORMALCURSOR);
	gotoxy(5,6);
	cout<<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(5,8);
	cout<<"COLLEGE-ID:"<<coll_id;
	gotoxy(5,10);
	cout<<"NAME:";
	gotoxy(5,12);
	cout<<"LOCATION:";
	gotoxy(5,14);
	cout<<"STREAM:";
	gotoxy(5,16);
	cout<<"DEGREE-I:";
	gotoxy(5,18);
	cout<<"DEGREE-II:";
	do
	{
		coll.clear(16,10);
		coll.clear(5,23);
		gotoxy(5,23);
		cout<<"ENTER THE NAME OF THE COLLEGE";
		valid=1;
		gotoxy(16,10);
		gets(coll_name);
		strupr(coll_name);
		if(coll_name[0]=='0')
			return;
		if(strlen(coll_name)==0||strlen(coll_name)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 NAME SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		coll.clear(28,12);
		coll.clear(5,23);
		gotoxy(5,23);
		cout<<"ENTER THE LOCATION OF THE COLLEGE";
		valid=1;
		gotoxy(28,12);
		gets(coll_loc);
		strupr(coll_loc);
		if(coll_loc[0]=='0')
			return;
		if(strlen(coll_loc)==0||strlen(coll_loc)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 LOCATION SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		coll.clear(26,14);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}

		gotoxy(5,23);
		cout<<"ENTER THE STREAM  OF THE COLLEGE(ARTS/SCIENCE/COMMERCE";
		valid=1;
		gotoxy(26,14);
		gets(coll_str);
		strupr(coll_str);
		if(coll_str[0]=='0')
			return;
		if(strlen(coll_str)==0||strlen(coll_str)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 STREAM SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		coll.clear(26,16);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER THE DEGREE COURSE FOR BACHELOR DEGREE(B.A/B.COM/B.SC)";
		valid=1;
		gotoxy(26,16);
		gets(coll_degI);
		strupr(coll_degI);
		if(coll_degI[0]=='0')
			return;
		if(strlen(coll_degI)==0||strlen(coll_degI)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 DEGREE SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		coll.clear(29,18);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER THE DEGREE COURSE FOR MASTER DEGREE(M.A/M.SC/M.COM)";
		valid=1;
		gotoxy(29,18);
		gets(coll_degII);
		strupr(coll_degII);
		if(coll_degII[0]=='0')
			return;
		if(strlen(coll_degII)==0||strlen(coll_degII)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 DEGREE SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		valid=1;
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"DO YOU WANT TO SAVE THE RECORD(Y/N):";
		ch=getch();
		if(ch==0)
			return;
		ch=toupper(ch);
	}while(ch!='N'&&ch!='Y');
	if(ch=='N')
		return;
	//append the record to college,dat
	add_to_file(coll_id,coll_name,coll_loc,coll_str,coll_degI,coll_degII);
}
/*This is a function which displays the details of all the colleges under the university
with all the detail such as colleg id, college name, college address, college stream,college degree
that are under that college.Thus the user can look and know the detail of colleges*/
void college::display_list(void)
{
	clrscr();
	int flag;
	fstream file;
	gotoxy(25,1);
	cout<<"COLLEGE DISPLAY LIST";
	gotoxy(25,2);
	cout<<"======================";
	gotoxy(1,3);
	for(int j=1;j<=79;j++)
		cout<<"=";
	gotoxy(1,5);
	cout<<"ID";
	gotoxy(4,5);
	cout<<"NAME";
	gotoxy(20,5);
	cout<<"LOCATION";
	gotoxy(34,5);
	cout<<"STREAM";
	gotoxy(48,5);
	cout<<"DEGREE-I";
	gotoxy(60,5);
	cout<<"DEGREE-II";
	gotoxy(1,6);
	for(j=1;j<=79;j++)
		cout<<"=";
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	int row=7;
	while(file.read((char*)this,sizeof(college)))
	{
		flag=0;
		delay(2);
		gotoxy(1,row);
		cout<<coll_id;
		gotoxy(4,row);
		puts(coll_name);
		gotoxy(20,row);
		puts(coll_loc);
		gotoxy(34,row);
		puts(coll_str);
		gotoxy(48,row);
		puts(coll_degI);
		gotoxy(60,row);
		puts(coll_degII);
		row++;
		if(row>23)
		{
			flag=1;
			row=6;
			gotoxy(4,24);
			cout<<"PRESS ANY KEY TO CONTINUE";
			clrscr();
		}
	}
	gotoxy(1,row);
	for(j=1;j<=79;j++)
		cout<<"=";
	row++;
	file.close();
	if(!flag)
	{
		gotoxy(4,24);
		cout<<"PRESS ANY KEY TO CONTINUE:";
		getch();
	}
}
/*This function is used to enquire about the college.This function ask for the college id
to enquie about and after matching the id it displays the record of the enquired college */
void college::college_enquiry(void)
{
	clrscr();
	int t_collid=0;
	college coll;
	gotoxy(71,1);
	cout<<"<0>=EXIT";
	gotoxy(5,5);
	cout<<"ENTER COLLEGE ID";
	cin>>t_collid;
	if(t_collid==0)
		return;
	if(!coll.found_college(t_collid))
	{
		gotoxy(5,5);
		cout<<"\7 INVALID COLLEGE ID";
		getch();
		return;
	}
	box_for_enquirycollege(t_collid);
	int row=9,flag;
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	while(file.read((char*)this,sizeof(college)))
	{
		if(coll_id==t_collid)
		{
			delay(2);
			gotoxy(4,row);
			puts(coll_str);
			gotoxy(38,row);
			puts(coll_degI);
			gotoxy(55,row);
			puts(coll_degII);
			row++;
			if(row>23)
			{
				flag=1;
				row=7;
				gotoxy(4,24);
				cout<<"PRESS ANY KEY TO CONTINUE:";
				getch();
				clrscr();
				box_for_enquirycollege(t_collid);
			}
		}
	}
	file.close();
	if(!flag)
	{
		gotoxy(4,24);
		cout<<"PRESS ANY KEY TO CONTINUE";
		getch();
	}
}
/* This function is used to modify the college detail.This function asks for the
college id for which the information is to be modified.Then it asks "Do you want to
Modify (Y/N)".If 'Y' is entred it asks for the user to enter new information.
*/
void college::college_modification(void)
{
	clrscr();
	int j;
	int t,t_collid;
	gotoxy(17,1);
	cout<<"<0>=EXIT";
	gotoxy(5,5);
	cout<<"ENTER THE COLLEGE ID:";
	cin>>t_collid;
	if(t_collid==0)
		return;
	clrscr();
	if(!found_college(t_collid))
	{
		gotoxy(5,5);
		cout<<"\7 COLLEGE NOT FOUND:";
		getch();
		return;
	}
	gotoxy(71,1);
	cout<<"<0>=EXIT";
	textbackground(WHITE);
	gotoxy(3,3);
	for(j=1;j<=76;j++)
		cprintf("");
	textbackground(BLACK);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	gotoxy(30,3);
	cprintf("MODIFY COLLEGE DETAIL");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(4,2);
	cout<<"DATE:"<<d1<<"/"<<m1<<"/"<<y1;
	char ch;
	display(t_collid);
	college coll;
	do{
		coll.clear(5,13);
		gotoxy(5,13);
		cout<<"MODIFY COLLEGE DETAILS:(Y/N)";
		ch=getche();
		if(ch=='0')
			return;
		ch=toupper(ch);
	}while(ch!='N'&&ch!='Y');
	if(ch=='N')
		return;
	int modified=0,valid;
	char t_name[30],t_loc[30],t_str[30],t_degI[30],t_degII[30];
	gotoxy(5,15);
	cout<<"NAME:";
	gotoxy(5,16);
	cout<<"LOCATION:";
	gotoxy(5,17);
	cout<<"STREAM:";
	gotoxy(5,18);
	cout<<"DEGREE I:";
	gotoxy(5,19);
	cout<<"DEGREE II:";
	do
	{
		coll.clear(15,15);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER NAME OR PRESS ENTER FOR NO CHANGE:";
		valid=1;
		gotoxy(15,15);
		gets(t_name);
		strupr(t_name);
		if(t_name[0]=='0')
			return;
		if(strlen(t_name)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("NAME SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		coll.clear(20,16);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER LOCATION OR PRESS ENTER FOR NO CHANGE:";
		valid=1;
		gotoxy(20,16);
		gets(t_loc);
		strupr(t_loc);
		if(t_loc[0]=='0')
			return;
		if(strlen(t_loc)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("LOCTION SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		coll.clear(18,17);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER STREAM OR PRESS ENTER FOR NO CHANGE:";
		valid=1;
		gotoxy(18,17);
		gets(t_str);
		strupr(t_str);
		if(t_str[0]=='0')
			return;
		if(strlen(t_str)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("STREAM SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	do
	{
		coll.clear(18,18);
		
		coll.clear(25,19);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER DEGREE OR PRESS ENTER FOR NO CHANGE:";
		valid=1;
		gotoxy(25,19);
		gets(t_degII);
		strupr(t_degII);
		if(t_degII[0]=='0')
			return;
		if(strlen(t_degII)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("DEGREE SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	if(strlen(t_degII)>0)
		modified=1;
	if(!modified)
		return;
	coll.clear(5,23);
	do
	{
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		valid=1;
		gotoxy(5,21);
		cout<<"DO YOU WANT TO SAVE CHANGES(Y/N)";
		ch=getche();
		if(ch=='0')
			return;
		ch=toupper(ch);
	}while(ch!='N'&&ch!='Y');
	if(ch=='N')
		return;
	modify_college(t_collid,t_name,t_loc,t_str,t_degI,t_degII);
	gotoxy(5,22);
	cout<<"\7 RECORD MODIFIED";
	gotoxy(5,23);
	cout<<"PRESS ANY KEY TO CONTINUE";
	getch();
}

/*supporting function of college*/
/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void college::clear(int col,int row)
{
	for(int j=col;j<=76;j++)
	{
		gotoxy(j,row);
		cout<<"";
	}
}
/* Function to find a college for display college function. This is used to find any account in the
"college.dat"data files,where the file is searched from the first record position and it searches
whether the entred id exit or not. If it exit then the variable found will return a value 1 or
0 as the parameter*/
int college::found_college(int t_collid)
{
	fstream file;
	file.open("college.dat",ios::in);
	file.seekg(0,ios::beg);
	int found=0;
	//searches the specified record in college.dat data file
	while(file.read((char*)this,sizeof(college)))
	{
		if(coll_id==t_collid)
		{
			found=1;
			break;
		}
	}
	file.close();
	return found;
}
/*Function for return name of the college from college.dat.This function is basically used
to return only name college if the college is in the "college.dat"data file.When the name is
returned it may simply display/modify other functions*/
char *college::return_name(int t_collid)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_name[30];
	//returns the name to display at  screen if found.
	while(file.read((char*)this, sizeof(college)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_name,coll_name);
			break;
		}
	}
	file.close();
	return t_name;
}
/*Function to return the location of the college from college.dat .This funcion is basicially
used to return only location of the college if location is in the "College.dat" data files.When
the loication  is returned it may simply display/modify other functions */
char *college::return_loc(int t_collid)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_loc[30];
	//return the address to display at screen if found
	while(file.read((char*)this,sizeof(college)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_loc,coll_loc);
			break;
		}
	}
	file.close();
	return t_loc;
}
/*Function to return the stream of the college from college.dat .This funcion is basicially
used to return only stream of the college if stream is in the "college.dat" data files.When
the stream  is returned it may simply display/modify other functions */
char *college::return_str(int t_collid)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_str[30];
	//return the stream to display at  screen if found
	while(file.read((char*)this,sizeof(college)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_str,coll_str);
			break;
		}
	}
	file.close();
	return t_str;
}
/*Function to return the stream of the college from college.dat .This funcion is basicially
used to return only stream of the college if stream is in the "college.dat" data files.When
the stream  is returned it may simply display/modify other functions */
char *college::return_degI(int t_collid)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_degI[30];
	//return the degree to display at  screen if found
	while(file.read((char*)this,sizeof(college)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_degI,coll_degI);
			break;
		}
	}
	file.close();
	return t_degI;
}
/*Function to return the stream of the college from college.dat .This funcion is basicially
used to return only stream of the college if stream is in the "college.dat" data files.When
the stream  is returned it may simply display/modify other functions */
char *college::return_degII(int t_collid)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_degII[30];
	//return the degree to display at  screen if found
	while(file.read((char*)this,sizeof(college)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_degII,coll_degII);
			break;
		}
	}
	file.close();
	return t_degII;
}


/*Function to display college details.This function displays the heading and
the college id,name,location and stream on the screen*/
void college::box_for_display(int t_collid)
{
	int d1,m1,y1;
	struct date d;
	getdate (&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(63,2);
	cout<<"DATE:"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(4,2);
	cout<<"COLLEGE ID"<<t_collid;
	college coll;
	char t_name[30];
	strcpy(t_name,coll.return_name(t_collid));
	char t_loc[30];
	strcpy(t_loc,coll.return_loc(t_collid));
	char t_stream[30];
	strcpy(t_stream,coll.return_str(t_collid));
	gotoxy(25,2);
	cout<<t_name;
	gotoxy(25,3);
	cout<<t_loc;
	gotoxy(4,5);
	cout<<"ENQUIRY MENU FOR COLLEGE";
	textbackground(WHITE);
	textcolor(BLACK);
	textcolor(WHITE);
	gotoxy(1,6);
	for(int i=1;i<=76;i++)
		cout<<"=";
	gotoxy(4,7);
	cprintf("STREEM            DEGREE-I          DEGREE-II");
	gotoxy(1,8);
	for(i=1;i<=76;i++)
		cout<<"=";
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
}
/*supporting function for college display*/
void college::display(int t_collid)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	//Display the record content matching with t_collid from COLLEGE.dat data files.
	while(file.read((char*)this,sizeof(college)))
	{
		if(t_collid==coll_id)
		{
			gotoxy(8,5);
			cout<<"COLLEGE ID:"<<coll_id;
			gotoxy(8,6);
			cout<<"NAME:";
			puts(coll_name);
			gotoxy(8,7);
			cout<<"LOCATION:";
			puts(coll_loc);
			gotoxy(8,8);
			cout<<"STREAM:";
			puts(coll_str);
			gotoxy(8,9);
			cout<<"DEGREE:";
			puts(coll_degI);
			gotoxy(8,10);
			cout<<"DEGREE:";
			puts(coll_degII);
			break;
		}
	}
	file.close();
}
/*supporting function for modification of college*/
void college::modify_college(int t_collid,char t_name[30],char t_loc[30],char t_str[30],char t_degI[30],char t_degII[30])
{
	int recno;
	recno=recordno(t_collid);
	fstream file;
	//open file COLLEGE.dat for overwrite mode.
	file.open("COLLEGE.dat",ios::out|ios::ate);
	strcpy(coll_name,t_name);
	strcpy(coll_loc,t_loc);
	strcpy(coll_str,t_str);
	strcpy(coll_degI,t_degI);
	strcpy(coll_degII,t_degII);
	int position;
	//finds the position in the data file;
	position=(recno-1)*sizeof(college);
	file.seekp(position);
	//overwrite the modified record in to the COLLEGE.dat data file.
	file.write((char *)this,sizeof(college));
	file.close();
	return;
}
/*supporting function for generating the last college id*/
int college::last_collid(void)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	//find the last id number.
	while(file.read((char *)this,sizeof(college)))
		count=coll_id;
	file.close();
	return count;
}
/* supporting function for add to file*/
void college::add_to_file(int t_collid,char t_name[30],char t_loc[30],char t_str[30],char t_degI[30],char t_degII[30])
{
	coll_id=t_collid;
	strcpy(coll_name,t_name);
	strcpy(coll_loc,t_loc);
	strcpy(coll_str,t_str);
	strcpy(coll_degI,t_degI);
	strcpy(coll_degII,t_degII);
	cout<<coll_str;
	//Append new record into COLLEGE.dat data files.
	fstream file;
	file.open("COLLEGE.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(college));
	file.close();
}
/*supporting function for college enquiry*/
void college::box_for_enquirycollege(int t_collid)
{
	
/*Function for returning the record for updating college information.*/
int college::recordno(int t_collid)
{
	fstream file;
	file.open("COLLEGE.dat",ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	//find the records position in COLLEGE.dat data file
	while(file.read((char*)this,sizeof(college)))
	{
		count++;
		if(t_collid==coll_id)
			break;
	}
	file.close();
	return count;
}
/*Function for creating a new student.This is a very important function which is used used to create new student with
all the details of the student.This function uses member functions like last_stuid(),add_to_file(), etc.
The last_stuid() function will create automatically a new student id number after cheaking from the "STUDENT.dat" file.
Here the Student id numbers start from 1 onwards if it is the first record.Also in this function the validation cheaking
occurs to the name,father's name,address,city,state,contact number,code zip,stream and degree.At the time of validation
cheaking the name,father's name,address,city,state,contact number,zip,stream and degree should not blank and sholud not
more than the specified length.*/
void student::new_student(void)
{
	char ch;
	int i,valid;
	clrscr();
	student stu;
	
stu_name[30],stu_fname[30],stu_add[30],stu_city[30],stu_state[30],stu_zip[30],stu_cont[30],stu_code[30],stu_strm[30],stu_deg[30];
	_setcursortype(_NORMALCURSOR);
	gotoxy(5,6);
	cout<<"DATE:-"<<d1<<'/'<<m1<<'/'<<y1;
	gotoxy(5,7);
	cout<<"STUDENT ID:-"<<stu_id;
	gotoxy(5,8);
	cout<<"STUDENT NAME:-";
	gotoxy(5,9);
	cout<<"FATHERS NAME:-";
	gotoxy(5,10);
	cout<<"ADDRESS:-";
	gotoxy(5,11);
	cout<<"CITY:-";
	gotoxy(5,12);
	cout<<"STATE:-";
	gotoxy(5,13);
	cout<<"ZIP CODE:-";
	gotoxy(5,14);
	cout<<"CONTACT NO:-";
	gotoxy(5,15);
	cout<<"STD CODE:-";
	gotoxy(5,16);
	cout<<"STUDENT STREAM:-";
	gotoxy(5,17);
	cout<<"STUDENT DEGREE:-";
	do
		{
			clear(24,8);
			clear(5,23);
			gotoxy(5,23);
			cout<<"ENTER THE NAME OF THE STUDENT";
			valid=1;
			gotoxy(24,8);
			gets(stu_name);
			strupr(stu_name);
			if(stu_name[0]=='0')
				return;
			if(strlen(stu_name)==0 || strlen(stu_name)>20)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("NAME SHOULD NOT BE GREATER THAN 20");
				getch();
			}
		}
		while(!valid);
		do
		{
			clear(24,9);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER FATHER'S NAME";
			valid=1;
			gotoxy(24,9);
			gets(stu_fname);
			strupr(stu_fname);
			if(stu_fname[0]=='0')
				return;
			if(strlen(stu_fname)=='0' || strlen(stu_fname)>20)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("NAME SHOULD NOT BE GREATER THAN 20");
				getch();
			}
		}while(!valid);
		do
		{
			clear(19,10);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER THE ADDRESS";
			valid=1;
			gotoxy(19,10);
			gets(stu_add);
			strupr(stu_add);
			if(stu_add[0]=='0')
				return;
			if(strlen(stu_add)==0 || strlen(stu_add)>20)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("ADDRESS SHOULD NOT BE  GREATER THAN 20");
				getch();
			}
		}while(!valid);
		do
		{
			clear(16,11);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER  CITY NAME";
			valid=1;
			gotoxy(16,11);
			gets(stu_city);
			strupr(stu_city);
			if(stu_city[0]=='0')
				return;
			if(strlen(stu_city)==0 || strlen(stu_city)>20)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("CITY NAME SHOULD NOT BE GREATER THAN 20");
				getch();
			}
		}while(!valid);
		do
		{
			clear(17,12);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER  STATE";
			valid=1;
			gotoxy(17,12);
			gets(stu_state);
			strupr(stu_state);
			if(stu_state[0]=='0')
				return;
			if(strlen(stu_state)==0 || strlen(stu_state)>20)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("STATE NAME SHOULD NOT BE GREATER THAN 20");
				getch();
			}
		}while(!valid);
		do
		{
			clear(20,13);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER THE ZIP CODE";
			valid=1;
			gotoxy(20,13);
			gets(stu_zip);
			if(stu_name[0]=='0')
				return;
			if(strlen(stu_zip)==0 || strlen(stu_zip)>8)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("NAME SHOULD NOT BE GREATER THAN 8");
				getch();
			}
		}while(!valid);
		do
		{
			clear(22,14);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER THE CONTACT NO.";
			valid=1;
			gotoxy(22,14);
			gets(stu_cont);
			if(stu_cont[0]=='0')
				return;
			if(strlen(stu_cont)==0 || strlen(stu_cont)>10)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("CONTACT NO. SHOULD NOT BE GREATER THAN 10");
				getch();
			}
		}while(!valid);
		do
		{
			clear(20,15);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER THE STD CODE";
			valid=1;
			gotoxy(20,15);
			gets(stu_code);
			if(stu_code[0]=='0')
				return;
			if(strlen(stu_code)==0 || strlen(stu_code)>10)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("CODE SHOULD NOT BE GREATER THAN 10");
				getch();
			}
		}while(!valid);
		do
		{
			clear(26,16);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER THE STREAM CODE";
			valid=1;
			gotoxy(26,16);
			gets(stu_strm);
			strupr(stu_strm);
			if(stu_strm[0]=='0')
				return;
			if(strlen(stu_strm)==0 || strlen(stu_strm)>20)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("STREAM SHOULD NOT BE GREATER THAN 20");
				getch();
			}
		}while(!valid);
		do
		{
			clear(26,17);
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"ENTER THE DEGREE CODE(B.A/B.SC/B.COM-I/II/III Or MA/M.SC/M.COM-I/II)";
			valid=1;
			gotoxy(26,17);
			gets(stu_deg);
			strupr(stu_deg);
			if(stu_deg[0]=='0')
				return;
			if(strlen(stu_deg)==0 || strlen(stu_deg)>20)
			{
				valid=0;
				gotoxy(5,23);
				cprintf("DEGREE SHOULD NOT BE GREATER THAN 20");
				getch();
			}
		}while(!valid);
		stu.clear(5,23);
		do
		{
			valid=1;
			for(int i=5;i<79;i++)
			{
				gotoxy(i,23);
				printf(" ");
			}
			gotoxy(5,23);
			cout<<"DO YOU WANT TO SAVE THE RECORD (Y/N):-";
			ch=getche();
			if(ch==0)
				return;
			ch=toupper(ch);
		}while(ch!='N'&&ch!='Y');
		if(ch=='N')
			return;
		//append the recore to student .dat.
		add_to_file(stu_id,stu_name,stu_fname,stu_add,stu_city,stu_state,stu_zip,stu_cont,stu_code,stu_strm,stu_deg);


}
/*This is a function which displays the details of all the Students under the university
with all the detail such as student id, student name, student address, student stream,student degree
etc.Thus the user can look and know the detail of student*/
void student::display_list(void)
{
	clrscr();
	int flag;
	fstream file;
	gotoxy(25,1);
	cout<<"STUDENT DISPLAY LIST";
	gotoxy(25,2);
	cout<<"=====================";
	gotoxy(1,3);
	for(int j=1;j<=79;j++)
		cout<<"=";
	gotoxy(1,5);
	cout<<"STUID";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(26,5);
	cout<<"FATHER NAME";
	gotoxy(43,5);
	cout<<"ADDRESS";
	gotoxy(62,5);
	cout<<"STREAM";
	gotoxy(72,5);
	cout<<"DEG";
	gotoxy(1,6);
	for(j=1;j<=79;j++)
		cout<<"=";
	file.open("STUDENT.dat0",ios::in);
	file.seekg(0,ios::beg);
	int row=7;
	//reads all the record to display on the screen
	while(file.read((char*)this,sizeof(student)))
	{
		flag=0;
		delay(2);
		gotoxy(1,row);
		cout<<stu_id;
		gotoxy(10,row);
		puts(stu_name);
		gotoxy(26,row);
		puts(stu_fname);
		gotoxy(43,row);
		puts(stu_add);
		gotoxy(63,row);
		puts(stu_strm);
		gotoxy(73,row);
		puts(stu_deg);
		row++;
		if(row>23)
		{
			flag=1;
			row=6;
			gotoxy(4,24);
			cout<<"PRESS ANY KEY TO CONTINUE";
			getch();
			clrscr();
		}
	}
	gotoxy(1,row);
	for(j=1;j<=79;j++)
		cout<<"=";
	row++;
	file.close();
	if(!flag)
	{
		gotoxy(4,24);
		cout<<"PRESS ANY KEY TO CONTINUE.....";
		getch();
	}
}
/*This function is used to enquire about the Student.This function ask for the student id
to enquire about and after matching the id it displays the record of the enquired student */
void student::enquiry_student(void)
{
	clrscr();
	int t_stuid=0;
	student stu;
	gotoxy(71,1);
	cout<<"<0>=EXIT";
	gotoxy(5,5);
	cout<<"ENTER STUDENT ID:";
	cin>>t_stuid;
	if(t_stuid==0)
		return;
	clrscr();
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5,5);
		cout<<"\7 INVALLID STUDENT ID";
		getch();
		return;
	}
	//Displays the haeading from this function.
	box_for_enquirystudent(t_stuid);
	int row=9,flag;
	fstream file;
	file.open("STUDENT.dat",ios::in);
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			delay(2);
			gotoxy(4,row);
			puts(stu_state);
			gotoxy(14,row);
			puts(stu_zip);
			gotoxy(25,row);
			puts(stu_code);
			gotoxy(38,row);
			puts(stu_contact);
			gotoxy(57,row);
			puts(stu_strm);
			gotoxy(70,row);
			puts(stu_deg);
			row++;
			if(row>23)
			{
				flag=1;
				row=7;
				gotoxy(4,24);
				cout<<"PRESS ANY KEY TO CONTINUE:";
				getch();
				box_for_enquirystudent(t_stuid);
			}
		}
	}
	file.close();
	if(!flag)
	{
		gotoxy(4,24);
		cout<<"PRESS ANY KEY TO CONTINUE:";
		getch();
	}
}
/* This function is used to modify the student detail.This function asks for the
student id for which the information is to be modified.Then it asks "Do you want to
Modify (Y/N)".If 'Y' is entred it asks for the user to enter new information.
*/
void student::student_modification(void)
{
	clrscr();
	int j;
	int t,t_stuid;
	gotoxy(17,1);
	cout<<"<0>=EXIT";
	gotoxy(5,5);
	cout<<"ENTER THE STUDENT ID:-";
	cin>>t_stuid;
	if(t_stuid==0)
		return;
	clrscr();
	if(!found_student(t_stuid))
	{
		gotoxy(5,5);
		cout<<"\7 STUDENT NOT FOUND";
		getch();
		return;
	}
	gotoxy(71,1);
	cout<<"<0>=EXIT";
	textbackground(WHITE);
	gotoxy(3,3);
	for(j=1;j<=76;j++)
		cprintf(" ");
	textbackground(BLACK);
	textcolor(BLACK+WHITE);
	textbackground(WHITE);
	gotoxy(30,3);
	cprintf("MODIFY STUDENT DETAIL SCREEN:");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(4,2);
	cout<<"DATE:"<<d1<<"/"<<m1<<"/"<<y1;
	char ch;
	display(t_stuid);
	student stu;
	do
	{
		stu.clear(5,13);
		gotoxy(5,13);

		cout<<"MODIFY THESE COLLEGE DETAILS<Y/N>";
		ch=getche();
		if(ch=='0')
			return;
		ch=toupper(ch);
	}
	while(ch!='N' && ch!='Y');
	if(ch=='N')
		return;
	int modified=0,valid;
	char t_name[30],t_fname[30],t_add[30],t_stream[30],t_city[30],t_state[30],t_zip[30],t_code[10],t_contact[30],t_deg[30];
	
		gets(t_state);
		strupr(t_state);
		if(t_state[0]=='0')
			return;
		if(strlen(t_state)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 STATE SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}
	while(!valid);
	do
	{	stu.clear(23,19);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER CONTACT OR PRESS ENTER FOR NO CHANGE";
		valid=1;
		gotoxy(23,19);
		gets(t_contact);
		strupr(t_contact);
		if(t_contact[0]=='0')
			return;
		if(strlen(t_contact)>10)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 CONTACT SHOULD NOT BE GREATER THAN 10");
			getch();
		}
	}
	while(!valid);
	do
	{
		stu.clear(18,20);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(5,23);
		cout<<"ENTER STREEM OR PRESS ENTER FOR NO CHANGE(ARTS/SCIENCE/COMMERCE)";
		valid=1;
		gotoxy(18,20);
		gets(t_stream);
		strupr(t_stream);
		if(t_stream[0]=='0')
			return;
		if(strlen(t_stream)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 STREEM SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}
	while(!valid);
	do
	{
		stu.clear(18,21);
		for(int i=5;i<79;i++)
		{
			gotoxy(i,23);
			printf(" ");
		}
		gotoxy(1,23);
		cout<<"ENTER DEGREE OR PRESS ENTER FOR NO CHANGE(B.A/B.SC/B.COM-I/II/III OR M.A/M.SC-I/II)";
		valid=1;
		gotoxy(18,21);
		gets(t_deg);
		strupr(t_deg);
		if(t_deg[0]=='0')
			return;
		if(strlen(t_deg)>20)
		{
			valid=0;
			gotoxy(5,23);
			cprintf("\7 DEGREE SHOULD NOT BE GREATER THAN 20");
			getch();
		}
	}while(!valid);
	if(strlen(t_deg)>0)
		modified=1;
	if(!modified)
		return;
	for(int i=1;i<81;i++)
	{
		gotoxy(i,23);
		printf(" ");

	}

	for(i=1;i<80;i++)
	{
		gotoxy(i,24);
		printf(" ");
	}
	//clears the screen at 23rd row & from 5th coloum
	stu.clear(5,23);
	do
	{
		gotoxy(5,23);
		cout<<"DO YOU WANT TO SAVE CHANGES (Y/N):-";
		ch=getche();
		if(ch=='0')
			return;
		ch=toupper(ch);
	}while(ch!='N' && ch!='Y');
	if(ch=='N')
		return;
	//passes the parameter to add in data file
	modify_student(t_stuid,t_name,t_fname,t_add,t_state,t_contact,t_stream,t_deg);
	for(i=5;i<79;i++)
	{
		gotoxy(i,23);
		printf(" ");
	}
	gotoxy(5,23);
	cout<<"\7 RECORD MODIFIED";
	gotoxy(5,24);
	cout<<"PRESS ANY KEY TO CONTINUE";
	getch();

}
/*supporting function function for student*/
/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void student::clear(int col,int row)
{
	for(int j=col;j<=79;j++)
	{
		gotoxy(j,row);
		cout<<"";
	}
}
/* Function to find a student for display college function. This is used to find any account in the
"student.dat"data files,where the file is searched from the first record position and it searches
whether the entred id exit or not. If it exit then the variable found will return a value 1 or
0 as the  parameter*/
int student::found_student(int t_stuid)
{
	fstream file;
	file.open("student.dat",ios::in);
	file.seekg(0,ios::beg);
	int found=0;
	//searches the specified record in student.dat data file
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			found=1;
			break;
		}
	}
	file.close();
	return found;
}
/*Function for return name of the student from student.dat.This function is basically used
to return only name student if the student is in the "student.dat"data file.When the name is
returned it may simply display/modify other functions*/
char *student::return_name(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_name[30];
	//returns the name to display at screen if found.
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_name,stu_name);
			break;
		}
	}
	file.close();
	return t_name;
}
/*Function for return name of the student's father from student.dat.This function is basically used
to return only name student's father if the student is in the "student.dat"data file.When the name is
returned it may simply display/modify other functions*/
char *student::return_fname(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_fname[30];
	//returns the father name to display at screen if found.
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_fname,stu_fname);
			break;
		}
	}
	file.close();
	return t_fname;
}

/*Function to return the address of the student from student.dat .This funcion is basicially
used to return only address of the student if address is in the "student.dat" data files.When
the address  is returned it may simply display/modify other functions */
char *student::return_address(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_address [30];
	//return the address to display at screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_address,stu_add);
			break;
		}
	}
	file.close();
	return t_address;
}
/*Function to return the city of the student from student.dat .This funcion is basicially
used to return only city of the student if city is in the "student.dat" data files.When
the city  is returned it may simply display/modify other functions */
char *student::return_city(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_city [30];
	//return the city to display at screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_city,stu_city);
			break;
		}
	}
	file.close();
	return t_city;
}
/*Function to return the state of the student from student.dat .This funcion is basicially
used to return only state of the student if state is in the "student.dat" data files.When
the state  is returned it may simply display/modify other functions */
char *student::return_state(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_state [30];
	//return the state to display at screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_state,stu_state);
			break;
		}
	}
	file.close();
	return t_state;
}
/*Function to return the zip of  the student from student.dat .This funcion is basicially
used to return only zip of the student if zip is in the "student.dat" data files.When
the zip  is returned it may simply display/modify other functions */
char *student::return_zip(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_zip[30];
	//return the zip to display at  screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_zip,stu_zip);
			break;
		}
	}
	file.close();
	return t_zip;
}

/*Function to return the contact of the student from student.dat .This funcion is basicially
used to return only contact of the student if contact is in the "student.dat" data files.When
the contact  is returned it may simply display/modify other functions */
char *student::return_contact(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_contact [30];
	//return the contact to display at screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_contact,stu_contact);
			break;
		}
	}
	file.close();
	return t_contact;
}
/*Function to return the code of the student from student.dat .This funcion is basicially
used to return only code of the student if code is in the "student.dat" data files.When
the code  is returned it may simply display/modify other functions */
char *student::return_code(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_code [30];
	//return the code to display at screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_code,stu_code);
			break;
		}
	}
	file.close();
	return t_code;
}
/*Function to return the stream of the student from student.dat .This funcion is basicially
used to return only stream of the student if stream is in the "student.dat" data files.When
the stream is returned it ma
y simply display/modify other functions */
char *student::return_stream(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_stream [30];
	//return the stream to display at report screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_stream,stu_strm);
			break;
		}
	}
	file.close();
	return t_stream;
}
/*Function to return the degree of the student from student.dat .This funcion is basicially
used to return only degree of the student if degree is in the "student.dat" data files.When
the degree is returned it may simply display/modify other functions */

char *student::return_degree(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	char t_deg[30];
	//return the stream to display at report screen if found
	while(file.read((char*)this,sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_deg,stu_deg);
			break;
		}
	}
	file.close();
	return t_deg;
}

/*Function to display student detail. This function displays the student name,
student id,father name,address,contact no.,zip, city, state.*/
void student::box_for_display(int t_stuid)
{
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(63,2);
	cout<<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(4,2);
	
/*supporting function for student enquiry*/
void student::box_for_enquirystudent(int t_stuid)
{
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(63,2);
	cout<<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(4,2);
	cout<<"STUDENT ID:"<<t_stuid;
	student stu;
	char t_name[30];
	strcpy(t_name,stu.return_name(t_stuid));
	char t_add[30];
	strcpy(t_add,stu.return_address(t_stuid));
	char t_fname[30];
	strcpy(t_fname,stu.return_fname(t_stuid));
	gotoxy(25,2);
	cout<<t_name;
	gotoxy(25,3);
	cout<<t_fname;
	gotoxy(25,3);
	cout<<t_add;
	gotoxy(4,5);
	cout<<"ENQUIRY REPORT OF STUDENT";
	textbackground(WHITE);
	textcolor(BLACK);
	textbackground(WHITE);
	gotoxy(1,6);
	for(int i=1;i<=79;i++)
		cout<<"=";
	gotoxy(4,7);
	cprintf("STATE      ZIP       CODE        CONTACT           STREAM         DEGREE");
	gotoxy(1,8);
	for(i=1;i<=79;i++)
		cout<<"=";
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
}
/*Function for returning the record for updating college information.*/
int student::recordno(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	//find the records position in COLLEGE.dat data file
	while(file.read((char*)this,sizeof(student)))
	{
		count++;
		if(t_stuid==stu_id)
			break;
	}
	file.close();
	return count;
}
/*This is a important function.This function asks for the student id for the
form entry and after entering the student id it matches the id in "STUDENT.dat"
if id is found it extract information related to that id and displays in the
screen and the writes it in to "FORM.dat" data file*/
void examinfo::exam_formentry()
{
	clrscr();
	int t,valid,i,t_stuid;
	student stu;
	examinfo einfo;
	shape s;
	s.box(2,1,79,25,218);
	s.box(25,2,54,4,219);
	gotoxy(5,5);
	cout<<"ENTER THE STUDENT ID:-";
	cin>>t_stuid;
	if(t_stuid==0)
		return;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5,5);
		cout<<"\7 STUDENT NOT FOUND";
		getch();
		return;
	}
	gotoxy(65,2);
	cout<<"<0>=EXIT";
	gotoxy(3,3);
	for(i=1;i<=76;i++)
	cprintf(" ");
	textbackground(BLACK);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	gotoxy(30,3);
	cout<<"EXAM ENTRY FORM";
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	int examform_id;
	char ch;
	examform_id=einfo.last_examformid();
	examform_id++;
	gotoxy(5,6);
	cout<<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(5,8);
	cout<<"EXAM FORM ID:-"<<examform_id;
	gotoxy(5,9);
	cout<<"NAME:-";
	gotoxy(5,10);
	cout<<"FATHER NAME:-";
	gotoxy(5,11);
	cout<<"ADDRESS:-";
	gotoxy(5,12);
	cout<<"STREAM:-";
	gotoxy(5,13);
	cout<<"DEGREE:-";
	stu.examdisplay(t_stuid,examform_id);
}
/* supporting function for add to file for student*/
void examinfo::add_to_file_form(int t_stuid,int t_examformid,char t_name[30],char t_fname[30],char t_add[30],char t_strm[30],char t_deg[30])
{
	fstream file;
	stu_id=t_stuid;
	examform_id=t_examformid;
	strcpy(stu_name,t_name);
	strcpy(stu_fname,t_fname);
	strcpy(stu_add,t_add);
	strcpy(stu_strm,t_strm);
	strcpy(stu_deg,t_deg);
	//append newm record into STUDENT.dat data file.
	file.open("FORM.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(examinfo));
	file.close();
}
/*supporting function for creating last student id*/
int examinfo:: last_examformid(void)
{
	fstream file;
	file.open("FORM.dat",ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	//find the last id number
	while(file.read((char *)this,sizeof(examinfo)))
		count=examform_id;
	file.close();
	return count;
}
/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void examinfo::clear(int col,int row)
{
	for(int j=col;j<=79;j++)
	{
		gotoxy(j,row);
		cout<<"";
	}
}
/*This is a special function related to form it reads the student incormation
from "STUDENT.dat" and put is on the screen of Exam form entry screen after
matching the id of the student*/
void student::examdisplay(int t_stuid,int t_examformid)
{

	fstream file;
	examinfo einfo;
	char tstu_name[30],tstu_fname[30],tstu_add[30],tstu_strm[30],tstu_deg[30];
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	//displays the record content  matching with t_stuid from STUDENT.dat data files.
	while(file.read((char *)this,sizeof(student)))
	{
		if(t_stuid==stu_id)
		{

			gotoxy(16,9);
			puts(stu_name);
			strcpy(tstu_name,stu_name);
			gotoxy(24,10);
			puts(stu_fname);
			strcpy(tstu_fname,stu_fname);
			gotoxy(19,11);
			puts(stu_add);
			strcpy(tstu_add,stu_add);
			gotoxy(18,12);
			puts(stu_strm);
			strcpy(tstu_strm,stu_strm);
			gotoxy(18,13);
			puts(stu_deg);
			strcpy(tstu_deg,stu_deg);


		}
	}
	file.close();
	char ch;
	do
	{
		einfo.clear(5,23);
		gotoxy(5,23);
		cout<<"DO YOU WANT TO SAVE THE RECORD (Y/N):-";
		ch=getche();
		if(ch==0)
			return;
		ch=toupper(ch);
	}while(ch!='N' && ch!='Y');
	if(ch=='N')
		return;
	else
	{
	       einfo.add_to_file_form(t_stuid,t_examformid,tstu_name,tstu_fname,tstu_add,tstu_strm,tstu_deg);

	}
}
/*This is a special function because this function displays all the forms that
are being entred and finally displays on the screen*/
/* supporting function for add to file for student*/
void examinfo::add_to_file_schedule(char t_deg[30],char t_sd1[30],char t_ed1[30],char t_sm1[30],char t_em1[30],char t_sy1[30],char t_ey1[30])
{
	fstream file;
	strcpy(sd1,t_sd1);
	strcpy(ed1,t_ed1);
	strcpy(sm1,t_sm1);
	strcpy(em1,t_em1);
	strcpy(sy1,t_sy1);
	strcpy(ey1,t_ey1);
	strcpy(deg,t_deg);
	//append newm record into STUDENT.dat data file.
	file.open("SCHEDULE.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(examinfo));
	file.close();
}
/*This is a important function the use to display the schedule of the exam
that are going to be conducted in the colleges*/
/*This is a special function.This funcion is used to enter the marks of the
student.This function first asks for the student id and then it flashes the
student name, address, stream, degree the it asks to enter the marks after comparing
the degree*/
void examinfo::result_entry(void)
{
	char ch;
	int i,valid,t_stuid,thp1,thp2,thp3,thp4,thp5,thp6,ts1,ts2,tcom,tgk,tp1,tp2,tp3,tp4,tp5,tp6;
	clrscr();
	char tstu_name[30],tstu_fname[30],tstu_add[30],tstu_strm[30],tstu_deg[30];
	shape s;
	student stu;
	s.box(2,1,79,25,218);
	s.box(25,2,54,4,219);
	gotoxy(65,2);
	cout<<"<0>=EXIT";
	gotoxy(5,3);
	cout<<"ENTER THE STUDENT ID:-";
	cin>>t_stuid;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5,4);
		cout<<"\7 STUDENT NOT FOUND";
		getch();
		return;
	}
	gotoxy(65,2);
	cout<<"<0>=EXIT";
	gotoxy(3,3);
	for(i=1;i<=79;i++)
	cprintf("");
	textbackground(BLACK);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	gotoxy(30,3);
	cprintf("RESULT ENTRY");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(5,6);
	cout<<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(5,8);
	cout<<"NAME:-";
	gotoxy(5,10);
	cout<<"DEGREE:-";
	gotoxy(5,12);
	cout<<"STREAM:-";
	stu.resultdisplay(t_stuid);
}
void student::resultdisplay(int t_stuid)
{

	fstream file;
	examinfo einfo;
	char tstu_name[30],tstu_fname[30],tstu_add[30],tstu_strm[30],tstu_deg[30];
	int thp1,thp2,thp3,thp4,thp5,thp6,thp7,thp8,ts1,ts2,tcom,tgk;
	int tp1,tp2,tp3,tp4,tp5,tp6,tp7,tp8,tp9,tp10,tp11,tp12,tp13,tp14,tp15,tp16;
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	//displays the record content  matching with t_stuid from STUDENT.dat data files.
	while(file.read((char *)this,sizeof(student)))
	{
		if(t_stuid==stu_id)
		{
			gotoxy(16,8);
			puts(stu_name);
			strcpy(tstu_name,stu_name);
			gotoxy(18,10);
			puts(stu_strm);
			strcpy(tstu_strm,stu_strm);
			gotoxy(18,12);
			puts(stu_deg);
			strcpy(tstu_deg,stu_deg);

		}
	}
	file.close();
	file.open("STUDENT.dat",ios::in);
	file.seekg(0,ios::beg);
	while(file.read((char*)this,sizeof(student)))
	{
		strcpy(tstu_deg,stu_deg);
		if(stu_id==t_stuid)
		{
		if((strcmp(stu_deg,"B.A-I")==0)||(strcmp(stu_deg,"B.SC-I")==0)||(strcmp(stu_deg,"B.COM-I")==0))
		{
			gotoxy(5,14);
			cout<<"HONOURS PAPER :";
			cin>>thp1;
			gotoxy(5,16);
			cout<<"HONOURS :";
			cin>>thp2;
			gotoxy(5,18);
			cout<<"SUBSIDIARY I:";
			cin>>ts1;
			gotoxy(5,19);
			cout<<"SUBSSIDIARY II:";
			cin>>ts2;
			gotoxy(5,20);
			cout<<"COMPULSORY";
			cin>>tcom;
		}
		else if((strcmp(stu_deg,"B.A-II")==0)||(strcmp(stu_deg,"B.SC-II")==0)||(strcmp(stu_deg,"B.COM-II")==0))
		{
			gotoxy(5,14);
			cout<<"HONOURS PAPER :";
			cin>>thp3;
			gotoxy(5,16);
			cout<<"HONOURS :";
			cin>>thp4;
			gotoxy(5,18);
			cout<<"SUBSIDIARY I:";
			cin>>ts1;
			gotoxy(5,19);
			cout<<"SUBSSIDIARY II:";
			cin>>ts2;
			gotoxy(5,20);
			cout<<"COMPULSORY";
			cin>>tcom;
		}
		else if((strcmp(stu_deg,"B.A-III")==0)||(strcmp(stu_deg,"B.SC-III")==0)||(strcmp(stu_deg,"B.COM-III")==0))
		{
			gotoxy(5,14);
			cout<<"HONOURS PAPER :";
			cin>>thp5;
			gotoxy(5,16);
			cout<<"HONOURS PAPER:";
			cin>>thp6;
			gotoxy(5,18);
			cout<<"HONUURS PAPER";
			cin>>thp7;
			gotoxy(5,19);
			cout<<"HONOURS PAPER IV:";
			cin>>thp8;
			gotoxy(5,20);
			cout<<"GENERAL KNOWLEDGE";
			cin>>tgk;
		}
		else if((strcmp(stu_deg,"M.A-I")==0)||(strcmp(stu_deg,"M.SC-I")==0)||(strcmp(stu_deg,"M.COM-I")==0))
		{
			gotoxy(5,14);
			cout<<"PAPER I:-";
			cin>>tp1;
			gotoxy(5,15);
			cout<<"PAPER II:-";
			cin>>tp2;
			gotoxy(5,16);
			cout<<"PAPER III:-";
			cin>>tp3;
			gotoxy(5,17);
			cout<<"PAPER IV:-";
			cin>>tp4;
			gotoxy(5,18);
			cout<<"PAPER V:-";
			cin>>tp5;
			gotoxy(5,19);
			cout<<"PAPER VI:-";
			cin>>tp6;
			gotoxy(5,20);
			cout<<"PAPER VII:-";
			cin>>tp7;
			gotoxy(5,21);
			cout<<"PAPER VIII:-";
			cin>>tp8;
		}
		else if((strcmp(stu_deg,"M.A-II")==0)||(strcmp(stu_deg,"M.SC-II")==0)||(strcmp(stu_deg,"M.COM-II")==0))
		{
			gotoxy(5,14);
			cout<<"PAPER IX:-";
			cin>>tp9;
			gotoxy(5,15);
			cout<<"PAPER X:-";
			cin>>tp10;
			gotoxy(5,16);
			cout<<"PAPER XI:-";
			cin>>tp11;
			gotoxy(5,17);
			cout<<"PAPER XII:-";
			cin>>tp12;
			gotoxy(5,18);
			cout<<"PAPER XIII:-";
			cin>>tp13;
			gotoxy(5,19);
			cout<<"PAPER XIV:-";
			cin>>tp14;
			gotoxy(5,20);
			cout<<"PAPER XV:-";
			cin>>tp15;
			gotoxy(5,21);
			cout<<"PAPER XVI:-";
			cin>>tp16;
		}
	    }
	}
	char ch;
	do
	{
		clear(5,23);
		gotoxy(5,23);
		cout<<"DO YOU WANT TO SAVE THE RECORD (Y/N):-";
		ch=getche();
		if(ch==0)
			return;
		ch=toupper(ch);
	}while(ch!='N' && ch!='Y');
	if(ch=='N')
		return;
	if(ch=='Y')
	{
		if((strcmp(tstu_deg,"B.A-I")==0)||(strcmp(tstu_deg,"B.SC-I")==0)||(strcmp(tstu_deg,"B.COM-I")==0))
		{
			einfo.add_to_filebaI(t_stuid,tstu_name,tstu_deg,thp1,thp2,ts1,ts2,tcom);
		}
		else if((strcmp(tstu_deg,"B.A-II")==0)||(strcmp(tstu_deg,"B.SC-II")==0)||(strcmp(tstu_deg,"B.COM-II")==0))
		{
			einfo.add_to_filebaII(t_stuid,tstu_name,tstu_deg,thp3,thp4,ts1,ts2,tcom);
		}
		else if((strcmp(tstu_deg,"B.A-III")==0)||(strcmp(tstu_deg,"B.SC-III")==0)||(strcmp(tstu_deg,"B.COM-III")==0))
		{
			einfo.add_to_filebaIII(t_stuid,tstu_name,tstu_deg,thp5,thp6,thp7,thp8,tgk);
		}
		else if((strcmp(tstu_deg,"M.A-I")==0)||(strcmp(tstu_deg,"M.SC-I")==0)||(strcmp(tstu_deg,"M.COM-I")==0))
		{
			einfo.add_to_filemaI(t_stuid,tstu_name,tstu_deg,tp1,tp2,tp3,tp4,tp5,tp6,tp7,tp8);
		}
		else if((strcmp(tstu_deg,"M.A-II")==0)||(strcmp(tstu_deg,"M.SC-II")==0)||(strcmp(tstu_deg,"M.COM-II")==0))
		{
			einfo.add_to_filemaII(t_stuid,tstu_name,tstu_deg,tp9,tp10,tp11,tp12,tp13,tp14,tp15,tp16);
		}
	}
}
//supporting function of result
void examinfo::add_to_filebaI(int t_stuid,char t_name[30],char t_deg[30],int t_hp1,int t_hp2,int t_s1,int t_s2,int t_com)
{
	fstream file;
	stu_id=t_stuid;
	hp1=t_hp1;
	hp2=t_hp2;
	s1=t_s1;
	s2=t_s2;
	com=t_com;
	strcpy(stu_name,t_name);
	strcpy(stu_deg,t_deg);
	//append newm record into STUDENT.dat data file.
	file.open("RESULTF.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(examinfo));
	file.close();
}
//suporting function of result
void examinfo::add_to_filebaII(int t_stuid,char t_name[30],char t_deg[30],int t_hp3,int t_hp4,int t_s1,int t_s2,int t_com)
{
	fstream file;
	stu_id=t_stuid;
	hp3=t_hp3;
	hp4=t_hp4;
	s1=t_s1;
	s2=t_s2;
	com=t_com;
	strcpy(stu_name,t_name);
	strcpy(stu_deg,t_deg);
	//append newm record into STUDENT.dat data file.
	file.open("RESULTS.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(examinfo));
	file.close();
}
//suporting function function of result
void examinfo::add_to_filebaIII(int t_stuid,char t_name[30],char t_deg[30],int t_hp5,int t_hp6,int t_hp7,int t_hp8,int t_gk)
{
	fstream file;
	stu_id=t_stuid;
	hp5=t_hp5;
	hp6=t_hp6;
	hp7=t_hp7;
	hp8=t_hp8;
	gk=t_gk;
	strcpy(stu_name,t_name);
	strcpy(stu_deg,t_deg);
	//append newm record into STUDENT.dat data file.
	file.open("RESULTT.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(examinfo));
	file.close();
}
//suporting fuinction of result
void examinfo::add_to_filemaI(int t_stuid,char t_name[30],char t_deg[30],int t_p1,int t_p2,int t_p3,int t_p4,int t_p5,int t_p6,int t_p7,int t_p8)
{
	fstream file;
	stu_id=t_stuid;
	p1=t_p1;
	p2=t_p2;
	p3=t_p3;
	p4=t_p4;
	p5=t_p5;
	p6=t_p6;
	p7=t_p7;
	p8=t_p8;
	strcpy(stu_name,t_name);
	strcpy(stu_deg,t_deg);
	//append newm record into STUDENT.dat data file.
	file.open("RESULTMF.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(examinfo));
	file.close();
}
//suporting function of result
void examinfo::add_to_filemaII(int t_stuid,char t_name[30],char t_deg[30],int t_p9,int t_p10,int t_p11,int t_p12,int t_p13,int t_p14,int t_p15,int t_p16)
{
	fstream file;
	stu_id=t_stuid;
	p9=t_p9;
	p10=t_p10;
	p11=t_p11;
	p12=t_p12;
	p13=t_p13;
	p14=t_p14;
	p15=t_p15;
	p16=t_p16;
	strcpy(stu_name,t_name);
	strcpy(stu_deg,t_deg);
	//append newm record into STUDENT.dat data file.
	file.open("RESULTMS.dat",ios::out|ios::app);
	file.write((char *)this,sizeof(examinfo));
	file.close();
}
/*This is a important function it displays the result of the student according
to their degree for different different  result data fiels*/
void examinfo::resultdisplay_list(void)
{
	clrscr();
	fstream file;
	student stu;
	gotoxy(25,1);
	cout<<"EXAM RESULT DISPLAY LIST";
	gotoxy(25,2);
	cout<<"=============================";
	int t_stuid;
	gotoxy(5,3);
	cout<<"enter student id";
	cin>>t_stuid;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5,4);
		cout<<"\7 invalid";
		getch();
		return;
	}
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(62,3);
	cout<<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1;
	char t_studeg[30];
	strcpy(t_studeg,stu.return_degree(t_stuid));
	if((strcmp(t_studeg,"B.A-I")==0) || (strcmp(t_studeg,"B.SC-I")==0) || (strcmp(t_studeg,"B.COM-I")==0))
	{
			gotoxy(1,4);
			for(int j=1;j<=79;j++)
				cout<<"=";
			gotoxy(1,5);
			cout<<"ID";
			gotoxy(3,5);
			cout<<"NAME";
			gotoxy(34,5);
			cout<<"DEGREE";
			gotoxy(48,5);
			cout<<"HONOURS";
			gotoxy(40,6);
			cout<<"PAPER I";
			gotoxy(50,6);
			cout<<"PAPER II";
			gotoxy(65,5);
			cout<<"SUBCIDIARY";
			gotoxy(60,6);
			cout<<"PAPER I";
			gotoxy(68,6);
			cout<<"PAPER II";
			gotoxy(76,5);
			cout<<"COMPULSORY";
			gotoxy(1,7);
			for(j=1;j<=79;j++)
				cout<<"=";
	file.open("RESULTF.dat",ios::in);
	file.seekg(0,ios::beg);
	int row=8;
	while(file.read((char*)this,sizeof(examinfo)))
	{

			gotoxy(1,row);
			cout<<stu_id;
			gotoxy(3,row);
			puts(stu_name);
			gotoxy(34,row);
			puts(stu_deg);
			gotoxy(40,row);
			cout<<hp1;
			gotoxy(50,row);
			cout<<hp2;
			gotoxy(60,row);
			cout<<s1;
			gotoxy(70,row);
			cout<<s2;
			gotoxy(72,row);
			cout<<com;
			row++;
			if(row>23)
			{
				row=7;
				gotoxy(4,24);
				cout<<"PRESS ANY KEY TO CONTINUE...";
				getch();
				clrscr();
			}
			gotoxy(1,row);
			for(int j=1;j<=79;j++)
				cout<<"=";

		}
		file.close();
	 }
	if((strcmp(t_studeg,"B.A-II")==0)||(strcmp(t_studeg,"B.SC-II")==0)||(strcmp(t_studeg,"B.COM-II")==0))
	{
		gotoxy(1,4);
		for(int j=1;j<=79;j++)
			cout<<"=";
		gotoxy(1,5);
		cout<<"ID";
		gotoxy(3,5);
		cout<<"NAME";
		gotoxy(34,5);
		cout<<"DEGREE";
		gotoxy(48,5);
		cout<<"HONOURS";
		gotoxy(40,6);
		cout<<"PAPER III";
		gotoxy(50,6);
		cout<<"PAPER IV";
		gotoxy(65,5);
		cout<<"SUBCIDIARY";
		gotoxy(60,6);
		cout<<"PAPER I";
		gotoxy(68,6);
		cout<<"PAPER II";
		gotoxy(76,5);
		cout<<"COMPULSORY";
		gotoxy(1,7);
		for(j=1;j<=79;j++)
			cout<<"=";
		file.open("RESULTS.dat",ios::in);
		file.seekg(0,ios::beg);
		int row=8;
	while(file.read((char*)this,sizeof(examinfo)))
	{
		gotoxy(1,row);
		cout<<t_stuid;
		gotoxy(3,row);
		puts(stu_name);
		gotoxy(34,row);
		puts(stu_deg);
		gotoxy(40,row);
		cout<<hp3;
		gotoxy(50,row);
		cout<<hp4;
		gotoxy(60,row);
		cout<<s1;
		gotoxy(70,row);
		cout<<s2;
		gotoxy(72,row);
		cout<<com;
		row++;
		if(row>23)
		{
			row=7;
			gotoxy(4,24);
			cout<<"PRESS ANY KEY TO CONTINUE...";
			getch();
			clrscr();
		}
		gotoxy(1,row);
		for(int j=1;j<=79;j++)
			cout<<"=";
	   }
		file.close();
	}
	if((strcmp(t_studeg,"B.A-III")==0)||(strcmp(t_studeg,"B.SC-III")==0)||(strcmp(t_studeg,"B.COM-III")==0))
	{
		gotoxy(1,4);
		for(int j=1;j<=79;j++)
			cout<<"=";
		gotoxy(1,5);
		cout<<"ID";
		gotoxy(3,5);
		cout<<"NAME";
		gotoxy(34,5);
		cout<<"DEGREE";
		gotoxy(53,5);
		cout<<"HONOURS";
		gotoxy(40,6);
		cout<<"PAPER V";
		gotoxy(50,6);
		cout<<"PAPER VI";
		gotoxy(60,6);
		cout<<"PAPER VII";
		gotoxy(70,6);
		cout<<"PAPER VIII";
		gotoxy(78,5);
		cout<<"G.K";
		gotoxy(1,7);
		for(j=1;j<=79;j++)
			cout<<"=";
		file.open("RESULTT.dat",ios::in);
		file.seekg(0,ios::beg);
		int row=8;
		while(file.read((char*)this,sizeof(examinfo)))
		{
			gotoxy(1,row);
			cout<<t_stuid;
			gotoxy(3,row);
			puts(stu_name);
			gotoxy(34,row);
			puts(stu_deg);
			gotoxy(40,row);
			cout<<hp5;
			gotoxy(50,row);
			cout<<hp6;
			gotoxy(60,row);
			cout<<hp7;
			gotoxy(70,row);
			cout<<hp8;
			gotoxy(72,row);
			cout<<gk;
			row++;
			if(row>23)
			{
				row=7;
				gotoxy(4,24);
				cout<<"PRESS ANY KEY TO CONTINUE...";
				getch();
				clrscr();
			}
			gotoxy(1,row);
			for(int j=1;j<=79;j++)
				cout<<"=";
		}
		file.close();
	}
	if((strcmp(t_studeg,"M.A-I")==0)||(strcmp(t_studeg,"M.SC-I")==0)||(strcmp(t_studeg,"M.COM-I")==0))
	{
		gotoxy(1,4);
		for(int j=1;j<=79;j++)
			cout<<"=";
		gotoxy(1,5);
		cout<<"ID";
		gotoxy(3,5);
		cout<<"NAME";
		gotoxy(34,5);
		cout<<"DEGREE";
		gotoxy(53,5);
		cout<<"MASTER DEGREE";
		gotoxy(40,6);
		cout<<"I";
		gotoxy(44,6);
		cout<<"II";
		gotoxy(48,6);
		cout<<"III";
		gotoxy(52,6);
		cout<<"IV";
		gotoxy(56,6);
		cout<<"V";
		gotoxy(60,6);
		cout<<"VI";
		gotoxy(64,6);
		cout<<"VII";
		gotoxy(68,6);
		cout<<"VIII";
		gotoxy(1,7);
		for(j=1;j<=79;j++)
			cout<<"=";
		file.open("RESULTMF.dat",ios::in);
		file.seekg(0,ios::beg);
		int row=8;
		while(file.read((char*)this,sizeof(examinfo)))
		{
			gotoxy(1,row);
			cout<<t_stuid;
			gotoxy(3,row);
			puts(stu_name);
			gotoxy(34,row);
			puts(stu_deg);
			gotoxy(40,row);
			cout<<p1;
			gotoxy(44,row);
			cout<<p2;
			gotoxy(48,row);
			cout<<p3;
			gotoxy(52,row);
			cout<<p4;
			gotoxy(56,row);
			cout<<p5;
			gotoxy(60,row);
			cout<<p6;
			gotoxy(64,row);
			cout<<p7;
			gotoxy(68,row);
			cout<<p8;
			row++;
			if(row>23)
			{

				row=7;
				gotoxy(4,24);
				cout<<"PRESS ANY KEY TO CONTINUE...";
				getch();
				clrscr();
			}
			gotoxy(1,row);
			for(int j=1;j<=79;j++)
				cout<<"=";
		}
	file.close();
	}
	if((strcmp(t_studeg,"M.A-II")==0)||(strcmp(t_studeg,"M.SC-II")==0)||(strcmp(t_studeg,"M.COM-II")==0))
	{
		gotoxy(1,4);
		for(int j=1;j<=79;j++)
			cout<<"=";
		gotoxy(1,5);
		cout<<"ID";
		gotoxy(3,5);
		cout<<"NAME";
		gotoxy(34,5);
		cout<<"DEGREE";
		gotoxy(53,5);
		cout<<"MASTER DEGREE";
		gotoxy(40,6);
		cout<<"IX";
		gotoxy(44,6);
		cout<<"X";
		gotoxy(48,6);
		cout<<"XI";
		gotoxy(52,6);
		cout<<"XII";
		gotoxy(56,6);
		cout<<"XIII";
		gotoxy(60,6);
		cout<<"XIV";
		gotoxy(64,6);
		cout<<"XV";
		gotoxy(68,6);
		cout<<"XVI";
		gotoxy(1,7);
		for(j=1;j<=79;j++)
			cout<<"=";
		file.open("RESULTMS.dat",ios::in);
		file.seekg(0,ios::beg);
		int row=8;
		while(file.read((char*)this,sizeof(examinfo)))
		{
			gotoxy(1,row);
			cout<<t_stuid;
			gotoxy(3,row);
			puts(stu_name);
			gotoxy(34,row);
			puts(stu_deg);
			gotoxy(40,row);
			cout<<p9;
			gotoxy(44,row);
			cout<<p10;
			gotoxy(48,row);
			cout<<p11;
			gotoxy(52,row);
			cout<<p12;
			gotoxy(56,row);
			cout<<p13;
			gotoxy(60,row);
			cout<<p14;
			gotoxy(64,row);
			cout<<p15;
			gotoxy(68,row);
			cout<<p16;
			row++;
			if(row>23)
			{
				row=7;
				gotoxy(4,24);
				cout<<"PRESS ANY KEY TO CONTINUE...";
				getch();
				clrscr();
			}
			gotoxy(1,row);
			for(j=1;j<=79;j++)
				cout<<"=";
		}
		file.close();
	}
	 getch();
}

void performance::foundation(void)
{

	gotoxy(65,2);
	cout<<"<0>=EXIT";
	gotoxy(3,3);
	for(int i=1;i<=76;i++)
		cprintf("");
	textbackground(BLACK);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	_setcursortype(_NOCURSOR);//changes cursor type
	gotoxy(30,3);
	cprintf("FOUNDATION");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	int d1,m1,y1;
	struct date d;//for extracting system date
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	gotoxy(5,4);
	cout<<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(5,5);
	textcolor(GREEN+BLINK);
	cout<<"\t \t \t \t OUR MISSION";
	gotoxy(5,6);
	textcolor(GREEN+BLINK);
	cout<<"	Global Leadership In Human Development Excellence In Education";
	gotoxy(5,7);
	textcolor(GREEN+BLINK);
	cout<<"& Healthcare Universities since its inception, five decades ago,";
	gotoxy(5,8);
	textcolor(GREEN+BLINK);
	cout<<"has viewed Community and Social development as its core focus.";
	gotoxy(5,9);
	textcolor(GREEN+BLINK);
	cout<<"The Foundation was primarily set up to sanctify this mission";
	gotoxy(5,10);
	textcolor(GREEN+BLINK);
	cout<<"and to re-affirm its commitment to social development in";
	gotoxy(5,11);
	textcolor(GREEN+BLINK);
	cout<<"the fields of Education, Healthcare, Science, Culture,";
	gotoxy(5,12);
	textcolor(GREEN+BLINK);
	gotoxy(5,13);
	textcolor(GREEN+BLINK);
	 cout<<"Heritage and Sports.";
	cout<<"The Foundation is also an effort to reach out to";
	gotoxy(5,14);
	textcolor(GREEN+BLINK);
	cout<<"like-minded individuals and organizations, to join ";
	gotoxy(5,15);
	textcolor(GREEN+BLINK);
	cout<<"	them in their endeavour to provide the much-needed impetus ";
	gotoxy(5,16);
	textcolor(GREEN+BLINK);
	cout<<"to a few globally relevant development issues.";
	gotoxy(5,17);
	textcolor(GREEN+BLINK);
	cout<<"The Foundation Is registered as a charitable ";
	gotoxy(5,18);
	textcolor(GREEN+BLINK);
	cout<<"trust and the Commissioner of Income Tax has ";
	gotoxy(5,19);
	textcolor(GREEN+BLINK);
	cout<<"granted recognition to It.Donations made to the";
	gotoxy(5,20);
	textcolor(GREEN+BLINK);
	cout<<"foundation are exempt under section BOG of the Income Tax Act, 1961.";
	gotoxy(5,21);
	textcolor(GREEN+BLINK);
	cout<<" Global Leadership in Human Development. Excellence ";
	gotoxy(5,22);
	textcolor(GREEN+BLINK);
	cout<<"in Healthcare and Education";
}

void main(void)
{

	main_menu ob_menu;
	int gdriver = DETECT,gmode,errorcode;
	char pass[10],ch;
	int i=0;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	ob_menu.first_screen();
	ab: gotoxy(4,20);
	  setcolor(7);
	  cout<<"ENTER THE PASSWORD :-";
	  do
	   {
		   ch=getch();
		   gotoxy(25+i,20);
		   cout<<"";
		   pass[i]=ch;
		   i++;
		   if(i>8)
		   {
			    i=0;
			    gotoxy(6,24);
			    cout<<"PASSWORD NOT GREATER THAN 8 CHARACTER LONG";
			    getch();
			    clrscr();
			    goto ab;
		     }
	    }while(ch!='\r');
	i--;
	pass[i]='\0';
       closegraph();
    /*compare the password*/
   if(strcmp(strupr(pass),"HELLO")==0)
    {
	clrscr();
	int driver,mode,errorcode;
	driver=DETECT;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	ob_menu.help();
	closegraph();
	ob_menu.control_menu();
	getch();
    }
    else
    {
      clrscr();
      int driver,mode,errorcode;
      driver=DETECT;
      initgraph(&driver,&mode,"c:\\tc\\bgi");
      gotoxy(10, 15);
      setcolor(7);
      cout<<"WRONG PASSWORD!";
    }
     getch();
     closegraph();

}







