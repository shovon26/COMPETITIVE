/*Problems link :
  https://www.spoj.com/problems/RMQSQ/
*/
///Code

#include<bits/stdc++.h>
#define ll long long int
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
typedef pair<int, int> pi32;
typedef pair<ll, ll> pi64;
typedef vector<int> vi32;
typedef vector<ll> vi64;
typedef vector<pi32> vp32;
typedef vector<pi64> vp64;
const int INF = 1e9 + 7;
const int MX = 1e5+7;
///////Range minimum Query
int a[MX];
int tr[4*MX];
void build(int node,int st,int ed)
{
	if(st==ed){
		tr[node]=a[st];
		//cerr(tr[node]);
		return ;
	}
	int mid=(st+ed)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,ed);
	tr[node]=min(tr[2*node],tr[2*node+1]);
}

int query(int node,int st,int ed,int l,int r){
	if(l>ed or r<st)return INF;  ///Completely outside
	//debug(st,ed);
	if(st>=l and ed<=r)return tr[node];  ///Completely inside
	int mid=(st+ed)/2;
	int lft=query(2*node,st,mid,l,r);
	int rgt=query(2*node+1,mid+1,ed,l,r);
	return min(lft,rgt);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n,q;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    
    cin>>q;
    while(q--){
		int l,r;cin>>l>>r;
		cout<<query(1,1,n,l+1,r+1)<<endl; ///In problem it was 0-based indexing
		
	}
    return 0;
}
