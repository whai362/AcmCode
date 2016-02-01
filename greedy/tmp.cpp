#include <iostream>
#include <cstdio>
#include <string.h>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 25005;
struct intversal{
	int begin,end;
}aa[N];
bool cmp(intversal a,intversal b){
	if(a.begin == b.begin)
		return a.end < b.end;
	return a.begin < b.begin;
}
int main(){
	//freopen("1.txt","r",stdin);
	int n,T;
	while(scanf("%d%d",&n,&T) != EOF){
		for(int i = 0; i < N; ++i){
		  aa[i].begin = INT_MAX;
		  aa[i].end = INT_MAX;
		}
	    for(int i = 0; i < n; ++i)
			scanf("%d%d",&aa[i].begin,&aa[i].end);
		sort(aa,aa+n,cmp);
		if(aa[0].begin > 1){
		  printf("-1\n");
		  continue;
		}
		int ans = 1,id = 0;
		for(int i = 0; i < n; ){
			int cnt = 0;
			for(int j = i + 1; j < n; ++j){
				if(aa[j].begin > aa[id].end + 1)
					break;
				if(aa[j].begin >= aa[id].begin && aa[j].end >= aa[id].end + 1){
					if(aa[j].end > aa[cnt].end)
				       cnt = j;
				}
			}
			if(cnt == 0){
			  i++;
			}
			else{
			  id = cnt;
			  ans++;
			  i = id;
			}
		}
		if(aa[id].end == T){
		  printf("%d\n",ans);
		}
		else
			printf("-1\n");
	}
	return 0;
}
