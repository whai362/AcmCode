#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1005
struct node{
	int l,r,mid,_min;
}nd[3*N];
int t[N],d0[N],d1[N],d2[N];
void build(int l,int r,int rt){
	int mid=(l+r)>>1;
	nd[rt].l=l,nd[rt].r=r,nd[rt].mid=mid;
	if(l==r){
		nd[rt]._min=t[l];
		return ;
	}
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	nd[rt]._min=min(nd[rt*2]._min,nd[rt*2+1]._min);
}
int query(int l,int r,int rt){
	if(nd[rt].l==l && nd[rt].r==r){
		return nd[rt]._min;
	}
	if(r<=nd[rt].mid)
		return query(l,r,rt*2);
	else if(l>nd[rt].mid)
		return query(l,r,rt*2+1);
	else
		return min(query(l,nd[rt].mid,rt*2),query(nd[rt].mid+1,r,rt*2+1));
}
int main(){
	int n,w,s0,s1,s2;
	int i,j;
	while(scanf("%d",&n)!=EOF){
	s0=s1=s2=0;
	memset(d0,0,sizeof(d0));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	for(i=1;i<=n;++i){
		scanf("%d%d",&t[i],&w);
		if(w==1) ++s0;
		if(w==0) ++s1;
		if(w==-1) ++s2;
		d0[i]=s0;
		d1[i]=s1;
		d2[i]=s2;
	}
	build(1,n,1);
	int _min=0x3f3f3f3f;
	int t0,t1,t2,t3;
	for(i=1;i<=n;++i){
		for(j=i;j<=n;++j){
			t0=query(i,j,1);
			t1=d0[j]-d0[i-1];
			t2=d1[j]-d1[i-1];
			t3=d2[j]-d2[i-1];
			//cout<<i<<' '<<j<<' '<<t0<<' '<<t1<<' '<<t2<<' '<<t3<<' '<<t0-2*t2-t3*t3+t1<<endl;
			_min=min(_min,t0-2*t2-t3*t3+t1);
		}
	}
	printf("%d\n",_min);
	}
	return 0;
}

