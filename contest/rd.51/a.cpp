#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[55],t[55];
	int ans=0,i,len;
	scanf("%s%s",s,t);
	len=strlen(t);
	for(i=0;i<len;++i){
		if(s[ans]==t[i]) ++ans;
	}
	printf("%d\n",ans+1);
	return 0;
}
