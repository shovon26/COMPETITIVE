#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define pi acos(-1.0)
#define pb push_back
#define clr(a) memset(a,0,sizeof a)
#define reset(a) memset(a,-1,sizeof a)
#define pii pair<int,int>
using namespace std;
const ll sz=1000003;
const ll mod=1e9+7;
int fx[]= {1,0,-1,0};
int fy[]= {0,1,0,-1};

ll inv[sz],mult[sz],invmult[sz];

ll gcd(ll a,ll b)
{
    return __gcd(a,b);
}

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

ll calculation()
{
   int i,j;
   for(i=1;i<=sz;i++)
   {
       ll x,y;
       ll val=extend_gcd(mod,i,x,y);
       if(y>0)inv[i]=y%mod;
       else   inv[i]=(y+mod)%mod;
   }
   mult[0]=1;
   for(i=1;i<=sz;i++)
   {
       mult[i]=mult[i-1]*i;
       mult[i]%=mod;
   }
   invmult[0]=1;
   for(i=1;i<=sz;i++)
   {
       invmult[i]=invmult[i-1]*inv[i];
       invmult[i]%=mod;
   }
   return 0;
}

ll a[sz],en[sz];
ll getans(ll l,ll r)
{
    ll ans=0,i;
    for(i=0;i<min(l,r-1)+1;i++)
    {
        ans+=combination(l,i)*combination(r,i+1);
        ans%=mod;
    }
    return ans;
}

int main()
{
    calculation();
   ll i,j,k,l,m,tc=0,t,n;
   cin>>t;
   while(t--)
   {
       cin>>n;
       for(i=0;i<n;i++)cin>>a[i];
       sort(a,a+n);
       ll ans=1;
       for(i=0;i<n-1;i++)
       {
           ans*=2;
           ans%=mod;
       }
       for(i=0;i<n;i++){
        en[a[i]]=i;
       }
       ll r;
       for(i=0;i<n;i++)
       {
           l=i;
           r=n-i-1;
           ans+=getans(l,r);
           l=i;
           r=n-en[a[i]]-1;
           ans-=getans(l,r);
       }
       ans%=mod;
       ans+=mod;
       ans%=mod;
       cout<<ans<<endl;
   }
    return 0;

}


