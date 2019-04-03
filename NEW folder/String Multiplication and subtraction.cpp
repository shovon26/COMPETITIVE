#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll sz=20006,inf=1e15;
ll fr[sz];

vector<int>v;
void multiply(string s)
{
  reverse(s.begin(),s.end());
  int res[sz];
  int carry=0;
  int j=0;
  for(int i=0;i<s.size();i++)
  {
    int x=((s[i]-'0')*2)%10+carry;
    carry=((s[i]-'0')*2);
    if(carry>=10)carry=1;
    else carry=0;
    res[j++]=x;
  }
  
  int y=(s[s.size()-1]-'0')*2;
  if(y>=10)v.pb(1);
  for(int i=j-1;i>=0;i--)v.pb(res[i]);
  
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);    
  string s;
  while(cin>>s){
   
   if(s[0]=='0' && s.size()==1)cout<<18<<endl;
   else if(s[0]=='1' && s.size()==1)cout<<1<<endl;
  else{
  multiply(s);
   int x=v[v.size()-1];
   
  if(x>=2)
  {
    for(int i=0;i<v.size()-1;i++)cout<<v[i];
      cout<<x-2;
    cout<<endl;
  }
  else
  {
    int sz=v.size();
    vector<int>vc;
    int carry=0;
    int xx=2;
    for(int i=sz-1;i>=0;i--)
    {
       int sub=v[i]-xx-carry;
       if(sub<0){
        sub=sub+10;
        carry=1;
        xx=0;
       }
       else carry=0;
       vc.pb(sub);
    }
    reverse(vc.begin(),vc.end());
    if(vc[0]==0){
    for(int i=1;i<vc.size();i++)cout<<vc[i];
      cout<<endl;
  }
  else
  {
    for(int i=0;i<vc.size();i++)cout<<vc[i];
      cout<<endl;
  }
  }
}
  v.clear();
}

  return 0;
}
