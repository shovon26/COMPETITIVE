/*
Problem Link::
https://codeforces.com/contest/450/problem/A
*/

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
const ll sz = 1e3 + 10, inf = 1e9 + 7;

int getId(vi32& v, int m)
{
	int n = v.size();
	deque<pair<int, int>>dq;
	for (int i = 0; i < n; i++)
	{
		dq.push_back({v[i], i});
	}

	while (!dq.empty())
	{
		int val = dq.front().ff;
		int id = dq.front().ss;
		if (dq.size() == 1)return id + 1;
		if (val <= m)dq.pop_front();
		else {
			dq.push_back({val - m, id});
			dq.pop_front();
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vi32 a(n);
	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << getId(a, m) << "\n";

	return 0;

}

/*7 3
6 1 5 4 2 3 1*/
