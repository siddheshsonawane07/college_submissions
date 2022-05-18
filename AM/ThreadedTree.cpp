
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
} * root;

class tree
{
public:
    Node *create(int val)
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
        else if (root->val == val)
        {
            cout << "Same values are not allowed\n";
            return;
        }
    }

    void preorder(Node *root)
    {
        vector<int> pre;
        Node *node = root;
        while (node != NULL)
        {
            if (node->left == NULL)
            {
                pre.push_back(node->val);
                node = node->right;
            }
            else
            {
                Node *curr = node->left;
                while (curr->right != NULL && curr->right != node)
                {
                    curr = curr->right;
                }
                if (curr->right == NULL)
                {
                    curr->right = node;
                    pre.push_back(node->val);
                    node = node->left;
                }
                else
                {
                    curr->right = NULL;
                    node = node->right;
                }
            }
        }
        for (int i = 0; i < pre.size(); i++)
        {
            cout << pre[i] << " ";
        }
    }

    void inorder(Node *root)
    {
        vector<int> in;
        Node *node = root;
        while (node != NULL)
        {
            if (node->left == NULL)
            {
                in.push_back(node->val);
                node = node->right;
            }
            else
            {
                Node *curr = node->left;
                while (curr->right != NULL && curr->right != node)
                {
                    curr = curr->right;
                }
                if (curr->right == NULL)
                {
                    curr->right = node;
                    node = node->left;
                }
                else
                {
                    curr->right = NULL;
                    in.push_back(node->val);
                    node = node->right;
                }
            }
        }
        for (int i = 0; i < in.size(); i++)
        {
            cout << in[i] << " ";
        }
    }

    void postorder(Node *root)
    {
        vector<int> post;
        Node *node = root;
        while (node != NULL)
        {
            if (node->right == NULL)
            {
                post.push_back(node->val);
                node = node->left;
            }
            else
            {
                Node *curr = node->right;
                while (curr->left != NULL && curr->left != node)
                {
                    curr = curr->left;
                }
                if (curr->left == NULL)
                {
                    curr->left = node;
                    post.push_back(node->val);
                    node = node->right;
                }
                else
                {
                    curr->left = NULL;
                    node = node->left;
                }
            }
        }
        reverse(post.begin(),post.end());
        for (int i = 0; i < post.size(); i++)
        {
            cout << post[i] << " ";
        }
    }
};

int main()
{
    tree t;
    cout << "Threaded Binary Tree\n";
    cout << "1)Insert a Node\n2)Preorder Traversal\n3)Inorder Traversal\n4)Postorder Traversal\n5)Exit\n";
    int ch, flag = 0, val;
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value : ";
            cin >> val;
            if (flag == 0)
            {
                t.create(val);
                flag = 1;
            }
            else
            {
                t.insert(root, val);
            }
            break;

        case 2:
            cout << "PreOrder Traversal is : ";
            t.preorder(root);
            cout << endl;
            break;
        case 3:
            cout << "InOrder Traversal is : ";
            t.inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "PostOrder Traversal is : ";
            t.postorder(root);
            cout << endl;
            break;
        case 5:
            cout << "END\n";
            exit(0);
        }
    } while (ch != 5);
}