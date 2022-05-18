#include <iostream>
#include <string>

using namespace std;

class telephone
{
    public:

    long long int mobile[10];
    int key, address;
    string name[10];

    telephone()
    {
        int i;
        for(i=0;i<10;i++)
        {
            mobile[i]=-1;
            name[i]="AB";
        }
    }

    void insertrecord_linearly()
    {
        string n="y";
        do
        {
        cout<<"Enter the mobile no.";
        cin>>key;
        address=key%10;

        while(1)
            {
                if(mobile[address]==-1)
                {
                    mobile[address]=key;
                    cout<<"Enter name for this mobile no.";
                    cin>>name[address];
                    break;
                }
                else
                    {
                        address++;
                        if(address==10)
                        {
                            address=0;
                        }
                    }
            }

        int cnt=0;
        for(int k=0;k<10;k++)
            {
                if(mobile[k]!=-1)
                {
                     cnt++;
                }
            }
        if(cnt==10)
            {
                cout<<"Hash table is full. You cannot store more Records!!";
            }
        cout<<"If you want to enter next mobile no. then enter (y) else enter (n): ";
        cin>>n;

        }while(n=="y");
    }


    void insertrecord_Quadratically()
    {
        string n="y";
        do
        {
        cout<<"Enter the mobile no.";
        cin>>key;
        address=key%10;

        if(mobile[address]==-1)
        {
            mobile[address]=key;
            cout<<"Enter name for this mobile no.";
            cin>>name[address];

        }
        else
        {
           //when collision occurs....
            int j=1;
            while(1)
                {
                    int t = (address + j * j) % 10;
                    if (mobile[t] == -1)
                    {
                        mobile[t] = key;
                        cout<<"Enter name for this mobile no.";
                        cin>>name[address];
                        break;
                    }
                    else
                    {
                        j++;
                    }

                }
        }

        int cnt=0;
        for(int k=0;k<10;k++)
        {
            if(mobile[k]!=-1)
            {
               cnt++;
            }


        }
        if(cnt==10)
        {
            cout<<"Hash table is full. You cannot store more Records!!";
        }
        cout<<"If you want to enter next mobile no. then enter (y) else enter (n): ";
        cin>>n;
        }while(n=="y");
    }

    void display()
    {
        int i;
        cout<<"\n***Displaying Records***"<<"\n";
        for(i=0; i<10; i++)
        {
           cout<<"Index="<<i<<"\n";
           cout<<"Mob no. ="<<mobile[i]<<"\n";
           cout<<"Name: "<<name[i]<<"\n";
        }
    }


};


int main()
{
    int choice;
    telephone obj1;
    do
    {
        cout<<"\n1. Insert record using linear probe. \n2. Insert record using Quadratic probe. \n3. Display Record \n4. Exit.";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                obj1.insertrecord_linearly();
                break;
            case 2:
                obj1.insertrecord_Quadratically();
                break;
            case 3:
                obj1.display();
            case 4:
                break;
        }

    }while(choice!=4);
    return 0;
}