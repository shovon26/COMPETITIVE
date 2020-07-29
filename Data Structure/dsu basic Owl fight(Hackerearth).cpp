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
const int MX = 1e5+10;
int parent[MX];
int find(int node){
	if(parent[node] < 0)return node;
	else return parent[node] = find(parent[node]);
}
void Union(int a,int b){
	parent[a] = min(parent[a],parent[b]);
	parent[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)parent[i] = -i;
	
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u=find(u);
		v=find(v);
		if(u != v)Union(u,v);
	}
	int q; cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		
		int a=find(u);
		int b=find(v);
		if(a == b)cout<<"TIE\n";
		else{
			if(parent[a] < parent[b])cout<<u<<endl;
			else cout<<v<<endl;
		}
	}
   return 0;
}
