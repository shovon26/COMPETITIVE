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
const int nax = 1e5+10;
int n, m;
vi adj[nax], cost[nax];
bool vis[nax];
vector<tuple<int, int, int> > mst;
priority_queue<tuple<int, int, int> > pq;
void Prims(){
	Mem(vis, 0);
	int cnt = 0;
	vis[0] = 1;
	int sz = SZ(adj[0]);
	for(int i=0; i<sz; i++) pq.push({-cost[0][i], 0, adj[0][i]});
	while(!pq.empty() && cnt < n){
		auto top_element = pq.top();
		pq.pop();
		int u = get<1>(top_element);
		int v = get<2>(top_element);
		int w = -get<0>(top_element);
		//debug(u, v);
		//cerr(w);
		if(!vis[v]){
			vis[v] = 1;
			cnt++;
			mst.pb({u, v, w});
			int sz1 = SZ(adj[v]);
			for(int i=0; i<sz1; i++) pq.push({-cost[v][i], v, adj[v][i]});
		}
	}
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   cin >> n >> m;
   for(int i=0; i<m; i++){
	   int u, v, w;
	   cin >> u >> v >> w;
	   adj[u].pb(v);
	   adj[v].pb(u);
	   cost[u].pb(w);
	   cost[v].pb(w);
   }
   Prims();
   for(auto x : mst){
	   cout << get<0>(x) << " " << get<1>(x) << " " << get<2> (x) << endl;
   }
   return 0;
}
/*
* input
4 4
0 1 2
1 2 2
2 3 10
0 3 5

* output
0 1 2
1 2 2
0 3 5

*/
