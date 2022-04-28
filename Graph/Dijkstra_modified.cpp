// https://leetcode.com/problems/path-with-minimum-effort/

#include<bits/stdc++.h>
using namespace std;
const int nax = 105;
const int inf = 1e5;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> adj[nax];
vector<vector<int>> dist(nax, vector<int>(nax, inf));
bool inside(int i, int j, int n, int m){
    return i >= 0 && i < n && j >= 0 && j < m;
}
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        auto cmp = [&](const array<int, 3> a, const array<int, 3> b){
            return a[0] >= b[0];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp) > pq(cmp);
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        while(!pq.empty()){
            int w = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if(r == n-1 && c == m-1) break;
            for(int i=0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(inside(nr, nc, n, m)){
                    int nw = max(dist[r][c], abs(arr[r][c] - arr[nr][nc]));
                    if(nw < dist[nr][nc]){
                        dist[nr][nc] = nw;
                        pq.push({nw, nr, nc});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
int main()
{
    Solution ob;
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    cout << ob.minimumEffortPath(arr) << endl;
    return 0;
}

