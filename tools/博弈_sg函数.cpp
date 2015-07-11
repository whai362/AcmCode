/*sg(Sprague-Grundy)函数
  sg值：一个点的SG值就是一个不等于它的后继点的SG的且大于等于零的最小整数。
  后继点：也就是按照题目要求的走法，能够走一步达到的那个点。

  sg函数值的性质：
  sg(x)==0 必败点
  sg(x)>0 必胜点
 */

//求单个sg函数值
int sg[MAXN];
int get_sg(int x, int n){
	if(sg[x]!=-1)
		return sg[x];
	bool vis[105]={0};
	for(int i=0;i<n;++i){
		int tmp = a[i]; //tmp是转移的下一个状态的步数
		if(x >= tmp){
			sg[x - tmp] = get_sg(x - tmp, n);
			vis[sg[x - tmp]] = 1;
		}
	}
	for(int i=0;;++i)
		if(!vis[i]) return sg[x]=i;
}
void init(){
	memset(sg,-1,sizeof(sg));
	sg[0]=0;
}

//预处理sg值
void get_sg(){
	sg[0]=0;
	for(int i=1;i<N;++i){
		set<int> s;
		for(int j=0;j<10;++j){
			int tmp=(1<<j); //tmp是转移的下一个状态的步数
			if(i >= tmp)
				s.insert(sg[i - tmp]);
		}
		int g=0;
		while(s.count(g)!=0) ++g;
		sg[i]=g;
	}
}

/*hdu 1847
  题意：
  1. 总共n张牌;
  2. 双方轮流抓牌；
  3. 每人每次抓牌的个数只能是2的幂次（即：1，2，4，8，16…）
  4. 抓完牌，胜负结果也出来了：最后抓完牌的人为胜者；
  假设Kiki和Cici都是足够聪明，并且每次都是Kiki先抓牌，请问谁能赢呢？
  限制：
  1 <= n <= 1000
  思路：
  sg函数
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int N=1005;
const int M=105;
int sg[N];

/*int get_sg(int x){
	if(sg[x]!=-1)
		return sg[x];
	bool vis[M];
	memset(vis,0,sizeof(vis));

	for(int i=0;i<10;++i){
		int tmp = (1<<i);
		if(x >= tmp){
			sg[x - tmp] = get_sg(x - tmp);
			vis[sg[x - tmp]] = 1;
		}
	}
	for(int i=0;;++i)
		if(!vis[i]) return i;
}
void get_sg(){
	sg[0]=0;
	for(int i=1;i<=1000;++i){
		sg[i]=get_sg(i);
	}
}*/

void get_sg(){
	sg[0]=0;
	for(int i=1;i<N;++i){
		set<int> s;
		for(int j=0;j<10;++j){
			int tmp=(1<<j);
			if(i >= tmp)
				s.insert(sg[i - tmp]);
		}
		int g=0;
		while(s.count(g)!=0) ++g;
		sg[i]=g;
	}
}

void init(){
	memset(sg,-1,sizeof(sg));
}

int main(){
	init();
	
	get_sg();

	int n;
	while(scanf("%d",&n)!=EOF){
		if(sg[n]==0)
			puts("Cici");
		else
			puts("Kiki");
	}
	return 0;
}
