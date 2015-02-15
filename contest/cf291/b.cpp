#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
#define MP make_pair
set< pair<pair<int,int>,int> > st;
void gao(int x1,int y1,int x2,int y2){
	int t1=x1-x2;
	int t2=y1-y2;
	if(t1<0) t1=-t1,t2=-t2;
	int d=__gcd(t1,t2);
	t1/=d;
	t2/=d;
	int c=-t2*x1-t1*y1;
	st.insert(MP(MP(t1,t2),c));
}
int main(){
	int n,x0,y0;
	int x,y;
	scanf("%d%d%d",&n,&x0,&y0);
	for(int i=0;i<n;++i){
		scanf("%d%d",&x,&y);
		gao(x0,y0,x,y);
	}
	printf("%d\n",st.size());
	return 0;
}
