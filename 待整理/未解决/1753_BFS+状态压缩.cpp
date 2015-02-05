//状态压缩：将4*4棋盘的各点用一个16位的二进制数来表示
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

struct state{
	int s,step;
}current={0};

queue<state>que;

int change[16]={0xc800,0xe400,0x7200,0x3100,0x8c80,0x4e40,0x2720,0x1310,0x08c8,0x04e4,0x0272,0x0131,0x008c,0x004e,0x0027,0x0013};
int m;
bool vis[65536]={false};

bool BFS(){
	state tmp;
	while(!que.empty()){
		current=que.front();
		que.pop();
		if(current.s==0xffff||current.s==0x0000){
			m=current.step;
			return true;
		}
		for(int i=0;i<16;i++){
			tmp.s=current.s^change[i];
			if(vis[tmp.s]) continue;
			tmp.step=current.step+1;
			que.push(tmp);
			vis[tmp.s]=true;
		}
	}
	return false;
}

int main(){
	int t,sum,a[4];
	char ss[5];
	for(int i=0;i<4;i++){
		t=1;
		sum=0;
		scanf("%s",ss);
		for(int j=3;j>=0;j--){
			sum+=(ss[j]=='b'?1:0)*t;
			t*=2;
		}
		a[i]=sum;
	}
	t=1;
	for(int i=3;i>=0;i--){
		current.s+=a[i]*t;
		t*=16;
	}
	que.push(current);
	if(BFS()) printf("%d\n",m);
	else printf("Impossible\n");
	return 0;
}
