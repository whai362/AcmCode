#include<stdio.h>
#include<string.h>
int main(){
	char n1[10],n2[10];
	int i,j,ans;
	scanf("%s%s",n1,n2);
	ans=0;
	for(i=0;i<strlen(n1);++i)
		for(j=0;j<strlen(n2);++j)
			ans=ans+(n1[i]-48)*(n2[j]-48);
	printf("%d\n",ans);
	return 0;
}
