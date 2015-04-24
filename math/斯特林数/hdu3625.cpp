/*hdu 3625 Examining the Rooms
  题意：
  好难描述
  思路：
  第一类斯特林数，其实分子就是枚举房间1和剩下的房间绑在一起的情况，为(n-1)*sigma(i=1~k,sti[n-1][i])。
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
LL sti[25][25];
void get_sti(int n){
	for(int i=1;i<=n;++i){
		sti[i][0]=0;
		sti[i][i]=1;
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;++j){
			sti[i][j]=(i-1)*sti[i-1][j]+sti[i-1][j-1];
		}
	}
}
void print(int n){
	LL sum;
	for(int i=1;i<=n;++i){
		sum=0;
		for(int j=0;j<=i;++j){
			cout<<sti[i][j]<<' ';
			sum+=sti[i][j];
		}
		cout<<endl;
		//cout<<sum<<endl;
	}
}
int main(){
	get_sti(20);
	//print(20);
	int n,k;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		double fz=0.0,fm=0.0;
		for(int i=0;i<=k;++i){
			fz+=(double)sti[n-1][i];
		}
		for(int i=0;i<=n;++i){
			fm+=(double)sti[n][i];
		}
		//cout<<fz<<' '<<fm<<endl;
		printf("%.4f\n",fz*(n-1)/fm);
	}
	return 0;
}
