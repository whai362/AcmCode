#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[105];
	int cnt=0,i,j,l;
	scanf("%s",a);
	l=strlen(a);
	for(i=0;i<l;){
		for(j=i;j<l && j<i+5;++j){
			if(a[i]!=a[j]) break;
			//cout<<i<<endl;
		}
		//cout<<j<<endl;
		i=j;
		//cout<<i<<endl;
		++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
