#include<bits/stdc++.h>
#define faster_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie()
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define ppb pop_back
#define long long long
using namespace std;
string s;
int fr[10000];
priority_queue< pair<int,int> >pq;
pair<int,int>p,q;
map<int,string>id;
struct tree
{
    int left,right;
} tr[10000];

void dfs(int node,string s1)
{
    if(tr[node].left==-1)
    {
        id[node]=s1;
        return;
    }
    dfs(tr[node].left,s1+"0");
    dfs(tr[node].right,s1+"1");
}


int main()
{
    int i,j,k,l;
    mem(tr,-1);
    cin>>s;
    l=s.size();
    for(i=0; i<l; i++)
        fr[s[i]-' ']++;

    for(i=0; i<=90; i++)
        if(fr[i])
            pq.push({-fr[i],i});
    j=91;
    while(pq.size()>1)
    {
        p=pq.top();
        pq.pop();
        q=pq.top();
        pq.pop();
        tr[j].left=q.second;
        tr[j].right=p.second;
        pq.push({p.first+q.first,j});
        j++;
    }
    dfs(j-1,"");
    for(i=0; i<l; i++)
    {
        cout<<id[s[i]-' '];
    }
    return 0;
}
