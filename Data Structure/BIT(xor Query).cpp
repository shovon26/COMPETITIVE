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
const int nax = 300000+10;
ll BIT[nax];
ll a[nax];
ll n, q;
void update(ll x, ll val)
{
	for (; x <= n; x += x & (-x))
		BIT[x] ^= val;
}
ll query(ll x)
{
	ll sum = 0;
	for (; x > 0; x -= x & (-x))
		sum ^= BIT[x];
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> q;
	Mem(BIT, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i, a[i]);
	}
	while (q--)
	{
		int type; cin >> type;
		if (type == 1) {
			ll id, val; cin >> id >> val;
			a[id] ^= val;
			update(id, val);
			//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
			//cout << endl;
		}
		else {
			ll l, r; cin >> l >> r;
			ll ans = query(r) ^ query(l - 1);
			cout << ans << "\n";
		}
	}
	return 0;
}

