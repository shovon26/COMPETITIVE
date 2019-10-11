#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int sz = 1100000 + 10;
///no of set bit(1) from 0 to n in binary representation
unordered_map<ll,ll>arr;
ll getsetbit(ll n){
    if(n==0)return 0;
    if(arr[n])return arr[n];
    return arr[n]=(n%2) ? (2*getsetbit(n/2)+n/2+1) : (getsetbit(n/2)+getsetbit(n/2-1)+n/2);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n;cin>>n;
	if(n==0)cout<<0<<endl,exit(0);

	ll x=getsetbit(n);
	cout<<x<<"\n";

	return 0;
}
