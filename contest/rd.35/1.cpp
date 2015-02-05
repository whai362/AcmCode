#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int i,count=0,s[4];
	for(i=0;i<4;++i) scanf("%d",&s[i]);
	sort(s,s+4);
	for(i=0;i<3;++i){
		if(s[i]==s[i+1]) ++count;
	}
	printf("%d\n",count);
	return 0;
}
