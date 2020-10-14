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
const int nax = 1000000+5;
ll bigmod(ll a, ll b, ll m)
{
    if (b == 0 )return 1;
    if (b & 1)
    {
        return ((a % m) * (bigmod(a, b - 1, m))) % m;
    }
    else
    {
        ll tmp = bigmod ( a, b / 2, m );
        return ( tmp * tmp ) % m;
    }
}

ll modInverse(ll a, ll m)
{
    return bigmod(a, m-2, m);
}

ll fact[nax+10];
void factorize(){
	fact[1] = 1;
	for(int i=2; i<=1000000; i++){
		fact[i] = (i*fact[i-1]*1LL)%mod;
	}
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   factorize();
   int _;
   scanf("%d", &_);
   int tc = 0;
   while(_--){
	   int n, k;
	   scanf("%d %d", &n, &k);
	   if(n == k || k == 0){
		   printf("Case %d: 1\n", ++tc);
		   continue;
	   }
	   ll ans = 0;
	   ans = ((fact[k]%mod) * (fact[n-k]%mod)) % mod;
	   ans = modInverse(ans, mod);
	   ans = ((fact[n]%mod) * (ans%mod)) % mod;
	   printf("Case %d: %lld\n", ++tc, ans);
   }
   
   return 0;
}
