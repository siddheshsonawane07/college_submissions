
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int adj[50][50]={0,0};
int main()
{
    int n;
    cout<<"Enter the Number of Citites : ";
    cin>>n;
    string city[n];
    for(int i=0;i<n;i++)
    {
         cout<<"Enter name of city "<<i+1<<" : ";
         cin>>city[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cout<<"Enter distance between "<<city[i]<<" and "<<city[j]<<" : ";
            cin>>adj[i][j];
            adj[j][i]=adj[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<city[i]<<"\t";
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\n"
            <<city[i];
        for(int j=0;j<n;j++)
        {
            cout<<"\t"<<adj[i][j]<<"\t";
        }     
    }
}