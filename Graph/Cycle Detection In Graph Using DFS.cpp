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
/*
For every visited vertex ‘v’, if there is an adjacent ‘u’ such that
u is already visited and u is not parent of v, then there is a cycle in graph. If we don’t find
such an adjacent for any vertex, we say that there is no cycle.

In simple we can say that if a node has a back edge then there is a cycle in the graph.
*/
bool dfs(int src, int par = -1)
{
	vis[src] = 1;
	for (auto child : adj[src]) {
		if (!vis[child]) {
			if (dfs(child, src) == 1)
				return true;
		}
		else if (child != par) {
			return true;
		}
	}
	return false;
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

	Mem(vis, 0);

	cout << dfs(1, -1) << '\n';

	return 0;

}
