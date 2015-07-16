/*poj 1330 Nearest Common Ancestors
  题意：
  给出一棵大小为n的树和一个询问(u,v), 问(u,v)的最近公共祖先。
  限制：
  2 <= n <= 10000
  思路：
  对于涉及有根树的问题，将树转化为从根dfs标号后得到的序列处理的技巧常常十分有效。对于LCA，这个技巧也十分有效。首先，按从根dfs访问的顺序得到顶点序列vs[i]和对应的深度depth[i]，对于每个顶点v，记其在vs中首次出现的下标为id[v]。
  这些都可以dfs一遍搞定。而LCA(u,v)就是访问u之后到访问v之前所经过顶点中离根最近的那个，假设id[u] <= id[v]则有：
  LCA(u,v) = vs[id[u] <= i <= id[v]中令depth(i)最小的i]
  这个可以用rmq求得。

 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
#define PB push_back
const int N=100005;

int dp[N*2][18];
void make_rmq_index(int n,int b[]){ //返回最小值对应的下标
    for(int i=0;i<n;i++)
        dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            dp[i][j]=b[dp[i][j-1]] < b[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}
int rmq_index(int s,int v,int b[]){
	int k=(int)(log((v-s+1)*1.0)/log(2.0));
	return b[dp[s][k]]<b[dp[v-(1<<k)+1][k]]? dp[s][k]:dp[v-(1<<k)+1][k];
}


vector<int> tree[N];
int vs[N*2]; //dfs访问的顺序
int depth[N*2]; //节点的深度
int id[N]; //各个顶点在vs中首次出现的下标

void dfs(int u,int p,int d,int &k){
	id[u]=k;
	vs[k]=u;
	depth[k++]=d;
	for(int i=0;i<tree[u].size();++i){
		if(tree[u][i]!=p){
			dfs(tree[u][i],u,d+1,k);
			vs[k]=u;
			depth[k++]=d;
		}
	}
}

int indeg[N];

void predo(int n){
	int root;
	for(int i=1;i<=n;++i){
		if(indeg[i]==0){
			root=i;
			break;
		}
	}
	int k=0;
	dfs(root,-1,0,k);

	/*
	for(int i=0;i<k;++i)
		cout<<i<<':'<<vs[i]<<' ';
	cout<<endl;
	for(int i=0;i<k;++i)
		cout<<i<<':'<<depth[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<i<<':'<<id[i]<<' ';
	cout<<endl;
	*/

	make_rmq_index(n*2-1,depth);
}

int LCA(int u,int v){
	return vs[rmq_index(min(id[u],id[v]), max(id[u],id[v])+1, depth)];
}

void init(int n){
	memset(indeg,0,sizeof(indeg));
	for(int i=1;i<=n;++i)
		tree[i].clear();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		init(n);
		int u,v;
		for(int i=0;i<n-1;++i){
			scanf("%d%d",&u,&v);
			tree[u].PB(v);
			++indeg[v];
		}
		predo(n);
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
/*
input:
1
5
2 3
3 4
3 1
1 5
3 5

output:
0:2 1:3 2:4 3:3 4:1 5:5 6:1 7:3 8:2
0:0 1:1 2:2 3:1 4:2 5:3 6:2 7:1 8:0
1:4 2:0 3:1 4:2 5:5
3
*/
