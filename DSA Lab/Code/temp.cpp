
#include <iostream>
#include <string>
using namespace std;

class dict;
class Node
{
    string word, mean;
    Node *left, *right;

public:
    friend class dict;
    Node()
    {
        left = right = NULL;
    }
    Node(string word, string mean)
    {
        this->word = word;
        this->mean = mean;
        left = right = NULL;
    }
};

class dict
{
    Node *root;

public:
    dict()
    {
        root = NULL;
    }

    void inorder()
    {
        asc(root);
    }
    
    void postorder()
    {
        desc(root);
    }

    void asc(Node *curr)
    {
        if (curr != NULL)
        {
            asc(curr->left);
            cout << curr->word << " - " << curr->mean << endl;
            asc(curr->right);
        }
    }

    void desc(Node *root)
    {
        if (root != NULL)
        {
            desc(root->right);
            cout << root->word << " - " << root->mean << endl;
            desc(root->left);
        }
    }

    bool insert(string word, string mean)
    {
        Node *node = new Node(word, mean);
        if (root == NULL)
        {
            root = node;
            return true;
        }
        Node *curr = root;
        Node *par = root;
        while (curr != NULL)
        {
            if (curr->word > word)
            {
                par = curr;
                curr = curr->left;
            }
            else if (curr->word < word)
            {
                par = curr;
                curr = curr->right;
            }
            else
            {
                cout << "Same words not allowed\n";
                return false;
            }
        }
        if (par->word > word)
        {
            par->left = node;
            return true;
        }
        else if (par->word < word)
        {
            par->right = node;
            return true;
        }
        return false;
    }

    int search(string word, int &cnt)
    {
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->word > word)
            {
                cnt++;
                curr = curr->left;
            }
            else if (curr->word < word)
            {
                cnt++;
                curr = curr->right;
            }
            else if (curr->word == word)
            {
                cnt++;
                break;
            }
        }
        return cnt;
    }

    Node *searchS(string word)
    {
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->word > word)
            {
                curr = curr->left;
            }
            else if (curr->word < word)
            {

                curr = curr->right;
            }
            else if (curr->word == word)
            {
                break;
            }
        }
        return curr;
    }

    void update(string word)
    {
        string nw;
        Node *curr = searchS(word);
        cout << "Enter new meaning of word " << curr->word << " : ";
        cin >> nw;
        curr->mean = nw;
    }
};

int main()
{
    int ch, cnt = 0;
    string word, meaning, uw, sw;
    dict d;
    cout << "-----------Dictionary---------\n";
    cout << "1)Add word\n2)Display in Ascending\n3)Display in Descending\n4)Update\n5)Search\n6)Exit\n";
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the word : ";
            cin >> word;
            cout << "Enter the meaning : ";
            cin >> meaning;
            d.insert(word, meaning);
            break;
        case 2:
            cout << "Ascending order is : \n";
            d.inorder();
            cout << endl;
            break;
        case 3:
            cout << "Descending order is : \n";
            d.postorder();
            cout << endl;
            break;
        case 4:
            cout << "Enter word you want to update : ";
            cin >> uw;
            d.update(uw);
            break;
        case 5:
            cnt = 0;
            cout << "Enter word you want to search : ";
            cin >> sw;
            d.search(sw, cnt);
            if (cnt == 0)
            {
                cout << "Word not found\n";
            }
            else
            {
                cout << "The comparisions required are : " << cnt << endl;
            }
            break;
        case 6:
            cout << "End\n";
            exit(0);
        }
    } while (ch != 6);
}