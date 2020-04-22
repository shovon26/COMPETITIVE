#include<bits/stdc++.h>
#define ll long long int
#define ss second
#define ff first
#define Mem(x,val) memset(x,val,sizeof x)
#define pb push_back
#define all(v) v.begin(),v.end()
#define unik(v)  v.erase(unique(v.begin(),v.end()),v.end())
#define cerr(x) cerr << __LINE__ << " th Line : " << #x << " = " << x << "\n"
using namespace std;
typedef pair<int, int> pi32;
typedef pair<ll, ll> pi64;
typedef vector<int> vi32;
typedef vector<ll> vi64;
const ll mod = 1e9 + 7;
const ll sz = 1e5 + 10, inf = 1e9 + 7;

vi32 adj[sz];
int vis[sz];
int dist[sz];
void dfs(int src)
{
	vis[src] = 1;
	cerr(src);
	for (auto x : adj[src]) {
		if (!vis[x]){
			dist[x]=dist[src]+1;
		    dfs(x);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int cnt = 0;
	Mem(vis, 0);
	Mem(dist,0);

	dfs(1); /// 1 is the source node
	for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
	return 0;

}
