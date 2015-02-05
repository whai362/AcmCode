#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
#define mp make_pair
#define pb push_back
struct Data{
	int v,c;
};
const int N=1000005;
int n,m,dx,dy;
map< pair<int,int>,int > _map;
Data tabx[N],taby[N];
vector<int> vecx[N],vecy[N];
int cx_size[N],cy_size[N];
void predo(){
	memset(tabx,-1,sizeof(tabx));
	memset(taby,-1,sizeof(taby));
	for(int i=0;i<n;++i){
		if(tabx[i].v!=-1) continue;
		int j=i;
		int cnt=0;
		while(tabx[j].v==-1){
			tabx[j].v=i;
			tabx[j].c=cnt++;
			vecx[i].pb(j);
			j=(j+dx)%n;
		}
		cx_size[i]=cnt;
	}
	for(int i=0;i<n;++i){
		if(taby[i].v!=-1) continue;
		int j=i;
		int cnt=0;
		while(taby[j].v==-1){
			taby[j].v=i;
			taby[j].c=cnt++;
			vecy[i].pb(j);
			j=(j+dy)%n;
		}
		cy_size[i]=cnt;
	}
}
void deal(int &x,int &y){
	int stepx=tabx[x].c;
	x=tabx[x].v;
	int stepy=taby[y].c;

	//cout<<'!'<<stepx<<' '<<stepy<<endl;

	int cy=cy_size[taby[y].v];
	//cout<<cy<<endl;
	stepy=((stepy-stepx)%cy+cy)%cy;
	//cout<<stepy<<endl;
	//cout<<vecy[0][1]<<endl;

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
		//cout<<x<<' '<<y<<endl;
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
