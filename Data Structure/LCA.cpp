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
const int nax = 2e5+10;
const int LOG = 32;

vi adj[nax];
int level[nax];
int sptable[nax][LOG];
void dfs(int u, int par){
	sptable[u][0] = par;
	level[u] = level[par] + 1;
	for(auto x : adj[u]){
		if(x != par)dfs(x, u);
	}
}

void sparseTable(int n){
	for(int j=1; (1<<j) <= n; j++){
		for(int i=1; i<=n; i++){
			if(sptable[i][j-1] == -1)continue;
			sptable[i][j] = sptable[sptable[i][j-1]][j-1];
		}
	}
}

int lca(int x, int y){
	
	if(level[x] > level[y])swap(x, y);
	int dist = level[y] - level[x];
	for(int i=24; i>=0; i--){
		if((1<<i) <= dist){
			dist -= (1<<i);
			y = sptable[y][i];
		}
	}
	
	if(x == y)return x;
	for(int i=24; i>=0; i--){
		if(sptable[x][i] == sptable[y][i])continue;
		x = sptable[x][i];
		y = sptable[y][i];
	}
	return sptable[x][0];
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   int n, m; cin >> n;
   for(int i=1; i<=n; i++){
       cin >> m;
       for(int j=0; j<m; j++){
		   int x; cin >> x;
		   x++;
		   adj[i].pb(x);
		   adj[x].pb(i);
	   }
   }
  
   for(int i=1; i<=n; i++)Mem(sptable[i], -1);
   Mem(level, 0);
   dfs(1, -1);
   sparseTable(n);
   int q;
   cin >> q;
   while(q--){
	   int u, v;
	   
	   cin >> u >> v;
	   u++;
	   v++;
	   int ans = lca(u, v);
	   cout << (ans == 0 ? 0 : ans-1) << endl;
   }
   return 0;
}
