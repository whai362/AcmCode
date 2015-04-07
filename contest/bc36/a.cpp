#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
char str[20];
int h[300];
int main(){
	while(scanf("%s",str)!=EOF){
		memset(h,0,sizeof(h));
		int len=strlen(str);
		int cnt=1;
		int nn=0;
		int flag=1;
		h[str[0]]=1;
		for(int i=1;i<len;++i){
			if(str[i]==str[i-1]){
				++h[str[i]];
			}
			else{
				if(nn==0){
					nn=h[str[i-1]];
				}
				else{
					if(nn!=h[str[i-1]]){
						flag=0;
						break;
					}
				}
				++cnt;
				++h[str[i]];
			}
		}
		if(nn!=h[str[len-1]]) flag=0;
		if(cnt!=3) flag=0;
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
