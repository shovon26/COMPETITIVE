#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
bool vis[100];
int pred[100],dist[1000];
void add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfs(int src,int dest,int v)///v=no of vertex
{
    list<int>q;

    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
        pred[i]=-1;
        vis[i]=false;
    }

    vis[src]=true;
    dist[src]=0;
    q.push_back(src);
    while(!q.empty())
    {
      int k=q.front();
      q.pop_front();
      for(int i=0;i<adj[k].size();i++)
      {
          int v=adj[k][i];
          if(!vis[v])
          {
              vis[v]=1;
              dist[v]=dist[k]+1;
              pred[v]=k;
              q.push_back(v);

              if(v==dest)return true;
          }
      }
    }
    return false;
}

void print(int s,int dest,int v)
{
    if(bfs(s,dest,v)==false)
    {
        cout<<"Not connected"<<endl;
        return ;
    }
    vector<int>path;
    int crawl=dest;
    path.push_back(crawl);

    while(pred[crawl]!=-1)
    {
        path.push_back(pred[crawl]);
        crawl=pred[crawl];
    }
cout<<"Shortest Path Distance : "<<dist[dest]<<endl;
cout<<"Path is :: ";
for(int i=path.size()-1;i>=0;i--)
{
    cout<<path[i]<<" ";
}
}
int main()
{
      int n,e,u,v,i,j,k;
      cin>>n>>e;
      for(i=0;i<e;i++)
      {
          cin>>u>>v;
          add_edge(u,v);
      }
      int src,dest;
      cout<<"Input Source and Destination :: ";
      cin>>src>>dest;
      print(src,dest,n);
    return 0;
}
