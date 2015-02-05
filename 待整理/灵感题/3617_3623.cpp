#include<cstdio>
#include<cstring>
int main(){
	char tmp[2],s1[30005],s2[30005];
	int i,n,p1,p2;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%s",tmp);
		s1[i]=tmp[0];
		s2[n-1-i]=tmp[0];
	}
	s1[n]=s2[n]=0;
	p1=p2=0;
	for(i=0;i<n;++i){
		if(i && i%80==0) printf("\n");
		if(strcmp(s1+p1,s2+p2)==-1){
			printf("%c",s1[p1]);
			++p1;
		}
		else{
			printf("%c",s2[p2]);
			++p2;
		}
	}
	printf("\n");
	return 0;
}
