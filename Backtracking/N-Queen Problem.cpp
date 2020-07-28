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
const int MX = 20;

//N-Queen Problem
int queen[MX]; ///queen[i] =  column number of ith row
int column[MX];
int diagonal1[2*MX];
int diagonal2[2*MX];

void Nqueen(int idx,int n){
	if(idx == n+1){
		for(int i=1;i<=n;i++){
			cout<<i<<' '<<queen[i]<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(column[i] || diagonal1[i+idx] or diagonal2[i-idx+n])continue;
		queen[idx] = i;
		column[i] = diagonal1[i+idx] = diagonal2[i-idx+n] = 1;
		Nqueen(idx+1,n);
		column[i] = diagonal1[i+idx] = diagonal2[i-idx+n] = 0;
	}
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   int n,m;
   cin>>n>>m;
   Mem(column,0);
   Mem(diagonal1,0);
   Mem(diagonal2,0);
   Nqueen(n,m);  // for 8-queen call with 1,8
 
   return 0;
}
