#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pi acos(-1.0)
using namespace std;
const ll mod = 1e9 + 7;
const int sz1 = 4*1e6 + 50, sz2 = 4*1e5 + 30;
char txt[sz1], patt[sz2];

void make_lps_array(char *pat, int M, int *lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

ll KMP(char *patt, char *txt)
{
	int M = strlen(patt);
	int N = strlen(txt);
	int lps[M + 10];
	make_lps_array(patt, M, lps);

	int i = 0;
	int j = 0;
	ll cnt = 0;
	while (i < N)
	{
		if (patt[j] == txt[i]) {
			j++; i++;
		}
		if (j == M) {
			cnt++;  ///will count number of pattern match in given text
			j = lps[j - 1];
		}
		else if (i < N && patt[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else i++;
		}
	}
	return cnt;
}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	getchar();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", patt);
		scanf("%s", txt);
		ll ans = KMP(patt, txt);
		printf("%lld\n", ans);
	}

	return 0;
}
