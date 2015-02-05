#include<iostream>
#include<cstdio>
using namespace std;
#define N 100005
struct node{
	int l,r,mid;
	__int64 sum;
}v[3*N];
__int64 a[N];
__int64 abs(__int64 n){
	if(n>=0) return n;
	return -n;
}
void build(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].mid=mid,v[n].sum=0;
	if(l==r){
		return ;
	}
	build(l,mid,2*n);
	build(mid+1,r,2*n+1);
}
__int64 query(int l,int r,int n){
	if(v[n].l==l && v[n].r==r){
		return v[n].sum;
	}
	if(r<=v[n].mid)
		return query(l,r,2*n);
	else if(l>v[n].mid)
		return query(l,r,2*n+1);
	else{
		return query(l,v[n].mid,2*n)+query(v[n].mid+1,r,2*n+1);
	}
}
void up(int n){
	v[n].sum=query(v[n].l,v[n].mid,2*n)+query(v[n].mid+1,v[n].r,2*n+1);
}
void update(int l,int r,int n,__int64 col){
	if(v[n].l==v[n].r){
		//cout<<"!"<<v[n].l<<endl;
		v[n].sum+=abs(a[v[n].l]-col);
		a[v[n].l]=col;
		return ;
	}
	if(r<=v[n].mid)
		update(l,r,2*n,col);
	else if(l>v[n].mid)
		update(l,r,2*n+1,col);
	else{
		update(l,v[n].mid,2*n,col);
		update(v[n].mid+1,r,2*n+1,col);
	}
	up(n);
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(__int64 i=1;i<=n;++i){
		a[i]=i;
	}
	build(1,n,1);
	for(int i=0;i<q;++i){
		int op;
		int u,v;
		__int64 w;
		scanf("%d",&op);
		if(op==2){
			scanf("%d%d",&u,&v);
			printf("%I64d\n",query(u,v,1));
		}
		else{
			scanf("%d%d%I64d",&u,&v,&w);
			update(u,v,1,w);
		}
	}
	return 0;
}
