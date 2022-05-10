/*
A book consists of chapters, chapters consist of sections and sections consist
of subsections. Construct a tree and print the nodes. Find the time and space
requirements of your method.
*/

#include <iostream>
using namespace std;
struct node 
{
    char label[20];
    int ch_count;
    struct node *child[10];
}*root;

class BST 
{
    public:
    void create();
    void display(node *r1);
    BST()
    {
        root=NULL;
    }
};
void BST::create()
{
    int i ,j, k, tchapters, tbook;
    root=new node;
    cout<<"Enter the name of the book "<<endl;
    cin>>root->label;
    cout<<"Enter the number of chapters the book contains ";
    cin>>tchapters;
    root->ch_count=tchapters;
    for(i=0; i<tchapters; i++)
    {
        root->child[i]=new node;
        cout<<"Enter the name of the chapter ";
        cin>>root->child[i]->label;
        
        cout<<"Enter the number of sections in this chapter ";
        cin>>root->child[i]->ch_count;
        
        for(j=0; j<root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter section head ";
            cin>>root->child[i]->child[j]->label;
            
            cout<<"Enter the number of sub-sections in this chapter ";
            cin>>root->child[i]->child[j]->ch_count;
            
            for(k=0; k<root->child[i]->child[j]->ch_count; k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"Enter sub-section head ";
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
        
    }
}
void BST::display(node *r1)
{
    int i,j,k,tchapters;
    if (r1!=NULL)
    {
        cout<<"\n  -----Book Hierarchy-----";
        cout<<"\n BOOK TITLE: "<<r1->label;
        tchapters=r1->ch_count;
        for(i=0; i<tchapters; i++)
        {
            cout<<"\n----------------"<<endl;
            cout<<"\n CHAPTER: "<<i+1<<". ";
            cout<<r1->child[i]->label<<endl;
            
            
            for(j=0; j<r1->child[i]->ch_count; j++)
            {
                cout<<"\n SECTION: ";
                cout<<r1->child[i]->child[j]->label<<endl;
                
                
                for(k=0; k<r1->child[i]->child[j]->ch_count; k++)
                {
                    cout<<"\n SUB-SECTION: ";
                    cout<<r1->child[i]->child[j]->child[k]->label<<endl;
                }
                
            }
            
            
        }
    }
}


int main()
{
    int choice  ;
    BST bst;
    while(1)
    {
        cout<<"\n\n--------------"<<endl;
        cout<<"Book tree creation"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1.Create "<<endl;
        cout<<"2.Display "<<endl;
        cout<<"3.Quit "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice )
        {
            case 1: 
            bst.create();
            
            case 2:
            bst.display(root);
            break;
            
            case 3: 
            exit(1);
            
            default:
            cout<<"Wrong choice "<<endl;
        }
        
    }
    

    return 0;
}