
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int n, vector<int> adj[])
{
    // vector<int> ans;
    vector<int> vis(n+1,0);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto it:adj[curr])
        {
            if(vis[it]==0)
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
}

void helper(int curr,vector<int>& vis, vector<int> adj[])
{
    vis[curr]=1;
    cout<<curr<<" ";
    for(auto it:adj[curr])
    {
        if(vis[it]==0)
        {
            helper(it,vis,adj);
        }
    }
}

void dfs(int n, vector<int> adj[])
{
    // vector<int> ans;
    vector<int> vis(n+1,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            helper(i,vis,adj);
        }
    }
    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
}

int main()
{
    int n, m;
    cout << "Enter the no. of vertex : ";
    cin >> n;
    cout << "Enter the no. of edges : ";
    cin >> m;
    vector<int> vis(n + 1, 0);
    vector<int> adj[n];
    cout << "Enter the 2 edges : \n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Graph Traversal :\n";
    cout << "1)BFS Traversal\n2)DFS Traversal\n3)Exit\n";
    int ch;
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "The BFS Traversal is : ";
            bfs(n, adj);
            cout << endl;
            break;
        case 2:
            cout << "The DFS Traversal is : ";
            dfs(n, adj);
            cout << endl;
            break;
        case 3:
            cout << "End";
            exit(0);
            break;
        }
    } while (ch != 3);
}