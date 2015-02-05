#include<cstdio>
int main(){
	char a[1005];
	scanf("%s",a);
	if(a[0]>='a') a[0]-='a'-'A';
	printf("%s\n",a);
	return 0;
}
