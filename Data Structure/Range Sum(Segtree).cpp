const int INF = 1e9 + 7;
const int MX = 1e5+7;
int a[MX];
int tr[4*MX];
void build(int node,int st,int ed)
{
	if(st==ed){
		tr[node]=a[st];
		//cerr(tr[node]);
		return ;
	}
	int mid=(st+ed)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,ed);
	tr[node]=tr[2*node]+tr[2*node+1];
}

int query(int node,int st,int ed,int l,int r){
	if(l>ed or r<st)return 0;  ///Completely outside
	//debug(st,ed);
	if(st>=l and ed<=r)return tr[node];  ///Completely inside
	int mid=(st+ed)/2;
	int lft=query(2*node,st,mid,l,r);
	int rgt=query(2*node+1,mid+1,ed,l,r);
	return lft+rgt;
}
