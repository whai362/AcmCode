#include<cstdio>
using namespace std;
int n,x,a[105][2],hash[105][7];
int main(){
	int i,j,flag=1;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;++i){
		scanf("%d%d",&a[i][0],&a[i][1]);
		hash[i][a[i][0]]=1;
		hash[i][a[i][1]]=1;
		hash[i][7-a[i][0]]=1;
		hash[i][7-a[i][1]]=1;
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(j==i) continue;
			if(!hash[j][a[i][0]] || !hash[j][a[i][1]]){
				flag=0;
				break;
			}
		}
		if(!flag) break;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
