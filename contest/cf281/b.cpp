#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define LL __int64
const int N=200005;
LL eq=0;
LL s1[N],s2[N];
int last;
int main(){
	int n;
	LL a;
	cin>>n;
	int c1=0,c2=0;
	for(int i=0;i<n;++i){
		cin>>a;
		eq+=a;
		if(a>0)
			s1[c1++]=a;
		else
			s2[c2++]=-a;
		if(i==n-1){
			if(a>0) last=1;
			else last=2;
		}
	}
	if(eq>0) puts("first");
	else if(eq<0) puts("second");
	else{
		int flag=0;
		int lim=min(c1,c2);
		for(int i=0;i<lim;++i){
			if(s1[i]>s2[i]){
				flag=1;
				break;
			}
			else if(s1[i]<s2[i]){
				flag=2;
				break;
			}
		}
		if(flag==1) puts("first");
		else if(flag==2) puts("second");
		else{
			if(c1>c2) puts("first");
			else if(c1<c2) puts("second");
			else{
				if(last==1) puts("first");
				else puts("second");
			}
		}
	}
	return 0;

}
