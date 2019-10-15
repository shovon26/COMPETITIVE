#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz=200000;
int a[sz];
ll merge(int a[],int tmp[],int left,int mid,int right)
{
    int i,j,k;
    ll inv_cnt=0;
    i=left;
    j=mid;
    k=left;
    while((i<=mid-1) and (j<=right))
    {
        if(a[i]<=a[j])tmp[k++]=a[i++];
        else tmp[k++]=a[j++],inv_cnt+=(mid-i);
    }

    while(i<=mid-1)tmp[k++]=a[i++];
    while(j<=right)tmp[k++]=a[j++];
    for(i=left;i<=right;i++)a[i]=tmp[i];
    return inv_cnt;
}
ll mergesort(int a[],int tmp[],int left,int right)
{
    ll mid,inv_cnt=0;
    if(right>left){
        mid=(left+right)/2;
        inv_cnt+=mergesort(a,tmp,left,mid);
        inv_cnt+=mergesort(a,tmp,mid+1,right);

        inv_cnt+=merge(a,tmp,left,mid+1,right);
    }
    return inv_cnt;
}
ll _getresult(int a[],int n){
    int tmp[n+1];
    return mergesort(a,tmp,0,n-1);
}
int main(){
 int t;cin>>t;
 while(t--){
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<_getresult(a,n)<<"\n";
 }
 return 0;
}
