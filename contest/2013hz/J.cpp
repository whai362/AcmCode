#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f

set<int> _set;
map<int,int> _map;
int main(){
	int n;
	int id,gd;
	while (~scanf("%d",&n),n){
		_set.clear();
		_map.clear();
		_set.insert(1000000000);
		_map[1000000000]=1;
		set<int>::iterator it;
		for (int i=1;i<=n;i++){
			scanf("%d%d",&id,&gd);
			_map[gd]=id;
			_set.insert(gd);
			it=_set.find(gd);
			int bd=-1,ed=-1;
			if (it!=_set.begin()) bd=*(--it),++it;
			if (it!=_set.end()) ed=*(++it),--it;
			int ans=INF;
			if (bd==-1){
				printf("%d %d\n",id,_map[ed]);
			}
			else if(ed==-1){
				printf("%d %d\n",id,_map[bd]);
			}
			else {
				if (gd-bd<=ed-gd)
					printf("%d %d\n",id,_map[bd]);
				else printf("%d %d\n",id,_map[ed]);
			}
		}
	}
	return 0;
}
