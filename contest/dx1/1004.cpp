#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define Maxn 100050
#define LL __int64
using namespace std;

struct Node{
	LL t,l;
	Node(){}
	Node(LL tt,LL ll){
		t=tt;l=ll;
	}
}a[Maxn],b[Maxn];
int n,m;
bool vis[Maxn];
bool cmp(Node x,Node y){
	if (x.l==y.l) return x.t<y.t;
	return x.l<y.l;
}
int gao(Node d){
	int l=1,r=m,mid=(l+r)>>1;
	while(l<r){
		bool flag=cmp(d,b[mid]);
		cout<<flag<<endl;
		if(flag) l=mid+1;
		else r=mid-1;
		mid=(l+r)>>1;
	}
	return l;
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i=1;i<=n;i++){
			scanf("%I64d%I64d",&a[i].t,&a[i].l);
		}
		for (int i=1;i<=m;i++){
			scanf("%I64d%I64d",&b[i].t,&b[i].l);
		}
		for(int i=1;i<=m;++i){
			cout<<b[i].t<<' '<<b[i].l<<endl;
		}
		memset(vis,0,sizeof(vis));
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+m,cmp);
		cout<<gao(a[0])<<endl;
	}
	return 0;
}

