#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	bool hash[10];
	char a[15];
	int count=0,i,len,n,k;
	scanf("%d%d",&n,&k);
	while(n--){
		scanf("%s",a);
		len=strlen(a);
		memset(hash,0,sizeof(hash));
		for(i=0;i<len;++i){
			hash[a[i]-'0']=1;
		}
		for(i=0;i<=k;++i){
			if(!hash[i]) break;
		}
		if(i>k) ++count;
	}
	printf("%d\n",count);
	return 0;
}
