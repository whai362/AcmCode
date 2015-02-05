#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int dx[]={0,1,0,-1},
	dy[]={1,0,-1,0};

int getdir(char ch){
	switch (ch){
		case 'E':return 0;
		case 'S':return 1;
		case 'W':return 2;
		case 'N':return 3;		 
		//default return -1;		 
	}
	return -1;
}

int t1,t2,n,s1,s2;
int tim;
void dfs(int t,int x1,int y1,int k1,int x2,int y2,int k2){
	if (t>=tim){
		printf("%d %d\n",x1,y1);
		printf("%d %d\n",x2,y2);
		return ;
	}
	//cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
		
	if (x1==x2&&y1==y2){
		swap(k1,k2);
	}
	else{
		if (t%t1==0&&t!=0)
			k1=(k1+3)%4;
		if (t%t2==0&&t!=0)
			k2=(k2+3)%4;
	}
	bool flag=false;
	int xx,yy;
	xx=x1+s1*dx[k1],yy=y1+s1*dy[k1];
	if (xx<=0) xx=2-xx,flag=true;
	if (yy<=0) yy=2-yy,flag=true;
	if (xx>n)  xx=2*n-xx,flag=true;
	if (yy>n)  yy=2*n-yy,flag=true;
	x1=xx;y1=yy;
	if (flag) k1=(k1+2)%4;
	flag=false;
	xx=x2+s2*dx[k2],yy=y2+s2*dy[k2];
	if (xx<=0) xx=2-xx,flag=true;
	if (yy<=0) yy=2-yy,flag=true;
	if (xx>n)  xx=2*n-xx,flag=true;
	if (yy>n)  yy=2*n-yy,flag=true;
	x2=xx;y2=yy;
	if (flag) k2=(k2+2)%4;
	dfs(t+1,x1,y1,k1,x2,y2,k2);
}

int main(){
	char ch[5];
	int k1,k2;
	while (~scanf("%d",&n),n){
		scanf("%s%d%d",ch,&s1,&t1);
		k1=getdir(ch[0]);
		scanf("%s%d%d",ch,&s2,&t2);
		k2=getdir(ch[0]);
		scanf("%d",&tim);
		dfs(0,1,1,k1,n,n,k2);
	}
	return 0;
}
