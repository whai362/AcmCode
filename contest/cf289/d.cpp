/*cf 509D Restoring Numbers
  题意：
  v[i][j]=(a[i]+b[j])%k
  现在给出n*m矩阵v[][], 求a[],b[]和k, 任意一种情况都行。
  限制：
  1 <= n,m <= 100; 0 <= v[i][j] <= 100
  思路：
  对于数组a[], 无论怎么变, 数组之间的差始终不变, b[]也同理
  利用这个求出k
  再设a[0]=0,b[0]=0,求出剩下的东西。
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
#define PB push_back
const int N=105;
const LL INF=(LL)3*1e9;
LL a[N][N];
vector<LL> r[N],c[N];
LL A[N],B[N];
LL _abs(LL a){
	if(a<0) return -a;
	return a;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%I64d",&a[i][j]);
	for(int i=0;i<n;++i)
		for(int j=1;j<m;++j)
			r[i].PB(a[i][j]-a[i][j-1]);
	for(int i=0;i<m;++i)
		for(int j=1;j<n;++j)
			c[i].PB(a[j][i]-a[j-1][i]);
	LL MOD=INF;
	int flag=0;
	for(int i=0;i<m-1;++i){
		for(int j=1;j<n;++j){
			if(r[j][i]==r[j-1][i]) continue;
			else{
				if(flag==0){
					MOD=_abs(r[j][i]-r[j-1][i]);
					flag=1;
				}
				else{
					if((r[j][i]+MOD)%MOD==(r[j][i]+MOD)%MOD) continue;
					else{ flag=-1; break; }
				}
			}
		}
		if(flag==-1) break;
	}
	for(int i=0;i<n-1;++i){
		for(int j=1;j<m;++j){
			if(c[j][i]==c[j-1][i]) continue;
			else{
				if(flag==0){
					MOD=_abs(c[j][i]-c[j-1][i]);
					flag=1;
				}
				else if(flag==-1) break;
				else{
					if((c[j][i]+MOD)%MOD==(c[j-1][i]+MOD)%MOD) continue;
					else{ flag=-1; break; }
				}
			}
		}
		if(flag==-1) break;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			if(a[i][j]>=MOD){ flag=-1; break; }
		if(flag==-1) break;
	}
	if(flag==-1) puts("NO");
	else{
		puts("YES");
		for(int i=0;i<n;++i)
			for(int j=0;j<m-1;++j)
				r[i][j]=(r[i][j]+MOD)%MOD;
		for(int i=0;i<m;++i)
			for(int j=0;j<n-1;++j)
				c[i][j]=(c[i][j]+MOD)%MOD;
		printf("%I64d\n",MOD);
		A[0]=0;
		B[0]=a[0][0];
		printf("%I64d",A[0]);
		for(int i=0;i<c[0].size();++i){
			A[i+1]=A[i]+c[0][i];
			printf(" %I64d",A[i+1]);
		}
		printf("\n%I64d",B[0]);
		for(int i=0;i<r[0].size();++i){
			B[i+1]=B[i]+r[0][i];
			printf(" %I64d",B[i+1]);
		}
		puts("");
	}
	return 0;
}
