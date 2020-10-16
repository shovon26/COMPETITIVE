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
///Tiling DP Problem
///2 X N matrix with no rotation
///We have two kinds of dominoes,one is 2X1 and another is 2X2.We have to fillup the tiles with these dominoes
ll mem[nax];
ll dp(int pos){
	if(pos == 1)return 1;
	if(pos == 2)return 2;
	if(mem[pos] != -1)return mem[pos];
	return mem[pos] = dp(pos-1) + dp(pos - 2);
}
///Tiling DP Problem
///2 X N matrix with rotation possible
ll mem[nax];
ll dp(int pos){
	if(pos == 1)  return 1;
	if(pos == 2)  return 3;
	if(mem[pos] != -1) return mem[pos];
	return mem[pos] = dp(pos-1) + dp(pos - 2) + dp(pos-2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int col; cin >> col;
	Mem(mem, -1);
	
	cout << dp(col) << endl;
	
	return 0;
}
