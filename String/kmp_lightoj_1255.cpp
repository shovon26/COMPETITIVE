#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int sz=1100000+10;
char txt[sz],patt[sz];
int nn[sz];
void make_kmp(char patt[])
{

    const int len=strlen(patt);
    int i=0,j=-1;

    nn[0] = -1;

    while(i<len)
    {
        while(j>=0 && patt[i]!=patt[j])
            j=nn[j];

        i++;
        j++;
        nn[i]=j;
    }
}

int KMP(char txt[],char patt[])
{
    int cnt=0;
    int i=0,j=0;
    const int len1=strlen(txt);
    const int len2=strlen(patt);
    make_kmp(patt);

    while(i<len1)
    {
        while(j>=0 && txt[i]!=patt[j])
            j=nn[j];

        i++;
        j++;
        if(j==len2)
        {
            cnt++;
            j=nn[j];
        }
    }

    return cnt;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",txt);
        scanf("%s",patt);
        printf("Case %d: %d\n",i,KMP(txt,patt));
    }
    return 0;
}
