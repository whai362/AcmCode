#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define M 100010
#define MAXN 500
#define MAXM 500
int dp[M][18];
/*
*一维RMQ ST算法
*构造RMQ数组 makermq(int n,int b[]) O(nlog(n))的算法复杂度
*dp[i][j] 表示从i到i+2^j -1中最小的一个值(从i开始持续2^j个数)
*dp[i][j]=min{dp[i][j-1],dp[i+2^(j-1)][j-1]}
*查询RMQ rmq(int s,int v)
*将s-v分成两个2^k的区间
*即k=(int)log2(s-v+1)
*查询结果应该为 min(dp[s][k],dp[v-2^k+1][k])
*/
void makermq(int n,int b[]){
    for(int i=0;i<n;i++)
        dp[i][0]=b[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int s,int v){
    int k=(int)(log((v-s+1)*1.0)/log(2.0));
    return min(dp[s][k],dp[v-(1<<k)+1][k]);
}

void makeRmqIndex(int n,int b[]){ //返回最小值对应的下标
    for(int i=0;i<n;i++)
        dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            dp[i][j]=b[dp[i][j-1]] < b[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}
int rmqIndex(int s,int v,int b[]){
    int k=(int)(log((v-s+1)*1.0)/log(2.0));
    return b[dp[s][k]]<b[dp[v-(1<<k)+1][k]]? dp[s][k]:dp[v-(1<<k)+1][k];
}
int main(){
    int a[]={3,4,5,7,8,9,0,3,4,5};
    //返回下标
    makeRmqIndex(sizeof(a)/sizeof(a[0]),a);
    cout<<rmqIndex(0,9,a)<<endl;
    cout<<rmqIndex(4,9,a)<<endl;
    //返回最小值
    makermq(sizeof(a)/sizeof(a[0]),a);
    cout<<rmq(0,9)<<endl;
    cout<<rmq(4,9)<<endl;
    return 0;
}
