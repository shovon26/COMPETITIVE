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

int in[sz], out[sz];
int TIME = 1;
void dfs(int node)
{
	vis[node] = 1;
	in[node] = TIME++;
	for (int child : adj[node])
	{
		if (!vis[child])dfs(child);
	}
	out[node] = TIME++;
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
	Mem(in, 0); Mem(out, 0);
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << "In time of node " << i << " = " << in[i] << ' ' << "Out time of Node " << i << " = " << out[i] << '\n';
	}
	cout << '\n';
	return 0;

}
