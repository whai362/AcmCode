#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define LL __int64
const int N=65;
const LL INF=100000000000000;
struct Point{
	LL x,y;
}p[N];
struct Data{
	int to;
	LL dis;
	Data(){}
	Data(int _to,LL _dis){
		to=_to;
		dis=_dis;
	}
};
vector<Data> _map[N];
LL _abs(LL x){
	if(x<0) return -x;
	else return x;
}
LL dis(Point p1,Point p2){
	return _abs(p1.x-p2.x)+_abs(p1.y-p2.y);
}
int n,k;
bool ok(LL di){
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<_map[i].size();++j){
			Data ch=_map[i][j];
			if(ch.dis<=di){
				vis[ch.to]=;
			}
		}
	}
	cout<<'!'<<di<<' '<<cnt<<endl;
	if(cnt>=k) return true;
	return false;
}
int main(){
	LL _max;
	scanf("%d%d",&n,&k);
	_max=0;
	for(int i=1;i<=n;++i){
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			LL di=dis(p[i],p[j]);
			_max=max(_max,di);
			if(i!=j){
				_map[i].push_back(Data(j,di));
				_map[j].push_back(Data(i,di));
			}
			else{
				_map[i].push_back(Data(j,di));
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout<<i<<':'<<endl;
		for(int j=0;j<_map[i].size();++j){
			cout<<_map[i][j].to<<' '<<_map[i][j].dis<<endl;
		}
	}
	LL l=0,r=_max,mid,ans=INF;
	while(l<r){
		mid=(l+r)>>1;
		cout<<mid<<endl;
		if(ok(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
