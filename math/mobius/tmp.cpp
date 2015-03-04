#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define LL __int64
const int N=1e5+5;
struct Dt{
	LL h,a;
	Dt(){}
	Dt(LL _h,LL _a){
		h=_h;
		a=_a;
	}
	bool operator < (const Dt &tmp) const{
		return h+a<tmp.h+tmp.a;
	}
}d[N];
int cnt;
priority_queue<Dt> q;
int main(){
	int n,m,k,p;
	Dt a;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=0;i<n;++i){
		scanf("%I64d%I64d",&a.h,&a.a);
		a.h=a.h+a.a*(m-1);
		q.push(a);
	}
	//cout<<q.top().h<<endl;
	LL lim=m-1;
	for(int i=0;i<m;++i){
		for(int j=0;!q.empty() && j<k;++j){
			Dt now=q.top();
			q.pop();
			cout<<now.h<<' '<<now.a<<' '<<lim<<endl;
			if(now.h==0){
				cout<<'?'<<now.h<<' '<<now.a<<' '<<lim<<endl;
				d[cnt++]=now;
				--j;
				continue;
			}
			else{
				LL tmp=now.h-now.a*lim;
				//cout<<tmp<<endl;
				if(tmp>=p) now.h-=p;
				else now.h=now.a*lim;
				q.push(now);
			}
		}
		if(q.empty()) break;
		--lim;
	}
	for(int i=0;i<cnt;++i){ cout<<'!'<<d[i].h<<' '<<d[i].a<<endl; q.push(d[i]); }
	LL ans=q.top().h+q.top().a;
	printf("%I64d\n",ans);
	return 0;
}
