#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int sz = 2e5 + 10;
ll BIT[sz], a[sz], n,q;
void update(int x, int val)
{
	for (; x <= n; x += x & -x)
		BIT[x] += val;
}
ll query(int x)
{
	ll sum = 0;
	for (; x > 0; x -= x & -x)
		sum += BIT[x];
	return sum;
}

int main()
{
	cin>>n>>q;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		update(i, a[i]);
	}
	while (q--)
	{
		int type; cin >> type;
		if (type == 1) {
			int id, val; cin >> id >> val;
			update(id, -a[id]);
			update(id, val);
			a[id] = val;
//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		}
		else {
			int l, r; cin >> l >> r;
			ll ans = query(r) - query(l - 1 );
			cout << ans << "\n";
		}
	}
	return 0;
}
