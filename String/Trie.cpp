///Hihocode 1014 - Trie Tree

//Given n number of string and m number of preffix ,count number of preffix matched with given n number of string.

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pi acos(-1.0)
using namespace std;
const ll mod = 1e9 + 7;
const int sz = 1e5 + 50, MX=26;

struct Trie{
  struct Node{
   int next[MX];
   int endd;
  }node[sz*20];
  int Size;

  int newnode(){
  	for(int i=0;i<MX;i++)
  		node[Size].next[i]=0;
  	node[Size].endd=0;
  	return Size++;
  }

  void init()
  {
  	Size=0;
  	newnode();
  }

  void Insert(string s){
     int len=s.size();
     int now=0;
     for(int i=0;i<len;i++)
     {
     	int x=s[i]-'a';
     	if(node[now].next[x]==0)
     		node[now].next[x]=newnode();
     	now=node[now].next[x];
     	node[now].endd ++;
     }
  }

  int get_result(string s)  ///will count number of matched prefix with given word
  {
      int len=s.size();
      int now=0,i;
      for( i=0;i<len;i++){
      	int x=s[i]-'a';
      	if(node[now].next[x]==0){
      		break;
      	}
      	now=node[now].next[x];
      }

    if(i==len)return node[now].endd;
    else return 0;
  }
   
}trie;
string s;
int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;cin>>n;
	
     trie.init();
     
     for(int i=0;i<n;i++){
     	cin>>s;
     	trie.Insert(s);
     }
     int m;cin>>m;
     for(int i=0;i<m;i++){
     	string p;
     	cin>>p;
     	cout<<trie.get_result(p)<<"\n";
     }

	return 0;
}
