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
typedef vector<vector<int>> vvi;
const ll mod = 1e9 + 7;
const int MX = 100;
//Total ncr combination is possible
int a[MX];
int n,r;

void Combination(int idx,int last){
	if(idx == r+1){
		for(int i=1;i<=r;i++)cout<<a[i]<<' ';
		cout<<endl;
		return;
	}
	for(int i=last+1; i<=n-r+idx;i++){ //r-idx <= n-i
		a[idx] = i;
		Combination(idx+1,i);
	}
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   cin>>n>>r;
   for(int i=1;i<=n;i++)cin>>a[i];
   
   Combination(1,0);
   
   return 0;
}

