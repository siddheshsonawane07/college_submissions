#include <iostream>
using namespace std;

class node{
    public: 
        char label[20];
        int ch_count;
        node *child[10];    
}*root;

class BST{
	public:
        void create();
        void display(node *r);
        BST()
        {
        root = NULL;
        }

};

void BST::create(){
	root = new node;
	cout<<"Enter the name of the book: "<<endl;
	cin>>root->label;
	cout<<"Enter the total number of chapters in the book: "<<endl;
	int total;
	cin>>total;
	root->ch_count = total;
	for(int i = 0; i<root->ch_count; i++){

		root->child[i] = new node;
		cout<<"Enter the name of the chapter"<<endl;
		cin>>root->child[i]->label;
		
		cout<<"Enter the number of sections in the chapter"<<endl;
		cin>>root->child[i]->ch_count;

		for(int j = 0; j<root->child[i]->ch_count; j++){
		
			root->child[i]->child[j] = new node;
			cout<<"Enter the name of the section"<<endl;
			cin>>root->child[i]->child[j]->label;

			cout<<"Enter the number of sub sections in the chapter"<<endl;
			cin>>root->child[i]->child[j]->ch_count;

			for(int k = 0; k<root->child[i]->child[j]->ch_count; k++){

				root->child[i]->child[j]->child[k] = new node;
				cout<<"Enter sub-section head"<<endl;
				cin>>root->child[i]->child[j]->child[k]->label;
			}

		
		}

	}

}

void BST::display(node *r){
	
	if(r!=NULL){
		
		cout<<"Book Hierarchy"<<endl;
		cout<<"Book Title: "<<r->label<<endl;
		
		for(int i = 0; i<r->ch_count; i++){
            
            cout<<"\n----------------"<<endl;
			cout<<" \n Chapter: "<<r->child[i]->label;
			
			for(int j = 0; j<r->child[i]->ch_count; j++){

                cout<<"\n ";
                
				cout<<" \n Section: "<<r->child[i]->child[j]->label;

				for(int k = 0; k<r->child[i]->child[j]->ch_count; k++){
			
					cout<<"\n Sub-section: "<<r->child[i]->child[j]->child[k]->label;

				}
			}	



		}
	
	}

}



int main(){
	int choice;
	BST bst;

	while(1){
        cout<<"\n --------";
		cout<<"Book tree creation"<<endl;
		cout<<"1. Create" <<endl;
		cout<<"2. Display" <<endl;
		cout<<"3. Quit"<<endl;
		cin>>choice;
		switch(choice){
		
			case 1: 
            bst.create();
            break;
			
			case 2: 
            bst.display(root);
            break;

			case 3: 
            exit(1);

			default: cout<<"Wrong Choice"<<endl;

		}

	}

 return 0;
}
