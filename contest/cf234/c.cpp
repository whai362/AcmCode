#include<cstdio>
#include<iostream>
using namespace std;
#define N 100005
struct point{
	__int64 x,y;
}p;
int main(){
	int i,j;
	__int64 n,m,nn,mm,x,y,z,a,t;
	cin>>nn>>mm>>x>>y>>z>>a;
	for(i=0;i<a;++i){
		cin>>p.x>>p.y;
		x%=4;
		n=nn;
		m=mm;
		for(j=0;j<x;++j){
			t=p.x;
			p.x=p.y;
			p.y=n+1-t;
			t=n;
			n=m;
			m=t;
		}
		//cout<<p.x<<' '<<p.y<<endl;
		y%=2;
		for(j=0;j<y;++j){
			p.y=m+1-p.y;
		}
		//cout<<p.x<<' '<<p.y<<endl;
		z%=4;
		for(j=0;j<z;++j){
			t=p.x;
			p.x=m+1-p.y;
			p.y=t;
			t=n;
			n=m;
			m=t;
		}
		cout<<p.x<<' '<<p.y<<endl;
	}
}
