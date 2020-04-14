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
typedef pair<int, int> pii;
const ll mod = 998244353;
const ll sz = 1e5 + 10, inf = 1e12 + 10;

bool cmp(string &s1, string &s2)
{
	return s1.size() < s2.size();
}
bool ok(string words, string str)
{
	int len1 = words.size();
	int len2 = str.size();
	for (int i = 0; i <= len1 - len2 ; i++)
	{
		int j;
		for (j = 0; j < len2; j++)
		{
			if (words[i + j] != str[j])break;
		}
		if (j == len2)return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*
	string words, str;
	cin >> words >> str;
	cout << ok(words, str);*/
	
	int n;
	cin >> n;
	string words[n + 2];
	for (int i = 0; i < n; i++)cin >> words[i];

	sort(words, words + n, cmp);
	vector < string> ans;
	for(auto i:words)
	{
		for(auto j:words)
		{

			if(i==j)continue;
			if(j.find(i)!=-1) ///check weather a string is substring of another from words string array
			{
				ans.pb(i);break;
			}
		}
	}

	for (string &x : ans)cout << x << '\n';

	return 0;
}
