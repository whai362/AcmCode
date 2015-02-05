#include<iostream>
#include<cstdio>
using namespace std;
#define N 100005
struct node{
	int l,r,mid;
	long long add,sum;
}v[3*N];
long long a[N];
void build(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].mid=mid,v[n].add=0;
	if(l==r){
		v[n].sum=a[l];
		return ;
	}
	build(l,mid,2*n);
	build(mid+1,r,2*n+1);
	v[n].sum=v[2*n].sum+v[2*n+1].sum;
}
void down(int n){
	if(v[n].add){
		v[2*n].sum+=v[n].add*(v[n].mid-v[n].l+1);
		v[2*n+1].sum+=v[n].add*(v[n].r-v[n].mid);
		v[2*n].add+=v[n].add;
		v[2*n+1].add+=v[n].add;
		v[n].add=0;
	}
}
long long query(int l,int r,int n){
	if(v[n].l==l && v[n].r==r){
		return v[n].sum;
	}
	down(n);
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
void update(int l,int r,int n,long long add){
	if(v[n].l==l && v[n].r==r){
		v[n].sum+=add*(r-l+1);
		v[n].add+=add;
		return ;
	}
	down(n);
	if(r<=v[n].mid)
		update(l,r,2*n,add);
	else if(l>v[n].mid)
		update(l,r,2*n+1,add);
	else{
		update(l,v[n].mid,2*n,add);
		update(v[n].mid+1,r,2*n+1,add);
	}
	up(n);
}
int main(){
	int n,q;
	int i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	build(1,n,1);
	for(i=0;i<q;++i){
		char op[5];
		int u,v;
		long long w;
		scanf("%s",op);
		if(op[0]=='Q'){
			scanf("%d%d",&u,&v);
			printf("%lld\n",query(u,v,1));
		}
		else{
			scanf("%d%d%lld",&u,&v,&w);
			update(u,v,1,w);
		}
	}
	return 0;
}
