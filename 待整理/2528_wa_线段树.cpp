#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10005
struct node{
	int l,r,m,cnt;
}v[N*3];
struct paper{
	int id,l,r;
}p[N];
bool cmp1(paper a,paper b){
	return a.r<b.r;
}
bool cmp2(paper a,paper b){
	return a.l<b.l;
}
void build(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].m=mid,v[n].cnt=0;
	if(l==r)
	  return ;
	build(l,mid,2*n);
	build(mid+1,r,2*n+1);
}
void insert(int p,int n){
	v[n].cnt++;
	if(v[n].l==v[n].r && v[n].l==p)
	  return ;
	if(p<=v[n].m)
	  insert(p,2*n);
	else
	  insert(p,2*n+1);
}
int _count(int l,int r,int n){
	if(v[n].l==l && v[n].r==r){
		return v[n].cnt;
	}
	int sum=0;
	if(r<=v[n].m){
		sum+=_count(l,r,2*n);
	}
	else if(l>v[n].m){
		sum+=_count(l,r,2*n+1);
	}
	else{
		sum+=_count(l,v[n].m,2*n)+_count(v[n].m+1,r,2*n+1);
	}
	return sum;
}
int main(){
	int i,n,ans1,ans2,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans1=ans2=0;
		for(i=0;i<n;++i){
			scanf("%d%d",&p[i].l,&p[i].r);
		}
		for(i=0;i<n;++i)
		  p[i].id=i;
		sort(p,p+n,cmp1);
		for(i=0;i<n;++i)
		  p[p[i].id].r=i+1;
		build(1,n,1);
		for(i=n-1;i>=0;--i){
			if(_count(1,p[i].r,1)==0)
			  ++ans1;
			insert(p[i].r,1);
		}
		sort(p,p+n,cmp2);
		for(i=0;i<n;++i)
		  p[p[i].id].l=i+1;
		build(1,n,1);
		for(i=n-1;i>=0;--i){
			if(_count(1,p[i].r,1)==0)
			  ++ans1;
			insert(p[i].r,1);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
