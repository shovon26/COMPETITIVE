int prime[nax+10];
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= nax; i++) prime[i] = i;
    for (int i = 4; i <= nax; i += 2)prime[i] = 2;

    for (int i = 3; i * i <= nax; i += 2)
    {
        if (prime[i] == i) {
            for (int j = i * i; j <= nax; j += i) {
                if (prime[j] == j)
                    prime[j] = i;
            }
        }
    }
}

vector<int> Prime_factor(int x)
{
    vector<int> ans;
    while (x != 1)
    {
        ans.push_back(prime[x]);
        x /= prime[x];
    }
    return ans;
}
