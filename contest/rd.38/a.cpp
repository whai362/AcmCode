#include<cstdio>
#include<cstring>
using namespace std;
bool hash[256];
int main(){
	char s[105];
	int count=0,i,len;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;++i){
		if(!hash[s[i]]){
			hash[s[i]]=1;
			++count;
		}
	}
	if(count%2) printf("IGNORE HIM!\n");
	else printf("CHAT WITH HER!\n");
	return 0;
}
