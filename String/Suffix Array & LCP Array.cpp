/*
 * Resource : https://cp-algorithms.com/string/suffix-array.html
 * */

#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
const ll mod = 1e9 + 7;
const int MX = 35;
//Suffix Array

vector<int>SortCyclicShifts(string s){
	int n = SZ(s);
	const int alphabet = 256;
	vi p(n), c(n), cnt(max(alphabet,n), 0);
	for(int i=0; i<n; i++){
		cnt[s[i]]++;
	}
	for(int i=1; i<alphabet; i++){
		cnt[i] += cnt[i-1];
	}
	for(int i=0; i<n; i++){
		p[--cnt[s[i]]] = i;
	}
	c[p[0]] = 0;
	int classes = 1;
	for(int i=1; i<n; i++){
		if(s[p[i]] != s[p[i-1]])classes++;
		c[p[i]] = classes - 1;
	}
	
	vi pn(n), cn(n);
	for(int h=0; (1<<h)<n; h++){
		for(int i=0; i<n; i++){
			pn[i] = p[i] - (1<<h);
			if(pn[i] < 0)pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin()+classes, 0);
		for(int i=0; i<n; i++)cnt[c[pn[i]]]++;
		for(int i=1; i<classes; i++)cnt[i] += cnt[i-1];
		for(int i=n-1; i>=0; i--)p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for(int i=1; i<n; i++){
			pi cur = {c[p[i]] , c[(p[i] + (1<<h)%n)]};
			pi prev = {c[p[i-1]], c[(p[i-1] + (1<<h)%n)]};
			if(cur != prev)classes++;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	return p;
}

vi SuffixArray(string s){
	s += '$';
	vi Sorted_shifts = SortCyclicShifts(s);
	Sorted_shifts.erase(Sorted_shifts.begin());
	return Sorted_shifts;
}

vi lcpArray(string s,vi SufAr){
	int n = SZ(s);
	vi rank(n, 0);
	for(int i=0; i<n; i++)rank[SufAr[i]] = i;
	
	int k = 0;
	vi lcp(n-1, 0);
	for(int i=0; i<n; i++){
		if(rank[i] == n-1){
			k=0;
			continue;
		}
		int j = SufAr[rank[i] + 1];
		while(i+k<n && j+k<n && s[i+k] == s[j+k])k++;
		lcp[rank[i]] = k;
		if(k>0)k--;
	}
	return lcp;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   string s;cin>>s;
   vi SuffAr = SuffixArray(s);
   for(int x:SuffAr)cout<<x<<' ';
   cout<<endl;
   vi lcp = lcpArray(s,SuffAr);
   for(int x:lcp)cout<<x<<' ';
   cout<<endl;
   return 0;
}

