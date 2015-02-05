#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long ans=0;
int main(){
	int a,i,n,tmp;
	long long cnt;
	priority_queue<int> q;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		if(a%2==0){
			tmp=0;
			while(a){
				while(a && a%2==0) a/=2;
				a-=1;
				++tmp;
			}
			q.push(tmp);
		}
		else{
			tmp=0;
			a-=1;
			++tmp;
			while(a){
				while(a && a%2==0) a/=2;
				a-=1;
				++tmp;
			}
			q.push(tmp);
		}
	}
	while(!q.empty()){
		tmp=q.top();
		cnt=0;
		while(!q.empty() && q.top()==tmp){
			++cnt;
			q.pop();
		}
		ans+=cnt*(cnt-1)/2;
	}
	cout<<ans<<endl;
}
