#include<cstdio>
using namespace std;
int cnt[10];
int main(){
	int a,i,f=0,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		if(a==1 || a==2 || a==3 || a==4 || a==6) ++cnt[a];
		else f=1;
	}
	if(!f && cnt[1]==cnt[2]+cnt[3] && cnt[2]==cnt[4]+cnt[6]-cnt[3] && cnt[4]==cnt[1]-cnt[6] && cnt[2]>=cnt[4] && cnt[6]>=cnt[3] && cnt[1] && ((cnt[2] && (cnt[4] || cnt[6])) || (cnt[3] && cnt[6]))){
	
			for(i=0;i<cnt[4];++i){
				printf("1 2 4\n");
			}
		
		for(i=0;i<cnt[6]-cnt[3];++i){
				printf("1 2 6\n");
		}
		
			for(i=0;i<cnt[3];++i){
				printf("1 3 6\n");
			}
		
	}
	else printf("-1\n");
	return 0;
}
