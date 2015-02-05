/* ***********************************************
Author        :kuangbin
Created Time  :2014/10/7 21:21:32
File Name     :E:\2014ACM\专题学习\数学\快速数论变换\HDU4656.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL __int64
//*********************************
//快速数论变换(NTT)
//求A和B的卷积，结果对P取模
//做长度为N1的变换，选取两个质数P1和P2
//P1-1和P2-1必须是N1的倍数
//E1和E2分别是P1,P2的原根
//F1是E1模P1的逆元,F2是E2模P2的逆元
//I1是N1对模P1的逆元,I2是N1对模P2的逆元
//
//然后使用中国剩余定理，保证了结果是小于MM=P1*P2的
//M1 = (P2对P1的逆元)*P2
//M2 = (P1对P2的逆元)*P1

const int P = 1000000007;//结果对P取模
const int N1 = 262144;// 2^{18}
const int N2 = N1+1;//数组大小
const int P1 = 998244353;//P1 = 2^{23}*7*17 + 1
const int P2 = 995622913;//P2 = 2^{19}*3*3*211 + 1
const int E1 = 996173970;
const int E2 = 88560779;
const int F1 = 121392023;//E1*F1 = 1(mod P1)
const int F2 = 840835547;//E2*F2 = 1(mod P2)
const int I1 = 998240545;//I1*N1 = 1(mod P1)
const int I2 = 995619115;//I2*N1 = 1(mod P2)
const LL M1 = 397550359381069386LL;
const LL M2 = 596324591238590904LL;
const LL MM = 993874950619660289LL;//MM = P1*P2
//计算x*y对z取模
LL mul(LL x,LL y,LL z){
	return (x*y - (LL)(x/(long double)z*y+1e-3)*z+z)%z;
}
int trf(int x1,int x2){
	return (mul(M1,x1,MM)+mul(M2,x2,MM))%MM%P;
}
int A[N2],B[N2],C[N2];
int A1[N2],B1[N2],C1[N2];
void fft(int *A,int PM,int PW){
	for(int m = N1,h;h = m/2, m >= 2;PW = (LL)PW*PW%PM,m=h)
		for(int i = 0,w=1;i < h;i++, w = (LL)w*PW%PM)
			for(int j = i;j < N1;j += m){
				int k = j+h, x = (A[j]-A[k]+PM)%PM;
				(A[j]+=A[k])%=PM;
				A[k] = (LL)w*x%PM;
			}
	for(int i = 0,j = 1;j < N1-1;j++){
		for(int k = N1/2; k > (i^=k);k /= 2);
		if(j < i)swap(A[i],A[j]);
	}
}
//计算A和B的卷积，结果保存在C中，结果对P取模
void mul(){
	memset(C,0,sizeof(C));
	memcpy(A1,A,sizeof(A));
	memcpy(B1,B,sizeof(B));
	fft(A1,P1,E1); fft(B1,P1,E1);
	for(int i = 0;i < N1;i++)C1[i] = (LL)A1[i]*B1[i]%P1;
	fft(C1,P1,F1);
	for(int i = 0;i < N1;i++)C1[i] = (LL)C1[i]*I1%P1;
	fft(A,P2,E2); fft(B,P2,E2);
	for(int i = 0;i < N1;i++)C[i] = (LL)A[i]*B[i]%P2;
	fft(C,P2,F2);
	for(int i = 0;i < N1;i++)C[i] = (LL)C[i]*I2%P2;
	for(int i = 0;i < N1;i++)C[i] = trf(C1[i],C[i]);
}
//int INV[P];//逆元
const int MAXN = 100010;
int F[MAXN];//阶乘
int a[MAXN];
int pd[MAXN];
int pb[MAXN];
int pc2[MAXN];
int p[MAXN];
#
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

LL Inv(LL a,int m){   //求逆元
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

int main()
{
    //预处理逆元
	//INV[1] = 1;
	//for(int i = 2;i < P;i++)
	//	INV[i] = (LL)P/i*(P-INV[P%i])%P;
	//F[0] = 1;
	//for(int i = 1;i < MAXN;i++)
	//	F[i] = (LL)F[i-1]*i%P;
	A[0]=Inv(2,P);
	B[0]=1;
	mul();
	for(int i=0;i<10;++i){
		cout<<(C[i]*(-1)%P+P)%P<<' ';
	}
	cout<<endl;
	return 0;
}
