// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    char name[20];
    int childCount;
    struct Node *child[20];
} * root;

class Book
{
public:
    int c, s, ss;
    Book()
    {
        root = NULL;
    }

    void create()
    {
        root = new Node();
        cout << "Enter Books name : ";
        cin >> root->name;
        cout << "Enter no. of chapter : ";
        cin >> c;
        root->childCount = c;
        for (int i = 0; i < c; i++)
        {
            root->child[i] = new Node();
            cout << "Enter chapter " << i + 1 << " name : ";
            cin >> root->child[i]->name;
            cout << "Enter no. of section : ";
            cin >> s;
            root->child[i]->childCount = s;
            for (int j = 0; j < s; j++)
            {
                root->child[i]->child[j] = new Node();
                cout << "Enter section " << j + 1 << " name : ";
                cin >> root->child[i]->child[j]->name;
                cout << "Enter no. of Sub-section : ";
                cin >> ss;
                root->child[i]->child[j]->childCount = ss;
                for (int k = 0; k < ss; k++)
                {
                    root->child[i]->child[j]->child[k] = new Node();
                    cout << "Enter sub-section " << k + 1 << " name : ";
                    cin >> root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }

    void display(Node *root)
    {
        int c, s, ss;
        cout << "\nBook : \n";
        cout << "Name of the book is : " << root->name << endl;
        c = root->childCount;
        for (int i = 0; i < c; i++)
        {
            cout << "Name of chapter " << i + 1 << " : " << root->child[i]->name << endl;
            s = root->child[i]->childCount;
            for (int j = 0; j < s; j++)
            {
                cout << "Name of section " << i + 1 << " : " << root->child[i]->child[j]->name << endl;
                ss = root->child[i]->child[j]->childCount;
                for (int k = 0; k < ss; k++)
                {
                    cout << "Name of Sub-section " << i + 1 << " : " << root->child[i]->child[j]->child[k]->name << endl;
                }
            }
        }
    }
};

int main()
{
    Book b;
    b.create();
    b.display(root);
}
