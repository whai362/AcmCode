#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=40005;
int n;
double x[N],y[N],r[N];
bool inside(int i,int j){
	double dx=x[i]-x[j],
		   dy=y[i]-y[j];
	return dx*dx+dy*dy<=r[j]*r[j];
}
int cnt[N];
void gao(){
	memset(cnt, 0, sizeof(cnt));
	vector< pair<double,int> > events;	//圆左右两端的x坐标
	for(int i=0;i<n;++i){
		events.pb(mp(x[i]-r[i],i));	//左端
		events.pb(mp(x[i]+r[i],i+n));	//右端
	}
	sort(events.begin(),events.end());

	/*for(int i=0;i<events.size();++i){
		cout<<events[i].first<<' ';
	}
	cout<<endl;*/

	cout<<"?"<<endl;

	set< pair<double,int> > outers;	//与扫描线相交的最外层的圆的集合
	vector<int> res;	//最外层圆的列表
	int cc=0;
	for(int i=0;i<events.size();++i){
		int id=events[i].second%n;	//扫描到左端
		if(events[i].second<n){
			set< pair<double,int> >::iterator it=outers.lower_bound(mp(y[id],id));
			//s//et< pair<double,int> >::iterator its = it;
			//int o1 = its->second;
			//int o2 = (--its)->second;
			if(it!=outers.end() && inside(id,it->second)){  continue; }
			if(it!=outers.begin() && inside(id,(--it)->second)){ continue; }
			res.pb(id);
			outers.insert(mp(y[id],id));
		}
		else{
			outers.erase(mp(y[id],id));
		}
	}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for(int i=0;i<res.size();++i){
		printf("%d%c",res[i]+1,i+1==res.size()? '\n':' ');
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
		}
		cout<<"!"<<endl;
		gao();
	}
	return 0;
}
