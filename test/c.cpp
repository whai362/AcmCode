#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5*1e5+5;
char str[N];
int len;
bool ok(int x,int k){
	int cnt=0;
	for(int i=0;i<len;++i){
		if(str[i]=='1'){
			++cnt;
			i=i+x-1;
		}
	}
	return (cnt<=k);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		scanf("%s",str);
		len=strlen(str);
		//cout<<ok(1,k)<<endl;
		int l=0,r=n,mid=(1+n)>>1;
		while(l<r){
			if(ok(mid,k))
				r=mid;
			else
				l=mid+1;
			mid=(l+r)>>1;
			//cout<<l<<' '<<r<<endl;
		}
		printf("%d\n",l);
	}
	return 0;
}
