#include<bits/stdc++.h>
#define ll long long
#define A 1111111
using namespace std;
const int sz=311111;

int n,k;
int fr[A],a[sz];
struct Query
{
    int l,r,id;
};
Query q[sz];
int L,R,sum,cnt=0,ans[sz];
bool cmp(Query a,Query b)
{
   int sqr=(int) sqrt(n);
   if(a.l/sqr!=b.l/sqr)return a.l<b.l;
   return a.r<b.r;
}

void add(int pos)
{
    fr[a[pos]]++;
    if(fr[a[pos]]==1)cnt++;
}

void sub(int pos)
{
    fr[a[pos]]--;
    if(fr[a[pos]]==0)cnt--;
}

void pre(int l,int r)
{
   while(L<l)
   {
       sub(L);
       L++;
   }
   while(R>r+1)
   {
       sub(R-1);
       R--;
   }
   while(L>l)
   {
       add(L-1);
        L--;
   }
   while(R<=r)
   {
       add(R);
       R++;
   }
}

void RES()
{
    cnt=L=R=0;
    for(int i=0;i<k;i++)
    {
        pre(q[i].l,q[i].r);
        ans[q[i].id]=cnt;
    }
}
int main()
{

    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);

   scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].id=i;
    }

    sort(q,q+k,cmp);

    RES();

    for(i=0;i<k;i++)printf("%d\n",ans[i]);


    return 0;
}



