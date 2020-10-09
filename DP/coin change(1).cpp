///lightoj - 1231
#include<bits/stdc++.h>
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
using ll = long long;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod = 100000007;
const int nax = 55;
ll a[nax], c[nax], n, k;
ll mem[55][1010];
ll dp(ll pos,ll rem){
   if(pos == n){
	   if(rem == 0)return 1;
	   else return 0;
   }
   if(mem[pos][rem] != -1) return mem[pos][rem];
   ll ans = 0;
   for(int cnt=0; cnt<=c[pos] && cnt*a[pos] <= rem; cnt++){
	   ans += dp(pos+1, rem - (cnt*a[pos]));
	   ans %= mod;
   }
   return mem[pos][rem] = ans % mod;
}
int main(){
   int _,tc = 0;
   cin >> _;while(_--){
	   cin >> n >> k;
	   for(int i=0; i<n; i++)cin >> a[i];
	   for(int i=0; i<n; i++)cin >> c[i];
	   Mem(mem, -1);
	   cout << "Case "<<++tc<<": "<< dp(0, k) << endl;
   }
   
   return 0;
}
