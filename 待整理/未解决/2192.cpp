#include<stdio.h>
#include<string.h>
char s1[210],s2[210],s3[420];
int main(){
	int n;
	int i,j,k,cas=0;
	scanf("%d",&n);
	while(n--){
		scanf("%s%s%s",s1,s2,s3);
		i=strlen(s1)-1;
		j=strlen(s2)-1;
		k=strlen(s3)-1;
		while(k>=0){
			if(s1[i]==s3[k]) --i;
			else if(s2[j]==s3[k]) --j;
			else break;
			--k;
		}
		printf("Data set %d: ",++cas);
		if(k<0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
