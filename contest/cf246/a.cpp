#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int i,cnt=0,n,k;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		int a;
		scanf("%d",&a);
		if(a+k<=5)
			++cnt;
	}
	cout<<cnt/3<<endl;
	return 0;
}
