#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
} * root;

class BST
{
public:
    Node *createBST(int val)
    {
        root = new Node();
        root->val = val;
        root->left = root->right = NULL;
        return root;
    }

    void insert(Node *root, int val)
    {
        Node *curr = new Node();
        curr->val = val;
        if (root->val > val)
        {
            if (root->left == NULL)
            {
                root->left = curr;
            }
            else
            {
                insert(root->left, val);
            }
        }
        else if (root->val < val)
        {
            if (root->right == NULL)
            {
                root->right = curr;
            }
            else
            {
                insert(root->right, val);
            }
        }
        else
        {
            cout << "Same values are not allowed\n";
            return;
        }
    }

    int longestPath(Node *root, int &ht)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = longestPath(root->left, ht);
        int r = longestPath(root->right, ht);
        ht = max(ht, l + r);
        return 1 + max(l, r);
    }

    void minimumVal(Node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        cout << "Minimum value in BST is : " << root->val << endl;
    }

    Node* swapNodes(Node *root)
    {
        Node *temp;
        if (root == NULL)
        {
            return NULL;
        }
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        swapNodes(root->left);
        swapNodes(root->right);
        return root;
    }

    void search(int key, Node *root)
    {
        if (root->val > key)
        {
            if (root->left == NULL)
            {
                cout << "Not Found\n";
            }
            else
            {
                search(key, root->left);
            }
        }
        else if (root->val < key)
        {
            if (root->right == NULL)
            {
                cout << "Not Found\n";
            }
            else
            {
                search(key, root->right);
            }
        }
        else if(key==root->val)
        {
            cout << "Node Found!!\n";
        }
    }

    void display(Node *root)
    {
        if (root != NULL)
        {
            display(root->left);
            cout << " " << root->val;
            display(root->right);
        }
    }
};

int main()
{
    int ch, flag = 0, val, key, ht = 0;
    BST b;
    cout << "------BST OPTION------\n";
    cout << "1)Insert new node\n2)Find number of nodes in longest path\n";
    cout << "3)Minimum Value in tree\n4)Swap left & right node\n5)Search a value\n6)Exit\n";
    do
    {
        cout << "Enter ur choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value : ";
            cin >> val;
            if (flag == 0)
            {
                b.createBST(val);
                flag = 1;
            }
            else
            {
                b.insert(root, val);
            }
            break;

        case 2:
            b.longestPath(root, ht);
            cout << "Longest Nodes path is : " << ht << endl;
            break;
        case 3:
            b.minimumVal(root);
            break;
        case 4:
            b.swapNodes(root);
            cout << "Swapped nodes are : "<<endl;
            b.display(root);
            cout<<endl;
            break;
        case 5:
            cout << "Enter key to search : ";
            cin >> key;
            b.search(key, root);
            break;
        case 6:
            cout << "End\n";
            exit(0);
        }
    } while (ch != 6);
}