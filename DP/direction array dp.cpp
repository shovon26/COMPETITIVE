/*
Problem link : https://leetcode.com/contest/weekly-contest-212/problems/path-with-minimum-effort/
*/

#include<bits/stdc++.h>
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
using ll = long long;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod = 1e9+7;
const int nax = 1e5+10;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& ar) {
        int H = SZ(ar);
        int W = SZ(ar[0]);
        if(H == 1 && W == 1) return 0;
        vector<vi> dp(H, vi(W, mod)); 
        dp[0][0] = 0;
        int prev = -1;
        for(int k=0; k < H*W; k++){
			for(int x=0; x<H; x++){
				for(int y=0; y<W; y++){
					for(int dir=0; dir<4; dir++){
						int xn = x + dx[dir];
						int yn = y + dy[dir];
						if(xn < 0 || xn >= H || yn < 0 || yn >= W || dp[x][y] >= dp[xn][yn])continue;
						int diff = abs(ar[x][y] - ar[xn][yn]);
						dp[xn][yn] = min(max(dp[x][y], diff), dp[xn][yn]);
					}
				}
			}
			//cerr(prev);
			if(prev == dp[H-1][W-1] && k > max(H, W)) return prev;
			prev = dp[H-1][W-1];
			//cerr(prev);
		}
		return dp[H-1][W-1];
    }
};
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   Solution ob;
   int n, m;
   cin >> n >> m;
   vector<vi>ar(n, vi(m));
   for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> ar[i][j];
   cout << ob.minimumEffortPath(ar) << endl;
   return 0;
}
