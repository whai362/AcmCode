/*======================================================
# Author: whai
#
# Last modified: 2015-10-06 15:57
#
# Filename: a1.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int MOD = 1e9 + 7;

//矩阵快速幂
struct Matrix{
	LL a[5][5];	//修改处
	int x,y;
};
int n;

Matrix mul(Matrix a,Matrix b){
	Matrix ret;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<b.y;++j){
			int tmp=0;	//修改处
			for(int k=0;k<a.y;++k){
				tmp=(tmp+a.a[i][k]*b.a[k][j]%MOD)%MOD;	//修改处
			}
			ret.a[i][j]=tmp;
		}
	}
	ret.x=a.x;
	ret.y=b.y;
	return ret;
}
Matrix power(Matrix m,int n){
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	for(int i=0;i<m.x;++i){		//不是正矩阵，修改
		ret.a[i][i]=1;
	}
	ret.x=ret.y=m.x;	//不是正矩阵，修改
	for(LL i=1;i<=n;i<<=1){
		if(i&n){
			ret=mul(ret,m);
		}
		m=mul(m,m);
	}
	return ret;
}

void gao(LL n) {
	Matrix a0;
	memset(a0.a, 0, sizeof(a0.a));
	a0.x = 1; a0.y = 3;
	a0.a[0][0] = 6;
	a0.a[0][1] = 35;
	a0.a[0][2] = 41;
	Matrix p;
	p.x = p.y = 3;
	memset(p.a, 0, sizeof(p.a));
	p.a[0][0] = p.a[2][0] = p.a[2][1] = 0;
	p.a[1][0] = p.a[2][2] = 1;
	p.a[1][1] = p.a[1][2] = 6;
	p.a[0][1] = p.a[0][2] = -1;
	p = power(p, n - 2);
	a0 = mul(a0, p);
	cout<<a0.a[0][2]<<endl;
}

int main() {
	LL n;
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		gao(n);
	}
	return 0;
}

