#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=1000005;
struct Data{
	int v,c;
}tabx[N],taby[N];
int cnty[N];	//记录循环节大小
vector<int> vecy[N];
map< pair<int,int>,int > _map;
int n,m,dx,dy;
void predo(){
	memset(tabx,-1,sizeof(tabx));
	memset(taby,-1,sizeof(taby));
	for(int i=0;i<n;++i){
		if(tabx[i].v!=-1) continue;
		int j=i,cnt=0;
		while(tabx[j].v==-1){
			tabx[j].v=i;
			tabx[j].c=cnt++;
			j=(j+dx)%n;
		}
	}
	for(int i=0;i<n;++i){
		if(taby[i].v!=-1) continue;
		int j=i,cnt=0;
		while(taby[j].v==-1){
			taby[j].v=i;
			taby[j].c=cnt++;
			vecy[i].pb(j);
			j=(j+dy)%n;
		}
		cnty[i]=cnt;
	}
}
void deal(int &x,int &y){
	int stepx=tabx[x].c;
	x=tabx[x].v;
	int stepy=taby[y].c;
	int sz=cnty[taby[y].v];
	stepy=((stepy-stepx)%sz+sz)%sz;
	y=vecy[taby[y].v][stepy];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&dx,&dy);
	predo();
	int x,y;
	int ansx,ansy,_max=0;
	for(int i=0;i<m;++i){
		scanf("%d%d",&x,&y);
		deal(x,y);
		int tmp=++_map[mp(x,y)];
		if(tmp>_max){
			_max=tmp;
			ansx=x;
			ansy=y;
		}
	}
	printf("%d %d\n",ansx,ansy);
	return 0;
}
