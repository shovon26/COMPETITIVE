///Coin change

#include<bits/stdc++.h>
using namespace std;
const int sz=500;

int f[sz];
int cc_set[sz];
int way(int n,int c_set[])
{
    memset(c_set,0,sizeof c_set);
    f[0]=0;
    f[1]=c_set[1];
    for(int i=2;i<=n;i++)
    {
        f[i]=max((c_set[i]+f[i-2]),f[i-1]);
        cout<<f[i]<<endl;
    }
    return f[n];
}

int main()
{
    int n,i,j,k;
    cout<<"Enter the information of coin::"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>cc_set[i];
    }
    cout<<"Maximum amount of coint :: ";
    cout<<way(n,cc_set)<<endl;

    return 0;
}

