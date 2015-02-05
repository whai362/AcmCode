#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std; 
char c1[13],c2[13],s[13];
int h[13],p[13];
void gao(){
	int i,len1=strlen(c1),len2=strlen(c2);;
	if(s[0]=='e'){
		for(i=0;i<len1;++i){
			h[c1[i]-'A']=2;
		}
		for(i=0;i<len2;++i){
			h[c2[i]-'A']=2;
		}
	}
	else if(s[0]=='u'){
		memset(p,0,sizeof(p));
		for(i=0;i<len1;++i){
			p[c1[i]-'A']=1;
		}
		for(i=0;i<len2;++i){
			p[c2[i]-'A']=-1;
		}
		for(i=0;i<12;++i){
			if((h[i]==0 || h[i]==1) && p[i]==1)
				h[i]=1;
			else if((h[i]==0 || h[i]==-1) && p[i]==-1)
				h[i]=-1;
			else
				h[i]=2;
		}
	}
	else{
		memset(p,0,sizeof(p));
		for(i=0;i<len1;++i){
			p[c1[i]-'A']=-1;
		}
		for(i=0;i<len2;++i){
			p[c2[i]-'A']=1;
		}
		for(i=0;i<12;++i){
			if((h[i]==0 || h[i]==1) && p[i]==1)
				h[i]=1;
			else if((h[i]==0 || h[i]==-1) && p[i]==-1)
				h[i]=-1;
			else
				h[i]=2;
		}
	}
}
int main(){
	int i,j,T;
	scanf("%d",&T);
	while(T--){
	memset(h,0,sizeof(h));
	for(i=0;i<3;++i){
		scanf("%s%s%s",c1,c2,s);
		gao();
	}
	int ans;
	for(i=0;i<12;++i){
		if(h[i]!=0 && h[i]!=2){
			ans=i;
			break;
		}
	}
	printf("%c is the counterfeit coin and it is ",ans+'A');
	if(h[i]<0)
		printf("light.\n");
	else
		printf("heavy.\n");
	}
	return 0;
}
