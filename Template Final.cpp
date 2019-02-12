#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define pi acos(-1.0)
#define pb push_back
#define SC(a) scanf("%d",&a)
#define PR(a) printf("%d\n",a)
#define clr(a) memset(a,0,sizeof a)
#define reset(a) memset(a,-1,sizeof a)
#define pii pair<int,int>
using namespace std;
const ll sz=1000003;
const ll mod=1e9+7;
int fx[]= {1,0,-1,0};
int fy[]= {0,1,0,-1};
ll inv[sz],mult[sz],invmult[sz];
vector<ll>v,vc;
map<ll,ll>mp;
ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll ans=extend_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;

    return ans;
}

ll modInverse(ll a,ll m)
{
  ll x,y;
  ll g=extend_gcd(a,m,x,y);

  ll res=(x%m + m)%m;

  return res;
}

ll combination(ll n,ll r)
{
    if(n==r || r==0) return 1;
    if(n<r) return 0;
    ll ans=1;
    ans*=mult[n];
    ans%=mod;
    ans*=invmult[r];
    ans%=mod;
    ans*=invmult[n-r];
    ans%=mod;
    return ans;
}

ll bigmod(ll a,ll b,ll m)
{
    if (b==0 )return 1;
    if (b & 1)
    {
        return ((a%m)*(bigmod(a,b-1,m)))%m;
    }
    else
    {
        ll tmp = bigmod ( a, b / 2, m );
        return ( tmp * tmp ) % m;
    }
}

void Divisor(ll n)
{
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            v.pb(n/i);
        }
    }
    sort(v.begin(),v.end());
}


int a[sz];
void sieve()
{
    a[0]=a[1]=1;
    int i,j,s=sqrt(sz);
    for(i=4; i<=sz; i+=2) a[i]=1;
    for(i=3; i<=s; i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=sz; j+=2*i)
            {
                a[j]=1;
            }
        }
    }
}

bool cmp(vector<string>s,vector<string>p)
{
    int len1=s.size();
    int len2=p.size();
    return len1>len2;
}

ll vis[sz];
vector<ll>adj[sz];
void dfs(int u)
{
  vis[u]=1;
  for(int i=0;i<adj[u].size();i++)
  {
    int v=adj[u][i];
    if(vis[v]==0)
    {
      dfs(v);
    }
  }
}

int cost[sz];

void bfs(int s)
{
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
    int k=q.front();
    q.pop();
    for(int i=0;i<adj[s].size();i++)
    {
        int v=adj[s][i];
       if(vis[v]==0)
       {
           vis[v]=1;
           cost[v]=cost[k]+1;
           q.push(v);
       }
    }
}
}

int dp[1000][100];
vector<int>caplist[101];
int allmask;
ll Ways(ll mask,ll i) ///Bitmask DP
{
    if(mask==allmask) return 1;
    if(i>100) return 0;
    if(~dp[mask][i]) return dp[mask][i];
    ll wayss=Ways(mask,i+1);
    int sz=caplist[i].size();
    for(int j=0;j<sz;j++)
    {
        if(mask & (1<<caplist[i][j])) continue;
        else wayss+=Ways(mask | (1<<caplist[i][j]),i+1);
     wayss%=mod;
    }
    return dp[mask][i]=wayss;
}
int main()
{

    ll i,j,k,l,m,tc=0,t,n;
    int in;
    SC(in);
    PR(in);
    return 0;

}



