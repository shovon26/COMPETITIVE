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
const ll mod = 1e9 + 7;
const int nax = 1e5+100;
ll n, W;
ll w[nax], v[nax];
ll mem[105][nax];
ll dp(ll pos,ll rem){
	if(pos == n){
		return 0;
	}
	if(mem[pos][rem] != -1)return mem[pos][rem];
	ll res1 = 0, res2 = 0;
	res1 = dp(pos+1, rem);
	if(w[pos] <= rem)
		res2 = v[pos] + dp(pos+1, rem - w[pos]);
    return mem[pos][rem] = max(res1, res2);
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   cin >> n >> W;
   
   for(int i=0; i<n; i++)cin >> w[i] >> v[i];
   Mem(mem, -1);
   cout << dp(0, W) << endl;
   
   return 0;
}
