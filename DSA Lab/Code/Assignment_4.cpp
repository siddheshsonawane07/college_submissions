/*
A Dictionary stores keywords &amp; its meanings. Provide facility for adding
new keywords, deleting keywords, updating values of any entry. Provide
facility to display whole data sorted in ascending/ Descending order. Also
find how many maximum comparisons may require for finding any
Use BST for tree implementation


strcmp = 0 //when the string matches
strcmp > 0 //left string is bigger than right string in comparison with ASCII values
strcmp < 0 //right string is bigger than left string

all upercase letters are less than all the lower case letters
digits are less than letters


*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
int op;
int cnt=0;
class node
{
	public:
	node *left;
	char word[50],mean[50];
	node *right;
};
class BT
{
	public:
	node *root;
	BT()
	{
		root=NULL;
    }
	void create();
	node* insert(node *,node *);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	void search(node *, char []);
	void modify(node *, char []);
	node *dlt(node * ,char []);
    node *FindMin(node * );


};

void BT::create()
{
	int op;
	node *temp;
    do
    {
    	temp=new node;
    	cout<<"Enter Word : ";
    	cin>>temp->word;
    	cout<<"Enter Meaning : ";
    	cin>>temp->mean;
     	temp->left=temp->right=NULL;
     	if(root==NULL)
     	{
    		root=temp;
     	}
     	else
     	{
    	 	root=insert(root,temp);
     	}
     	cout<<"Want to insert again : ";
     	cin>>op;
    }	while(op==1);
}

node* BT::insert(node *root,node *temp)
{     
	if(strcmp (temp->word, root->word) < 0 ){	
  		if(root->left == NULL){
   			root->left = temp;
		}
  		else{
   		insert(root->left,temp);
		}
	}
 	else{ 
	 	if(root->right == NULL){
   			root->right = temp;
	 	}
  	 	else{	
   			insert(root->right,temp);
		}
	}
    return root;
}

void BT::inorder(node *temp)
{
    if(temp!=NULL)
    {
    	inorder(temp->left);
    	cout<<temp->word<<" -> "<<temp->mean<<" , ";
    	inorder(temp->right);
    }
}

void BT::preorder(node *temp)
{
    if(temp!=NULL)
    {
    	cout<<temp->word<<"-> "<<temp->mean<<" , ";
    	preorder(temp->left);
    	preorder(temp->right);
    }
}

void BT::postorder(node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->word<<"-> "<<temp->mean<<" , ";
    }
}

void BT::search(node *temp , char src[]){

	if(temp != NULL)
	{
		if((strcmp(temp->word , src)) == 0){
			cout<<"\n Word Found ";
			cout<<"\n Word    : "<<temp->word;
			cout<<"\n meaning : "<<temp->mean;
			cnt++;
		}
		else 
		{
			if((strcmp( src, temp->word )) > 0){
				search(temp->right , src);
				cnt++;
			}
			else {
				search(temp->left , src);
				cnt++;
			}
		}
	}
	else{
		cout<<"\n Word Not Found ";
	}
		cout<<"\n Total no of Comparisions to search an element is: "<<cnt;
	}

void BT::modify(node *temp , char src[])
{
	if(temp != NULL)
	{
	 	if((strcmp(temp->word , src)) == 0){
	    	cout<<"\n Word Found ";
	    	cout<<"\n Enter New Meaning Of Word "<<temp->word;
	    	cin>>temp->mean;
		}
	 	else{
		 	if((strcmp(temp->word , src)) < 0){
				modify(temp->right , src);
		 	}
		 	else if((strcmp(temp->word , src)) > 0)
		 	{
				modify(temp->left , src);
		 	}
	 	}
	}
	else{
		cout<<"\n Word Not Found ";
	}
}

node* BT::FindMin(node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}


node* BT::dlt(node *root , char src[])
{
    node* temp;

    if(root==NULL){
        cout<<"Element not found"<<endl;
    }

    if(strcmp(root->word,src)>0){
            root->left=dlt(root->left,src);
            return root;
    }

    if(strcmp(root->word,src)<0){
            root->right=dlt(root->right,src);
            return root;
    }

    if(root->left==NULL && root->right==NULL){

            temp=root;
            delete(root);
            return NULL;
    }

    if(root->right==NULL){

            temp=root;
            root=root->left;
            strcpy(temp->word,root->word);
            strcpy(temp->mean,root->mean);
            delete temp;
            return root;
    }
	
    else if(root->left==NULL){
		
            temp=root;
            root=root->right;
            strcpy(temp->word,root->word);
            strcpy(temp->mean,root->mean);
            delete temp;
            return root;
    }

    temp=FindMin(root->right);
    strcpy(temp->word,root->word);
    strcpy(temp->mean,root->mean);
    root->right=dlt(root->right,temp->word);
    return root;
}



int main(){

		BT b;
		int op;
		char src[100];
		while(1)
		{
	     cout<<"\n ";
		 cout<<"\n 1. Insert Binary Search Tree ";
		 cout<<"\n 2. Display Inorder,preorder and postorder ";
		 cout<<"\n 3. Search The Word ";
		 cout<<"\n 4. Modify The Meaning Of Word ";
		 cout<<"\n 5. Delete Word From Dictionary ";
		 cout<<"\n 6. Exit";
		 cout<<"\n Enter your choice:";
		 cin>>op;
		 switch(op)
		 {
		 case 1:
			b.create();
			break;

		 case 2:
			cout<<"\n Inorder : ";
			b.inorder(b.root);
			cout<<"\n Preorder : ";
			b.preorder(b.root);
			cout<<"\n Postorder : ";
			b.postorder(b.root);
			break;


		 case 3:
			 cnt=0;
			 cout<<"\n Enter The Word Want To Search : ";
			 cin>>src;
			 b.search(b.root , src);
			 break;

		 case 4:
			 cout<<"\n Enter The Word Want To Modify ";
			 cin>>src;
			 b.modify(b.root , src);
			 break;

		 case 5:
			 cout<<"\n Enter The Word Want To Delete ";
			 cin>>src;
			 b.dlt(b.root , src);
			 break;

		
		case 6:
		     exit(0);
			 break;

		 default :
			 cout<<"\n Invalid Option ";
			 break;
		 }
		}

		return 0;
	}