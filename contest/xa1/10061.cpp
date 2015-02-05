#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=7000005;
int s[6],e[6];
int vis[N];
int bei[]={100000,10000,1000,100,10,1};
int _swap(int x,int i,int j){
	int n1=(x/bei[i])%10,
		n2=(x/bei[j])%10;
	//cout<<n1<<' '<<n2<<endl;
	int ret=x+(n2-n1)*bei[i];
	ret+=(n1-n2)*bei[j];
	return ret;
}
int qian(int x){
	int ret;
	ret=_swap(x,0,4);
	ret=_swap(ret,1,5);
	ret=_swap(ret,0,1);
	return ret;
}
int hou(int x){
	int ret;
	ret=_swap(x,0,4);
	ret=_swap(ret,1,5);
	ret=_swap(ret,4,5);
	return ret;
}
int zuo(int x){
	int ret;
	ret=_swap(x,0,2);
	ret=_swap(ret,1,3);
	ret=_swap(ret,0,1);
	return ret;
}
int you(int x){
	int ret;
	ret=_swap(x,0,2);
	ret=_swap(ret,1,3);
	ret=_swap(ret,2,3);
	return ret;
}
int cnt=0;
int gao(int st,int en){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	vis[st]=1;
	q.push(st);
	while(!q.empty()){
		++cnt;
		int now=q.front();
		//cout<<now<<endl;
		q.pop();
		cout<<now<<',';
		int tmp=qian(now);
		int flag=0;
		if(vis[tmp]==0){
			q.push(tmp);
			vis[tmp]=vis[now]+1;
			flag=1;
		}
		tmp=hou(now);
		if(vis[tmp]==0){
			q.push(tmp);
			vis[tmp]=vis[now]+1;
			flag=1;
		}
		tmp=zuo(now);
		if(vis[tmp]==0){
			q.push(tmp);
			vis[tmp]=vis[now]+1;
			flag=1;
		}
		tmp=you(now);
		if(vis[tmp]==0){
			q.push(tmp);
			vis[tmp]=vis[now]+1;
			flag=1;
		}
	}
	return -1;
}
int h[7];

int main(){
	while(scanf("%d%d%d%d%d%d",&s[0],&s[1],&s[2],&s[3],&s[4],&s[5])!=EOF){
		scanf("%d%d%d%d%d%d",&e[0],&e[1],&e[2],&e[3],&e[4],&e[5]);
		memset(h,0,sizeof(h));
		h[s[0]]=s[1];
		h[s[1]]=s[0];
		h[s[2]]=s[3];
		h[s[3]]=s[2];
		h[s[4]]=s[5];
		h[s[5]]=s[4];
		int flag=1;
		/*for(int i=0;i<6;i+=2){
			//cout<<e[i]<<' '<<e[i+1]<<endl;
			if(h[e[i]]!=e[i+1]){
				flag=0;
				break;
			}
		}*/
		if(flag){
		int st=0,en=0;
		for(int i=0;i<6;++i){
			st=st*10+s[i];
			en=en*10+e[i];
		}
		int ans=gao(st,en);
		//cout<<cnt<<endl;
		printf("%d\n",ans);
		}
		else puts("-1");
	}
	return 0;
}
