#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int sz = 2e5 + 10;
ll a[sz], tr[4 * sz];
void build(int node, int st, int ed) {
	if (st == ed) {
		tr[node] = a[st];
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int m = (st + ed) / 2;
	build(l, st, m);
	build(r, m + 1, ed);
	tr[node] = (tr[l] + tr[r]);
}

void update(int node, int st, int ed, int idx, int val) {
	if (st > idx || ed < idx)return ;
	if (st >= idx and ed <= idx) {
		tr[node] = val;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int m = (st + ed) / 2;
	update(l, st, m, idx, val);
	update(r, m + 1, ed, idx, val);
	tr[node] = (tr[l] + tr[r]);
}

ll query(int node, int st, int ed, int l, int r) {
	if (l > ed or r < st)return 0;
	if (st >= l and ed <= r)return tr[node];
	int left = 2 * node, right = 2 * node + 1;
	int mid = (st + ed) / 2;
	ll sum = (query(left, st, mid, l, r) + query(right, mid + 1, ed, l, r));
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
	while (q--)
	{
		int type; cin >> type;
		if (type == 1) {
			int id, val; cin >> id >> val;
			update(1, 1, n, id, val);
		}
		else {
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l, r) << "\n";
		}
	}
	return 0;
}
