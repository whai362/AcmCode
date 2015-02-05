#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int v[1005];
int c[1005];
int main(){
	int m,t,r,w;
	scanf("%d%d%d",&m,&t,&r);
	for(int i=0;i<m;++i){
		scanf("%d",&w);
		v[w]=1;
	}
	int ok=1;
	int ans=0;
	for(int i=-r+1;i<305;++i){
		if(i>0 && v[i] && c[i]<r){ ok=0; break; }
		int nd=0;
		for(int j=1;j<=r;++j){
			if(i+j>0 && v[i+j])
				nd|=(r-c[i+j]>=j);
		}
		if(nd){
			++ans;
			for(int j=1;j<=t;++j){
				if(i+j>0) ++c[i+j];
			}
		}
	}
	if(ok) printf("%d\n",ans);
	else puts("-1");
	return 0;
}
