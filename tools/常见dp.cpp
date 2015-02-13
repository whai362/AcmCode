1.	DP问题常见模型的状态转移方程
1)	最长公共子串
一二维分别表示两个字符串的长度
dp[i][j] = dp[i-1][j-1] + 1; str[i] == str[j]
dp[i][j] =  0; str[i] != str[j]

2)	最长上升或下降子序列
给定一个序列a1,a2..........an;
dp[i]表示以ai结尾的最长上升子序列长度(下降相反）
for(i=1;i<=n;i++){
       dp[i]=1;
       for（k=1;k<i;k++){
            if(ak<ai&&dp[i]<dp[k]+1)
              dp[i]=dp[k]+1;
       }
}

3)	01背包问题
有N件物品和一个容量为V的背包。第i件物品的体积是v[i]，价值是c[i]。求解将哪些物品装入背包可使价值总和最大。
for(i=1;i<=n;++i){
       for(j=V;j>=0;j--){
            if(j>=v[i])
              dp[j]=max{dp[j],dp[j-v[i]]+c[i]};
       }
}

4)	完全背包问题
有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的体积是v[i]，价值是c[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
for（i=1;i<=n;i++）{
    for(j=v[i];j<=V;j++){//注意这里是从v[i]开始到Ｖ
        dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
    }
}

5)	多重背包问题
有N种物品和一个容量为V的背包。第i种物品最多有n[i]件可用，每件费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
for(i=1;i<=n;i++){
    for(j=V;j>=0;j--){
        for(k=1;k<=n[i];k++){
            if(j>=k*v[i])
                dp[i][j]=max(dp[i-1][v-k*v[i]]+k*c[i]);
        }
    }
}

6)	最大m子段和
最大m子段和问题：给定由n个整数（可能为负）组成的序列a1、a2、a3...,an,以及一个正整数m，要求确定序列的m个不相交子段，使这m个子段的总和最大。
dp[i][j] 表示以第i个元素为结尾,使用j个子段所能达到的最大值
dp[i][j] = max(dp[i - 1][j] + a[i], 	//把第i个元素包含在最后一个子段内
			   dp[k][j - 1] + a[i]		//第i个元素单独为一子串
			   )(k=j-1…i-1);	
简化算法：
dp0[i][j]表示以第i个元素为结尾,使用j个子段所能达到的最大值
dp1[i][j]表示前i个元素，使用j个子段所能达到的最大值	
dp0[i][j]=max(dp0[i-1][j],dp1[i-1][j-1])+a[i];
dp1[i][j]=max(dp1[i-1][j],dp0[i][j]);	//分是否加入第i个元素来转移

int gao(int m,int n){
    memset(dp0,0,sizeof(dp0));
    memset(dp1,0,sizeof(dp1));
    int _max;
    for(int i=1;i<=m;++i){
        _max=-INF;
        for(int j=i;j<=n;++j){
            dp0[j]=max(dp0[j-1],dp1[j-1])+a[j];
            dp1[j-1]=_max;
            _max=max(dp0[j],_max);
        }
    }
    return _max;
}

