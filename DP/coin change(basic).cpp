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
const int nax = 105;
const int inf = 1e9;
int coin[nax];
int mem[nax][nax];
int n, W;
///Recursive
int dp(int pos, int rem){
	if(rem < 0)return inf;
	if(pos == n){
		if(rem == 0)return 0;
		else return inf;
	}
	
	if(mem[pos][rem] != -1)return mem[pos][rem];
	debug(pos, rem);
	return mem[pos][rem] = min(1+dp(pos, rem - coin[pos]), dp(pos+1, rem));
	
}

///Iterative

int evaluate_table(int pos,int rem){
	if(rem < 0)return inf;
	if(pos == n){
		if(rem == 0)return 0;
		return inf;
	}
	return mem[pos][rem];
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   cin >> n >> W;
   for(int i=0; i<n; i++)cin >> coin[i];
   Mem(mem, -1);
   cout << dp(0, W) << endl; 
   Mem(mem, 0);
   
   ///Iterative
   for(int i=n-1; i>=0; i--){
	   for(int cur=0; cur<=W; cur++){
		   mem[i][cur] = min(1+evaluate_table(i+1, cur-coin[i]), evaluate_table(i+1, cur));
	   }
   }
   cout << mem[0][W] << endl;
   return 0;
}
