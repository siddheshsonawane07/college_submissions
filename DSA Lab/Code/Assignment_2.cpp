/*
Department maintains a student information. The file contains roll number,
name, division and address. Allow user to add, delete information of student.
Display information of particular employee. If record of student does not
exist an appropriate message is displayed. If it is, then the system displays
the student details.
Use sequential file to main the data.
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
    int retadmno()
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
        if(obj.retadmno()==n)
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
        if (obj.retadmno()!=n)
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
    int ch;
    do {
        cout<<"\n\n\n****File Operations*** "<<endl;
        cout<<"\n1.Write \n2.Display \n3.Search \n4.Delete "<<endl;
        cout<<"Enter your choice "; cin>>ch;
        switch(ch)
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
    }while(ch!=5);
    return 0;
}