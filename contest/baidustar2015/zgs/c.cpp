#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define LL __int64
int a[1005][4];
int b[55][4];
set<LL> tab;
int cas=0;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			scanf("%d.%d.%d.%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		for(int i=0;i<m;++i)
			scanf("%d.%d.%d.%d",&b[i][0],&b[i][1],&b[i][2],&b[i][3]);
		printf("Case #%d:\n",++cas);
		for(int i=0;i<m;++i){
			int cnt=0;
			tab.clear();
			for(int j=0;j<n;++j){
				LL key=0;
				for(int k=0;k<4;++k){
					key=key*1000+(b[i][k] & a[j][k]);
				}
				//cout<<key<<endl;
				if(tab.find(key)==tab.end()){
					++cnt;
					tab.insert(key);
				}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
