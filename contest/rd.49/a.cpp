#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int a,cnt=0,cnt1,i,j,n,k;
	char num[15];
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		cnt1=0;
		sprintf(num,"%d",a);
		int len=strlen(num);
		for(j=0;j<len;++j){
			if(num[j]=='4' || num[j]=='7') ++cnt1;
		}
		if(cnt1<=k) ++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
