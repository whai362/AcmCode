#include<iostream>
#include<cstdio>
using namespace std;
char str[200];
int main(){
	int n;
	int flag=0;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;++i){
		for(int j=1;j<n;++j){
			int cnt=0;
			for(int k=i;k<n;k+=j){
				if(str[k]=='*') ++cnt;
				else break;
			}
			if(cnt>=5){
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) puts("yes");
	else puts("no");
}
