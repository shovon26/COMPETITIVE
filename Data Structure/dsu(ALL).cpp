int parent[MX];
int find(int node){
	if(node == parent[node])return node;
	else return find(parent[node]);
}

//Path Compression
int find(int node){
	if(parent[node]<0)return node;
	else return parent[node] = find(parent[node]);
}

void union(int a,int b){
	a = find(a);
	b = find(b);
	
	if(a == b)return;
	else parent[a] = b;
}
