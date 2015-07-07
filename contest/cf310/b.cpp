#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define LL __int64
#define MP make_pair
const int N=2*1e5 + 5;
LL l[N],r[N];
LL a;
int n,m;
int ans[N];
bool maybe=1;

pair< pair<LL,LL>, int > data1[N];
pair< LL,int > data2[N];
set< pair<LL,int> > _set;

int cnt=0;

void gao(){
	if(maybe==0){ puts("No"); return ; }
	int cur=1;
	for(int i=0;i<m;++i){
		while(cur<n && data1[cur].first.first<=data2[i].first){
			_set.insert(MP(data1[cur].first.second,data1[cur].second));
			++cur;
		}
		set< pair<LL,int> > :: iterator it;
		if(!_set.empty()){
			it=_set.begin();
			if((*it).first < data2[i].first){
				puts("No");
				return ;
			}
			//cout<<data2[i].second<<endl;
			ans[(*it).second]=data2[i].second+1;
			++cnt;
			_set.erase(it);
		}
	}
	if(cnt!=n-1){
		puts("No");
	}
	else{
		puts("Yes");
		for(int i=1;i<n;++i){
			printf("%d%c",ans[i],i==n-1?'\n':' ');
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if(m<n-1) maybe=0;
	for(int i=0;i<n;++i){
		scanf("%I64d%I64d",&l[i],&r[i]);
	}
	for(int i=0;i<m;++i){
		scanf("%I64d",&a);
		data2[i] = MP(a,i);
	}
	for(int i=1;i<n;++i){
		data1[i] = MP( MP(l[i]-r[i-1], r[i]-l[i-1]), i);
	}
	sort(data1+1,data1+n);
	sort(data2,data2+m);
	//cout<<"!"<<endl;
	gao();
	return 0;
}
