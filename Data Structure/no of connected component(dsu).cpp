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
const int MX = 2*1e6+10;

int edges[MX][2];
int parent[MX];
int n,m;
int find(int node){
	if(parent[node] == node)return node;
	return parent[node] = find(parent[node]);
}
int CountComponents(){
	int count = n;
	for(int i=0;i<m;i++){
		int u = edges[i][0];
		int v = edges[i][1];
		int x = find(u);
		int y = find(v);
		if(x != y){
			count--;
			parent[y] = x;
		}
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++)parent[i] = i;
    
    for(int i=0; i<m; i++){
		for(int j=0; j<2; j++)cin>>edges[i][j];
	}
	cout<<CountComponents()<<endl;	
	
    return 0;
}
