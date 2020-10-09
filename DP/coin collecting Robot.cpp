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
const int nax = 1000+5;
// Coin Collecting Robot
int mem[nax][nax];
int n, m;
int coin[nax][nax];
int dp(int r,int c){
	if(r == n && c == m)return coin[n][m];
	//debug(r, c);
	if(mem[r][c] != -1)return mem[r][c];
	mem[r][c] = 0;
	if(c < m) mem[r][c] =coin[r][c] + dp(r, c+1);
	if(r < n) mem[r][c] = max(mem[r][c], coin[r][c] + dp(r+1, c));
	return mem[r][c];
}
//With visited Array
bool vis[nax][nax];
int DP(int r, int c){
	if(r == n && c == m)return coin[n][m];
	//debug(r, c);
	if(vis[r][c] == 1)return mem[r][c];
	vis[r][c] = 1;
	if(c < m) mem[r][c] =coin[r][c] + dp(r, c+1);
	if(r < n) mem[r][c] = max(mem[r][c], coin[r][c] + dp(r+1, c));
	return mem[r][c];
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   cin >> n >> m;
   for(int i=1; i<=n; i++){
	   for(int j=1; j<=m; j++)cin >> coin[i][j];
   }
   Mem(mem, -1);
   int tc; cin >> tc;
   while(tc--){
	   int r, c; cin >> r >> c;
	   cout << dp(r, c) << endl;
   }
   
   return 0;
}
