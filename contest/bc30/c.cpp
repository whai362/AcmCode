#include<cstdio>
#include<iostream>
using namespace std;
#define N 1000005;
int h[N];
struct node{
	int l,r,m,max,min;
}v[N*3];
void bulid(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].m=mid;
	if(l==r){
		v[n].max=v[n].min=h[l-1];
		return;
	}
	else{
		bulid(l,mid,2*n);
		bulid(mid+1,r,2*n+1);
		v[n].max=max(v[2*n].max,v[2*n+1].max);
		v[n].min=min(v[2*n].min,v[2*n+1].min);
	}
}
int getMax(int l,int r,int n){
	if(l==v[n].l && r==v[n].r)
	  return v[n].max;
	if(r<=v[n].m)
	  return getMax(l,r,2*n);
	else if(l>v[n].m)
	  return getMax(l,r,2*n+1);
	else
	  return max(getMax(l,v[n].m,2*n),getMax(v[n].m+1,r,2*n+1));
}
int getMin(int l,int r,int n){
	if(l==v[n].l && r==v[n].r)
	  return v[n].min;
	if(r<=v[n].m)
	  return getMin(l,r,2*n);
	else if(l>v[n].m)
	  return getMin(l,r,2*n+1);
	else
	  return min(getMin(l,v[n].m,2*n),getMin(v[n].m+1,r,2*n+1));
}
int tab[N],vis[N];
int main(){
	int i,n,q,l,r;
	while(scanf("%d%d",&n,&q);
	for(i=0;i<n;++i)
	  scanf("%d",&h[i]);
	  memset(tab,0,sizeof(tab));
	  memset(vis,0,sizeof(vis));
	  tab[1]=1;
	for(i=1;i<n;++i){

			tab[i+1]=tab[i];
		if(!vis[h[i]]){
			++tab[i+1];
			vis[h[i]]=1;
		}
	}
	bulid(1,n,1);
	for(i=0;i<q;++i){
		scanf("%d%d",&l,&r);
		_max=getMax(l,r,1);
		_min=getMin(l,r,1);
		if(_min
	}
	}
	return 0;
}
