#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char str[250];
	int i,n,max1,min1,max2,min2;
	bool hash[100];
	scanf("%d%s",&n,str);
	if(n==1) printf("YES\n");
	else{
	max1=max2=0,min1=min2=100;
	memset(hash,0,sizeof(hash));
	for(i=0;i<n;++i){
		if(str[i]>max1) max1=str[i];
		if(str[i]<min1) min1=str[i];
	}
	for(i=n;i<2*n;++i){
		if(str[i]>max2) max2=str[i];
		if(str[i]<min2) min2=str[i];
	}
	if(min1<=min2 && max1>=max2 || min1>=min2 && max1<=max2) printf("NO\n");
	else printf("YES\n");
	}
	return 0;
}
