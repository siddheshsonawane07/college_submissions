#include<iostream>
using namespace std;
class telephone
{
    public:
    int key;
    int n;
    string phone[20];
    string name[20];
    int address;
   
    telephone()
    {
        for(int i=0;i<20;i++)
        {
            phone[i]="-1";
        }
    }
   
    // void getrecord()
    // {
    //     cout<<"How many record wants to store : ";
    //     cin>>n;
    //     for(int i=0;i<n;i++)
    //     {
    //         cout<<"Enter telephone number : ";
    //         cin>>key;
    //         address=key%n;
    //         if(phone[address]=="-1")
    //         {
    //             cout<<"Enter name : ";
    //             cin>>phone[address];
    //         }
    //         else
    //         {
    //             address=cal_address(key);
    //             cout<<"Enter name : ";
    //             cin>>phone[address];
    //         }
    //     }
       
    // }
    // int cal_address(int key)
    // {
    //     address=key%n;
    //         while(phone[address]!="-1")
    //         {
    //             address++;
    //             if(address>=n)
    //             {
    //                 address=0;
    //             }
    //         }
        
    //     return address;
    // }
    
    void getrecord()
    {
        cout<<"How many record wants to store : ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter telephone number : ";
            cin>>key;
            address=key%n;
            if(phone[address]=="-1")
            {
                cout<<"Enter name : ";
                cin>>phone[address];
            }
            else
            {
                address=cal_address(key);
                cout<<"Enter name : ";
                cin>>phone[address];
            }
        }
       
    }

    int cal_address(int key)
    {
     
        
        return address;
    }
   
    void show()
    {
        for(int i=0;i<n;i++)
        cout<<i<<"   "<<phone[i]<<endl;
    }
   
};
int main()
{
    telephone t;
    t.getrecord();
    t.show();
}