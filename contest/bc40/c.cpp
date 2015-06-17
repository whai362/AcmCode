/*hdu 5226 Tom and matrix
  题意：
  Tom放学回家的路上，看到天空中出现一个矩阵。Tom发现，如果矩阵的行、列从0开始标号，第i行第j列的数记为a[i][j]，那么a[i][j]=C(i,j)
  如果i < j，那么a[i][j]=0
  Tom突发奇想，想求一个矩形范围((x1,y1),(x2,y2))内所有数的和。Tom急着回家，当然不会自己算，所以就把任务交给你了。
  因为数可能很大，答案对一个质数p取模。
  限制：
  0 <= x1 <= x2 <=1e5
  0 <= y1 <= y2 <=1e5
  2 <= p <= 1e9
  思路：
  sigma(i=a~b,C(i,k)) = C(b+1,k+1) - C(a,k+1)
  还有注意模的时候注意要消除除数要与p消除公因子，再计算。也可以用lucas定理。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1e5+5;
LL f[N],ny[N];
int cnt[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}

void predo(int n,int MOD){
	f[0]=1;
	ny[0]=inv(1,MOD);
	for(int i=1;i<=n;++i){
		int tmp=i;
		while(tmp%MOD==0) tmp/=MOD;
		f[i]=f[i-1]*tmp%MOD;
		ny[i]=inv(f[i],MOD);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=2;i<=n;++i)
		for(int j=i/MOD;j>0;j/=MOD)
			cnt[i]+=j;
}
LL C(int n,int k,int MOD){
	if(k>n) return 0;
	int num=cnt[n]-cnt[k]-cnt[n-k];
	if(num) return 0;
	return f[n]*ny[k]%MOD*ny[n-k]%MOD;
}
LL cal(int l,int r,int k,int MOD){
	if(l>r) return 0;
	return (C(r+1,k+1,MOD)-C(l,k+1,MOD)+MOD)%MOD;
}
void gao(int x1,int y1,int x2,int y2,int MOD){
	LL ans=0;
	for(int i=y1;i<=y2;++i){
		int l=max(i,x1);
		int r=x2;
		//cout<<l<<' '<<r<<' '<<i<<' ';
		ans=(ans+cal(l,r,i,MOD))%MOD;
		//cout<<ans<<endl;
	}
	printf("%I64d\n",ans);
}
int main(){
	int x1,y1,x2,y2,p;
	while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&p)!=EOF){
		predo(max(x2,y2)+2,p);
		gao(x1,y1,x2,y2,p);
	}
	return 0;
}
