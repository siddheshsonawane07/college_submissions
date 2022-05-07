#include <iostream>
#include <cstring>
using namespace std;
struct hash
{
string word;
string meaning;
int chain;
} obj[10];
void hash_initialization()
{
for (int i = 0; i < 10; i++)
{
obj[i].word = "-";
obj[i].meaning = "-";
obj[i].chain = -1;
}
}
void display()
{
for (int i = 0; i < 10; i++)
{
cout << obj[i].word << "-->" << obj[i].meaning << "-->" << obj[i].chain << endl;
}
}
int calculate(string word)
{
int key = 0;
for (int i = 0; i < word.length(); i++)
{
key = key + word[i];
}
return key % 10;
}
void collision(int key, string word, string meaning)
{
int i = 1;
while (((key + i) % 10) < 10)
{
if (obj[(key + i) % 10].word == "-")
{
obj[(key + i) % 10].word = word;
obj[(key + i) % 10].meaning = meaning;
obj[(key + i - 1) % 10].chain = (key + i) % 10;
break;
}
else
{
i++;
}
}
}
void insert()
{
string wd, mg;
cout << "Enter the word => ";
cin >> wd;
cout << "Enter the meaning => ";
cin >> mg;
int hash_key = calculate(wd);
if (obj[hash_key].word == "-")
{
obj[hash_key].word = wd;
obj[hash_key].meaning = mg;
}
else
{
collision(hash_key, wd, mg);
}
}
void find(string wd)
{
int hash_key = calculate(wd);
if (obj[hash_key].word == wd)
{
cout << "found" << endl;
cout << obj[hash_key].word << "-->" << obj[hash_key].meaning << endl;
}
else if (obj[hash_key].chain != -1)
{
int temp = obj[hash_key].chain;
while (true)
{
if (obj[temp].word == wd)
{
cout << "found" << endl;
cout << obj[temp].word << "-->" << obj[temp].meaning << endl;
break;
}
temp = obj[temp].chain;
}
}
else
{
cout << "Not Found" << endl;
}
}
void Del(string wd)
{
int hash_key = calculate(wd);
if (obj[hash_key].word == wd)
{
obj[hash_key].word = "-";
obj[hash_key].meaning = "-";
obj[hash_key].chain = -1;
}
else if (obj[hash_key].chain != -1)
{
int temp = obj[hash_key].chain;
while (true)
{
if (obj[temp].word == wd)
{
obj[temp].word = "-";
obj[temp].meaning = "-";
obj[temp].chain = -1;
break;
}
temp = obj[temp].chain;
}
}
else
{
cout << "Word Not Found" << endl;
}
}
int main()
{
int choice, n;
string wd_find, wd_Del;
hash_initialization();
do
{
cout << "==============Enter your choice==============" << endl;
cout << "1) Insert" << endl;
cout << "2) Find" << endl;
cout << "3) Delete" << endl;
cout << "4) Print" << endl;
cout << "5) Exit" << endl;
cin >> choice;
switch (choice)
{
case 1:
cout << "Enter how entries you want to make ";
cin >> n;
for (int i = 0; i < n; i++)
{
insert();
}
break;
case 2:
cout << "Enter the word to found => ";
cin >> wd_find;
find(wd_find);
break;
case 3:
cout << "Enter the word to be deleted =>";
cin >> wd_Del;
Del(wd_Del);
break;
case 4:
display();
break;
case 5:
break;
default:
cout << "Invalid choice" << endl;
break;
}
} while (choice < 5);
return 0;
}
