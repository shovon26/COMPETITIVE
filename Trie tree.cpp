#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll sz=1e5;
ll trie[60*sz+2][3],ss;

void add(ll x)
{
    ll now=0;
    for(ll i=30; i>=0; i--)
    {
        bool z=x&(1<<i);
        if(!trie[now][z])
            trie[now][z]=++ss;
        now=trie[now][z];
    }
}

ll query(ll x)
{
    ll now=0,ret=0;
    for(ll i=30; i>=0; i--)
    {
        bool z=x&(1<<i);
        if(trie[now][z^1])
        {
            ret|=(1<<i);
            now=trie[now][z^1];
        }
        else
            now=trie[now][z];
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,j,k;
    int t;
    cin>>t;
    while(t--)
    {
        memset(trie,0,sizeof(trie));
        ss=0;
        add(0);
        ll kk=0;
        cin>>n;
        ll ans=0;
        for(i=1; i<=n; i++)
        {
            cin>>k;
            kk^=k;
            ans=max(ans,query(kk));
            add(kk);
        }
        cout<<ans<<endl;

    }
    return 0;
}
///trie koribo
