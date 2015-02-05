#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	int t=0,cnt=0;
	while(n>0){
		if(t && t%m==0) ++n;
		if(t && t%k==0) --n,++cnt;
		cout<<t<<' '<<n<<' '<<cnt<<endl;
		++t;
	}
	cout<<cnt<<endl;
	return 0;
}
