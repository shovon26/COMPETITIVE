///Hihocoder 1014

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pi acos(-1.0)
using namespace std;
const ll mod = 1e9 + 7;
const int sz = 20*1e5 + 50, MX = 26;

char s[sz];
int root, newnode;
int node[sz][MX];
int isword[sz];
int cnt[sz];
void initialize()
{
	root = 0;
	newnode = 0;
	//cnt[newnode]=0;
	for (int i = 0; i < MX; i++)
		node[root][i] = -1;
}

void insert(char *s)
{
	int len = strlen(s);
	int now = root;
	bool f = 0, ff = 0;
	for (int i = 0; i < len; i++) {
		
			if (node[now][s[i] - 'a'] == -1) {
				node[now][s[i] - 'a'] = ++newnode;
			}
			for (int j = 0; j < MX; j++)node[newnode][j] = -1;
			now = node[now][s[i] - 'a'];
			cnt[now]++;

		}

}

int get_result(char *s)
{
	int len = strlen(s);
	int now = 0, i;
	for (i = 0; i < len; i++)
	{
		
			if (node[now][s[i] - 'a'] == -1) {
				break;
			}
			now = node[now][s[i] - 'a'];
		
	}
	//isword[now] = 1;
	//cout << i << " :::::::::\n";
	//cout<<i<<" abcde"<<endl;
	if (i == len) return cnt[now];
	else return 0;
}

char patt[sz];

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	initialize();
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i++) {

		scanf("%s", patt);
		insert(patt);
	}
	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		scanf("%s", patt);
		cout << get_result(patt) << "\n";
	}

	return 0;
}
