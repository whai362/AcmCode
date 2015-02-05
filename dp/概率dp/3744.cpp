/*
   题意：
   n个雷，走一步的概率为p，走两步的概率为1-p，求安全通过雷区的概率。
   (1<=n<=10,0.25<=p<=0.75,1<=mine_pos<=1e8)
   题解：
   设dp[i]表示安全通过第i个点的概率，则有：
   dp[i]=dp[i-1]*p+dp[i-2]*(1-p);
   考虑到mine_pos<=1e8，所以用矩阵快速幂：
   [dp[i-1] dp[i-2]] * [p   1] = [dp[i] dp[i-1]]
					    1-p 0
   然后一些特殊情况特殊处理。
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;
struct Matrix{
	double a[2][2];
	int x,y;
}ans,fac;
int n,
	pos[15];
double p;
bool find(int _pos){
	for(int i=0;i<n;++i){
		if(_pos==pos[i]) return true;
	}
	return false;
}
Matrix mul(Matrix &a,const Matrix &b){
	Matrix ret;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<b.y;++j){
			double d=0;
			for(int k=0;k<a.y;++k)
				d=d+a.a[i][k]*b.a[k][j];
			ret.a[i][j]=d;
		}
	}
	ret.x=a.x;
	ret.y=b.y;
	return ret;
}
Matrix power(Matrix m,int n){
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	for(int i=0;i<2;++i)
		ret.a[i][i]=1;
	ret.x=ret.y=2;
	for(int i=1;i<=n;i<<=1){
		if(i&n)
			ret=mul(ret,m);
		m=mul(m,m);
	}
	return ret;
}
void cal(int _pos){
	Matrix tmp;
	tmp.x=tmp.y=2;
	if(find(_pos)){
		tmp.a[0][0]=0;
		tmp.a[0][1]=0;
	}
	else{
		tmp.a[0][0]=p;
		tmp.a[0][1]=1;
	}
	if(find(_pos-1)) tmp.a[1][0]=0;
	else tmp.a[1][0]=1-p;
	tmp.a[1][1]=0;
	ans=mul(ans,tmp);
}
int main(){
	while(scanf("%d%lf",&n,&p)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d",&pos[i]);
		}
		sort(pos,pos+n);

		memset(ans.a,0,sizeof(ans.a));	
		ans.x=1;
		ans.y=2;
		if(pos[0]==1) ans.a[0][0]=0;
		else ans.a[0][0]=1;

		fac.x=fac.y=2;
		fac.a[0][0]=p;
		fac.a[0][1]=1;
		fac.a[1][0]=1-p;
		fac.a[1][1]=0;

		for(int i=0;i<n;++i){
			int pow;
			if(i) pow=pos[i]-pos[i-1]-2;
			else pow=pos[i]-1;
			if(pow>0) ans=mul(ans,power(fac,pow));
			cal(pos[i]);
			//cout<<'!'<<ans.a[0][0]<<' '<<ans.a[0][1]<<endl;
			if(i!=n-1) cal(pos[i]+1);
			//cout<<'!'<<ans.a[0][0]<<' '<<ans.a[0][1]<<endl;
		}
		cout<<fixed<<setprecision(7)<<ans.a[0][0]<<endl;
	}
	return 0;
}
