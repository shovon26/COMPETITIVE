struct DSU {
	vector<int>par, sz;
	int cnt = 1;
	DSU(int n) : par(n+1), sz(n, 1) { //1-based indexing
		for(int i=1; i<=n; i++)par[i] = cnt++;
	}
	int find(int x){
		return (x == par[x] ? x : (par[x] = find(par[x])));
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
	bool unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return false;
		sz[x] += sz[y];
		par[y] = x;
		return true;
	}
	int size(int x){
		return sz[find(x)];
	}
};

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   DSU D(n);
   return 0;
}
