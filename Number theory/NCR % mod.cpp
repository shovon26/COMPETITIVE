const ll mod = 1e9+7;
const int nax = 2e5+5;
ll fact[nax+10];
void factorize(){
	fact[1] = 1;
	for(int i=2; i<=nax; i++){
		fact[i] = (i*fact[i-1]*1LL)%mod;
	}
}
ll bigmod(ll a, ll b, ll m)
{
    if (b == 0 )return 1;
    if (b & 1)
    {
        return ((a % m) * (bigmod(a, b - 1, m))) % m;
    }
    else
    {
        ll tmp = bigmod ( a, b / 2, m );
        return ( tmp * tmp ) % m;
    }
}

ll modInverse(ll a, ll m)
{
    return bigmod(a, m-2, m);
}
ll NCR(ll n, ll r){
	if(n == r || r == 0) return 1;
	if(n < r || r < 0) return 0;
	ll ans = ((fact[r]%mod) * (fact[n-r]%mod)) % mod;
	ans = modInverse(ans, mod);
	ans = ((ans%mod) * (fact[n]%mod)) % mod;
	return ans;
}
