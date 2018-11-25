#include<bits/stdc++.h>
#include<cstring>
#define ll long long
#define pi acos(-1.0)
#define pb push_back
#define clr(a) memset(a,0,sizeof a)
#define reset(a) memset(a,-1,sizeof a)
#define pii pair<int,int>
using namespace std;
const int sz=150;
int fx[]= {1,0,-1,0};
int fy[]= {0,1,0,-1};

///Disjoint Set Union
int sizee[sz];
void initialize(int a[],int n)
{
    for(int i=0;i<n;i++)a[i]=i,sizee[i]=1;
}


int root_representative(int a[],int i)
{
    while(a[i]!=i)
    {
        a[i]=a[a[i]];
        i=a[i];
    }
    return i;
}

void weighted_union(int arr[],int sizee[],int A,int B)
{
    int root_A=root_representative(arr,A);
    int root_B=root_representative(arr,B);
    if(sizee[root_A]<sizee[root_B])
    {
        arr[root_A]+=arr[root_B];
        sizee[root_B]+=sizee[root_A];
    }
    else
    {
        arr[root_B]+=arr[root_A];
        sizee[root_A]+=sizee[root_B];
    }
}
int main()
{

   int i,j,k,l,m,tc=0,t;

    return 0;

}


