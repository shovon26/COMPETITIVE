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
const int nax = 1000+100;
// Longest Common Subsequence
int mem[nax][nax];
string a, b;
int lenA, lenB;
int dp(int pA,int pB){
	if(pA == lenA || pB == lenB)return 0;
	if(mem[pA][pB] != -1) return mem[pA][pB];
	if(a[pA] == b[pB]) mem[pA][pB] = 1 + dp(pA+1, pB+1);
	else mem[pA][pB] = max(dp(pA+1, pB), dp(pA, pB+1));
	return mem[pA][pB];
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   while(cin >> a){
	   cin >> b;
	   lenA = SZ(a);
	   lenB = SZ(b);
	   Mem(mem, -1);
	   cout << dp(0, 0) << endl;
   }
   
   return 0;
}
