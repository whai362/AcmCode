#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
const int N=1005;
const int MOD=1000003;
LL a[N];
int bit[32][2];
LL fa[N],ny[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}

void predo(){
	fa[0]=ny[0]=1;
	for(int i=1;i<N;++i){
		fa[i]=fa[i-1]*i%MOD;
		ny[i]=inv(fa[i],MOD);
	}
}
LL C(int n,int m){
	if(m>n) return 0;
	return fa[n]*ny[m]%MOD*ny[n-m]%MOD;
}
void gao(int n){
	for(int i=1;i<=n;++i){
		for(int j=0;j<=31;++j){
			if(a[i] & (1<<j)) ++bit[j][1];
			else ++bit[j][0];
		}
	}

	//for(int i=0;i<5;++i){
	//	cout<<bit[i][0]<<' '<<bit[i][1]<<endl;
	//}

	for(int i=1;i<=n;++i){
		LL ans=0;
		LL mul=1;
		//cout<<endl;
		for(int j=0;j<=31;++j){
			LL sum=0;
			for(int k=1;k<=i;k+=2){
				//if(j==0 && i==2) cout<<bit[j][0]<<' '<<i-k<<endl;
				sum=(sum+C(bit[j][0],i-k)*C(bit[j][1],k))%MOD;
			}
			//cout<<sum<<' ';
			ans=(ans+sum*mul)%MOD;
			mul=mul*2%MOD;
		}
		//cout<<endl;
		cout<<ans;
		if(i==n) cout<<endl;
		else cout<<' ';
	}
}
void init(){
	memset(bit,0,sizeof(bit));
}
int main(){
	int n;
	predo();
	while(cin>>n){
		init();
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		gao(n);
	}
	return 0;
}
