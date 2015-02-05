//八皇后递归写法
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;
//1 0 0 2 10 4 40 92 352 724 2680 14200 73712
bool ok(int k,int q,int pos[]){
	int i;
	for(i=1;i<q;++i){
		if(pos[i]==k || abs(q-i)==abs(k-pos[i]))
			return false;
	}
	return true;
}
int cnt=0;
int N=14;
void print(int pos[]){
	int i;
	char _map[N][N+1];
	memset(_map,'*',sizeof(_map));
	for(i=0;i<N;++i)
		_map[i][N]=0;
	++cnt;
	//for(i=1;i<N+1;++i)
	//	_map[i-1][pos[i]-1]='Q';
	//fout<<++cnt<<':'<<endl;
	//for(i=0;i<N;++i)
		//fout<<_map[i]<<endl;	//	输出优化，把单字符输出转化为字符串输出
	//fout<<endl;
}
void dfs(int q,int pos[]){
	int i,j;
	static int cnt=0;
	if(q>N){
		print(pos);
		return ;
	}
	for(i=1;i<N+1;++i){
		if(ok(i,q,pos)){
			pos[q]=i;
			dfs(q+1,pos);
		}
	}
}
int main(){
	int pos[N+1];
	double st=clock();
	memset(pos,0,sizeof(pos));
	dfs(1,pos);
	cout<<cnt<<endl;
	return 0;
}

