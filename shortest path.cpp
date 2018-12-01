#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int vis[100];
void bfs(int s)
{
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0;i<adj[k].size();i++)
        {
            int v=adj[k][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                q.push(v);

            }
        }
    }
}
int main()
{
    int u,v,i,j,k;
    int n,e;
    cin>>n>>e;
    for(i=0;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
