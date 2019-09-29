int fx[] = {1, 0, -1, 0};
int fy[] = {0, 1, 0, -1};


//(a*b)%mod if a * b is large
ll Multiply(ll a, ll b)
{
    a %= mod;
    ll res = 0;
    while (b)
    {
        if (b & 1)
        {
            res = (res + a) % mod;
        }
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

int a[sz];
void sieve()
{
    a[1] = true;
    for (int i = 2; i <= mxn; i++) a[i] = i;
    for (int i = 4; i <= mxn; i += 2)a[i] = 2;

    for (int i = 3; i * i <= mxn; i += 2)
    {
        if (a[i] == i) {
            for (int j = i * i; j <= mxn; j += i) {
                if (a[j] == j)
                    a[j] = i;
            }
        }
    }
}

vector<int> Prime_factor(int x) ///Prime Factorization
{
    vector<int> ans;
    while (x != 1)
    {
        ans.push_back(a[x]);
        x /= a[x];
    }
    return ans;
}

vector<ll> factorize(long long n)  ///Prime Factor of a number upto 1e12
{
	vector<ll>v;
	int count = 0;
	while (!(n % 2)) {
		n >>= 1;
		count++;
	}
	if (count)
		v.pb(2LL);

	for (ll i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			count++;
			n = n / i;
		}
		if (count)
			v.pb(i);
	}

	if (n > 2)
		v.pb(n);

	return v;
}

ll extend_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll ans = extend_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;

    return ans;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = extend_gcd(a, m, x, y);

    ll res = (x % m + m) % m;

    return res;
}

int phi(int n) {     ///Euler Totient Function
	int result = n;
	ll sum = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
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

void Divisor(ll n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v.pb(i);
            v.pb(n / i);
        }
    }
    sort(v.begin(), v.end());
}


int a[sz];
void sieve()
{
    a[0] = a[1] = 1;
    int i, j, s = sqrt(sz);
    for (i = 4; i <= sz; i += 2) a[i] = 1;
    for (i = 3; i <= s; i += 2)
    {
        if (a[i] == 0)
        {
            for (j = i * i; j <= sz; j += 2 * i)
            {
                a[j] = 1;
            }
        }
    }
}


ll vis[sz];
vector<ll>adj[sz];
void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (vis[v] == 0)
        {
            dfs(v);
        }
    }
}

int cost[sz];

void bfs(int s)
{
    vis[s] = 1;
    queue<int>q;
    q.push(s);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = 0; i < adj[s].size(); i++)
        {
            int v = adj[s][i];
            if (vis[v] == 0)
            {
                vis[v] = 1;
                cost[v] = cost[k] + 1;
                q.push(v);
            }
        }
    }
}

int dp[1000][100];
vector<int>caplist[101];
int allmask;
ll Ways(ll mask, ll i) ///Bitmask DP
{
    if (mask == allmask) return 1;
    if (i > 100) return 0;
    if (~dp[mask][i]) return dp[mask][i];
    ll wayss = Ways(mask, i + 1);
    int sz = caplist[i].size();
    for (int j = 0; j < sz; j++)
    {
        if (mask & (1 << caplist[i][j])) continue;
        else wayss += Ways(mask | (1 << caplist[i][j]), i + 1);
        wayss %= mod;
    }
    return dp[mask][i] = wayss;
}

bool Miller_Robin(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);

    ll x = bigmod(a, d, n);

    if (x == 1 || x == n - 1)return true;

    while (d != n - 1)
    {
        x = Multiply(x, x) % mod;
        d *= 2;

        if (x == 1)return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool is_prime(ll n, ll k)
{
    if (n <= 1 || n == 4)return false;
    if (n == 2 || n == 3)return true;

    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!Miller_Robin(d, n))
            return false;

    return true;
}



