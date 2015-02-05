#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct num{
	char str[15];
}s[10005];
int n;
bool init(char *s1,char *s2){
	int i,len;
	len=strlen(s1);
	for(i=0;i<len;++i){
		if(s1[i]!=s2[i]) return 0;
	}
	return 1;
}
bool cmp(num s1,num s2){
	if(strcmp(s1.str,s2.str)==-1) return 1;
	else return 0;
}
int main(){
	int i,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i)
		  scanf("%s",s[i].str);
		sort(s,s+n,cmp);
		for(i=0;i<n-1;++i){
			if(init(s[i].str,s[i+1].str)) break;
		}
		if(i==n-1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
