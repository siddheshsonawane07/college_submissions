#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class student 
{
    public:
    int admno;
    char name[20];
    char divv[20];
    char addr[20];
    
    void setdata()
    {
        cout<<"\nEnter name ";cin>>name;
        cout<<"\nEnter admno ";cin>>admno;
        cout<<"\nEnter div ";cin>>divv;
        cout<<"\nEnter addr ";cin>>addr;
    }
    void putdata()
    {
        cout<<"Details "<<endl;
        cout<<"Admno "<<admno<<endl;
        cout<<"Name "<<name<<endl;
        cout<<"Div "<<divv<<endl;
        cout<<"Address "<<addr<<endl;
    }
    int readmno()
    {
        return admno;
    }
};
void write_record()
{
    ofstream ofile;
    ofile.open("student.dat",ios::binary | ios::app);
    student obj;
    obj.setdata();
    ofile.write((char*)&obj,sizeof(obj));
    ofile.close();
}
void display()
{
    ifstream ifile;
    ifile.open("student.dat", ios::in);
    student obj;
    while(ifile.read((char*)&obj,sizeof(obj)))
    {
        obj.putdata();
    }
    ifile.close();
}
void search(int n)
{
    ifstream ifile;
    ifile.open("student.dat", ios::in);
    student obj;
    int flag=0;
    while(ifile.read((char*)&obj,sizeof(obj)))
    {
        if (obj.readmno()==n)
        {
            cout<<" Record found successfully"<<endl;
            obj.putdata();
            flag=1;
            break;
        }
    }
    if (flag==0)
    cout<<"Record not found";
    ifile.close();
}
void del(int n)
{
    ifstream ifile; ofstream ofile;
    ifile.open("student.dat", ios::in);
    ofile.open("temp.dat",ios::out);
    student obj;
    while(ifile.read((char*)&obj,sizeof(obj)))
    {
        if (obj.readmno()!=n)
        {
            ofile.write((char*)&obj,sizeof(obj));
        }
    }
    ifile.close();ofile.close();
    cout<<"\nRecord deleted successfully";
    remove("studen.dat");
    rename("temp.dat","student.dat");
}
int main()
{
    int ch,n;
    while(1)
    {
        cout<<"\n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit"<<endl;
        cout<<"\nEnter your choice ";cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nHow many records you want ";cin>>n;
            for (int i=0; i<n; i++)
            {
                write_record();
            }
            break;
            case 2:
            display();
            break;
            case 3:
            cout<<"Enter admno of the student ";cin>>n;
            search(n);
            break;
            case 4:
            cout<<"Enter admno to be deleted ";cin>>n;
            del(n);
            break;
            case 5:
            exit(0);
            
        }
    }
    return 0;
}