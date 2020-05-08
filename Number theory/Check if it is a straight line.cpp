/*
Problem Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
*/
//Code

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
#define SZ(x) (int)x.size()
using namespace std;
typedef pair<int, int> pi32;
typedef pair<ll, ll> pi64;
typedef vector<int> vi32;
typedef vector<ll> vi64;
typedef vector<pi32> vp32;
typedef vector<pi64> vp64;
const ll mod = 1e9 + 7;
const ll MX = 1000, inf = 1e9 + 7;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.empty() || coordinates[0].empty() || coordinates.size()==1){
            return false;
        }
        int H=coordinates.size();
        vector<pair<int,int>>point;
        for(int row=0;row<H;row++){
           point.push_back({coordinates[row][0],coordinates[row][1]});
        }
        set<pi32>st;
        for(auto it:point)st.insert({it.ff,it.ss});
        if(SZ(st)==1)return false;
        
        int x=point.front().ff;
        int y=point.front().ss;
        bool f1=1;
        for(int i=1;i<H;i++){
			if(point[i].ff!=x){
				f1=0;break;
			}
		}
		if(f1)return true;
		bool f2=1;
		for(int i=1;i<H;i++){
			if(point[i].ss!=y){
				f2=0;break;
			}
		}
		if(f2)return true;
        
        int dx=point[1].first-point[0].first;
        int dy=point[1].second-point[0].second;
        dx=abs(dx);
        dy=abs(dy);
        int gcd=__gcd(dx,dy);
        dx/=gcd;
        dy/=gcd;
        debug(dy,dx);

        for(int i=0;i<H;i++){
            for(int j=i+1;j<H;j++){
				if(i==j)continue;
                 int d_x=point[j].first-point[i].first;
                 int d_y=point[j].second-point[i].second;
                 d_x=abs(d_x);
                 d_y=abs(d_y);
                 int g=__gcd(d_x,d_y);
                 d_x/=g;
                 d_y/=g;
                debug(d_x,d_y);
                if(d_x!=dx or d_y!=dy){
                    return false;
                    break;
                }
            }
        }
        return true;
    }
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	Solution ob;
	int H;
	cin>>H;
	vector<vector<int>>P(H,vector<int>(2));
	for(int i=0;i<H;i++){
		for(int j=0;j<2;j++)cin>>P[i][j];
	}
	cout<<ob.checkStraightLine(P)<<endl;
	
	return 0;
}


