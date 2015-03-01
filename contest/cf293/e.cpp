#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int INF=1e9+10;
char num[30];
LL a[100005];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%s",num);
		a[i]=INF;
		if(num[0]!='?') sscanf(num,"%I64d",&a[i]);
	}
	int flag=1;
	for(int i=0;i<n;++i){
		if(a[i]!=INF) continue;
		if(i<k-1){
			int p=i+2;
			if(p>=n) a[i]=0;
			else a[i]=min((LL)0,a[p]-1);
		}
		else{
			int p=i-2;
			a[i]=a[p]+1;
		}
		int pre=i-2;
		int bac=i+2;
		if(pre>=0 && a[i]<=a[pre]){ flag=0; break; }
		if(bac<n && a[i]>=a[bac]){ flag=0; break; }
	}
	if(flag==0) puts("Incorrect sequence");
	else{
		for(int i=0;i<n;++i){
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
