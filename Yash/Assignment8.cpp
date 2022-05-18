#include<iostream>
#include<string>
using namespace std;
struct dic 
{
    string word,meaning; int chain;
};
class Hash
{
    public:
    int key,x,i,sum,c,q;
    string w, m;
    dic d[10];
    Hash()
    {
        for (int i=0; i<10; i++)
        {
            d[i].word=" ";
            d[i].meaning=" ";
            d[i].chain=-1;
        }
    }
    void insert()
    {
        cout<<"Enter the number of enteries <10 ";cin>>q;
        for (int i=0; i<q; i++)
        {
            cout<<"Enter the word ";cin>>w;
            cout<<"\nEnter its meaning ";cin>>m;
            sum=0;
            for (int i=0; i<w.length(); i++)
            {
                sum=sum+w[i];
            }
            x=sum%10;
            c=x;
            while(1)
            {
                if (d[x].word==" ")
                {
                    d[x].word=w;
                    d[x].meaning=m;
                    if (c!=x)
                    {
                        d[x].chain=c;
                    }
                    break;
                }
                else
                x=(x+1)%10;
                if (c==x)
                {
                    cout<<"Hash Table full";
                    break;
                }
            }
        }
    }
    void display()
    {
        for (int i=0; i<10; i++)
        {
            cout<<"Word: "<<d[i].word<<" "<<"Mean: "<<d[i].meaning<<" "<<d[i].chain<<endl;;      
            
        }
    }
    void search()
    {
        cout<<"\nEnter the word ";cin>>w;
        sum=0;
        for (int i=0; i<w.length(); i++)
        {
            sum=sum+w[i];
        }
        x=sum%10;
        c=x;
        while(1)
        {
            if (d[x].word==w)
            {
                cout<<"Word Found ";
                break;
            }
            x=(x+1)%10;
            if (c==x)
            {
                cout<<"Word not found ";
                break;
            }
        }
    }
    void delo()
    {
        cout<<"Enter the word to be deleted ";cin>>w;
        sum=0;
        for(int i=0; i<w.length(); i++)
        {
            sum=sum+w[i];
        }
        x=sum%10;
        c=x;
        while(1)
        {
           if (d[x].word==w)
           {
               cout<<"deleted successfully";
               d[x].word=" "; d[x].meaning=" ";break;
           }
           x=(x+1)%10;
           if (c==x)
           {
               cout<<"Word not found ";break;
           }
        }
    }
};
    

int main()
{
    Hash h;
    h.insert();
    h.display();
    h.search();
    h.delo();
    return 0;