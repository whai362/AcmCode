#include<cstdio>
#include<cstring>
using namespace std;
char s[100005];
int main(){
	int i,ans,len,flag=1;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;++i){
		if(s[i]=='0' && flag) flag=0;
		else if(i==len-1 && flag) flag=0;
		else printf("%c",s[i]);
	}
	return 0;
}
