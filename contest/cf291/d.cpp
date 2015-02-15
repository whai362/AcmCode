#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define LL __int64
const int N=100005;
int a[N][6];
int n,m;
LL k;
int ans[6];
priority_queue<int> q[5],t[5];
int main(){
	scanf("%d%d%I64d",&n,&m,&k);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&a[i][j]);
	int pi=0,pj=0,maxl=-1;
	int _max[6];
	for(int i=0;i<m;++i){
		ans[i]=0;
		_max[i]=a[0][i];
		q[i].push(a[0][i]);
	}
	++pj;
	while(pj<=n){
		LL sum=0;
		for(int i=0;i<m;++i)
		   sum=sum+_max[i];

		//cout<<"!"<<pi<<' '<<pj<<endl;
		//cout<<"?"<<endl;
		//for(int i=0;i<m;++i)
		//	cout<<_max[i]<<' ';
		//cout<<endl<<"-----"<<endl;

		if(sum<=k){
			int tmp=pj-pi;
			if(tmp>maxl){
				maxl=tmp;
				for(int i=0;i<m;++i)
					ans[i]=_max[i];
			}
			if(pj<n){
				for(int i=0;i<m;++i){
					q[i].push(a[pj][i]);
					_max[i]=q[i].top();
				}
			}
			++pj;
		}
		else{
			for(int i=0;i<m;++i){
				t[i].push(a[pi][i]);
				while(!t[i].empty() && !q[i].empty() && t[i].top()==q[i].top()){
					t[i].pop();
					q[i].pop();
				}
				if(q[i].empty()) _max[i]=0;
				else _max[i]=q[i].top();

			}
			++pi;
		}
	}
	for(int i=0;i<m;++i){
		printf("%d%c",ans[i],i==m-1?'\n':' ');
	}
	return 0;
}
