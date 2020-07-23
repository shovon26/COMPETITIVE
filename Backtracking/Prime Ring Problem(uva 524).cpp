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
const int MX = 100;

int prime[MX+10];
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 4; i <= MX; i += 2)prime[i] = 1;

    for (int i = 3; i * i <= MX; i += 2)
    {
        if (!prime[i]) {
            for (int j = i * i; j <= MX; j += i) {
                prime[j] = 1;
            }
        }
    }
}
	
int n;
int a[MX] = {0};
bool taken[MX] = {0};
void Print(){
	printf("1 ");
	for(int i=2;i<=n;i++){
		printf("%d",a[i]);
		if(i<n)printf(" ");
	}
	printf("\n");
}

void Backtrack(int idx){
	if(idx == n+1 && !prime[a[n]+1]){
		Print();
		return ;
	}
	for(int i=2;i<=n;i++){
		if(!taken[i] && !prime[i+a[idx-1]]){
			taken[i] = 1;
			a[idx] = i;
			Backtrack(idx+1);
			taken[i] = 0;
		}
	}
}
int main()
{
   //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int tc=0;
   sieve();
   a[1]=1;
   while(scanf("%d",&n) != EOF){
	   ++tc;
	   if(tc>1)printf("\n");
	   printf("Case %d:\n",tc);
	   Backtrack(2);
   }
 
   return 0;
}
