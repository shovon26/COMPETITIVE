#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const ll sz=505,inf=1e5;
vector<pii >adj[sz];
int n;
vector<int>dist(505,inf);
void dijkstra(int src)
{
  priority_queue<pii,vector<pii >,greater<pii >  >pq;
  
  pq.push({0,src});
  dist[src]=0;

  while(!pq.empty())
  {
    int u=pq.top().second;
    pq.pop();

    vector<pii> :: iterator it;
    for(it=adj[u].begin();it!=adj[u].end();++it)
    {
      int v=(*it).first;
      int weight=(*it).second;
      if(dist[v]>(dist[u]+weight))
      {
        dist[v]=dist[u]+weight;
        pq.push({dist[v],v});
      }
    }
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);    
  
   int u,v,w;
   cin>>n;
  for(int i=0;i<n;i++)
   {
    cin>>u>>v>>w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
   }
   int src;
   cin>>src;
   dijkstra(src);

   int q;
   cin>>q;
   while(q--)
   {
    int des;
    cin>>des;

    int res=dist[des];

    if(res==inf)cout<<"NO PATH"<<endl;
    else cout<<res<<endl;

   }
  return 0;
}
