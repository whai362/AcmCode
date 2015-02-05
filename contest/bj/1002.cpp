#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
const int N=100005;
const double PI=acos(-1.0);
struct Data{
	double x,h;
	Data(){}
}d[2*N];
struct seg{
	int l,r;
}seg[N];
bool cmp(Data d1,Data d2){
	return d1.x<d2.x;
}
double ans0[N],ans1[N],in[N];
int index[N];
map<double,double> _map;
int main(){
	int n,m,T,cas=0;
	scanf("%d",&T);
	while(T--){
	_map.clear();
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%lf%lf",&d[i].x,&d[i].h);
	}
	scanf("%d",&m);
	for(int i=n;i<n+m;++i){
		scanf("%lf",&d[i].x);
		d[i].h=0;
		in[i-n]=d[i].x;
	}
	sort(d,d+n+m,cmp);
	int l=0,r=0;
	int cnt=0;
	for(int i=0;i<n+m;++i){
		if(d[i].h==0){
			r=i;
			seg[cnt].l=l;
			seg[cnt].r=r;
			index[cnt++]=i;
			l=r+1;
		}

	}
	seg[cnt].l=l;
	seg[cnt++].r=n+m;
	int tmpi;
	double _max=0,tmp;
	int p0,p1;
	for(int i=seg[0].l;i<seg[0].r;++i){
		tmp=d[i].h/(d[seg[0].r].x-d[i].x);
		if(tmp>_max){
			_max=tmp;
			p0=i;
			tmpi=i;
		}
	}
	ans0[0]=_max;
	for(int i=1;i<cnt-1;++i){
		_max=0;
		for(int j=0;j<=p0;++j){
			if(j==p0){
				tmp=d[j].h/(d[seg[i].r].x-d[j].x);
				if(tmp>_max){
					_max=tmp;
					p0=j;
					tmpi=j;
				}
			}
			else if(d[j].h>d[p0].h){
				tmp=d[j].h/(d[seg[i].r].x-d[j].x);
				if(tmp>_max){
					_max=tmp;
					p0=j;
					tmpi=j;
				}
			}
		}
		if(i>1){
			for(int j=seg[i-1].l;j<seg[i-1].r;++j){
				tmp=d[j].h/(d[seg[i].r].x-d[j].x);
				if(tmp>_max){
					_max=tmp;
					tmpi=j;
				}
			}
		}
		for(int j=seg[i].l;j<seg[i].r;++j){
			tmp=d[j].h/(d[seg[i].r].x-d[j].x);
			if(tmp>_max){
				_max=tmp;
				tmpi=j;
			}
		}
		ans0[i]=_max;
	}
	
	
	_max=0;
	for(int i=seg[cnt-1].l;i<seg[cnt-1].r;++i){
		tmp=d[i].h/(d[i].x-d[seg[cnt-1].l-1].x);
		if(tmp>_max){
			_max=tmp;
			p0=i;
			tmpi=i;
		}
	}
	ans1[cnt-2]=_max;
	
	for(int i=cnt-2;i>0;--i){
		_max=0;
		for(int j=p0;j<seg[cnt-1].r;++j){
			if(j==p0){
				tmp=d[j].h/(d[j].x-d[seg[i].l-1].x);
				if(tmp>_max){
					_max=tmp;
					p0=j;
					tmpi=j;
				}
			}
			else if(d[j].h>d[p0].h){
				tmp=d[j].h/(d[j].x-d[seg[i].l-1].x);
				if(tmp>_max){
					_max=tmp;
					p0=j;
					tmpi=j;
				}
			}
		}
		if(i<cnt-2){
			for(int j=seg[i+1].l;j<seg[i+1].r;++j){
				tmp=d[j].h/(d[j].x-d[seg[i].l-1].x);
				if(tmp>_max){
					_max=tmp;
					tmpi=j;
				}
			}
		}
		for(int j=seg[i].l;j<seg[i].r;++j){
			tmp=d[j].h/(d[j].x-d[seg[i].l-1].x);
			if(tmp>_max){
				_max=tmp;
				tmpi=j;
			}
		}
		ans1[i-1]=_max;
	}
	for(int i=0;i<cnt-1;++i){
		double du=PI/2-atan(ans0[i])+atan(ans1[i]);
		_map.insert(make_pair(d[index[i]].x,du*180.0/PI));
	}
	printf("Case #%d:\n",++cas);
	for(int i=0;i<m;++i){
		printf("%.10lf\n",_map[in[i]]);
	}
	}
	return 0;
}
