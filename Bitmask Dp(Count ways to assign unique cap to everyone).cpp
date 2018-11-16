#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define pi acos(-1.0)
#define pb push_back
#define clr(a) memset(a,0,sizeof a)
#define reset(a) memset(a,-1,sizeof a)
#define pii pair<int,int>
using namespace std;
const int sz=2e6+5;
const int mod=1e9+7;
int fx[]= {1,0,-1,0};
int fy[]= {0,1,0,-1};
int a[sz],b[sz];

int dp[1000][100];
vector<int>caplist[101];
int allmask;
ll Ways(ll mask,ll i)
{
    if(mask==allmask) return 1;
    if(i>100) return 0;
    if(~dp[mask][i]) return dp[mask][i];

    ll wayss=Ways(mask,i+1);
    int sz=caplist[i].size();
    for(int j=0;j<sz;j++)
    {
        if(mask & (1<<caplist[i][j])) continue;
        else wayss+=Ways(mask | (1<<caplist[i][j]),i+1);
        wayss%=mod;
    }
    return dp[mask][i]=wayss;
}

void get_input(int n)
{

    string temp,str;
    int x;
    getline(cin,str);
    for(int i=0;i<n;i++){
            getline(cin,str);
    stringstream ss(str);
    while(ss >> temp)
    {
        stringstream s;
        s << temp;
        s >> x;
    caplist[x].pb(i);
    }
    }
    allmask=(1<<n)-1;
    reset(dp);
    cout<<Ways(0,1);

}
int main()
{
   int i,j,k,l,m,tc=0,t,n;
    cin>>n;
    get_input(n);

    return 0;

}





