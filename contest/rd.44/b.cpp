#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int i,m,n,len;
	char num[5];
	int a[6]={50,80,170,20,200,110};
	scanf("%d",&n);
	if(n==1 || n==2) printf("-1\n");
	else if(n==3) printf("210\n");
	else{
	m=(n-3)%6;
	if(m==0) m=6;
	sprintf(num,"%d",a[m-1]);
	len=strlen(num);
	printf("1");
	for(i=1;i<n-len;++i) printf("0");
	printf("%d\n",a[m-1]);
	}
	return 0;
}
