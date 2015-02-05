#include<cstdio>
#include<queue>
using namespace std;
struct data{
	int a,b,n;
	data(){}
	data(int a,int b,int n):a(a),b(b),n(n){}
	bool operator < (const data &other) const{
		return a<other.a;
	}
}d;
int a[500005];
int main(){
	int i,n,b,tmp1;
	while(scanf("%d%d",&n,&b) && (n!=-1 || b!=-1)){
		priority_queue<data> q;
		for(i=0;i<n;++i){
			scanf("%d",&a[i]);
			q.push(data(a[i],i,1));
		}
		tmp1=b-n;
		for(i=0;i<tmp1;++i){
			d=q.top();
			q.pop();
			++d.n;
			if(a[d.b]%d.n){
				q.push(data(a[d.b]/d.n+1,d.b,d.n));
			}
			else{
				q.push(data(a[d.b]/d.n,d.b,d.n));
			}
		}
		printf("%d\n",q.top().a);
	}
	return 0;
}
