#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;
int BIT[N];
int lowbit(int x){ return x&-x; }
int sum(int x){
	int s=0;
	while(x>0){
		s+=BIT[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int x){
	while(x<N){
		++BIT[x];
		x+=lowbit(x);
	}
}
int a[N];

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		memset(BIT,0,sizeof(BIT));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);	
		}
		int ans=0;
		for(int i=n-1;i>=0;--i){
			if(sum(a[i])) ++ans;
			update(a[i]);
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
