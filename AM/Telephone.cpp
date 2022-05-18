
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class hashing
{
public:
    int size, flag = 1;
    vector<int> hashTable;
    hashing()
    {
        cout << "Enter size of the table : ";
        cin >> size;
        hashTable.resize(size, -1);
    }

    void linear(long long int num)
    {
        if (flag == 0)
        {
            cout << "You cannot add more as Table is Full!\n";
            return;
        }
        int hashVal = num % size;
        for (int i = 0; i < size; i++)
        {
            if (hashTable[i] == num)
            {
                cout << "Number already exists!\n";
                return ;
            }
        }
        if (hashTable[hashVal] == -1)
        {
            hashTable[hashVal] = num;
        }
        else
        {
            if (hashVal == size)
            {
                hashVal = 0;
            }
            while (hashTable[hashVal] != -1)
            {
                hashVal += 1;
                if (hashVal == size)
                {
                    hashVal = 0;
                }
            }
            hashTable[hashVal] = num;
        }
        int cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (hashTable[i] != -1)
            {
                cnt++;
            }
        }
        if (cnt == size)
        {
            cout << "Table is Full\n";
            flag = 0;
        }
    }

    void quadratic(long long int num)
    {
        int hashVal = num % size;
        for (int i = 0; i < size; i++)
        {
            if (hashTable[i] == num)
            {
                cout << "Number already exists!\n";
            }
        }
        if (hashTable[hashVal] == -1)
        {
            hashTable[hashVal] = num;
        }
        else
        {
            for (int j = 1; j < size; j++)
            {
                int newHashVal = (hashVal + (j * j)) % size;
                if (hashTable[newHashVal] == -1)
                {
                    hashTable[newHashVal] = num;
                    break;
                }
                else
                {
                    cout << "Block is filled\n";
                }
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "a[" << i << "] : " << hashTable[i] << endl;
        }
    }

    void find(long long int num)
    {
        int f = 0;
        for (int i = 0; i < size; i++)
        {
            if (hashTable[i] == num)
            {
                cout << "Number found" << endl;
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            cout << "Not found" << endl;
        }
    }
};

int main()
{
    hashing h;
    long long int num,choice;
    cout<<"------MENU-----\n";
    cout<<"1)Insert number using Linear Probation\n2)Insert number using Quadratic Probation\n3)Display\n4)Search\n5)Exit\n";
    do
    {
        cout<<"Enter choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the number : ";
            cin>>num;
            h.linear(num);
            break;

        case 2:
            cout<<"Enter the number : ";
            cin>>num;
            h.quadratic(num);
            break;
        case 3:
            h.display();
            break;
        case 4:
            cout<<"Enter the number to find : ";
            cin>>num;
            h.find(num);
            break;
        case 5:
            cout<<"End";
            exit(0);        
        }
    } while (choice!=5);
    
}