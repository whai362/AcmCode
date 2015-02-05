#include<stdio.h>
struct student{
	int a,b,c;
	char name[10];
}s[10];
int main(){
	int bully,i,min,max,n,tmp,victim;
	while(scanf("%d",&n)&&n!=-1){
		max=0,min=300;
		for(i=0;i<n;++i){
			scanf("%d%d%d%s",&s[i].a,&s[i].b,&s[i].c,s[i].name);
			tmp=s[i].a*s[i].b*s[i].c;
			if(tmp<min) min=tmp,victim=i;
			if(tmp>max) max=tmp,bully=i;
		}
		printf("%s took clay from %s.\n",s[bully].name,s[victim].name);
	}
	return 0;
}
