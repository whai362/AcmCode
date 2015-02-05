//Memory Time 
//1052K  47MS 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
	int N;   //物品种数（面额种数）	
	int cash;  //背包容量（最大可取金额）
	int i,j;
	while(cin>>cash>>N){
		/*Input*/
		int* n=new int[N+1];  //n[i]第i种物品的个数（第i种面额的数量）
		int* w=new int[N+1];  //w[i]第i种物品的价值（第i种面额的价值）
		int* dp=new int[cash+1];  //dp[j]记录的是 当前最接近状态j且<=j的值，dp值会累积
		int* count=new int[cash+1];//计数器，限制某种物品（面额）的选取个数
		for(i=1;i<=N;i++){
			cin>>n[i]>>w[i];
		}

		/*Initial*/
		memset(dp,0,4*(cash+1));  //由于dp申请的是动态内存，用sizeof计算长度会出错
		//这里要用 类型大小*个数,这里为 int*(cash+1) , int大小为4
		
		/*DP*/
		for(i=1;i<=N;i++){
			memset(count,0,4*(cash+1));  //每更换一次面额，计数器清零
			for(j=w[i];j<=cash;j++)      //对于第i种货币，其面额d[i]~cash间任一个状态都可能发生
			  if(dp[j]<dp[j-w[i]]+w[i] && count[j-w[i]]<n[i]){	//count[j-c[i]]<n[i],取某种面额前，必须保证这次操作之前所取该种面额的次数小于n[i]
				  dp[j] = dp[j-w[i]]+w[i];	//选取第i个物品后，背包容量（允许取的最大金额）减少c[i]
				  count[j]=count[j-w[i]]+1;	//对于当前状态j，第i种面额被抽了count[j]次
			  }
		}

		/*Output*/
		cout<<dp[cash]<<endl;
		
		/*Release Space*/
		delete n;
		delete w;
		delete dp;
		delete count;
	}
	return 0;
}

