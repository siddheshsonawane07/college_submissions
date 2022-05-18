/*
BFS: Breadth first search
We first traverse through the sibling nodes
Using BFS, we can find the shortest distance between two nodes
BFS can be implemented using queue
We will push the 1st node into the queue data structure and mark it as visited. After this, we will find its adjacent nodes. If we get some unvisited node, we will simply push this adjacent node into the queue data structure
Now since the work of the 1st node is done, we will pop out this node from the queue. Now, this process goes on until the queue is not empty.
Time Complexity : O(N+E),N = Nodes , E = travelling through adjacent nodes


DFS: Depth first search
Start with a random node from graph
Make an array to keep track of visited nodes, once visited make that node as visited
Print this current node
Get  neighbour nodes and perform above steps recursively for each node deeply/depthly if node is unvisited.
Time complexity: O(N+E), Where N is the time taken for visiting N nodes and E is for travelling through adjacent nodes.

*/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

int matrix[50][50]={0,0};
int visited[50]={0};

void dfs(int s, int v, string arr[])
{
	visited[s]=1;
	cout<<arr[s]<<" ";
	for (int i=0; i<v; i++)
	{
		if (matrix[s][i] && !visited[i] )
		{
			dfs(i,v,arr);
		}
	}
}


void bfs(int s, int v, string arr[])
{
	bool visited[v] = {0};
	int node;
	queue<int>bfsq;

	if(!visited[s]) //checks if it is already visited
	{
		cout<<arr[s]<<" ";
		visited[s]=1; //marks it as visited
		bfsq.push(s); //pushes the node into queue
		while(!bfsq.empty())
		{
			node = bfsq.front();
			for (int i=0; i<v; i++)
			{
				if (matrix[node][i] && !visited[i] )
				{
					cout<<arr[i]<<" ";
					visited[i]=1;
					bfsq.push(i);
				}
			}
			bfsq.pop(); //deletes the printed element
		}
	}
}

			
int main()
{
	int vertices,edges;
	cout<<"Enter the number of vertices :";
    cin>>vertices;
	string city[vertices];

	for (int i=0; i<vertices; i++)
	{
		cout<<"Enter the name of the city "<<i+1<<" ";
        cin>>city[i];
	}
	// cout<<"Enter the distance between cities :";

	for (int i=0; i<vertices; i++)
	{
		for (int j=i+1; j<vertices; j++)
		{
			cout<<"\n Enter the distance between "<<city[i]<<" and "<<city[j]<<" "; 
            cin>>edges;
			matrix[i][j]=matrix[j][i]=edges;
		}
	}
	cout<<endl;
	
    for (int i=0; i<vertices; i++)
	{
		cout<<"\t"<<city[i];
	}
	cout<<endl;
	
    for (int i=0; i<vertices; i++)
	{
		cout<<city[i]<<"\t";
		for (int j=0; j<vertices; j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	    cout<<"Enter the starting vertex by writing the index number of the city: ";
	    int n; 
        cin>>n;
	    cout<<"DFS" <<endl;
	    dfs(n-1,vertices,city);
	    cout<<endl;
	    cout<<"BFS"<<endl;
	    bfs(n-1,vertices,city);
        return 0;
}
	