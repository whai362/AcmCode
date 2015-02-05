#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define M 2500000
int len,p[M];
char s[M],str[M];

void kp(){
	int i;
	int mx=0;
	int id;
	for(i=1;i<len;++i){
		if(mx>i) p[i]=min(p[2*id-i],p[id]+id-i);
		else p[i]=1;
		for(;str[i+p[i]]==str[i-p[i]];++p[i]);
		if(p[i]+i>mx){
			mx=p[i]+i;
			id=i;
		}
	}
}
void trans(){
	int i,j,k;
	str[0]='$';
	str[1]='#';
	for(i=0;i<len;++i){
		str[i*2+2]=s[i];
		str[i*2+3]='#';
	}
	len=len*2+2;
	s[len]=0;
}
int main(){
	int cas=0,i,max;
	for(int j=100;j<999999;++j){
		sprintf(s,"%d",j);
		len=strlen(s);
		trans();
		kp();
		max=0;
		for(i=0;i<len;++i) if(p[i]>max) max=p[i];
		if(max-1==1){
			cout<<j<<endl;
		}
	}
	return 0;
}
