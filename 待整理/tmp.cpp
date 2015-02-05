#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10];
int main(){
	int n,m;
	char num[10];
	while(cin>>m){
		memset(a,0,sizeof(a));
	for(int i=0;i<=m;++i){
		sprintf(num,"%d",i);
		int len=strlen(num);
		for(int j=0;j<len;++j){
			++a[num[j]-'0'];
		}
	}
	for(int i=0;i<10;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	}
	return 0;
}
