#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	int len;
	char a[210];
	scanf("%s",a);
	len=strlen(a);
	sort(a,a+len);
	printf("%s\n",a);
	while(next_permutation(a,a+len)) printf("%s\n",a);
	return 0;
}

