#include<iostream>
#include<cstdio>
using namespace std;
#define N 1005
struct node{
	int l,r,mid;
	int add,sum;
}v[3*N];
void build(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].mid=mid,v[n].add=0;
	v[n].sum=0;
	if(l==r){
		return ;
	}
	build(l,mid,2*n);
	build(mid+1,r,2*n+1);
	v[n].sum=v[2*n].sum+v[2*n+1].sum;
}
void down(int n){
	if(v[n].add){
		v[2*n].sum=v[n].mid-v[n].l+1;
		v[2*n+1].sum=v[n].r-v[n].mid;
		v[2*n].add=1;
		v[2*n+1].add=1;
		v[n].add=0;
	}
}
int query(int l,int r,int n){
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
void update(int l,int r,int n){
	if(v[n].l==l && v[n].r==r){
		v[n].sum=r-l+1;
		v[n].add=1;
		return ;
	}
	down(n);
	if(r<=v[n].mid)
		update(l,r,2*n);
	else if(l>v[n].mid)
		update(l,r,2*n+1);
	else{
		update(l,v[n].mid,2*n);
		update(v[n].mid+1,r,2*n+1);
	}
	up(n);
}
int main(){
	int n;
	int l,r;
	while(scanf("%d",&n)!=EOF){
		build(0,1004,1);
		for(int i=0;i<n;++i){
			scanf("%d%d",&l,&r);
			if(l>r) swap(l,r);
			update(l,r,1);
		}
		printf("%d\n",query(0,1004,1));
	}
	return 0;
}

