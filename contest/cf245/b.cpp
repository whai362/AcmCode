#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 105
struct data{
	int l,r,c;
}d[N];
int main(){
	int n,k,x;
	int i;
	scanf("%d%d%d",&n,&k,&x);
	memset(d,0,sizeof(d));
	for(i=0;i<n;++i){
		scanf("%d",&d[i].c);
	}
	for(i=1;i<n;++i){
		if(d[i].c!=d[i-1].c){
			d[i].l=i;
			int j=i-1;
			while(j>=0 && d[j].c==d[i-1].c){
				d[j].r=i-1;
				--j;
			}
		}
		else{
			d[i].l=d[i-1].l;
		}
	}
	i=n-1;
	while(i>=0 && d[i].c==d[n-1].c){
		d[i].r=n-1;
		--i;
	}
	int ans=0;
	for(i=0;i<n;++i){
		int tmp;
		if(d[i].c==x && d[i].r-d[i].l+1>=2){
			tmp=d[i].r-d[i].l+1;
			int l=d[i].l,r=d[i].r;
			while(l!=0 && r!=n-1 && d[l-1].c==d[r+1].c){
				int count=d[l-1].r-d[l-1].l+1+d[r+1].r-d[r+1].l+1;
				if(count>2) tmp+=count;
				else break;
				l=d[l-1].l,r=d[r+1].r;
			}
			ans=max(tmp,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
