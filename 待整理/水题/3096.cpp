#include<cstdio>
#include<cstring>
using namespace std;
char s[80];
bool hash[30][30];
int main(){
	int i,j,flag,len;
	while(scanf("%s",&s) && s[0]!='*'){
		flag=0;
		len=strlen(s);
		for(i=1;i<len;++i){
			memset(hash,0,sizeof(hash));
			for(j=0;j+i<len;++j){
				if(!hash[s[j]%26][s[j+i]%26]) hash[s[j]%26][s[j+i]%26]=1;
				else{
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) printf("%s is NOT surprising.\n",s);
		else printf("%s is surprising.\n",s);
	}
	return 0;
}
