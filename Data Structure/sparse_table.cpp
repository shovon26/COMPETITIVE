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
const int nax = 55;
const int LOG = 25;
int a[nax];
int sptable[nax][LOG];

void sparseTable(int n){
	for(int j=1; (1<<j) <= n; j++){
		for(int i=1; i<=n; i++){
			if(i+(1<<j)-1 > n)break;
			sptable[i][j] = min(sptable[i][j-1], sptable[i+(1<<(j-1))+1][j-1]);
		}
	}
}

int Q(int l,int r){
	int lg = 31 - __builtin_clz(r-l+1);
	return min(sptable[l][lg], sptable[r-(1<<lg)+1][lg]);
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   int n; cin >> n;
   for(int i=1; i<=n; i++){
	   cin >> a[i];
	   sptable[i][0] = a[i];
   }
   sparseTable(n);
   for(int i=1; i<=n; i++){
	   for(int j=1; j<=2; j++)cout<<sptable[i][j] << ' ';
	   cout << endl;
   }
	   
   int q;
   cin >> q;
   while(q--){
	   int l, r;cin >> l >> r;
	   cout << Q(l, r) << endl;
   }
   
   return 0;
}
