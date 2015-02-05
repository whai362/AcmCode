#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1005;
int s[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		int a;
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			s[a]=1;
		}
		int cnt=0;
		for(int i=1;i<N;++i){
			if(s[i]==0){
				if(cnt==0) printf("%d",i);
				else printf(" %d\n",i);
				++cnt;
			}
			if(cnt==2) break;
		}
	}
	return 0;
}
