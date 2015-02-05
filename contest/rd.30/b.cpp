#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	char s[10];
	bool hash[10];
	int count=0,i,j,n,tmp,len,flag;
	scanf("%d",&n);
	tmp=(int)sqrt((double)n);
	for(i=1;i<=tmp;++i){
		if(n%i==0){
			flag=0;
			memset(hash,0,sizeof(hash));
			sprintf(s,"%d",n);
			len=strlen(s);
			for(j=0;j<len;++j) hash[s[j]%10]=1;
			sprintf(s,"%d",i);
			len=strlen(s);
			for(j=0;j<len;++j)
			  if(hash[s[j]%10]){
				flag=1;
				break;
			  }
			if(flag){
				++count;
			}
			flag=0;
			if(n/i!=i){
				sprintf(s,"%d",n/i);
				len=strlen(s);
				for(j=0;j<len;++j)
				  if(hash[s[j]%10]){
					flag=1;
					break;
				  }
				if(flag){
					++count;
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
