/*Problem link:
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3301/
Problem name:Valid Parenthesis String
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
const ll mod = 998244353;
const ll sz = 2 * 1e5 + 5, inf = 2 * 1e18 + 10;

bool isValidParanthesis(string s)
{
	stack<pair<char, int> >open, star,close1;
	queue<pair<char, int> >close,star1;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(') {
			open.push({s[i], i});
			continue;
		}
		if (s[i] == '*') {
			star.push({s[i], i});
			star1.push({s[i], i});
			continue;
		}
		if (s[i] == ')') {
			close.push({s[i], i});
			continue;
		}
	}
	int len1 = open.size();
	int len2 = star.size();
	int len3 = close.size();
	if ((len1 + len2) < len3 || (len3 + len2) < len1)return false;
	char ch, x;
	int id1, id2, idx1, idx2;
	bool f1 = 0, f2 = 0;
	
	if (open.size() > 0 && close.size() > 0) {
		while (!open.empty()) {

			ch = open.top().first;
			id1 = open.top().second;
			x = close.back().first;
			id2 = close.back().second;

			if (id2 < id1) {
				//cerr(id2);
				return false;
			
			}
			//cerr(ch); cerr(id1); cerr(x); cerr(id2);
			open.pop();
			close.pop();
			if (open.size() == 0) {
				f1 = 1; break;
			}
			if (close.size() == 0) {
				f2 = 1; break;
			}
		}
		//cerr(f1); cerr(f2);
	}

	else if (open.size() == 0)
	{
		char c1, c2;
		int i1, i2;
		while (!close.empty())
		{
			c1 = close.front().first;
			i1 = close.front().second;
			i2 = star1.front().second;
			///cerr(i1);cerr(i2);
			if (i2 > i1)return false;
			close.pop(); star1.pop();
		}
		return true;
	}
	else if (close.size() == 0)
	{
		char c1, c2;
		int i1, i2;
		while (!open.empty())
		{
			c1 = open.top().first;
			i1 = open.top().second;
			i2 = star.top().second;
			//cerr(i1);cerr(i2);
			if (i2 < i1)return false;
			open.pop(); star.pop();
		}
		return true;
	}

	
	if (f1) {
		char c1, c2;
		int i1, i2;
		if (len2 < close.size())return false;
		while (!close.empty())
		{
			c1 = close.front().first;
			i1 = close.front().second;
			c2 = star.top().first;
			i2 = star.top().second;
			if (i2 > i1)return false;
			close.pop(); star.pop();
		}
	}
	else if (f2)
	{
		char c1, c2;
		int i1, i2;
		if (len2 < open.size())return false;
		while (!open.empty())
		{
			c1 = open.top().first;
			i1 = open.top().second;
			c2 = star.top().first;
			i2 = star.top().second;
			if (i2 < i1)return false;
			open.pop(); star.pop();
		}
	}
    
	if (open.size() == 0 && close.size() == 0)return true;
	else return false;

}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	cout << isValidParanthesis(s) << '\n';

	return 0;
}

///(()*)(()((())()))(*)((((())*())))()(((()((()(*()))
