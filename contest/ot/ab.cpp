#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=15;
struct Data{
	bool st[N],vis[N];
	int step;
};
int main(){
	Data d;
	for(int i=0;i<N;++i){
		d.st[i]=d.vis[i]=0;
	}
	d.step=0;
	queue<Data> q;
	q.push(d);
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		int flag=1;
		for(int i=0;i<N;++i){
			if(now.st[i]==0){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<now.step<<endl;
			break;
		}
		for(int i=0;i<N;++i){
			if(now.vis[i]==0){
				Data tmp;
				for(int j=0;j<N;++j){
					tmp.st[j]=now.st[j];
					tmp.vis[j]=now.vis[j];
				}
				tmp.step=now.step+1;
				tmp.st[i]^=1;
				tmp.st[(i+N/2)%N]^=1;
				tmp.st[(i+N/2+1)%N]^=1;
				tmp.vis[i]=1;
				q.push(tmp);
			}
		}
	}
}
