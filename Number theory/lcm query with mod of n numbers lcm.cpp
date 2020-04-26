#include<bits/stdc++.h>
#define ll long long int
#define ss second
#define ff first
#define Mem(x,val) memset(x,val,sizeof x)
#define pb push_back
#define all(v) v.begin(),v.end()
#define unik(v)  v.erase(unique(v.begin(),v.end()),v.end())
#define cerr(x) cerr << __LINE__ << " th Line : " << #x << " = " << x << "\n"
using namespace std;
typedef pair<int, int> pi32;
typedef pair<ll, ll> pi64;
typedef vector<int> vi32;
typedef vector<ll> vi64;
const ll mod = 1e9 + 7;
const ll sz = 1e7, inf = 1e9 + 7;
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

int prime[sz];

void sieve()
{
	prime[0] = prime[1] = 1;
	for (int i = 2; i <= sz; i++)prime[i] = i;
	for (int i = 4; i <= sz; i += 2)prime[i] = 2;

	for (int i = 3; i * i <= sz; i += 2) {
		if (prime[i] == i) {
			for (int j = i * i; j <= sz; j += i) {
				if (prime[j] == j)prime[j] = i;
			}
		}
	}
}

ll get_LcmModulo(ll n, ll m)
{
	vi64 vc;
	vi64 a; a.pb(n); a.pb(m);
	unordered_map<ll, ll>ans;
	for (ll i = 0; i < 2; i++) {
		ll num = a[i];
		unordered_map<ll,ll>temp;
		while (num > 1) {
			ll factor = prime[num];
			temp[factor]++;
			num /= factor;
		}
		for (auto it : temp) {
			ans[it.ff] = max(ans[it.ff], it.ss);
		}

		ll res = 1;
		for (auto it : ans) {
			res = res * (bigmod(it.ff, it.ss, mod));
		}
		if (res < 0)res += mod;
		vc.pb(res);
	}
	return vc.back();
}



ll lcm(ll n, ll m) {
	return (n * m) / __gcd(n, m);
}

ll arr[sz];
ll tree[6 * sz];

void build(ll node, ll start, ll end)
{
	if (start == end)
	{
		tree[node] = arr[start] ;
		return;
	}

	ll mid = (start + end) / 2;

	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	ll left_lcm = tree[2 * node] ;
	ll right_lcm = tree[2 * node + 1] ;

	tree[node] = get_LcmModulo(left_lcm, right_lcm);
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
	if (end < l || start > r)
		return 1;

	if (l <= start && r >= end) {
		//cerr(tree[node]);
		return tree[node];
	}

	ll mid = (start + end) / 2;
	ll left_lcm = query(2 * node, start, mid, l, r);
	ll right_lcm = query(2 * node + 1, mid + 1, end, l, r);
	ll ans = get_LcmModulo(left_lcm, right_lcm);
	//cerr(ans);
	//if (ans < 0)ans += mod;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sieve();
	/*ll n,m;cin>>n>>m;
	cout<<get_LcmModulo(n,m);*/

	ll n; cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];

	build(1, 0, n - 1);

	int q; cin >> q;
	while (q--) {
		ll l, r; cin >> l >> r;
		l--; r--;
		cout << query(1, 0, n - 1, l, r) << '\n';
	}

	return 0;
}
