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
const int MX = 300+10;

class Solution {
public:
    void Make(vvi &pref,vvi &mat){
		int h=SZ(mat);
        int w=SZ(mat[0]);
		for(int i=0;i<h;i++){
		   for(int j=w-1;j>=0;j--){
			   if(mat[i][j]==0)continue;
			   
			   if(j!=w-1)pref[i][j]+=pref[i][j+1];
			   pref[i][j]+=mat[i][j];
		   }
	   }
	}
	int GetRes(vvi &mat){
		int h=SZ(mat);
        int w=SZ(mat[0]);
        vvi pref(h,vi (w,0));
        
        Make(pref,mat);
        int ans=0;
        for(int j=0;j<w;j++){
			int i=h-1;
			stack<pi>st;
			int sum=0;
			while(i>=0){
				int c=0;
				while(!st.empty() and st.top().ff>pref[i][j]){
					sum-=(st.top().ss+1)*(st.top().ff-pref[i][j]);
					c+=st.top().ss+1;
					st.pop();
				}
				sum+=pref[i][j];
				ans+=sum;
				st.push({pref[i][j],c});
				i--;
			}
		}
		return ans;
	}
    int numSubmat(vector<vector<int>>& mat) {
        
        return GetRes(mat);
    }
};

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
   Solution ob;
   int h,w;
   cin>>h>>w;
   vvi a(h,vi (w));
    for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)cin>>a[i][j];
	}
	cout<<ob.numSubmat(a)<<endl;

   return 0;
}
