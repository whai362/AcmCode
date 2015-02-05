#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char tab[]="BKMGTPEZY";
int main(){
	int T;
	char str[105];
	scanf("%d",&T);
	char dw;
	int cas=0;
	while(T--){
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;++i){
			if(str[i]=='['){
				dw=str[i+1];
				break;
			}
		}
		double zhen=1.0,jia=1.0;
		len=strlen(tab);
		for(int i=0;i<len;++i){
			if(tab[i]!=dw){
				zhen*=1024.0;
				jia*=1000.0;
			}
			else
				break;
		}
		printf("Case #%d: %.2f%%\n",++cas,(zhen-jia)*100/zhen);
	}
	return 0;
}
