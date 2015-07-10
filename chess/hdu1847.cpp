#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int N=1005;
const int M=105;
int sg[N];

/*bool vis[M];
int get_sg(int x){
	if(sg[x]!=-1)
		return sg[x];

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

	//for(int i=0;i<=10;++i){
	//	cout<<sg[i]<<' ';
	//}
	//cout<<endl;

	int n;
	while(scanf("%d",&n)!=EOF){
		if(sg[n]==0)
			puts("Cici");
		else
			puts("Kiki");
	}
	return 0;
}
