#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int MOD=1e9+7;

struct Matrix{
    LL a[35][35];	//
    int n,m;
    Matrix(int _n=0,int _m=0,LL val=0){
        n=_n; m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=(i==j?val:0);
    }
    void print(){
        for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<' ';
        puts("");
    }
    Matrix operator *(Matrix tmp){
        Matrix ret(n,tmp.m);
        for(int i=0;i<n;i++)
            for(int j=0;j<tmp.m;j++)
                for(int k=0;k<m;k++)
                    ret.a[i][j]=(ret.a[i][j]+a[i][k]*tmp.a[k][j])%MOD;	//
        return ret;
    }
}A[65][35],pre[35],suf[35];
LL n,k;
void init(){
	for(int i=0;i<65;++i)
		for(int j=0;j<k;++j)
			A[i][j]=Matrix(k+1,k+1,0);
	for(int i=0;i<k;++i)
		pre[i]=suf[i]=Matrix(k+1,k+1,0);
	for(int i=0;i<k;++i)
		for(int j=0;j<k+1;++j)
			A[0][i].a[j][j]=A[0][i].a[j][i]=1;
}

void predo(int i){
	if(i==0) return ;
	pre[0]=A[i-1][0];
	for(int j=1;j<k;++j)
		pre[j]=pre[j-1]*A[i-1][j];
	suf[k-1]=A[i-1][k-1];
	for(int j=k-2;j>=0;--j)
		suf[j]=A[i-1][j]*suf[j+1];
	A[i][0]=suf[0];
	for(int j=1;j<k;++j){
		A[i][j]=suf[j]*pre[j-1];
		//A[i][j].print();
	}
}

void gao(){
	int m=0;
	Matrix ans=Matrix(k+1,k+1,1);
	while(n){
		LL x=0,tmp=n;
		predo(m);
		while(tmp){
			x=(x+tmp/k)%k;
			tmp/=k;
		}
		cout<<n<<' '<<x<<endl;
		for(int i=n%k-1;i>=0;--i)
			ans=A[m][(i+x)%k]*ans;
		++m;
		n/=k;
	}
	//ans.print();
	LL out=1;
	for(int i=0;i<k;++i)
		out=(out+ans.a[k][i])%MOD;
	printf("%I64d\n",out);
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	init();
	gao();
	return 0;
}
