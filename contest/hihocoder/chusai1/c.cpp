#include<cstdio>
#include<iostream>
using namespace std;
long long ans[21]={0,2,5,18,45,138,405,1242,3429,10530,31293,94338,282285,847098,2540565,7623882,21972789,66812850,199539693,599531058,1797659325};
int main(){
	int n,m,t;
	int l;
	scanf("%d",&t);
	for(l=1;l<=t;++l){
		scanf("%d%d",&n,&m);
		cout<<"Case "<<l<<": "<<ans[n]%m<<endl;
	}
	return 0;
}
