#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 10010
int num[N],sorted[N],hash[N],visited[N];
int main(){
	int begin,i,len,n,t,ans;
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%d",&num[i]);
			sorted[i]=num[i];
			hash[num[i]]=i;
		}
		sort(sorted,sorted+n);
		while(n){
			i=0,len=0;
			while(visited[i]) ++i;
			begin=i;
			while(1){
				--n;
				++len;
				visited[i]=1;
				i=hash[sorted[i]];
				if(i==begin) break;
			}
			if(len==1) continue;
			ans=ans+len-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
