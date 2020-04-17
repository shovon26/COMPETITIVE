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
	int balance = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '(' || s[i] == '*')balance++;
		else if (s[i] == ')')
		{
			balance--;
			if (balance == -1)return false;
		}
	}
	balance = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == ')' || s[i] == '*')balance++;
		else if (s[i] == '(')
		{
			balance--;
			if (balance == -1)return false;
		}
	}
	return true;
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
