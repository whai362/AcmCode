/*hdu 5165
  题意：
  Bob有一个数组{a1,a2,...,an}，数组中的每个元素都是介于1到n之间的整数。Bob还有m个函数，他们的定义域和值域都是集合{1,2,...,n}。Bob和Alice轮流开始玩游戏，Alice先开始。对于每一轮，玩家可以选择一个函数f使得数组中每个元素 ai(1 <= i <= n)变成f(ai)。例如，一开始数组是{1,1,2,4,5}，有一个函数f(1)=1,f(2)=3,f(3)=4,f(4)=1,f(5)=2。那么经过一次操作，数组变为{1,1,3,1,2}。如果数组中的所有元素都相同（无论当前论是Bob还是Alice），那么Alice胜利游戏结束。然后Bob的目的是阻止Alice胜利。 假设Alice和Bob都足够聪明，每次都采取最优策略。问：无论数组的初始状态是什么，Alice是否都能够必胜？
  输入描述：
  输入第一行包含一个整数T(1 <= T <= 200)表示测试数据组数。对于每组测试数据：第一行包含两个整数n和m(1 <= n,m <= 100)表示数组的大小和函数的个数。接下来m行，每行包含n个整数f(1),f(2),...,f(n) (1 <= f(i) <= n,1 <= i <= n)。
  输出描述：
  对于每组数据，如果Alice一定能够必胜，输出YES，否则输出NO。
  思路：
  
  1.对于Alice，如果对于每个数对(x,y),都能通过某些函数把它变成(z,z),则Alice必胜，因为由于函数不能一对多，所以这个过程是不可逆的，所以当Alice把(x,y)变成(z,z)，Bob不能把它复原，或者变成不一样的数。

  2.设(x,y)通过某些函数转换为(z,z)为过程1。
  由必胜态倒推，可以看出如果x==y，过程1总是可以成功的。
  设dp[x][y][0/1]为对于数对(x,y)，Alice先手0，后手1，过程1成功则dp[x][y][0/1]=1，否则dp[x][y][0/1]=0。
  所以，在最初的时候dp[i][i][0/1]==1。
  我们把dp[x][y][0/1]==1的全部入队，每次取最前面的一个，进行更新，更新分成两种情况：
  
  a)如果Alice此时为先手，则它的前驱为Bob先手。
  设Bob先手为事件A，要使事件A的过程1可以成功，则事件A的所有后继的过程1都是成功的。
  
  b)如果Alice此时为后手，则它的前驱为Alice先手。
  设Alice先手为事件B，要使事件B的过程1可以成功，则事件B的一个后继的过程1可以成功就行了。

  所以一开始建图的时候要建一个正向的图，一个方向的图。
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
#define MP make_pair
#define PB push_back
const int N=10005;
vector<int> mp[N],rv[N];
map< pair<int,int>,int > vis;
int f[N],p2i[N][N];
int dp[N*N][2];
int n,m;
struct Dt{
	int v,turn;
	Dt(){}
	Dt(int _v,int _turn){ v=_v; turn=_turn; }
};
queue<Dt> que;
void init(){
	int id=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			p2i[j][i]=p2i[i][j]=id++;
	for(int i=0;i<id;++i){
		mp[i].clear();
		rv[i].clear();
	}
	vis.clear();
	for(int i=0;i<id;++i){
		dp[i][0]=dp[i][1]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=0;i<m;++i){
			for(int j=1;j<=n;++j)
				scanf("%d",&f[j]);
			for(int j=1;j<=n;++j)
				for(int k=j+1;k<=n;++k){
					int fr=p2i[j][k];
					int to=p2i[f[j]][f[k]];
					if(vis[MP(fr,to)]==0){
						mp[fr].PB(to);
						rv[to].PB(fr);
						vis[MP(fr,to)]=1;
					}
				}
		}
		for(int i=1;i<=n;++i){
			que.push(Dt(p2i[i][i],0));
			que.push(Dt(p2i[i][i],1));
			dp[p2i[i][i]][0]=dp[p2i[i][i]][1]=1;
		}
		while(!que.empty()){
			Dt now=que.front();
			que.pop();
			if(now.turn==0){
				int to=now.v;
				for(int i=0;i<rv[to].size();++i){
					int fr=rv[to][i];
					if(dp[fr][1]==0){
						int st=1;
						for(int i=0;i<mp[fr].size();++i)
							st&=dp[mp[fr][i]][0];
						dp[fr][1]=st;
						if(dp[fr][1])
							que.push(Dt(fr,1));
					}
				}
			}
			else{
				int to=now.v;
				for(int i=0;i<rv[to].size();++i){
					int fr=rv[to][i];
					if(dp[fr][0]==0){
						dp[fr][0]=1;
						que.push(Dt(fr,0));
					}
				}
			}
		}
		int ans=1;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				ans&=dp[p2i[i][j]][0];
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
