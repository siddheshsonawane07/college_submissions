/*
Department maintains a student information. The file contains roll number,
name, division and address. Allow user to add, delete information of student.
Display information of particular employee. If record of student does not
exist an appropriate message is displayed. If it is, then the system displays
the student details.
Use sequential file to main the data.

sequential file: A sequential file contains records organized by the order in which they were entered. The order of the records is fixed. Records in sequential files can be read or written only sequentially. After you place a record into a sequential file, you cannot shorten, lengthen, or delete the record.

infile.open("myfile.txt", ios::in);  //for reading only 
outfile.open("myfile.txt", ios::out); //for writing only 
inoutfile.open("myfile",ios::in|ios::out); //for reading and writing
outfile.open("myfile.txt", ios::app); //for appending 
outfile.open("myfile.txt", ios::trunc); The truncate option says that “if the file already exists, then wipe it out and start with a new file.

fstream //This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.
cstdio // Stream properties. Streams have some properties that define which functions can be used on them and how these will treat the data input or output through them.

    &obj - this is the memory address of the object called obj.

    (char*) &obj - you are type casting &obj into a character pointer.

    sizeof(obj) - yields the size of the object that you are referring to.

    outfile.write - this is the function call evoked by the outfile object.

    Thus,

    outfile.write( (char*)&obj, sizeof(obj) ) will write the data from the file into an object named obj. 

*/

#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
class student 
{
    int admno;
    char name[50];
    char addr[50];
    char divv[50];
    public:
        void setdata()
        {
            cout<<"\nEnter roll number of the student ";
            cin>>admno;
            cout<<"\nEnter name of the student ";
            cin>>name;
            cout<<"\nEnter the division of the student ";
            cin>>divv;
            cout<<"\nEnter the address of the student ";
            cin>>addr;
        }
        void showdata ()
        {
            cout<< "\n*Student Roll No: "<<admno<<endl;
            cout<<"*Student Name: "<<name<<endl;
            cout<<"*Student Division: "<<divv<<endl;
            cout<<"*Student Address: "<<addr<<endl;
        }
        int admno()
        {
            return admno;
        }
    
};

void write_record()
{
    ofstream outfile;
    outfile.open("student.dat",ios::binary | ios::app);
    student obj;
    obj.setdata();
    outfile.write((char*)&obj, sizeof(obj));
    outfile.close();
}

void display()
{
    ifstream infile;
    infile.open("student.dat", ios::binary );
    student obj;
    while(infile.read((char*)&obj, sizeof(obj)))
    {
        obj.showdata();
    }
    infile.close();
}

void search(int n)
{
    ifstream infile;
    infile.open("student.dat", ios::binary);
    int flag=0;
    student obj;
    while(infile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.admno()==n)
        {
            obj.showdata();
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        cout<<"\nRecord not found "<<endl;
        
    }
    infile.close();
}

void delete_record(int n)
{
    student obj;
    ifstream infile;
    infile.open("student.dat", ios::binary);
    ofstream outfile;
    outfile.open("temp.dat",ios::out | ios::binary);
    while(infile.read((char*)&obj, sizeof(obj)))
    {   
        //copy the student.bat data to temp.data except the record which we want to delete
        //thus, temp.dat will contain the all the data except the record which is to be deleted
        //then, delete the student.dat file and then rename the temp.dat file to student.bat
        //bcz deletion is not directly possible in sequential file
        if (obj.admno()!=n)
        {
            outfile.write((char*)&obj, sizeof(obj));
        }
    }
    infile.close(); 
    outfile.close();
    
    remove("student.dat");
    rename("temp.dat","student.dat");
}

int main()
{
    int choice;
    do {
        cout<<"\n\n\n****File Operations*** "<<endl;
        cout<<"\n1.Write \n2.Display \n3.Search \n4.Delete "<<endl;
        cout<<"Enter your choice "; 
        cin>>choice;
        switch(choice)
        {
            case 1:
            int n;
            cout<<"\nEnter number of records ";cin>>n;
            for(int i=0; i<n; i++)
            {
                write_record();
            }
            break;
            
            case 2:
            cout<<"\nList of records "<<endl;
            display();
            break;
            
            case 3:
            int s;
            cout<<"\nEnter the student's roll number you want to search for :";cin>>s;
            search(s);
            break;
            
            case 4:
            cout<<"\nEnter the number to be deleted ";
            int d;
            cin>>d;
            delete_record(d);
            break;
            
            default:
            cout<<"Wrong choice ";
            break;
            
        }
    }while(choice!=5);
    return 0;
}