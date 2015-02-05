#include<cstdio>
#include<cstring>
using namespace std;
#define N 100005
int main(){
	char tmp,s1[N],s2[N];
	int b1,b2,count,i,flag;
	scanf("%s%s",s1,s2);
	if(strlen(s1)==1 || strlen(s2)==1) printf("NO\n");
	else if(strlen(s1)!=strlen(s2)) printf("NO\n");
	else{
		count=0;
		for(i=0;i<strlen(s1);++i){
			if(s1[i]!=s2[i]){
				++count;
				if(count==1) b1=i;
				else b2=i;
			}
		}
		if(count==0) printf("YES\n");
		else if(count==2){
			tmp=s2[b1];
			s2[b1]=s2[b2];
			s2[b2]=tmp;
			if(!strcmp(s1,s2)) printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}
