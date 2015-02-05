#include<cstdio>
#include<cstring>
using namespace std;
char s[200005];
int main(){
	int cnt1=0,cnt2=0,len;
	scanf("%d%s",&len,s);
	for(int i=0;i<len;++i){
		if(s[i]=='I') ++cnt1;
		else if(s[i]=='A') ++cnt2;
	}
	if(cnt1>1) printf("0\n");
	else{
		if(cnt1==1) printf("1\n");
		else printf("%d\n",cnt2);
	}
	return 0;
}
