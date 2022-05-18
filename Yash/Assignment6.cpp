#include<iostream>
#include<string>
using namespace std;
class gp
{
  public:
  int v1,e,a,i,j; 
  int admj[20][20];
  string city[10];
  gp()
  {
      v1=e=a=i=j=0;
      for(i=0; i<20; i++)
      {
          for(int j=0; j<20; j++)
          {
              
            admj[i][j]=0;
              
          }
      }
  }
  void insert()
  {
      cout<<"Enter the number of vertices ";cin>>a;
      for (i=0; i<a; i++)
      {
          cout<<"Enter the name of the city ";cin>>city[i];
      }
      cout<<"\nEnter the time duration for flight between two cities in hrs, if not enter 0"<<endl;
      for(i=0; i<a; i++)
      {
          for(int j=i+1; j<a; j++)
          {
              cout<<"\nEnter the time duration between "<<city[i]<<" and "<<city[j]<<" ";cin>>e;
              admj[i][j]=admj[j][i]=e;
          }
      }
      
  }
  void display()
  {
      cout<<"\nAdjacency Matrix ";
      cout<<endl;
      for (int i=0; i<a; i++)
      {
          cout<<"\t"<<city[i];
      }
      cout<<endl;
      for (int i=0; i<a; i++)
      {
          cout<<city[i]<<"\t";
          for(int j=0; j<a; j++)
          {
              cout<<admj[i][j]<<"\t";
          }
          cout<<endl;
      }
      
      cout<<"\nAdjacency list "<<endl;
      for (int i=0; i<a; i++)
      {
          for (int j=i+1; j<a; j++)
          {
              if (admj[i][j]!=0 && admj[j][i]!=0)
              {
                  cout<<city[i]<<"-->"<<city[j]<<endl;
              }
          }
      }
  }
  
};
int main()
{
    cout<<"Welcome to represent graph using adjacency matrix "<<endl;
    gp g;
    g.insert();
    g.display();
    return 0;
}
