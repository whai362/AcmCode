#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	return a;
}
int appx(char s1[],char s2[]){
	int i,j,k,max=0,count=0;
	for(i=0;i<strlen(s1);++i){
		for(j=i,k=0;j<strlen(s1)||k<strlen(s2);++j,++k)	if(s1[j]==s2[k]) ++count;
		if(count>max) max=count,count=0;
	}
	return max;
}
int main(){
	int n,m1,m2,max,len;
	char str1[500],str2[500];
	while(scanf("%s",str1)&&(str1[0]!='-'||str1[1]!='1')){
		scanf("%s",str2);
		m1=appx(str1,str2);
		m2=appx(str2,str1);
		max=m1>m2? m1:m2;
		len=strlen(str1)+strlen(str2);
		//cout<<max<<len<<endl;
		n=gcd(2*max,len);
		printf("appx(%s,%s) = ",str1,str2);
		if(max==0) printf("%d\n",0);
		else if(2*max==len) printf("%d\n",1);
		else printf("%d/%d\n",2*max/n,len/n);
	}
	return 0;
}
