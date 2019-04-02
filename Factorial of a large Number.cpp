#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int sz=1000;
//int res[sz];

int multiply(int x,int res[],int res_sz)
{
  int carry=0;
  for(int i=0;i<res_sz;i++)
  {
    int prod=res[i]*x+carry;
    res[i]=prod%10;
    carry=prod/10;
  }
  while(carry)
  {
    res[res_sz]=carry%10;
    carry/=10;
    res_sz++;
  }
  return res_sz;
}

void factorial(int n)
{
  int res_sz=1;
  int res[sz];
  res[0]=1;
  for(int i=2;i<=n;i++)res_sz=multiply(i,res,res_sz);
   //cout<<res_sz<<endl;
    for(int i=res_sz-1;i>=0;i--)cout<<res[i];
      cout<<endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  ll t;
  cin>>t;
  while(t--){   
  int n;
  cin>>n;
  factorial(n);
}

  return 0;

}
