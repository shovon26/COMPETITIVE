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
const int inf = 1e9;
const int nax = 1e6+1;

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   int n, x;
   cin >> n >> x;
   vi coin(n);
   for(int i=0; i<n; i++)cin >> coin[i];
   vi mem(x+1, inf);
   mem[0] = 0;
   for(int i=1; i<=x; i++){
	   for(int j=0; j<n; j++){
		   if((i - coin[j]) >= 0) mem[i] = min(mem[i], mem[i-coin[j]] + 1);
	   }
   }
   cout << ( mem[x] == inf ? -1 : mem[x]) << endl;
   return 0;
}
