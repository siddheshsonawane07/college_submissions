
// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

class student{
    int rollNo;
    char name[50],add[50],div[50];
    public:
    void getData()
    {
        cout<<"Enter your name : ";
        cin>>name;
        cout<<"Enter your Roll No. : ";
        cin>>rollNo;
        cout<<"Enter your Divsion : ";
        cin>>div;
        cout<<"Enter your Address : ";
        cin>>add;
    }

    void showData()
    {
        cout<<"\nName : "<<name<<endl;
        cout<<"Roll No. : "<<rollNo<<endl;
        cout<<"Division : "<<div<<endl;
        cout<<"Address : "<<add<<endl;
    }

    int getRoll()
    {
        return rollNo;
    }
};

void add()
{
    ofstream of;
    of.open("student.dat", ios::binary|ios::app);

    student obj;
    obj.getData();

    of.write((char*)&obj,sizeof(obj));

    of.close();
}

void display()
{
    ifstream is;
    is.open("student.dat", ios::binary);

    student obj;
    
    while(is.read((char*)&obj,sizeof(obj)))
    {
        obj.showData();
    }

    is.close();
}

void search(int n)
{
    ifstream is;
    is.open("student.dat", ios::binary);

    student obj;

    while(is.read((char*)&obj,sizeof(obj)))
    {
        if(obj.getRoll()==n)
        {
            obj.showData();
        }
    }

    is.close();
}

void del(int n)
{
    ofstream of;
    of.open("temp.dat", ios::out|ios::binary);

    ifstream is;
    is.open("student.dat", ios::binary);

    student obj;

    while(is.read((char*)&obj,sizeof(obj)))
    {
        if(obj.getRoll()!=n)
        {
            of.write((char*)&obj,sizeof(obj)); 
        }
    }

    of.close();
    is.close();

    remove("student.dat");
    rename("temp.dat","student.dat");
}

int main()
{
    int ch, d;
    cout << "----------File Handling----------\n";
    cout << "1)Add\n2)Display\n3)Search\n4)Delete\n5)Quit\n";
    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            add();
            break;

        case 2:
            cout << "List of records\n";
            display();
            break;

        case 3:
            cout << "Enter Student Roll No : ";
            int s;
            cin >> s;
            search(s);
            break;
        case 4:
            cout << "Enter no to be deleted : ";
            int d;
            cin >> d;
            del(d);
            cout << "\nRecord Deleted";
            break;
        case 5:
            cout << "End\n";
            return 0;
        }
    }
    while (ch != 5);
}
