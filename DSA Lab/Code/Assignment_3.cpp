/*
Beginning with an empty binary search tree, Construct binary search tree by
inserting the values in the order given. After constructing a binary tree
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped
at every node
v. Search a value
*/

#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        Node *left, *right;
};

class Tree{
    public:
        Node *root;
        
        Node *createTree(int key){
            root = new Node();
            
            root->key = key;
            root->left = NULL;
            root->right = NULL;

            return root;
        }

        void insert(Node* root,int key){
            root = insertNode(root, key);
        }

        Node* insertNode(Node *root, int key){

            if(root == NULL){
                root = new Node();
                root->key = key;
            } 
            else if(key<=root->key){
                root->left = insertNode(root->left, key);
            }else{
                root->right = insertNode(root->right, key);
            }
            return root;
        }

        void display_Inorder(Node* root)
        {
            if (root != NULL)
            {
                display_Inorder(root->left);
                cout << root->key << "  ";
                display_Inorder(root->right);
            }
        }

        void display_Preorder(Node* root)
        {
            if (root != NULL)
            {
                cout << root->key << "  ";
                display_Preorder(root->left);
                display_Preorder(root->right);
            }
        }

        void display_Postorder(Node* root)
        {
            if (root != NULL)
            {
                display_Postorder(root->left);
                display_Postorder(root->right);
                cout << root->key << "  ";
            }
        }

        bool search(Node* root, int key){
            if(root == NULL){
                return false;
            }
            else if(key == root->key){
                return true;
            }
            else if(key <= root->key){
                return search(root->left,key);
            }
            else{
                return search(root->right,key);
            }
        }

        void display_Min(Node *root){
            while(root->left != NULL){
                root = root->left;
            }
            cout<<"Minimum number is " <<root->key <<endl;
        }

        void display_Max(Node *root){
            while(root->right != NULL){
                root = root->right;
            }
            cout<<"Maximum number is " <<root->key <<endl;
        }

        int longest_path(Node *root){
            if(root == NULL){
                return 0;
            }

            int leftH = longest_path(root->left);
            int rightH = longest_path(root->right);

            if(leftH>rightH){
                return (leftH + 1);
            }
            else{
                return (rightH + 1);
            }

        }

        Node* swapNodes(Node* root)
        {
            Node* temp;
            if(root==NULL){
                return NULL;
            }

            temp = root->left;      
            root->left=root->right;
            root->right=temp;

            swapNodes(root->left);
            swapNodes(root->right);
        }


};

int main(){
    
    Node* root;
    Tree t1;
    int choice,key;
    int flag = 0;
    while(1){
        cout<<"\n "<<endl;
        cout<<" MENU "<<endl;
        cout<<"1. Insert Node "<<endl;
        cout<<"2. Display Inorder of the Tree"<<endl;
        cout<<"3. Display Minimum"<<endl;
        cout<<"4. Display Maximum"<<endl;
        cout<<"5. Search in the tree"<<endl;
        cout<<"6. Number of nodes in the longest path"<<endl;
        cout<<"7. Swap left and right subtrees"<<endl;
        cout<<"8. EXIT "<<endl;
        cout<<"Enter choice: ";
        cin >> choice;

        switch(choice){

            case 1: 
                cout <<"Enter the number ";
                cin >> key;
                if (flag == 0)     
                {
                root = t1.createTree(key);   
                flag = 1;
                }
                else
                {
                t1.insert(root, key);
                }
                break;

            case 2:
                t1.display_Inorder(root);
                break;

            case 3:
                t1.display_Min(root);
                break;

            case 4:
                t1.display_Max(root);
                break;

            case 5:
                cout<<"Enter number to be searched in the tree: ";
                int searchkey, result;
                cin>>searchkey;
                result = t1.search(root,searchkey);
                if(result == 0){
                    cout<<"Key not found"<<endl;
                }else{
                    cout<<"Key found " <<endl;
                }
                break;
            
            case 6:
                int longest;
                longest = t1.longest_path(root);
                cout << "Number of nodes in the longest path: "<<longest <<endl;
                break;

            case 7:
                t1.swapNodes(root);
                cout<<"The new tree is: "<<endl;
                t1.display_Inorder(root);
                break;

            case 8:
                exit(1);

            default:
                cout<<"Wrong Choice "<<endl;
        }
    }
    
    return 0;
}