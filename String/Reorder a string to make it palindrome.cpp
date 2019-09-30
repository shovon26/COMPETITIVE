#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll sz = 2e5 + 5, mod = 1e9 + 7;
int a[sz], b[sz];
int fr[sz];
int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	map<char, int>mp;
	for (char ch : s)mp[ch]++;

	int cnt = 0;
	for (auto it : mp) {
		if (it.second % 2)cnt++;
	}
	if (cnt > 1) {
		cout << "NO SOLUTION\n";
		exit(0);
	}

	vector<pair<char, int> > v, vc, vk;

	for (auto it : mp)v.pb({it.first, it.second});

	char cc;
	bool f = 0;
	int to;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second % 2)
		{
			f = 1;
			to = v[i].second;
			cc = v[i].first;
			break;
		}
	}


	if (!f) {
		string ans = "";
		for (int i = 0; i < v.size(); i++) {
			for (int cnt = 1; cnt <= v[i].second / 2; cnt++) {
				ans += v[i].first;
			}
		}
		string rev = ans;
		reverse(rev.begin(), rev.end());
		ans += rev;
		cout << ans << "\n";
	}
	else {
		string ans = "";
		for (int i = 0; i < v.size(); i++) {
			if (cc == v[i].first)continue;
			for (int cnt = 1; cnt <= v[i].second / 2; cnt++) {
				ans += v[i].first;
			}
		}
		string rev = ans;
		reverse(rev.begin(), rev.end());
		for (int i = 0; i < to; i++)ans += cc;
		ans += rev;
		cout << ans << "\n";

	}

	return 0;
}

