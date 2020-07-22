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

int n;
void Print(int a[]){
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
}
bool taken[MX];
int a[MX];
void Backtrack(int idx){
	if(idx == n+1){
		Print(a);  
		return ;
	}
	for(int i=1; i<=n; i++){
		if(!taken[i]){
			taken[i] = 1;
			a[idx] = i;
			Backtrack(idx+1);  //Solve for remaining option
			taken[i] = 0;
		}
	}
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   
   Backtrack(1);
   
   //int n;cin>>n;
   //vi a(n);
   //for(int &x:a)cin>>x;
   
   //do{
	   //for(int x:a)cout<<x<<' ';
	   //cout<<endl;
   //}
   //while(next_permutation(all(a)));
   
   return 0;
}

