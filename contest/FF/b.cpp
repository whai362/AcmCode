#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int N=1005;
struct Data{
	int f,id,h,s;
	Data(){}
	Data(int _f,int _id,int _h,int _s){
		f=_f;
		id=_id;
		h=_h;
		s=_s;
	}
	bool operator < (const Data &other) const{
		if(s!=other.s) return s<other.s;
		else return h>other.h;
	}
};
int a[N][N],visc[N],visr[N];
int main(){
	int n,m,k,p;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&a[i][j]);
		}
	}
	priority_queue<Data> q;
	for(int i=0;i<n;++i){
		int sum=0;
		for(int j=0;j<m;++j){
			sum+=a[i][j];
		}
		q.push(Data(1,i,m,sum));
	}
	for(int i=0;i<m;++i){
		int sum=0;
		for(int j=0;j<n;++j){
			sum+=a[j][i];
		}
		q.push(Data(2,i,n,sum));
	}
	long long ans=0;
	while(k--){
		Data now=q.top();
		q.pop();
		if(now.f==1){
			if(visc[now.id]){
				int tmp=now.s-visc[now.id]*p;
				visc[now.id]=0;
				q.push(Data(now.f,now.id,now.h,tmp));
				++k;
			}
			else{
				//cout<<now.f<<' '<<now.id<<endl;
				//cout<<now.s<<endl;
				ans=ans+now.s;
				now.s-=m*p;
				for(int i=0;i<m;++i){
					++visr[i];
				}
				q.push(now);
			}
		}
		else{
			if(visr[now.id]){
				int tmp=now.s-visr[now.id]*p;
				visr[now.id]=0;
				q.push(Data(now.f,now.id,now.h,tmp));
				++k;
			}
			else{
				//cout<<now.f<<' '<<now.id<<endl;
				//cout<<now.s<<endl;
				ans=ans+now.s;
				now.s-=n*p;
				for(int i=0;i<n;++i){
					++visc[i];
				}
				q.push(now);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
