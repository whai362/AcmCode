#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
const int Maxn=24;
int n;
int has[][24]={20,1,22,3,10,4,0,7,8,9,11,5,2,13,14,15,6,17,12,19,16,21,18,23,
			    6,1,12,3,5,11,16,7,8,9,4,10,18,13,14,15,20,17,22,19,0,21,2,23,
		        1,3,0,2,23,22,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,21,9,8,
			    2,0,3,1,6,7,8,9,23,22,10,11,12,13,14,15,16,17,18,19,20,21,5,4,
			    0,1,8,14,4,3,7,13,17,9,10,2,6,12,16,15,5,11,18,19,20,21,22,23,
		        0,1,11,5,4,16,12,6,2,9,10,17,13,7,3,15,14,8,18,19,20,21,22,23};
	
int start[25];
struct Node{
	int s[25];
	int step;
	bool check(int a,int b,int c,int d){
		if (s[a]==s[b]&&s[b]==s[c]&&s[c]==s[d]) return true;
		return false;
	}
};
int ck[][4]={0,1,2,3,
			 4,5,10,11,
			 6,7,12,13,
			 8,9,14,15,
			 16,17,18,19,
			 20,21,22,23};
/*bool check(int a ,int b ,int c,int d,Node tmp){
	if (tmp.s[a]==tmp.s[b]&&tmp)
}*/

int Count(Node tmp){
	int ret=0;
	for (int i=0;i<6;i++){
		if(tmp.check(ck[i][0],ck[i][1],ck[i][2],ck[i][3])) ++ret;
	}
	return ret;
}
unordered_map<string,int> mp;
int bfs(){
	mp.clear();
	int ret=0;
	queue<Node> que;
	Node tmp;for (int i=0;i<Maxn;i++) tmp.s[i]=start[i];
	string zt="";
	tmp.step=0;
	for(int i=0;i<24;++i){
		zt+=(char)(tmp.s[i]+'A');
	}
	mp[zt]=1;
	cout<<zt<<endl;
	que.push(tmp);
	while (!que.empty()){
		Node pre=que.front();que.pop();
		Node nex;
		//if (pre.step<=n) ret=max(ret,Count(pre));
		//if (pre.step>=n) continue;
		for (int k=0;k<6;k++){
			for (int i=0;i<Maxn;i++){
				nex.s[i]=pre.s[has[k][i]];
			}
			nex.step=pre.step+1;
			zt="";
			for(int ii=0;ii<24;++ii){
				zt+=(nex.s[ii]+'A');
			}
			if(mp[zt]==1) continue;
			mp[zt]=1;
			cout<<zt<<endl;
			que.push(nex);
		}
	}
	return ret;
}

int main(){
	while (~scanf("%d",&n)){
		for (int i=0;i<Maxn;i++) scanf("%d",&start[i]);
		printf("%d\n",bfs());
	}
	return 0;
}
