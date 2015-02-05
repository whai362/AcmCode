#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[1005];
int hash[150];
int main(){
	int i,j,l,k,len,flag=1;
	scanf("%d%s",&k,str);
	len=strlen(str);
	for(i=0;i<len;++i){
		++hash[str[i]];
	}
	for(i='a';i<='z';++i){
		if(hash[i]%k){
			flag=0;
			break;
		}
	}
	if(flag){
		for(i=0;i<k;++i){
			for(j='a';j<='z';++j){
				for(l=0;l<hash[j]/k;++l) printf("%c",j);	
			}
		}
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}
