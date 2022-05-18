#include<iostream>
using namespace std;
struct node
{
    char label[20];int chcount; 
    struct node* child[10];
}*root;
class GT
{
    public:
    GT()
    {
        root=NULL;
    }
    void create();
    void display(node*r1);
};
void GT::create()
{
    root=new node;
    int tchapters,i,j,k;
    cout<<"Enter book name ";cin>>root->label;
    cout<<"\nEnter the number of chapters ";cin>>tchapters;
    root->chcount=tchapters;
    for(i=0; i<tchapters; i++)
    {
        root->child[i]=new node;
        cout<<"\nEnter the name of the chapters ";cin>>root->child[i]->label;
        cout<<"\nEnter the number of section ";cin>>root->child[i]->chcount;
         
        for(j=0; j<root->child[i]->chcount; j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"\nEnter the name of the sections ";cin>>root->child[i]->child[j]->label;
            cout<<"\nEnter the number of sub-section ";cin>>root->child[i]->child[j]->chcount;
            
            for(k=0;k<root->child[i]->child[j]->chcount;k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"\nEnter the name of the sub-sections ";cin>>root->child[i]->child[j]->child[k]->label;
                
               
            }
        }
    }
}
void GT::display(node *r1)
{
    int i,j,k;
    if (r1!=NULL)
    {
        cout<<"\nBOOK HIERARCHY "<<endl;
        cout<<"Title "<<r1->label;
        for(i=0; i<r1->chcount; i++)
        {
            cout<<"\nChapters "<<i+1;
            cout<<"\n"<<r1->child[i]->label<<endl;
            
            for(j=0; j<r1->child[i]->chcount; j++)
            {
                cout<<"\nSections "<<j+1;
                cout<<"\n"<<r1->child[i]->child[j]->label<<endl;
                
                for(k=0;k<r1->child[i]->child[j]->chcount;k++)
                {
                    cout<<"\nSub-Sections "<<k+1;
                    cout<<"\n"<<r1->child[i]->child[j]->child[k]->label<<endl;
                }
            }
            
            
        }
        
    }
}
int main()
{
    int ch; GT t;
    while(1)
    {
        cout<<"\n1.Insert \n2.Display \n3.Exit"<<endl;
        cout<<"Enter your choice ";cin>>ch;
        switch(ch)
        {
            case 1:
            t.create();
            break;
            case 2:
            t.display(root);
            break;
            case 3:
            exit(0);
        }
    }
    return 0;
}