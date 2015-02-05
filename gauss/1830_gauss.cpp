/*
   题意：
   n个开关，给出n个开关操作前和操作后的状态，再给出有联系的开关，每行两个数i j，表示如果操作第i个开关，第j个开关的状态也会变化，求从初状态到末状态有多少种方法。
   (0<n<29)
   题解：
   高斯消元法。
   */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=35;
int st[N],en[N];

//const int N=105;
int a[N][N];	//增广矩阵
int x[N];	//解集
int free_x[N];	//标记是否是自由变元
int free_num;
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var，使用前初始化a
//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int gauss(int equ,int var){
	int max_r, col, k;
	free_num = 0;
	for(k = 0, col = 0; k < equ && col < var; k++, col++){
		max_r = k;
		for(int i = k+1 ; i < equ; i++)
			if(abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;
		if(a[max_r][col] == 0){
			k--;
			free_x[free_num++] = col; //自由变元
			continue;
		}
		if(max_r != k){
			for(int j = col; j < var+1; j++)
				swap(a[k][j],a[max_r][j]);
		}
		for(int i = k+1; i < equ;i++)
			if(a[i][col] != 0)
				for(int j = col; j < var+1;j++)
					a[i][j] ^= a[k][j];
	}
	for(int i = k;i < equ;i++)
		if(a[i][col] != 0)
			return -1;
	if(k < var)return var-k;
	for(int i = var-1; i >= 0;i--){
		x[i] = a[i][var];
		for(int j = i+1; j < var;j++)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;
}

int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&st[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&en[i]);
		memset(a,0,sizeof(a));
		int u,v;
		while(scanf("%d%d",&u,&v) && (u || v))
			a[v-1][u-1]=1; //改看看
		for(int i=0;i<n;++i)
			a[i][i]=1;
		for(int i=0;i<n;++i)
			a[i][n]=st[i]^en[i];
		int ans=gauss(n,n);
		if(ans==-1)
			puts("Oh,it's impossible~!!");
		else
			printf("%d\n",1<<ans);
	}
	return 0;
}
