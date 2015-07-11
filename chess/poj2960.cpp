#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
const int MAXN=1e4+5;
int a[N];
int sg[MAXN];

int get_sg(int x, int n){
	if(sg[x]!=-1)
		return sg[x];
	bool vis[105]={0};
	for(int i=0;i<n;++i){
		int tmp = a[i];
		if(x >= tmp){
			sg[x - tmp] = get_sg(x - tmp, n);
			vis[sg[x - tmp]] = 1;
		}
	}
	for(int i=0;;++i)
		if(!vis[i]) return sg[x]=i;
}

void init(){
	memset(sg,-1,sizeof(sg));
	sg[0]=0;
}

//void get_sg(int n){
//	sg[0]=0;
//	for(int i=1;i<=100;++i){
//		sg[i]=get_sg(i,n);
//	}
//}

int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		init();
		int m;
		scanf("%d",&m);
		int h_cnt;
		char ans[N];
		for(int i=0;i<m;++i){
			scanf("%d",&h_cnt);
			int h;
			int tmp=0;
			for(int j=0;j<h_cnt;++j){
				scanf("%d",&h);
				//cout<<get_sg(h,n)<<' ';
				tmp ^= get_sg(h, n);
			}
			//cout<<endl;
			if(tmp==0) ans[i]='L';
			else ans[i]='W';
		}
		ans[m]=0;
		puts(ans);
	}
	return 0;
}
