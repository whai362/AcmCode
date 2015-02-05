#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[600005];
int main(){
	int i,l,len,t;
	scanf("%d",&t);
	getchar();
	for(l=1;l<=t;++l){
		cin.getline(str,sizeof(str));
		len=strlen(str);
		printf("Case %d: ",l);
		for(i=len-1;i>=0;--i){
			if(str[i]==' '){
				printf("%s ",str+i+1);
				str[i]=0;
			}
		}
		printf("%s\n",str);
	}
	return 0;
}

