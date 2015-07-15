#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int N=50005;
struct cam{
	int l;
	int r;
	int count;
}list[N*4];

void build(int k,int l,int r){
	list[k].l=l;
	list[k].r=r;
	list[k].count=r-l+1;
	if(l==r)
		return;
	int mid=(l+r)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}

int update(int k,int x){
	int ans;
	if(list[k].l==list[k].r){
		list[k].count=0;
		return list[k].l;
	}
	if(x<=list[k<<1].count)
		ans=update(k<<1,x);
	else
		ans=update(k<<1|1,x-list[k<<1].count);
	list[k].count=list[k<<1].count+list[k<<1|1].count;
	return ans;
}

int query[3005],ans[50005];
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		build(1,1,n);
		for(int i=0;i<n;++i){
			int a;
			scanf("%d",&a);
			ans[i]=update(1,a);
		}
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			int q;
			scanf("%d",&q);
			printf("%d%c",ans[q-1],i==m-1?'\n':' ');
		}
	}
	return 0;
}

