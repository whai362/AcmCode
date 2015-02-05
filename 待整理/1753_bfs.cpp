#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int N=1e5+5;
struct Data{
	int n,step;
	Data(){}
	Data(int _n,int _step){
		n=_n;
		step=_step;
	}
};
int flip[]={51200,58368,29184,12544,
			35968,20032,10016,4880,
			2248,1252,626,305,
			140,78,39,19};
bool vis[N];
char in[5][5];
int main(){
	for(int i=0;i<4;++i){
		cin>>in[i];
	}
	int n=0,goal1=0,goal2=65535;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			n<<=1;
			if(in[i][j]=='b'){
				n+=1;
			}
		}
	}
	//printf("%x\n",n);
	queue<Data> q;
	vis[n]=true;
	q.push(Data(n,0));
	int ans=-1;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		if(now.n==goal1 || now.n==goal2){
			ans=now.step;
			break;
		}
		for(int i=0;i<16;++i){
			int tmp=now.n^flip[i];
			//printf("%x\n",tmp);
			if(tmp==goal1 || tmp==goal2){
				ans=now.step+1;
				break;
			}
			if(!vis[tmp]){
				vis[tmp]=true;
				q.push(Data(tmp,now.step+1));
			}
			//int nn;
			//cin>>nn;
		}
		if(ans!=-1){
			break;
		}
	}
	if(ans==-1){
		printf("Impossible\n");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}
