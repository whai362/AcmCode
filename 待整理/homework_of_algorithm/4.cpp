//十皇后
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define N 16 
bool ok(int k,int q,int pos[]){
	int i;
	for(i=1;i<q;++i){
		if(pos[i]==k || abs(q-i)==abs(k-pos[i]))
			return false;
	}
	return true;
}
void print(int pos[]){
	int i;
	char _map[N][N+1];
	memset(_map,'*',sizeof(_map));
	for(i=0;i<N;++i)
		_map[i][N]=0;
	for(i=1;i<=N;++i)
		_map[i-1][pos[i]-1]='Q';
	for(i=0;i<N;++i)
		printf("%s\n",_map[i]);	//	输出优化，把单字符输出转化为字符串输出
	printf("\n");
}
bool dfs(int q,int pos[]){
	int i,j;
	static int cnt=0;
	if(q>N){
		print(pos);
		return true;
	}
	for(i=1;i<=N;++i){
		if(ok(i,q,pos)){
			pos[q]=i;
			if(dfs(q+1,pos)) return true;
		}
	}
	return false;
}
int main(){
	int pos[N+1];
	memset(pos,0,sizeof(pos));
	if(!dfs(1,pos)){
		printf("Not found!\n");
	}
	return 0;
}
