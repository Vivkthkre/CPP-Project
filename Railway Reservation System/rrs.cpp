#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include<dos.h>
#include<string.h>
class train

{
 private:
 char name[40];
 int card;
 int age;
 int tno;
 int ph;
 int conf;
 int type;
 float rate;
    char tname[100];
    char ei[15];
    char bp[100];
    char dest[100];
    int c1;
    public:
    void trave()
    {
    strcpy(tname,"NULL");
    strcpy(bp,"NULL");
    strcpy(dest,"NULL");
    card=0;
    age=0;
    tno=0;
    ph=0;
    rate=0;
    c1=0;
    type=0;

   }
    void getdetail()
    {
	cout<<"\n";
	cout<<"    Enter the details as follows\n";
	cout<<"\n";
	cout<<setw(35)<<"  enter your name  ";
	gets(name);
	cout<<"\n";
	cout<<setw(35)<<"  enter your age   ";
	cin>>age;
	cout<<"\n";
	cout<<setw(35)<<"  Train name:      ";
	gets(tname);
	cout<<"\n";
	cout<<setw(35)<<" Boarding point:   ";
	gets(bp);
	cout<<"\n";
	cout<<setw(35)<<" Destination pt:   ";
	gets(dest);
	cout<<"\n";
	cout<<setw(35)<<"  No of seats       ";
	cin>>c1;
	cout<<"\n";
	cout<<setw(35)<<"enter your phone no. ";
	cin>>ph;
	cout<<"\n";
	cout<<setw(35)<<" enter the type from  below given details::";
	cout<<"\n";
	cout<<" 1. A/C         500        \n";
	cout<<"\n";
	cout<<" 2. SLEEPER     250        \n";
	cout<<"\n";
	cout<<" 3. chair       100        \n";
	cout<<"\n";
	cout<<" enter your choice no.";
	cin>>type;
	if(type==1)
	cout<<"A/C";
	cout<<"\n";
	if(type==2)
	cout<<"SLEPPER";
	cout<<"\n";
	if (type==3)

	cout<<"CHAIR ";
	cout<<"\n";
	cout<<type;
		cout<<"\n";

	cout<<" enter the rate ";
	if(type==1)
	rate=500;
	cout<<"$$ 500  $$";
	cout<<"\n";
	if(type==2)
	rate=250;
	cout<<"$$  250 $$";
	cout<<"\n";
	if(type==3)
	rate=100;
	cout<<" $$ 100 $$";
	cout<<"\n";
	   float b;
       b=(rate*c1);
	clrscr();
	cout<<"..,,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,..,..,.,..,.,..,..,.,.";
	cout<<"\n";
	cout<<"\n";
	cout<<" YOUR BILL ..... "<<b;
	cout<<"\n";
	cout<<" enter 1 for confirmation ";
	cout<<"\n";
	cin>>conf;
	if(conf==1)
	{
	cout<<"\n";
	cout<<" Enter the details for payment";
	cout<<"\n";
	cout<<"\n";
	cout<<" Enter your credit card no.";
	cin>>card;
	cout<<"\n";
	cout<<" Enter your email id.";
	gets(ei);

	cout<<"............. THANK YOU..................";
	}
	else
	{
	cout<<"  FIRST CONFIRM FOR PAYMENT DETAILS ";
	cout<<"\n";
	cout<<" thank you ";
	exit(0);
	}
 }
    void displaydetail()
    { clrscr();
     float b;
   b=(rate*c1);
    cout<<"\n";
    cout<<" your ticket";
    cout<<"\n";
    cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][]";
    cout<<"\n";
    cout<<"[]   Name             "<<name<<"\n";
    cout<<"[]   Age              "<<age<<"\n";
    cout<<"[]   Train name       "<<tname<<"\n";
    cout<<"[]   Boarding point:  "<<bp<<"\n";
    cout<<"[]   Destination pt:  "<<dest<<"\n";
    cout<<"[]   No of seats      "<<c1<<"\n";
    cout<<"[]   type             "<<type<<"\n";
    cout<<"[]   your bill        "<<b <<"\n";

    cout<<"[][][][][]][][][][][][][][][][][][][][][][][][][][][]";
    cout<<"\n";
    cout<<"\n";
    cout<<".......................................................";



    }
    void train::modify()
    {

    cout<<"[]   Name             "<<name<<"\n";
    cout<<"[]   Age              "<<age<<"\n";
    cout<<"[]   Train name       "<<tname<<"\n";
    cout<<"[]   Boarding point:  "<<bp<<"\n";
    cout<<"[]   Destination pt:  "<<dest<<"\n";
    cout<<"[]   No of seats      "<<c1<<"\n";
    cout<<"[]   type             "<<type<<"\n";
    char nm[21]= " ";
    char tn[20]= " ";
    char b[20]= " " ;
    char d[20]= " ";
 int ag,seat,ty;
    cout<<"\n";
    cout<<"\n";
    cout<<"enter the new name";
    cout<<"\n";
    cout<<" OR (enter '.' to retain old one)";
    gets(nm);
    cout<<"\n";
    cout<<"\n";
    cout<<"enter the new age";cout<<"\n";
    cout<<" OR(enter  '1 ' to retain old one)";
    cin>>ag;
    cout<<"\n";
    cout<<"\n";
    cout<<"enter the new boarding point:"; cout<<"\n";
    cout<<"OR(enter '.' to retain od one)";
    gets(b);
    cout<<"\n";
    cout<<"\n";
    cout<<"enter the new train name :(enter '.' to retain od one)";
    gets(tn);
    cout<<"\n";
    cout<<"\n";
    cout<<"enter the new destination:(enter '.' to retain od one)";
    gets(d);
    cout<<"\n";
    cout<<"\n";
    cout<<"enter the new no. of seats(enter '1' to retain od one)";
    cin>>seat;
    cout<<"\n";
    cout<<"\n";
    cout<<"enter the new seat type:(enter '1' to retain od one)";
    cin>>ty;
    if(strcmp(nm,".")!=0)
    strcpy(name,nm);
    if(strcmp(b,".")!=0)
    strcpy(bp,b);
    if(strcmp(d,".")!=0)
    strcpy(dest,d);
    if(strcmp(tn,".")!=0)
    strcpy(tname,tn);
    if(ag!= 1)
    age=age;
    if(seat!= 1)
    c1=seat;
    if(ty!=1)
    type=ty;




   }

     int check()

    {
    return ph;
    }


};
void reserve();
void cancel();
void search();
void modification();

void main()
{
clrscr();
train u;
u.trave();
int ch;
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
cout<<"                   WELCOME TO RAILWAY RESERVATION SYSTEM                       ";
cout<<"\n";
cout<<"]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]";
cout<<"\n";
cout<<setw(50) <<"        EXPERIENCE OUR SERVICE.......    \n";
cout<<"\n";
cout<<"                   .....our facilties are:......                  \n";
cout<<"\n";
cout<<"  1.BOOK YOUR TICKET          \n";
cout<<"\n";
cout<<"  2.CANCELLATION              \n";
cout<<"\n";
cout<<"  3.RATES OF TICKETS          \n";
cout<<"\n";
cout<<"  4.TRAIN DETAILS             \n";
cout<<"\n";
cout<<"  5.UPDATE YOUR TICKET        \n";
cout<<"\n";
cout<<"  6.TICKET STATUS             \n";
cout<<"\n";
cout<<"  7. EXIT                     \n";
cout<<"\n";
cout<<" please enter the serial no. of your choice  \n";
cin>>ch;
switch(ch)
{
 case 1: clrscr();
 cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
 cout<<"\n";
 cout<<"                        WELCOME TO RESERVATION CORNER                           ";
 cout<<"\n";
 cout<<" \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ ";
 cout<<"\n";
 reserve();
 break;
 case 2:
 cout<<"\n";
 clrscr();
 cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
 cout<<"                  WELCOME TO CANCELLATION CORNER                   ";
 cout<<"\n";
 cout<<"\n";
 cancel();
 break;
 case 3:
 clrscr();
 cout<<"\n";
 cout<<"\n";
 cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
 cout<<"\n";
 cout<<"\n";
 cout<< setw(50)<<" RATES OF TICKETS $$$$ "<<"\n";
 cout<<"\n";
 cout<<"\n";
 cout<<setw(35)<<" 1. A\C FIRST CLASS      (500)  " << "\n";
 cout<<"\n";
 cout<<setw(35)<<" 2. A\C SECOND CLASS     (450)  "<<"\n";
 cout<<"\n";
 cout<<setw(35)<<" 3. FIRST CLASS SLEEPER  (300)  "<<"\n";
 cout<<"\n";
 cout<<setw(35)<<" 4. A/C CHAIR CAR        (200)  "<<"\n";
 cout<<"\n";
 cout<<setw(35)<<" 5. SECOND CLASS CHAIR   (100)  "<<"\n";
 cout<<"\n";
 break;
 case 4:
 clrscr();
 cout<<"\n";
 cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
 cout<<"\n";
 cout<<"\n";
 cout<<"                        WELCOME                            ";
 cout<<".............. ........TRAIN DETAILS.......................";   cout<<"\n";
 cout<<"\n";
 cout<<setw(50)<<" 1. RAJDHANI TRAINS                           ";
 cout<<"\n";
 cout<<setw(50)<<" 2. SHATABDI TRAINS                           ";
 cout<<"\n";
 cout<<setw(50)<<" 3. YUVA/ GARIBATH                            ";
 cout<<"\n";
 cout<<setw(50)<<" 4. DURONTO                                   ";
 cout<<"\n";
 cout<<" please write the appropriate serial no.               ";
   cin>>ch;
  {
   if ( ch== 1)

  {
   cout<<"                     RAJDHANI TRAINS                         ";
   cout<<"\n";
   cout<<" TRAIN no.                TRAIN NAME                    ORIGIN-DESTINATION                "<<"\n";
   cout<<" 12301                kolkata RAJDHANI       Howrah-New delhi                "<<"\n";
   cout<<"\n";
   cout<<" 12302               Sdah RAJDHANI           Sealdah-New delhi               "<<"\n";
   cout<<"\n";
   cout<<" 12303                Jammu RAJDHANI         New delhi-Jammu tawi            "<<"\n";
   cout<<"\n";
   cout<<" 12304                ChennaiRADJDHANI       Chennai central - Hnizamuddin   "<<"\n";
   cout<<"\n";
   cout<<" 12305                Bilasur RAJDHANI       bilaspur-New delhi              "<<"\n";
   cout<<"\n";
   cout<<" 12306                Mumbai RAJDHANI        Mumbai central -New delhi       "<<"\n";
   cout<<"\n";
   cout<<" 12307                Banglore RADJDHANI     Banglore -delhi         "<<"\n";
   cout<<"\n";
   cout<<" 12308                BBS                    Bhubaneswar-New delhi   "<<"\n";
   cout<<"\n";
   cout<<" 12309                DBRG RAJ EXP           Dibrugarh-new delhi     "<<"\n";
   cout<<"\n";
   cout<<" 12310                RNC NDLS RAJEXP        Ranchi-new delhi        "<<"\n";
   }
   if(ch== 2)
   {
   cout<<"              SHATABDI TRAINS                          "<<"\n";

   cout<<" TRAIN no.                TRAIN NAME                    ORIGIN-DESTINATION   ";
   cout<<"\n";
   cout<<" 12001                    NDLS SHTBDI                   BHOPAL-NEW DELHI     ";
   cout<<"\n";
   cout<<" 12002                    LKO SWRAN SHTBDI              LUCKNOW-NEW DELHI    ";
   cout<<"\n";
   cout<<" 12003		    KALKA SHTBDI                  NEW DELHI-KALKA      ";
   cout<<"\n";
   cout<<" 12004                    SHATABDI EXP                  CHENNAI-MYSORE       ";
   cout<<"\n";
   cout<<" 12005                    AMRITSAR SHTBDI               NEW DELHI- AMRITSAR  ";
   cout<<"\n";
   cout<<" 12006                    DEHRADUN SHTBDI               NEW DELHI-DEHRADUN   ";
   }
   if(ch==3)
   {
   cout<<"               YUVA TRAINS                                "<<"\n";
   cout<<"\n";
   cout<<" TRAIN no.                TRAIN NAME                    ORIGIN-DESTINATION   ";
   cout<<"\n";
   cout<<" 06511                    YPR EXP                       YESVANTIPUR-JAIPUR   ";
   cout<<"\n";
   cout<<" 06512                    NAGPUR GARIBRATH              PUNE-NAGPUR          ";
   cout<<"\n";
   cout<<" 06513                    MUMBAI GRARIBRATH             JABALPUR- MUMBAI     ";
   cout<<"\n";
   cout<<" 06514                    NDLS HWH YUVA                 HOWRAH-NEW DELHI     ";
   cout<<"\n";
   cout<<" 06515                    BSBANVT                       ANAND VIHAR-BHAGALPUR";
   cout<<"\n";
   cout<<" 06516                    PURI GARIBRATH                YESVANTIPUR-PURI     ";
   }
   if(ch== 4)
   {
   cout<<"                       DURONTO                                        ";
   cout<<"\n";
   cout<<" TRAIN no.                TRAIN NAME                    ORIGIN-DESTINATION   ";  cout<<"\n";
   cout<<" 12211                    HOWRAH DURONTO                PUNE-HOWRAH          ";  cout<<"\n";
   cout<<" 12212                    INDORE DURONTO                MUMBAI-INDORE        ";  cout<<"\n";
   cout<<" 12213                    JAIPUR DURONTO                MUMBAI-JAIPUR        ";  cout<<"\n";
   cout<<" 12214                    DEEJAT DURONTO                DELHI-JAMMU TWAI     ";  cout<<"\n";
   cout<<" 12215                    SHMPNBE DURONTO               SHALIMAR-PATNA       ";  cout<<"\n";
   cout<<" 12216                    DURONTO EXP                   YESVANTIPUR-DELHI SROHILA";   cout<<"\n";
  }



}
 break;
 case 5:
 clrscr();
 cout<<"\n";
 cout<<"\n";
 cout<<"                   WELCOME TO UPDATE CORNER                               ";
 cout<<"\n";
 cout<<"\n";
 cout<<"\n";
 cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
 cout<<"\n";
 cout<<"\n";
 cout<<" Here you can easily UPDATE your ticket ";
 cout<<"\n";
 modification();
 break;
 case 6:
 clrscr();
 cout<<"\n";
 cout<<"\n";
 cout<<"\n";
 cout<<setw(35)<<"  CHECK YOUR TICKET STATUS";
 search();
 break;
 }




 getch();
 }
 void reserve()
 {
 train per ;
 per.trave();

 fstream outfile;
 outfile.open("train.dat",ios::in|ios::out|ios::binary);
 per.getdetail();
 outfile.write((char*)&per, sizeof(per));
 outfile.seekg(0);
 per.displaydetail();
 getch();
}
void cancel()

{
  clrscr();
  int phno;
  char nm[17];
  int tn;
  train t;
  ifstream fio;
  fio.open("train.dat",ios::in|ios::binary);
  ofstream file;
  file.open("temp.dat",ios::out |ios::binary);
  cout<<"ENTER THE FOLLOWING DETAILS :";
  cout<<"\n";
  cout<<"\n";
  cout<<setw(35)<<" enter your name.";
  gets(nm);
  cout<<"\n";
  cout<<setw(35)<<" enter your ticket no.";
  cin>>tn;
  cout<<"\n";
  cout<<setw(35)<<"enter the phone  no. ";
  cin>>phno;
  cout<<"\n";
  while(!fio.eof())
  {
  fio.read((char*)&t,sizeof(t));
  if(t.check() ==phno)
   {
    t.displaydetail();
    cout<<" \n";
    cout<<setw(35)<<" ARE YOU SURE ,YOU WANT TO CANCEL YOUR TICKET ";
    cout<<"\n";
    int conf;
    cout<<" ENTER 1 TO CONFIRM.\n";
    cin>>conf;
    if(conf==1)
    cout<<" YOUR TICKET HAS BEEN CANCELLED\n";
    else
	   {
	   cout<<" TICKET IS NOT CANCELLED ";cout<<"\n";

    cout<<"HAPPY JOURNEY\n";
    break;
       }
    }

 else
 {
 cout<<"record not found!!!";
 }
 }


fio.close();

  getch();
 }
void search()
{

clrscr();

train p;
int phone,a,tno;
char nm[30];
ifstream fi;
fi.open("train.dat",ios::in|ios::binary);
cout<<"\n";
cout<<" ENTER THE DETAILS OF TICKET ";
cout<<"\n";
cout<<setw(35)<<" enter the ticket no,";
cin>>tno;
cout<<"\n";
cout<<setw(35)<<" enter your name";
cin>>nm;
cout<<"\n";
cout<<setw(35)<<" enter your age ";
cin>>a;
cout<<"\n";
cout<<setw(35)<<" enter the phone no.";
 cin>>phone;
 while(!fi.eof())
 {
 fi.read((char*)&p,sizeof(p));
 if(p.check()==phone)
 {
 p.displaydetail();
 cout<<"\n";
 cout<<" STATUS:";
 cout<<"     RESERED:  ";
 cout<<"\n";
 break;
 }
 else
 {
 cout<<"\n";
 cout<<"\n";

 cout<<"RECORD NOT FOUND!!";
 cout<<"\n";
 cout<<" ENTER RIGHT INFORMATION";
 }
 }

fi.close();
getch();
}
void modification()
{
clrscr();
train p;
fstream fio;
long pos;
fio.open("train.dat",ios::in|ios::binary);
int phone;
int mod;
cout<<"ENTER THE DETAILS :- ";
cout<<"\n";
cout<<setw(35)<<" enter your ticket no.";
cin>>mod;
cout<<setw(35)<<" enter the phone no.";
cin>>phone;
while(!fio.eof())
{
 fio.read((char*)&p,sizeof(p));
 if(p.check()==phone)
 {
p.modify();
fio.seekg(pos);
fio.write((char*)&p,sizeof(p));
break;
}

else
cout<<"record not found";


}

fio.seekg(0);
while(!fio.eof())
{
fio.read((char*)&p,sizeof(p));
p.displaydetail();
break;

}
fio.close();
getch();
}
