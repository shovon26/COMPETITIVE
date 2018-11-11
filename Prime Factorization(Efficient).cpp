#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<int>prime;
int pr[10000+1];
bool check(int n)
{
    int i,j,k;
    if(n==1 || n==0)return false;
    if(n==2)return true;
    for(i=2;i<=sqrt(n)+1;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

void Sieve()
{

    int i,j,k;
    pr[0]=1;pr[1]=1;
    for(i=2;i*i<=10000;i++)
    {
        if(pr[i]==0)
        {
            for(j=i*i;j<=10000;j+=i)
            {
                if(pr[j]==0)pr[j]=i;
            }
        }
    }
    for(i=2;i<=10000;i++)
    {
        if(pr[i]==0)pr[i]=i;
        cout<<pr[i]<<" ";
    }
}

vector<int> factorize(int n)
{
    Sieve();

    vector<int>res;
    while(n!=1)
    {
        res.pb(pr[n]);
        n=n/pr[n];
    }
    return res;
}
int main()
{
    vector<int>v;
    v=factorize(25);
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    return 0;
}

