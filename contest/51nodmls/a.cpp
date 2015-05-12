#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e6+5;
char str[N];
int main(){
	int n;
	while(scanf("%s",str)!=EOF){
		int len=strlen(str);
		if(len%2==0){
			int tmp=len/2;
			int flag=1;
			for(int i=0;i<tmp;++i){
				if(str[i]!=str[tmp+i]){
					flag=0;
					break;
				}
			}
			if(flag) puts("YES");
			else puts("NO");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
