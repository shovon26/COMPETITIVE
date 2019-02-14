#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll sz=200000+10;

bool vis[sz];

vector<ll>adj[sz];
bool dfs(ll s,ll p)
{
    vis[s]=true;
    for(auto x: adj[s])
    {
        if(!vis[x])
        {
            if(dfs(x,s))return true;
        }
        else if(x!=p)return true;
    }
    return false;
}

int main()
{
     ll t,n,k;

     cin>>t;
     while(t--){

     cin>>n>>k;
    for(ll i=0;i<=sz;i++)adj[i].clear();
    memset(vis,0,sizeof vis);
     for(ll i=0;i<k;i++)
     {
         ll u,v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u);
     }


       ll ff=0;

     for(ll i=1;i<=n;i++)
     {
         if(!vis[i])
         {
            if(dfs(i,-1))ff=1;
         }
     }
     //cout<<ff<<endl;
     if(ff==1)cout<<"YES"<<endl;
     else cout<<"NO."<<endl;

     }
    return 0;
}






