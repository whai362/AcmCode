#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[105];
int main(){
	int i,l;
	scanf("%s",a);
	l=strlen(a);
	sort(a,a+l);
	//printf("%s\n",a);
	for(i=0;i<l;++i){
		if(a[i]!='+') break;
	}
	printf("%c",a[i++]);
	for(;i<l;++i){
		printf("+%c",a[i]);
	}
	printf("\n");
	return 0;
}
