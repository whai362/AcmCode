#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	char s1[55],s2[55];
	while(scanf("%s",s1) && s1[0]!='#'){
		strcpy(s2,s1);
		next_permutation(s1,s1+strlen(s1));
		if(strcmp(s1,s2)==1) printf("%s\n",s1);
		else printf("No Successor\n");
	}
	return 0;
}
