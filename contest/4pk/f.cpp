#include<cstdio>
#include<iostream>
using namespace std;
#define N 100005
struct node{
	int l,r,mid,flag;
	int _max0,lmax0,rmax0,_max1,lmax1,rmax1,all0,all1;
}nd[3*N];
int a[N];
void swap(int &n1,int &n2){
	int tmp=n1;
	n1=n2;
	n2=tmp;
}
void up(int rt){
	nd[rt]._max0=max(max(nd[rt*2]._max0,nd[rt*2+1]._max0),nd[rt*2].rmax0+nd[rt*2+1].lmax0);
	if(nd[rt*2].all0)
		nd[rt].lmax0=nd[rt*2]._max0+nd[rt*2+1].lmax0;
	else
		nd[rt].lmax0=nd[rt*2].lmax0;
	if(nd[rt*2+1].all0)
		nd[rt].rmax0=nd[rt*2+1]._max0+nd[rt*2].rmax0;
	else
		nd[rt].rmax0=nd[rt*2+1].rmax0;
	nd[rt].all0=nd[rt*2].all0&nd[rt*2+1].all0;

	nd[rt]._max1=max(max(nd[rt*2]._max1,nd[rt*2+1]._max1),nd[rt*2].rmax1+nd[rt*2+1].lmax1);
	if(nd[rt*2].all1)
		nd[rt].lmax1=nd[rt*2]._max1+nd[rt*2+1].lmax1;
	else
		nd[rt].lmax1=nd[rt*2].lmax1;
	if(nd[rt*2+1].all1)
		nd[rt].rmax1=nd[rt*2+1]._max1+nd[rt*2].rmax1;
	else
		nd[rt].rmax1=nd[rt*2+1].rmax1;
	nd[rt].all1=nd[rt*2].all1&nd[rt*2+1].all1;
}

void down(int rt){
	nd[rt*2].flag=!nd[rt*2].flag;
	nd[rt*2+1].flag=!nd[rt*2+1].flag;
		swap(nd[rt*2]._max0,nd[rt*2]._max1);
		swap(nd[rt*2].lmax0,nd[rt*2].lmax1);
		swap(nd[rt*2].rmax0,nd[rt*2].rmax1);
		swap(nd[rt*2].all0,nd[rt*2].all1);
		swap(nd[rt*2+1]._max0,nd[rt*2+1]._max1);
		swap(nd[rt*2+1].lmax0,nd[rt*2+1].lmax1);
		swap(nd[rt*2+1].rmax0,nd[rt*2+1].rmax1);
		swap(nd[rt*2+1].all0,nd[rt*2+1].all1);
	nd[rt].flag=0;
}
void build(int l,int r,int rt){
	int mid=(l+r)>>1;
	nd[rt].l=l,nd[rt].r=r,nd[rt].mid=mid,nd[rt].flag=0;
	if(l==r){
		if(a[l]){
			nd[rt]._max0=nd[rt].lmax0=nd[rt].rmax0=0;
			nd[rt]._max1=nd[rt].lmax1=nd[rt].rmax1=1;
			nd[rt].all0=0;
			nd[rt].all1=1;
		}
		else{
			nd[rt]._max0=nd[rt].lmax0=nd[rt].rmax0=1;
			nd[rt]._max1=nd[rt].lmax1=nd[rt].rmax1=0;
			nd[rt].all0=1;
			nd[rt].all1=0;
		}
		return ;
	}
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	up(rt);
}
void update(int l,int r,int rt){
	if(nd[rt].l==l && nd[rt].r==r){
		nd[rt].flag=!nd[rt].flag;	
		swap(nd[rt]._max0,nd[rt]._max1);
		swap(nd[rt].lmax0,nd[rt].lmax1);
		swap(nd[rt].rmax0,nd[rt].rmax1);
		swap(nd[rt].all0,nd[rt].all1);
		return ;
	}
	if(nd[rt].l==nd[rt].r) return ;
	if(nd[rt].flag){
		down(rt);
	}
	if(r<=nd[rt].mid) update(l,r,rt*2);
	else if(l>nd[rt].mid) update(l,r,rt*2+1);
	else{
		update(l,nd[rt].mid,rt*2);
		update(nd[rt].mid+1,r,rt*2+1);
	}
	up(rt);
}
node query(int l,int r,int rt){
	if(nd[rt].l==l && nd[rt].r==r){
		return nd[rt];
	}
	if(nd[rt].flag){
		down(rt);
	}
	if(r<=nd[rt].mid) return query(l,r,rt*2);
	else if(l>nd[rt].mid) return query(l,r,rt*2+1);
	else{
		node nd1=query(l,nd[rt].mid,rt*2);
		node nd2=query(nd[rt].mid+1,r,rt*2+1);
		node ans;
		ans._max1=max(max(nd1._max1,nd2._max1),nd1.rmax1+nd2.lmax1);
		if(nd1.all1)
			ans.lmax1=nd1._max1+nd2.lmax1;
		else
			ans.lmax1=nd1.lmax1;
		if(nd2.all1)
			ans.rmax1=nd2._max1+nd1.rmax1;
		else
			ans.rmax1=nd2.rmax1;
		return ans;
	}
}
int main(){
	int c,l,r,n,q;
	int i;
	while(scanf("%d",&n)!=EOF){
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	build(1,n,1);
	scanf("%d",&q);
	for(i=0;i<q;++i){
		scanf("%d%d%d",&c,&l,&r);
		if(c){
			update(l,r,1);
		}
		else{
			printf("%d\n",query(l,r,1)._max1);
		}
	}
	}
	return 0;
}

