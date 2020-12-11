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
int n, m, u, v, w, par[nax];
vector<tuple<int, int, int> > edge, mst;
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<2>(a) < get<2>(b);
}
int find(int a){
	if(par[a] == a) return a;
	return par[a] = find(par[a]);
}
void kruskal(){
	for(int i=0; i<n; i++)par[i] = i;
	sort(all(edge), cmp);
	for(auto p : edge){
		int pu = find(get<0>(p));
		int pv = find(get<1>(p));
		if(pu != pv){
			par[pu] = pv;
			mst.pb(p);
		}
	}
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n >> m;
   for(int i=0; i<m; i++){
	   cin >> u >> v >> w;
	   edge.pb({u, v, w});
   }
   kruskal();
   for(auto x : mst){
	   cout << get<0>(x) << " " << get<1>(x) << " " << get<2> (x) << endl;
   }
   return 0;
}
