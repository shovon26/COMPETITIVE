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
const ll mod = 1e9 + 7;
const int MX = 50;

bool taken[MX];
vector<char>res;
string s;
int r,n;

void backtrack(int start){
	if(SZ(res) == r){
		for(int i=0;i<r;i++)cout<<res[i];
		cout<<endl;
		return ;
	}
	for(int i=start;i<n;i++){
		if(!taken[i]){
			taken[i] = 1;
			res.pb(s[i]);
			backtrack(i+1);
			taken[i] = 0;
			res.pop_back();
		}
		while(s[i] == s[i+1])i++;  ///next one should start with a different character
	}
}

int main()
{
   while(cin>>s>>r){
	   Mem(taken,0);
	   n=SZ(s);
	   sort(all(s));
	   backtrack(0);
   }
   return 0;
}
