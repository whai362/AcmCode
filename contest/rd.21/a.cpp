#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	char a[15];
	int i,len;
	scanf("%s",a);
	len=strlen(a);
	sort(a,a+len);
	for(i=len-1;i>=0;--i){
		if(a[i]==a[len-1]) printf("%c",a[i]);
		else break;
	}
	printf("\n");
	return 0;
}
