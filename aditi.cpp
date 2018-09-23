/*Aditi Singhal
11-A
Roll No. -2
Topic - HOSPITAL MANAGEMENT*/
//*************************Including Header Files***********************//
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
//************************Structures(Patient)*******************************//
struct patient
{
int patient_no;
char name[30];
char disease[30];
char doctor[30];
char sex;
int bed_no;
};

//************************Structures(Doctor)*******************************//
struct doctor
{
float charges;
char doctor_name[30];
char department[5];
char days[3][10];
char time[10];
char specialist[20];
};

//**********************Including Functions******************************//

//*************Function to store new deatils of the patient**********//
void create_patient()
{
patient data;
fstream fl;
fl.open("patient.dat",ios::out|ios::binary|ios::app);
cout<<"Patient Name  :  ";
gets(data.name);
cout<<"Patient Number  :  ";
cin>>data.patient_no;
cout<<"Sex (M/F)  :  ";
cin>>data.sex;
cout<<"Disease the patient was suffering from  :  " ;
gets(data.disease);
cout<<"Patient's  Treating Doctor  :  ";
gets(data.doctor);
cout<<"Patient's Bed Number  :  ";
cin>>data.bed_no;
fl.write((char*)&data,sizeof(data));
fl.close();
}


//*************Function to store new deatils of the doctors**********//
void create_doctor()
{
doctor data;
fstream fl;
fl.open("doctor.dat",ios::app|ios::binary|ios::out);
cout<<"Name of the Doctor  :  ";
gets(data.doctor_name);
cout<<"Department of the Doctor  :  ";
gets(data.department);
cout<<"Specialisation of the Doctor  :  ";
gets(data.specialist);
cout<<"Days of OPD  :  " <<endl;
for(int i=0;i<3;i++)
gets(data.days[i]);
cout<<"Timings of the Doctor  :  ";
gets(data.time);
cout<<"Charges of the Doctor  :  ";
cin>>data.charges;
fl.write((char*)&data,sizeof(data));
fl.close();
}


//*********Function to search and display a record of the patient**********//

void display_patient()
{
int p;
int flag=0;
patient data;
fstream fl;
cout<<"Enter the Patient Number to be searched?? ";
cin>>p;
clrscr();
fl.open("patient.dat",ios::in|ios::binary);
while(fl.read((char*)&data,sizeof(data)))
{
if(p==data.patient_no)
{
flag=1;
cout<<"Patient Name  :   ";
puts(data.name);
cout<<"Patient Number  :   "<<data.patient_no<<endl;
cout<<"Sex (M/F)  :   "<<data.sex<<endl;
cout<<"Disease the patient was suffering from  :   ";
puts(data.disease);
cout<<"Patient's  Treating Doctor  :  ";
puts(data.doctor);
cout<<"Patient's Bed Number  :  "<<data.bed_no<<endl;
}
}
if(flag==0)
cout<<"Record  not found !! ";
fl.close();
}

//*********Function to search and display a record of the doctor**********//

void display_doctor()
{
char p[30];
int flag=0;
doctor data;
fstream fl;
cout<<"Enter the Doctor Name to be searched ?? ";
gets(p);
fl.open("doctor.dat",ios::in|ios::binary);
while(fl.read((char*)&data,sizeof(data)));
{
if(strcmp(p,data.doctor_name)==0)
{
flag=1;
cout<<"Name of the Doctor  :   ";
puts(data.doctor_name);
cout<<"Department of the Doctor  :   ";
puts(data.department);
cout<<"Specialisation of the Doctor  :  ";
puts(data.specialist);
cout<<"Days of OPD  :  ";
for(int i=0;i<3;i++)
{
 puts(data.days[i]);
}
cout<<"Timings of the Doctor  :   ";
puts(data.time);
cout<<"Charges of the Doctor  :  ";
cout<<data.charges;
}
}
if(flag==0)
cout<<"Record  not found !! ";
fl.close();
}


//*********************Function to modify record for patient ***************//

void modify_patient()
{
patient data,d;
fstream fl;
fl.open("patient.dat",ios::in|ios::out|ios::binary);
long int y,pos=-1;
cout<<"Enter the Patient Number whose data is to be modified ?? "<<endl;
cin>>y;
while(fl.read((char*)&data,sizeof(data)))
{
if(y==data.patient_no)
{
cout<<"*******************Initial Data Record********************** "<<endl;
cout<<endl;
cout<<"Patient Name  :  ";
puts(data.name);
cout<<"Patient Number  :  "<<data.patient_no<<endl;
cout<<"Sex (M/F)  :  "<<data.sex<<endl;
cout<<"Disease the patient was suffering from  :  ";
puts(data.disease);
cout<<"Patient's  Treating Doctor  :  ";
puts(data.doctor);
cout<<"Patient's Bed Number  :  "<<data.bed_no<<endl;
pos=fl.tellg()-sizeof(data);
break;
}
}
if(pos>-1)
{
cout<<"Enter new Record ?? "<<endl;
cout<<"Patient Name  :  ";
gets(d.name);
cout<<"Patient Number :  ";
cin>>d.patient_no;
cout<<"Sex (M/F)  :  ";
cin>>d.sex;
cout<<"Disease the patient was suffering from  :  ";
gets(d.disease);
cout<<"Patient's  Treating Doctor  :  ";
gets(d.doctor);
cout<<"Patient's Bed Number  :  ";
cin>>d.bed_no;
fl.seekp(pos,ios::beg);
fl.write((char*)&d,sizeof(d));
cout<<"Record modified successfully !!  "<<endl;
}
else
cout<<"Record does not exists!! "<<endl;
}

//*********************Function to modify record for doctor ***************//

void modify_doctor()
 {
doctor data;
fstream fl;
fl.open("doctor.dat",ios::in|ios::out|ios::binary);
long int pos=-1;
char y[30];
cout<<"Enter the Doctor's Name whose data is to be modified  ?? ";
gets(y);
clrscr();
while(fl.read((char*)&data,sizeof(data)))
 {
  if(strcmp(y,data.doctor_name)==0)
  {
cout<<"*******************Initial Data Record********************** "<<endl;
cout<<endl;
  cout<<"Name of the Doctor  :   ";
puts(data.doctor_name);
cout<<"Department of the Doctor  :   ";
puts(data.department);
cout<<"Specialisation of the Doctor  :  ";
puts(data.specialist);
cout<<"Days of OPD  :  ";
for(int i=0;i<3;i++)
{
 puts(data.days[i]);
}
cout<<"Timings of the Doctor  :   ";
puts(data.time);
cout<<"Charges of the Doctor  :  ";
cout<<data.charges;
	pos=fl.tellg()-sizeof(data);
	break;
  }
 }
if(pos>-1)
{
cout<<endl;
cout<<"Enter new Record ??  "<<endl;
cout<<"Name of the Doctor  :  ";
gets(data.doctor_name);
cout<<"Department of the Doctor :  ";
gets(data.department);
cout<<"Specialisation of the Doctor  :  ";
gets(data.specialist);
cout<<"Days of OPD  :  ";
for(int i=0;i<3;i++)
 {
  gets(data.days[i]);
 }
cout<<"Timings of the Doctor  :  ";
gets(data.time);
cout<<"Charges of the Doctor  :  ";
cin>>data.charges;
fl.seekp(pos,ios::beg);
fl.write((char*)&data,sizeof(data));
cout<<"Record modified successfully !!  "<<endl;
}
else
cout<<"Record does not exists !!  "<<endl;
}

//************Function to delete record of the patient********************//

void delete_patient()
{
int r,found=0;
fstream fl,newfl;
fl.open("patient.dat",ios::in|ios::binary);
newfl.open("newpatient.dat",ios::out|ios::binary);
patient data;
cout<<"Enter the Patient Number to be deleted ?? ";
cin>>r;
while(fl.read((char*)&data,sizeof(data)))
 {
  if(r!=data.patient_no)
	{
	 newfl.write((char*)&data,sizeof(data));
	}
  else
	 found=1;
 }
fl.close();
newfl.close();
remove("patient.dat");
remove("newpatient.dat"),("patient.dat");
if(found==1)
cout<<"Record Deleted  !!";
else
cout<<"Record not found  !!";
}

//*************Function to delete the record of a doctor***********//

void delete_doctor()
{
int found=0;
char r[30];
fstream fl,newfl;
fl.open("doctor.dat",ios::in|ios::binary);
newfl.open("newdoctor.dat",ios::out|ios::binary);
doctor data;
cout<<"Enter the Doctor Name to be deleted ?? ";
gets(r);
clrscr();
while(fl.read((char*)&data,sizeof(data)))
{
if(strcmp(r,data.doctor_name)==0)
{
found=1;
}
else
newfl.write((char*)&data,sizeof(data));
}
fl.close();
newfl.close();
remove("doctor.dat");
remove("newdoctor.dat"),("doctor.dat");
if(found==1)
cout<<"Record  not found !!";
else
cout<<"Record Deleted !!";
}

//**************Function to display all the records of pateints***************//

void displayallpatient()
{
patient data;
fstream fl;
fl.open("patient.dat",ios::in|ios::binary);
while(fl.read((char*)&data,sizeof(data)))
{
cout<<endl;
cout<<"Patient Name  :  ";
puts(data.name);
cout<<"Patient Number  :  "<<data.patient_no<<endl;
cout<<"Sex (M/F)  :  "<<data.sex<<endl;
cout<<"Disease the patient was suffering from  :  ";
puts(data.disease);
cout<<"Patient's  Treating Doctor  :  ";
puts(data.doctor);
cout<<"Patient's Bed Number  :  "<<data.bed_no<<endl;
cout<<endl;
}
}

//**************Function to display all the records of doctors***************//
void displayalldoctor()
{
doctor data;
fstream fl;
fl.open("doctor.dat",ios::in|ios::binary);
while(fl.read((char*)&data,sizeof(data)))
{
cout<<"Name of the Doctor :   ";
puts(data.doctor_name);
cout<<"Department of the Doctor :   ";
puts(data.department);
cout<<"Specialisation of the Doctor : ";
puts(data.specialist);
cout<<"Days of OPD:  ";
for(int i=0;i<3;i++)
 {
  puts(data.days[i]);
  }
cout<<"Timings of the Doctor :   ";
puts(data.time);
cout<<"Charges of the Doctor  :  ";
cout<<data.charges;
cout<<endl;
cout<<endl;
}
}

//************Function for Calculation of Bill of the Patient**************//

void bill()
 {
 char x[30];
 float mcharges, tmt,amt;
 int days, y,rate;
 int found=0;
 doctor data1;
 patient data;
 fstream fl,fk;
 cout<<"************************Bill Calculation**************************";
 cout<<endl;
 cout<<"Enter the Patient Number ?? "<<endl;
 cin>>y;
 fl.open("patient.dat", ios::in|ios::binary);
 fk.open("doctor.dat", ios::in|ios::binary);
 while(fl.read((char*)&data,sizeof(data)))
  {
	 if(y==data.patient_no)
	  {
		 found=1;
		 strcpy(x,data.doctor);
		 break;
	  }
  }
if(found==0)
cout<<"Record not found !!"<<endl;
 while(fk.read((char*)&data1,sizeof(data1)))
 {
  if(strcmp(x,data1.doctor_name)==0)
	{
	 rate=data1.charges;
	}
 }
cout<<"Enter the number of days the patient was admitted ?? ";
cin>>days;
cout<<"Enter the total medicine charges ?? ";
cin>>mcharges;
cout<<"The charges of the Doctor = ";
cout<<rate;
cout<<endl;
cout<<endl;
amt=(mcharges+(days*700)+rate);
tmt= (amt+(amt*0.2));
cout<<"Total Bill = Rs. "<<tmt<<endl;
}

//*********************Main Function*****************************//

void main()
{
clrscr();
int choice,m;
 do{
 cout<<endl;
 cout<<endl;
 cout<<"**********************************************************************";
	cout<<"**************************************HOSPITAL MENU***************************************"<<endl;
	cout<<endl;
  cout<<"                        Enter 1 FOR MENU OF PATIENT"<<endl;
  cout<<"                        Enter 2 FOR MENU OF DOCTOR"<<endl;
  cin>>m;
  clrscr();
  if(m==1)
  {
	cout<<"**********************MENU FOR PATIENT'S DETAILS AND INPUT*********************"<<endl;
	cout<<endl;
	cout<<"1. Input the details of the patient"<<endl;
	cout<<"2. Display all the records"<<endl;
	cout<<"3. Search and display and record"<<endl;
	cout<<"4. Modify a record"<<endl;
	cout<<"5. Delete a record"<<endl;
	cout<<"6. Calculation of Bill"<<endl;
	cin>>choice;
	clrscr();
	switch(choice)
	  {
		case 1: cout<<"                ****************Input Details************"<<endl;
				  create_patient();
				  cout<<endl;
				  cout<<"Record created Successfully !!"<<endl;
		break;
		case 2:  cout<<"             ***********************Displaying All Records*********************"<<endl;
					cout<<endl;
					cout<<endl;
				  displayallpatient();
		break;
		case 3: cout<<"             ***********************Displaying Record*********************"<<endl;
					cout<<endl;
					cout<<endl;
				  display_patient();
		break;
		case 4: modify_patient();
		break;
		case 5: delete_patient();
		break;
		case 6: bill();
		break;
	  }
	}
else if(m==2)
{
cout<<"********************MENU FOR DOCTOR'S DETAILS AND INPUT******************** "<<endl;
cout<<"1. Input the details of the doctors"<<endl;
cout<<"2. Display all the records"<<endl;
cout<<"3. Search and display and record"<<endl;
cout<<"4. Modify a record"<<endl;
cout<<"5. Delete a record"<<endl;
cin>>choice;
clrscr();
switch(choice)
{
case 1:cout<<"                ****************Input Details************"<<endl;
		 create_doctor();
		 cout<<endl;
break;
case 2:  cout<<"             ***********************Displaying All Records*********************"<<endl;
					cout<<endl;
					cout<<endl;
		  displayalldoctor();
break;
case 3: cout<<"             ***********************Displaying Record*********************"<<endl;
					cout<<endl;
					cout<<endl;
		  display_doctor();
break;
case 4: modify_doctor();
break;
case 5: delete_doctor();
break;
}
}
}while(choice!='7');

getch();
}

