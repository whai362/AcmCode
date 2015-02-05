#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int i,j,len,flag=1;
	char s[10];
	for(i=0;i<8;++i){
		scanf("%s",s);
		if(flag){
			len=strlen(s);
			for(j=0;j<len-1;++j){
				if(s[j]==s[j+1]){
					flag=0;
					break;
				}
			}
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
