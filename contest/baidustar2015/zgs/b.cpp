#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
char str[N];
int k;
int len;
void gao(){
	int a=(len+k-1)/k;
	int b=len%k;
	if(b==0) b=len/a;
	//cout<<a<<' '<<b<<endl;
	for(int i=0;i<a-1;++i){
		for(int j=0;j<b;++j){
			putchar(str[i+j*a]);
		}
		for(int j=i+b*a;j<len;j+=(a-1)){
			putchar(str[j]);
		}
	}
	for(int i=0;i<b;++i){
		putchar(str[i*a+a-1]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		getchar();
		gets(str);
		len=strlen(str);
		scanf("%d",&k);
		printf("Case #%d:\n",++cas);
		gao();
	}
	return 0;
}
