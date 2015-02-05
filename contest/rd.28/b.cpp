#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
	int i,n1,n2,m,_min=0,_max=0,tmp,tmp1,a[1005];
	scanf("%d%d",&n1,&m);
	priority_queue<int> q;
	n2=n1;
	for(i=0;i<m;++i){
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	sort(a,a+m);
	for(i=0;i<m;++i){
		if(n1>a[i]){
			n1=n1-a[i];
			_min+=(1+a[i])*a[i]/2;
		}
		else{
			_min+=(a[i]-n1+1+a[i])*n1/2;
			break;
		}
	}
	while(n2--){
		tmp1=q.top();
		q.pop();
		_max+=tmp1;
		--tmp1;
		if(tmp1) q.push(tmp1);
	}
	printf("%d %d\n",_max,_min);
	return 0;
}
