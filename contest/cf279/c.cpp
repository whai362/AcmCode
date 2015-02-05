#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
const int N=1000005;
char str[N],o1[N],o2[N];
LL h[N];
LL a,b;
void predo(int len){
	LL n=1;
	for(int i=len-1;i>=0;--i){
		h[i]=(LL)(str[i]-'0')*n%b;
		n=(n*10)%b;
	}
}
int main(){
	scanf("%s%I64d%I64d",str,&a,&b);
	int len=strlen(str);
	predo(len);
	int ansp=1;
	while(str[ansp]=='0')
		++ansp;
	LL l=0,r=0;
	for(int i=0;i<ansp;++i)
		l=(l*10+str[i]-'0')%a;
	for(int i=ansp;i<len;++i)
		r=(r*10+str[i]-'0')%b;
	while(ansp<len && (l!=0 || r!=0 || str[ansp]=='0')){
		l=(l*10+str[ansp]-'0')%a;
		r=(r-h[ansp]+b)%b;
		++ansp;
	}
	for(int i=0;i<ansp;++i)
		o1[i]=str[i];
	for(int i=ansp;i<len;++i)
		o2[i-ansp]=str[i];
	if(ansp==len) puts("NO");
	else{
		puts("YES");
		puts(o1);
		puts(o2);
	}
	return 0;
}
