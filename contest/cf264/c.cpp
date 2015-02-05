#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=2005;
int n;
struct Data{
	int x,y;
	LL w;
	Data(){}
	Data(int _x,int _y,LL _w){
		x=_x;
		y=_y;
		w=_w;
	}
}d[N*N];
int cnt=0;
LL _map[N][N],h1[2*N],h2[2*N],tot[N*N];
bool cmp(Data d1,Data d2){
	return d1.w>d2.w;
}
bool ok(int x,int y,int p){
	int b11=y-x,
		b12=y+x,
		b21=d[p].y-d[p].x,
		b22=d[p].y+d[p].x;
	if((b22-b11)%2!=0){
		if((b21-b12)%2!=0)
			return true;
		else return false;
	}
	else return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%I64d",&_map[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			h1[i+j-1]+=_map[i][j];
			h2[n+(i-j)]+=_map[i][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			_map[i][j]=h1[i+j-1]+h2[n+(i-j)]-_map[i][j];
			d[cnt++]=Data(i,j,_map[i][j]);
		}
	sort(d,d+cnt,cmp);
	/*for(int i=0;i<cnt;++i){
		cout<<d[i].w<<endl;
	}*/
	LL _max=0,ax,ay,bx,by,tmp,p;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			p=0;
			tmp=_map[i][j];
			while(1){
				if(ok(i,j,p)){
					break;
				}
				++p;
			}
			tmp+=_map[d[p].x][d[p].y];
			if(tmp>_max){
				_max=tmp;
				ax=i;
				ay=j;
				bx=d[p].x;
				by=d[p].y;
			}
		}
	}
	//cout<<_max<<endl;
	//cout<<ax<<' '<<ay<<' '<<bx<<' '<<by<<endl;
	//cout<<_map[ax][ay]<<' '<<_map[bx][by]<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<_map[i][j]<<' ';
		}
		cout<<endl;
	}
	/*for(int i=1;i<2*n;++i){
		cout<<h1[i]<<' ';
	}
	cout<<endl;
	for(int i=1;i<2*n;++i){
		cout<<h2[i]<<' ';
	}
	cout<<endl;*/
	return 0;
}
