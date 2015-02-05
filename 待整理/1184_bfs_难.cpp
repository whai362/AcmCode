/*宽搜,有一部分可以算出来,所以可以把它分割出来*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
struct Data{
	int num[6];
	int status,point,step;
};
bool status[][6]={
	1,0,0,0,0,0,
	1,1,0,0,0,0,
	1,1,1,0,0,0,
	1,1,1,1,0,0,
	1,1,1,1,1,0,
	1,0,0,0,0,1,
	1,1,0,0,0,1,
	1,1,1,0,0,1,
	1,1,1,1,0,1,
	1,1,1,1,1,1
};
bool vis[10][10][10][10][10][10][6][10];
char init[7],goal[7];
void setVis(Data d){
	vis[d.num[0]][d.num[1]][d.num[2]][d.num[3]][d.num[4]][d.num[5]][d.point][d.status]=true;
}
bool getVis(Data d){
	return 
		vis[d.num[0]][d.num[1]][d.num[2]][d.num[3]][d.num[4]][d.num[5]][d.point][d.status];
}
int _abs(int n){
	if(n>=0) return n;
	return -n;
}
int gao(Data d){
	int ret=0,flag=1;
	for(int i=0;i<6;++i){
		if(status[d.status][i]){
			ret+=_abs(d.num[i]-goal[i]);
		}
		else if(d.num[i]!=(int)goal[i]){
			flag=0;
			break;
		}
	}
	if(flag) return ret;
	return INF;
}
int main(){
	scanf("%s%s",init,goal);
	Data tmp;
	for(int i=0;i<6;++i){
		tmp.num[i]=init[i]-'0';
		goal[i]-='0';
	}
	tmp.status=tmp.point=tmp.step=0;
	queue<Data> q;
	q.push(tmp);
	setVis(tmp);
	int ans=INF;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		ans=min(ans,gao(now)+now.step);
		if(now.point!=0){
			tmp=now;
			swap(tmp.num[0],tmp.num[tmp.point]);
			++tmp.step;
			if(!getVis(tmp)){
				q.push(tmp);
				setVis(tmp);
			}
		}
		if(now.point!=5){
			tmp=now;
			swap(tmp.num[5],tmp.num[tmp.point]);
			if(tmp.status<5) tmp.status+=5;
			++tmp.step;
			if(!getVis(tmp)){
				q.push(tmp);
				setVis(tmp);
			}
		}
		if(now.point>0){	//添加能过000159 000519 8这组数据
			tmp=now;
			--tmp.point;
			++tmp.step;
			if(!getVis(tmp)){
				q.push(tmp);
				setVis(tmp);
			}
		}
		if(now.point<5){
			tmp=now;
			int last=tmp.status>4? tmp.status:tmp.status-5;
			if(tmp.status==4) tmp.status=9;
			else if(tmp.status<9) ++tmp.status;
			++tmp.point;
			++tmp.step;
			if(!getVis(tmp)){
				q.push(tmp);
				setVis(tmp);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
