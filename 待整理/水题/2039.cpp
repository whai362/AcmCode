#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int i,j,len,n;
	char str[205];
	while(scanf("%d",&n) && n){
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<n;++i){
			for(j=0;j<len;j+=2*n){
				printf("%c",str[j+i]);
				if(j+2*n-i-1<len) printf("%c",str[j+2*n-i-1]);
			}
		}
		printf("\n");
	}
	return 0;
}
