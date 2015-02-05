/*
   题意：
   给出一个5*6的01矩阵，给出初状态，和操作：每次操作会对该数和它四周的数进行翻转，求一种翻转方案。
   题解：
   高斯消元。
 */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=35;
int mat[10][10];

//高斯消元整数模板
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

bool in(int x,int y){
	if(x>=0 && x<5 && y>=0 && y<6)
		return true;
	return false;
}
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
void build(int x,int y){
	int u=x*6+y,v;
	a[u][u]=1;
	a[u][30]=mat[x][y]^0;
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i],
			tmpy=y+dy[i];
		if(in(tmpx,tmpy)){
			v=tmpx*6+tmpy;
			a[v][u]=1;
		}
	}
}
int main(){
	int cas=0,T;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		for(int i=0;i<5;++i){
			for(int j=0;j<6;++j){
				scanf("%d",&mat[i][j]);
				build(i,j);
			}
		}
		int ans=gauss(30,30);
		//cout<<ans<<endl;
		printf("PUZZLE #%d\n",++cas);
		for(int i=0;i<30;++i){
			printf("%d%c",x[i],(i+1)%6!=0?' ':'\n');
		}
	}
	return 0;
}
