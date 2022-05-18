#include <iostream>
using namespace std;
class Node 
{
    public:
    int key;
    Node *left,*right;
};
class Tree 
{
    public:
    Node *root;
    Tree()
    {
        root=NULL;
    }
    
    Node* createtree(int key)
    {
        root=new Node();
        root->key=key;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    
    void insertnode(int key, Node* root)
    {
        Node* node=new Node();
        node->key=key;
        if(root->key > key )
        {
            if(root->left==NULL)
            {
                root->left=node;
            }
            else 
            { insertnode(key, root->left);}
        }
        else if (root->key<key )
        {
            if(root->right==NULL)
            {
                root->right=node;
            }
            else 
            { insertnode(key,root->right);}
            
        }
        
        else 
        {
            cout<<"No duplicate values allowed ";
        }
        
    }
    
    void searchnode(int searchkey, Node* root)
    {
        if (root==NULL )
        {
            cout<<"No tree available ";
        }
        if (root->key==searchkey)
        {
            cout<<"Key found !!!"<<endl;
        }
        else if (root->key > searchkey )
        {
            if (root->left==NULL)
            {
                cout<<"Key is not present in the tree "<<endl;
            }
            else searchnode(searchkey ,root->left);
        }
        else if (root->key < searchkey)
        {
            if(root->right== NULL)
            {
                cout<<"Key is not present in the tree "<<endl;
            }
            else  searchnode(searchkey, root->right );
            
        }
      
    }
    
    void displayinorder(Node* root)
    {
        if (root!=NULL)
        {
            displayinorder(root->left);
            cout<<root->key<<endl;
            displayinorder(root->right);
        }
    }
    
    void displaymin(Node* root)
    {
        while(root->left !=NULL)
        {
            root=root->left;
        }
        cout<<"\nMinimum number is "<<root->key<<endl;
    }
    
    int longestpath(Node* root)
    {
        if (root==NULL)
        return 0;
        int lctr=longestpath(root->left);
        int rctr=longestpath(root->right);
        if (lctr>rctr)
        return(lctr+1);
        else 
        return(rctr+1);
    }
    
    Node* swapnodes(Node *root)
    {
        Node* temp;
        if (root==NULL)
        return NULL;
        
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        swapnodes(root->left);
        swapnodes(root->right);
        return NULL;
    }
    
};

int main()
{
   int choice, order, key, searchkey, flag=0;
   Tree t1;
   Node* root;
   do{
       cout<<"\n1.Enter a number \n2.Display \n3.Display min valued node "<<endl;
       cout<<"4.Swap left and right node \n5.Search \n6.No of nodes in longest path \n7.Exit \n";
       cout<<"Enter you choice ";cin>>choice;
       switch(choice )
       {
           case 1: 
           cout<<"\nEnter the number "; cin>>key;
           if (flag==0)
           {
               root=t1.createtree(key);
               flag=1;
           }
           else 
           {
               t1.insertnode(key, root);
           }
           break;
           
           case 2:
           t1.displayinorder(root);
           break;
           
           case 3:
           t1.displaymin(root);
           break;
           
           case 4:
           t1.swapnodes(root);
           cout<<"Swapped ! The new list is : ";
           t1.displayinorder(root);
           break;
           
           case 5:
           cout<<"\nEnter the key you want to search "; cin>>searchkey;
           t1.searchnode(searchkey,root);
           break;
           
           case 6:
           cout<<"\nThe height of the tree or the longest path is "<<t1.longestpath(root);
           break;
           
           case 7:
           exit(0);
           
       }
    
   }while(choice !=7);
    return 0;
}


