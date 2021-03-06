#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
double p;
int flag[25][25];


const int N=215;
const double eps=1e-12;
double a[N][N]; //方程的左边的矩阵和等式右边的值
double x[N];	//求解之后x存的就是结果
int equ,var;	//方程数和未知数个数

void Gauss(){
	int row,col,max_r;
	int i,j;
	row = col = 0;
	while(row < equ && col < var){
		max_r = row;
		for(i = row+1; i < equ; i++)
			if(fabs(a[i][col])-fabs(a[max_r][col]) > eps)
				max_r = i;

		if(max_r != row){
			for(j = col; j <= var; j++)
				swap(a[row][j],a[max_r][j]);
		}
		if(fabs(a[row][col]) < eps){
			col++;
			continue;
		}

		for(i = row+1; i < equ; i++){
			if(fabs(a[i][col]) > eps){
				double t = a[i][col]/a[row][col];
				a[i][col] = 0.0;
				for(j = col+1; j <= var; j++)
					a[i][j] -= a[row][j]*t;
			}
		}
		row++;
		col++;
	}
	for(i = equ-1; i >= 0; i--){
		if(fabs(a[i][i]) < eps) continue;
		double tmp = a[i][var];
		for(j = i+1; j < var; j++)
			tmp -= a[i][j]*x[j];
		x[i] = tmp/a[i][i];
	}
}

int main(){
	int cnt=0;
	for(int i=0;i<20;++i){
		for(int j=0;j<=i;++j){
			flag[i][j]=cnt++;
		}
	}
	while(~scanf("%lf",&p)){
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		for(int i=0;i<20;++i){
			for(int j=0;j<i;++j){
				int u=flag[i][j];
				a[u][u]=1;
				a[u][210]=1;
				a[u][flag[i][max(0,j-2)]]-=1-p;
				a[u][flag[i][j+1]]-=p;
			}
			int u=flag[i][i];
			a[u][u]=1;
			a[u][210]=1;
			a[u][flag[i][max(0,i-2)]]-=1-p;
			if(i+1<20) a[u][flag[i+1][i]]-=p;
		}
		equ=var=210;
		Gauss();
		printf("%.6lf\n",x[0]);
	}
	return 0;
}
