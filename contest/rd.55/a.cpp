#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	bool hash[10];
	int i,j,y,len;
	char year[10];
	scanf("%d",&y);
	for(i=y+1;;++i){
		memset(hash,0,sizeof(hash));
		sprintf(year,"%d",i);
		len=strlen(year);
		for(j=0;j<len;++j){
			if(!hash[year[j]%48]) hash[year[j]%48]=1;
			else break;
		}
		if(j==len) break;
	}
	printf("%d\n",i);
	return 0;
}
