//八皇后非递归写法
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
ofstream fout("out2.txt"); 
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
void dfs(){
	int j;
	int pos[9],i[9];
	j=i[1]=1;
	memset(pos,0,sizeof(pos));
	while(i[1]<9){
		if(i[j]>8){
			--j;
			++i[j];
		}
		else if(ok(i[j],j,pos)){
			pos[j]=i[j];
			++j;
			if(j>8){
				print(pos);
				--j;
				++i[j];
			}
			else i[j]=1;
		}
		else ++i[j];
	}
}
int main(){
	double st=clock();
	dfs();
	fout<<(clock()-st)/CLOCKS_PER_SEC<<"秒"<<endl;
	return 0;
}
