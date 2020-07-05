//Time Complexity : O(2^n * n)
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ss second
#define ff first
#define Mem(x,val) memset(x,val,sizeof x)
#define pb push_back
#define all(v) v.begin(),v.end()
#define unik(v)  v.erase(unique(v.begin(),v.end()),v.end())
#define cerr(x) cerr << __LINE__ << " th Line : " << #x << " = " << x << "\n"
#define debug(a,b) cerr << #a<<" = "<<a<<"   |   "<<#b<<" = "<<b<<'\n'
#define endl '\n'
#define SZ(a) ((int)a.size())
using namespace std;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod = 1e9 + 7;
const int MX = 100+10;

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   int n;
   cin>>n;
   vi a(n);
   for(int i=0;i<n;i++)cin>>a[i];
   vector<int>subset[1<<n];
   for(int mask=0;mask<(1<<n);mask++){
	   for(int i=0;i<n;i++){
		   if(mask & (1<<i))subset[mask].pb(a[i]);
	   }
   }
   
   for(int mask=0;mask<(1<<n);mask++){
	   for(int x:subset[mask])cout<<x<<" ";
	   cout<<endl;
   }
   
   return 0;
}
