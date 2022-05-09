#include<iostream>
using namespace std;
const int nax = 1001;
int G[nax][nax];
int color[nax];
int n, m;
int Q[nax];
bool bfs(int src){
    color[src] = 1;
    int rear = 0, front = 0;
    Q[rear] = src;
    rear++;
    while(front != rear){
        int u = Q[front];
        front++;
        if(G[u][u] == 1) return false;
        for(int v=1; v<=n; v++){
            if(G[u][v] && color[v] == -1){
                color[v] = 1 - color[u];
                Q[rear] = v;
                rear++;
            }
            else if(G[u][v] && color[u] == color[v]) return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    for(int i=1; i<=n; i++) color[i] = -1;
    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            if(bfs(i) == false){
                cout << "Not Bipartite\n";
                return 0;
            }
        }
    }
    cout << "Bipartite" << endl;
    return 0;
}
