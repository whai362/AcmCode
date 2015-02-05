#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int cov=0,cc,Max;
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y){
		x=_x;
		y=_y;
	}
}p[20];
char st[205][205];
int nx[]={-1,0};
int ny[]={0,1};
bool dealn(int id){
	bool flag=true;
	int x1=p[id].x+nx[0],
		y1=p[id].y+ny[0],
		x2=p[id].x+nx[1],
		y2=p[id].y+ny[1];
	if(st[x1][y1]!='#' && st[x2][y2]!='#'){
		cov=cov | (1<<id);
		int tmp;
		if(st[x1][y1]>='0' && st[x1][y1]<='0'+14){
			tmp=st[x1][y1]-'0';
			cov=cov | (1<<tmp);
		}
		if(st[x2][y2]>='0' && st[x2][y2]<='0'+14){
			tmp=st[x2][y2]-'0';
			cov=cov | (1<<tmp);
		}
		return true;
	}
	else return false;
}
int ox1[]={-1,0,1,0},
	oy1[]={0,1,0,-1},
	ox2[]={0,1,0,-1},
	oy2[]={1,0,-1,0};
bool dealo(int id){
	cc=cov;
	int x1,y1,x2,y2;
	for(int i=0;i<4;++i){
		x1=p[id].x+ox1[i],
		y1=p[id].y+oy1[i],
		x2=p[id].x+ox2[i],
		y2=p[id].y+oy2[i];
		int tmp;
		if(st[x1][y1]!='#' && st[x2][y2]!='#'){
			cov=cov | (1<<id);
			if(st[x1][y1]>='0' && st[x1][y1]<='0'+14){
				tmp=st[x1][y1]-'0';
				cov=cov | (1<<tmp);
			}
			if(st[x2][y2]>='0' && st[x2][y2]<='0'+14){
				tmp=st[x2][y2]-'0';
				cov=cov | (1<<tmp);
			}
			//max ans
			if(cov==Max-1) return true;
		}
		cov=cc;
	}
	return false;
}
void undealo(){
	cov=cc;
}

int main(){
	int n,m;
	while (~scanf("%d%d",&n,&m)){
		if (n==0&&m==0) break;
		memset(st,0,sizeof(st));
	//	cout<<st[0][0]<<endl;
		for (int i=1;i<=n;i++){
			scanf("%s",st[i]+1);
		}
		int cnt=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (st[i][j]=='.'){
					st[i][j]=cnt+'0';
					p[cnt]=Point(i,j);
					cnt++;
				}
			}
		}
		Max=(1<<cnt);// cout<<Max<<endl;
		int ans=inf;
		if(cnt==0) ans=0;
		for (int i=0;i<Max;i++){
			cov=0;
			int l_cnt=0;
			for (int j=0;j<cnt;j++){
				if (((1<<j)&i)){
					if(!dealn(j)) l_cnt=inf;
					else ++l_cnt;	
				}
			}
			if (l_cnt>=inf) continue;
			if(cov==Max-1)
				ans=min(ans,l_cnt);
			else{
				for(int j=0;j<cnt;j++){
					if(((1<<j)&i)==0){
						if(dealo(j)){
							ans=min(ans,l_cnt+1);
						}
						undealo();
					}
				}
			}
		}
		Point p;
		if(ans==inf)
			puts("-1");
		else 
			printf("%d\n",ans);
	}
	return 0;
}
