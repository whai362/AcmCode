#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[1005],tmp[1005];
int h[1005];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		scanf("%s",str);
		memset(h,0,sizeof(h));
		for(int i=0;i<n;++i){
			if(str[i]=='?'){
				str[i]='a';
				h[i]=1;
			}
		}
		tmp[n]=0;
		for(int i=0;i<n;++i){
			tmp[n-1-i]=str[i];
		}
		int flag=1;
		for(int i=0;i<n;++i){
			if(str[i]!=tmp[i]){
				flag=0;
				break;
			}
		}
		if(flag){
			for(int i=0;i<n;++i){
				if(n%2==1 && i==n/2) continue;
				if(h[n-1-i]==1 && str[i]==tmp[i]){
					++str[n-1-i];
					flag=0;
					break;
				}
			}
		}
		if(!flag) puts(str);
		else puts("QwQ");
	}
	return 0;
}
