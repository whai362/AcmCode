/*
遇到素数需要打表时，先估算素数的个数：
num = n / lnx;
num为大概数字，越大误差越小（只是估计，用于估算素数表数组大小）
这个打表法效率貌似很高，网上说几乎达到了线性时间（不知道是真是假=。=）
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
int n;
bool visit[10100000];
int prime[10000000];


void init_prim()
{
	memset(visit, true, sizeof(visit));
	int num = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (visit[i] == true)
		{
			num++;
			prime[num] = i;
		}
		for (int j = 1; ((j <= num) && (i * prime[j] <= n));  ++j)
		{
			visit[i * prime[j]] = false;
			if (i % prime[j] == 0) break; //点睛之笔
		}
	}
}

int main()
{
	memset(prime, 0, sizeof(prime));
	int count = 0;
	cin>>n;
	init_prim();
	for(int i = 0; i <= n; ++i)
		if(prime[i])
		{
			cout<<prime[i]<<" ";
			count++;
		}
		cout<<endl;
		cout<<"素数个数为："<<count<<endl;
}        

