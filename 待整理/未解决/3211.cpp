#include<iostream>
#include<queue>
using namespace std;
struct cloth{
	int t;
	string c;
}cl[105];
int main(){
	int ans,i,j,n,m;
	string c[15];
	cin>>m>>n;
	for(i=0;i<m;++i)
	  cin>>c[i];
	for(i=0;i<n;++i)
	  cin>>cl[i].t>>cl[i].c;
	ans=0;
	for(i=0;i<m;++i){
		priority_queue<int> q;
		for(j=0;j<n;++j)
		  if(cl[j].c==c[i]) q.push(cl[j].t);
		while(!q.empty()){
			ans+=q.top();
			q.pop();
			if(!q.empty()) q.pop();
			else break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
