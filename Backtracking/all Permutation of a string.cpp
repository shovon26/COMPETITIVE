//Resourse : https://www.youtube.com/watch?v=GuTPwotSdYw
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
const int MX = 100;

void Permutation(string s,int l,int r){
	if(l == r){
		cout<<s<<endl;
		return ;
	}
	for(int i=l; i<=r; i++){
		swap(s[l],s[i]);
		Permutation(s,l+1,r);
		swap(s[l],s[i]);
	}
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   string s;cin>>s;
   int l=0,r=SZ(s)-1;
   Permutation(s,l,r);
   return 0;
}


