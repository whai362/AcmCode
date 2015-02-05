#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	int l,t1,t2,t3;
	char n1[20],n2[20];
	scanf("%s",&n1);
	strcpy(n2,n1);
	sscanf(n2,"%d",&t1);
	l=strlen(n2);
	n2[l-1]=0;
	sscanf(n2,"%d",&t2);
	strcpy(n2,n1);
	l=strlen(n2);
	n2[l-2]=n2[l-1];
	n2[l-1]=0;
	sscanf(n2,"%d",&t3);
	printf("%d\n",max(t1,max(t2,t3)));
	return 0;
}
