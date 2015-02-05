/*cf283div1c
  题意：给出n个任务(a1,b1),(a2,b2),...,(an,bn),给出m个人(c1,d1,k1),(c2,d2,k2),...,(cn,dn,kn),只有c<=a<=b<=d时，这个人才能完成任务，且这个人可以完成k个任务，问分配任务的可行性方案。
  限制：
  0<=n,m<=1e5 0<=a,b,c,d<=1e9
  题解：
  贪心
  对于任意一个任务选择一个尽量和它适配的人去解决。
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define mp make_pair
const int N=100005;
struct Data{
	int l,r,k,id;
}d[2*N];
int ans[N];
map< pair<int,int>,int > _map;
map< pair<int,int>,int >::iterator it;
bool cmp(Data a,Data b){
	if(a.l==b.l){
		if(a.r==b.r) return a.id>b.id;
		return a.r>b.r;
	}
	return a.l<b.l;
}
int main(){
	int n,m;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i){
		scanf("%d%d",&d[i].l,&d[i].r);
		d[i].id=-i;
	}
	scanf("%d",&m);
	for(;i<n+m;++i){
		scanf("%d%d%d",&d[i].l,&d[i].r,&d[i].k);
		d[i].id=i;
	}
	sort(d,d+n+m,cmp);
	for(int i=0;i<n+m;++i){
		if(d[i].id>0)
			_map[mp(d[i].r,d[i].id-n+1)]=d[i].k;
		else{
			it=_map.lower_bound(mp(d[i].r,0));
			if(it==_map.end()){
				puts("NO");
				return 0;
			}
			else{
				ans[-d[i].id]=it->first.second;
				--it->second;
				if(it->second==0)
					_map.erase(it);
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;++i)
		printf("%d%c",ans[i],i!=n-1?' ':'\n');
	return 0;
}

