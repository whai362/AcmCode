#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 500000
struct node{
	int l,r,cnt,m;
}v[N*3];
struct Data{
	int x,id;
}d[N];
bool cmp1(Data d1,Data d2){
	return d1.x<d2.x;
}
/*bool cmp2(Data d1,Data d2){
	return d1.id>d2.id;
}*/
void bulid(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].m=mid,v[n].cnt=0;
	if(l==r) return;
	bulid(l,mid,2*n);
	bulid(mid+1,r,2*n+1);
}
void insert(int x,int n){
	++v[n].cnt;
	if(v[n].l==v[n].r && v[n].l==x)
	  return;
	if(x<=v[n].m)
	  insert(x,2*n);
	else
	  insert(x,2*n+1);
}
int _count(int l,int r,int n){
	if(v[n].l==l && v[n].r==r)
	  return v[n].cnt;
	else{
		int sum=0;
		if(r<=v[n].m)
		  sum+=_count(l,r,2*n);
		else if(l>v[n].m)
		  sum+=_count(l,r,2*n+1);
		else
		 sum+=_count(l,v[n].m,2*n)+_count(v[n].m+1,r,2*n+1);
		return sum;
	}
}
int main(){
	int maxx,n,T;
	long long ans=0;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	maxx=0;
	ans=0;
	for(int i=0;i<n;++i){
		scanf("%d",&d[i].x);
		d[i].id=i;
	}
	sort(d,d+n,cmp1);
	bulid(0,n,1);
	for(int i=0;i<n;++i){
		int j=i;
		while(d[j].x==d[i].x && j<n){
			//cout<<d[j].x<<' '<<_count(d[j].id,n,1)<<endl;
			ans+=(long long)_count(d[j].id,n,1);
			++j;
		}
		for(int k=i;k<j;++k){
			insert(d[k].id,1);
		}
		i=j-1;
	}
	cout<<ans<<endl;
	}
	return 0;
}

