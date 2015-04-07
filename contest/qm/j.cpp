#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct LV{
	int x;
	double g;
}lv[105];
struct CS{
	int x;
	double p;
}cs[105];
const int N=1005;
vector<int> w[N];
vector<double> v[N];
int cnt;
int c;
int Find(int x){
	for(int i=0;i<=c;++i){
		if(lv[i].x>x) return i;
	}
	return -1;
}
void deal(int id){
	int dj=Find(cs[id].x);
	if(dj==-1) return ;
	double ds,dg;
	if(dj==0){
		++dj;
	}
	int sb=dj-1;
	ds=lv[dj].x-cs[id].x;
	dg=lv[dj].g-lv[dj-1].g;
	//w[cnt]=ds;
	//g[cnt]=id;
	w[id+1].push_back(ds);
	v[id+1].push_back(cs[id].p*dg);
	++dj;
	for(;dj<=c;++dj){
		ds=lv[dj].x-cs[id].x;
		dg=lv[dj].g-lv[sb].g;
		w[id+1].push_back(ds);
		v[id+1].push_back(cs[id].p*dg);;
	}
	//cout<<"!"<<cnt<<endl;
}
double dp[205][1005];
int main(){
	int T;
	int cas=0;
	scanf("%d",&T);
	int n,x;
	while(T--){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<N;++i){ w[i].clear(); v[i].clear(); }
		cnt=0;
		scanf("%d%d%d",&c,&n,&x);
		lv[0].x=0;
		lv[0].g=0;
		for(int i=1;i<=c;++i){
			scanf("%d%lf",&lv[i].x,&lv[i].g);
		}
		double div=0;
		for(int i=0;i<n;++i){
			scanf("%d%lf",&cs[i].x,&cs[i].p);
			div+=cs[i].p;
			deal(i);
		}
		double _max=0;
		for(int i=1;i<=n;++i){
			for(int j=x;j>=0;--j){

				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				for(int k=0;k<w[i].size();++k){
					if(j>=w[i][k])
						dp[i][j]=max(dp[i][j],dp[i-1][j-w[i][k]]+v[i][k]);
					_max=max(dp[i][j],_max);
				}
			}
		}
		//for(int i=0;i<cnt;++i){
		//	cout<<w[i]<<' '<<v[i]<<endl;
		//}
		double ans=0;
		if(div==0) ans=0;
		else ans=_max/div;
		printf("Case %d: %.4f\n",++cas,ans);
	}
	return 0;
}
