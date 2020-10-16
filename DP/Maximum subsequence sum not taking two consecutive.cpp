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
const ll mod = 1000003;
const int nax = 10000+10;
///Maximum subsequence sum
int mem[nax];
int n;
int a[nax];
int vis[nax];
int dp(int pos){  ///Way 1
	if(pos >= n) return 0;
	if(vis[pos])return mem[pos];
	vis[pos] = 1;
	return mem[pos] = max(dp(pos+2) + a[pos], dp(pos+1));
}

///Maximum subsequence sum
int mem[nax][2];
int arr[nax];
int vis[nax][2];
int n;
int dp(int pos, bool prev){  ///Way 2
	if(pos == n+1) return 0;
	if(vis[pos][prev])return mem[pos][prev];
	vis[pos][prev] = 1;
	if(prev == 0){ // dont take previous value
		int val1 = dp(pos+1, 1) + arr[pos];
		int val2 = dp(pos+1, 0);
		return mem[pos][prev] = max(val1, val2);
	}
	else{  //Already taken prev value,so just go to next position
		int val = dp(pos+1, 0);
		return mem[pos][prev] = val;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)cin >> a[i];
	Mem(vis, 0);
	cout << dp(0) << endl;  ///Way 1
	
	return 0;
}
