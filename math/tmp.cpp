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

const int P = 1000000007;//结果对P取模
const int N1 = 262144;// 2^{18}
const int N2 = N1+1;//数组大小
const int P1 = 998244353;//P1 = 2^{23}*7*17 + 1
const int P2 = 995622913;//P2 = 2^{19}*3*3*211 + 1
const int P3 = 1004535809;
const int E1 = 996173970;
const int E2 = 88560779;
const int E3 = 3;
const int F1 = 121392023;//E1*F1 = 1(mod P1)
const int F2 = 840835547;//E2*F2 = 1(mod P2)
const int F3 = 334845270;
const int I1 = 998240545;//I1*N1 = 1(mod P1)
const int I2 = 995619115;//I2*N1 = 1(mod P2)
const int I3 = 1004531977;
//计算x*y对z取模
LL mul(LL x,LL y,LL z){
	return (x*y - (LL)(x/(long double)z*y+1e-3)*z+z)%z;
}
int A[N2],B[N2],C[N2];
int A1[N2],B1[N2],C1[N2];
int A2[N2],B2[N2],C2[N2];
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
int M1,M2,M3,t1,t2,t3;
void init(){
	M1=(LL)P2*P3%P;
	M2=(LL)P1*P3%P;
	M3=(LL)P1*P2%P;
	t1=Inv(M1,P1)%P;
	t2=Inv(M2,P2)%P;
	t3=Inv(M3,P3)%P;
}

int CRT(int a1,int a2,int a3){
	LL ret=0;
	ret=(LL)a1*t1%P*M1%P;
	ret=(ret+(LL)a2*t2%P*M2%P)%P;
	ret=(ret+(LL)a3*t3%P*M3%P)%P;
	return (int)ret;
}

//计算A和B的卷积，结果保存在C中，结果对P取模
void mul(){
	init();
	memset(C,0,sizeof(C));
	memcpy(A1,A,sizeof(A));
	memcpy(B1,B,sizeof(B));
	memcpy(A2,A,sizeof(A));
	memcpy(B2,B,sizeof(B));
	fft(A1,P1,E1); fft(B1,P1,E1);
	for(int i = 0;i < N1;i++)C1[i] = (LL)A1[i]*B1[i]%P1;
	fft(C1,P1,F1);
	for(int i = 0;i < N1;i++)C1[i] = (LL)C1[i]*I1%P1;
	
	fft(A2,P2,E2); fft(B2,P2,E2);
	for(int i = 0;i < N1;i++)C2[i] = (LL)A2[i]*B2[i]%P2;
	fft(C2,P2,F2);
	for(int i = 0;i < N1;i++)C2[i] = (LL)C2[i]*I2%P2;

	fft(A,P3,E3); fft(B,P3,E3);
	for(int i = 0;i < N1;i++)C[i] = (LL)A[i]*B[i]%P3;
	fft(C,P3,F3);
	for(int i = 0;i < N1;i++)C[i] = (LL)C[i]*I3%P3;
	
	for(int i=0;i<10;++i){
		cout<<C1[i]<<' '<<C2[i]<<' '<<C[i]<<endl;
	}

	for(int i = 0;i < N1;i++)C[i] = CRT(C1[i],C2[i],C[i]);
}
//int INV[P];//逆元
const int MAXN = 100010;
int F[MAXN];//阶乘
int a[MAXN];
int pd[MAXN];
int pb[MAXN];
int pc2[MAXN];
int p[MAXN];

int main(){
	init();
	cout<<CRT(499122177,497811457,502267905)<<endl;
	//A[0]=Inv(2,P);
	//B[0]=1;
	//mul();
	//F[0]=1;
	//for(int i=1;i<10;++i){
	//	F[i]=F[i-1]*i%P;
	//}
	//for(int i=0;i<10;++i){
	//	//cout<<C[i]<<' ';
	//	cout<<(C[i]*(-F[i+1])%P+P)%P<<' ';
	//}
	//cout<<endl;
	return 0;
}
