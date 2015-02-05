#include<stdio.h>
#include<string.h>
int main(){
	int i,j;
	char s[100010],t[100010];
	while(scanf("%s%s",s,t)!=EOF){
		j=0;
		for(i=0;i<strlen(s);++i){
			for(;j<strlen(t);++j){
				if(s[i]==t[j]) break;
			}
			if(j!=strlen(t)) ++j;
			else break;
		}
		if(i==strlen(s)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
