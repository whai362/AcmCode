#include<iostream>
#include<cstdio>
using namespace std;
int n,k,d,cnt=0,sum=0,
	ans[1005],out[1005][1005];
bool judge(){
	int tmp=1;
	for(int i=0;i<d;++i){
		tmp*=k;
		if(tmp>=n) return true;
	}
	return false;
}
void print(int dep){
	if(dep==d){
		for(int i=0;i<d;++i){
			out[i][cnt]=ans[i];
		}
		++cnt;
		return ;
	}
	for(int i=1;i<=k;++i){
		ans[dep]=i;
		print(dep+1);
		if(cnt==n) return ;
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&d);
	if(k>=n){
		for(int i=0;i<d;++i){
			for(int j=1;j<=n;++j){
				printf("%d ",j);
			}
			puts("");
		}
	}
	else{
		if(judge()){
			print(0);
			for(int i=0;i<d;++i){
				for(int j=0;j<n;++j){
					printf("%d ",out[i][j]);
				}
				puts("");
			}
		}
		else puts("-1");
	}
	return 0;
}
