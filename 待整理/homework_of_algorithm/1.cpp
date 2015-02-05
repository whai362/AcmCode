//八皇后递归写法
#include<fstream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;
ofstream fout("out1.txt");
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
	char _map[8][9];
	static int cnt=0;
	memset(_map,'*',sizeof(_map));
	for(i=0;i<8;++i)
		_map[i][8]=0;
	for(i=1;i<9;++i)
		_map[i-1][pos[i]-1]='Q';
	fout<<++cnt<<':'<<endl;
	for(i=0;i<8;++i)
		fout<<_map[i]<<endl;	//	输出优化，把单字符输出转化为字符串输出
	fout<<endl;
}
void dfs(int q,int pos[]){
	int i,j;
	static int cnt=0;
	if(q>8){
		print(pos);
		return ;
	}
	for(i=1;i<9;++i){
		if(ok(i,q,pos)){
			pos[q]=i;
			dfs(q+1,pos);
		}
	}
}
int main(){
	int pos[9];
	double st=clock();
	memset(pos,0,sizeof(pos));
	dfs(1,pos);
	fout<<(clock()-st)/CLOCKS_PER_SEC<<"秒"<<endl;
	return 0;
}
