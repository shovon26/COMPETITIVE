///Find the longest palindromic substring inside a string
///cses.fi longest palindrome
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int sz = 1100000 + 10;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manachar(string s)
{
	string x = "@#";
	for (auto c : s)
		x.push_back(c), x.push_back('#');
	x.push_back('$'); s = x;
	int n = s.size();
	int l = 0, r = 0; vector<int>pp(n);
	for (int i = 0; i < n; i++)
	{
		pp[i] = min(r - i, pp[l + r - i]);
		while (s[i - pp[i]] == s[i + pp[i]])pp[i]++;
		if (i + pp[i] > r)l = i - pp[i], r = i + pp[i];
	}
	for (int i = 2; i < n - 1; i += 2)
		od.push_back(pp[i] - 1);
	for (int i = 3; i < n - 1; i += 2)
		ev.push_back(pp[i] - 1);
}


int main()
{

	string s; cin >> s;
	manachar(s);

	int id_odd=-1, id_even=-1;
	int mx1 = 0, mx2 = 0;

	for (int i = 0; i < od.size(); i++) {
		if (od[i] > mx1) {
			mx1 = od[i];
			id_odd = i;
		}
	}
	//cout << mx1 << " " << id_odd << "\n";
	for (int i = 0; i < ev.size(); i++) {
		if (ev[i] > mx2) {
			mx2 = ev[i];
			id_even = i;
		}
	}

	//cout << mx2 << " " << id_even << "\n";

	if(mx1>mx2)
	{
		string ans;
		int hf=mx1/2;
		for(int i=id_odd-hf;i<=id_odd+hf;i++)ans+=s[i];
		cout<<ans<<"\n";
	}
	else{
		string ans;
		int hf=mx2/2;
		for(int i=id_even-hf+1;i<=id_even+hf;i++)ans+=s[i];
		cout<<ans<<"\n";
	}


	return 0;
}
