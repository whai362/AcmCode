#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1000005;
char str[N];
struct Data{
	int type,cnt;
}d[N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
	scanf("%s",str);
	memset(d,0,sizeof(d));
	long long ans=0;
	int len=strlen(str);
	int cnt=0;
	for(int i=0;i<len;++i){
		char now=str[i];
		if(now=='B')
			d[cnt].type=0;
		else
			d[cnt].type=1;
		int j=i;
		for(;j<len;++j){
			if(now==str[j]){
				++d[cnt].cnt;
			}
			else break;
		}
		i=j-1;
		++cnt;
	}
	if(n==1){
		for(int i=0;i<cnt;++i){
			ans+=(1+(long long)d[i].cnt)*(long long)d[i].cnt/2;
		}
	}
	else{
	for(int i=0;i+n-1<cnt;++i){
		ans+=(long long)d[i].cnt*(long long)d[i+n-1].cnt;
	}
	}
	printf("%lld\n",ans);
	}
	return 0;
}
