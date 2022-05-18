#include<iostream>
#include<string>
#include<queue>
using namespace std;
int admj[50][50]={0,0};
int visited[50]={0};
void dfs(int s, int v, string arr[])
{
	visited[s]=true;
	cout<<arr[s]<<" ";
	for (int i=0; i<v; i++)
	{
		if (admj[s][i] && !visited[i] )
		{
			dfs(i,v,arr);
		}
	}
}
void bfs(int s, int v, string arr[])
{
	bool visited[v];
	for (int i=0; i<v; i++)
	{
		visited[i]=false;
	}
	int v2;
	queue<int>bfsq;
	if(!visited[s])
	{
		cout<<arr[s]<<" ";
		visited[s]=true;
		bfsq.push(s);
		while(!bfsq.empty())
		{
			v2=bfsq.front();
			for (int i=0; i<v; i++)
			{
				if (admj[v2][i] && !visited[i] )
				{
					cout<<arr[i]<<" ";
					visited[i]=true;
					bfsq.push(i);
				}
			}
			bfsq.pop();
		}
	}
}

			
int main()
{
	int v1,c;
	cout<<"Enter the number of vertices :";cin>>v1;
	string city[v1];
	for (int i=0; i<v1; i++)
	{
		cout<<"Enter the name of the cities :"<<i<<" ";cin>>city[i];
	}
	cout<<"Enter the distance between cities :";
	for (int i=0; i<v1; i++)
	{
		for (int j=i+1; j<v1; j++)
		{
			cout<<"\nEnter the distance between "<<city[i]<<" and "<<city[j]; cin>>c;
			admj[i][j]=admj[j][i]=c;
		}
	}
	
	cout<<endl;
	for (int i=0; i<v1; i++)
	{
		cout<<"\t"<<city[i];
	}
	cout<<endl;
	for (int i=0; i<v1; i++)
	{
		cout<<city[i]<<"\t";
		for (int j=0; j<v1; j++)
		{
			cout<<admj[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Enter the starting vertex by writing the index number of the city";
	int n; cin>>n;
	cout<<"DFS" <<endl;
	dfs(n,v1,city);
	cout<<endl;
	cout<<"BFS"<<endl;
	bfs(n,v1,city);
    return 0;
}
	