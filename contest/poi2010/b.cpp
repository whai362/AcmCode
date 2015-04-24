#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=100005;
int a[N];
int ans[N];
int vis[N];
stack<int> s1,s2;
void print(int n){
	for(int i=0;i<n;++i){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
bool deal(int x,int &p,int n){
	if(p<n && a[p]==x){
		ans[p]=1;
		vis[a[p]]=1;
		++p;
		return true;
	}
	
	if(vis[x]==1){
		if(s1.top()==x){
			s1.pop();
			return true;
		}
		if(s2.top()==x){
			s2.pop();
			return true;
		}
		return false;
	}
	
	while(a[p]!=x){
		int A=s1.top()-a[p];
		int B=s2.top()-a[p];
		if(A<0 && B<0) return false;
		else if(A>0 && B<0){
			ans[p]=1;
			s1.push(a[p]);
		}
		else if(A<0 && B>0){
			ans[p]=2;
			s2.push(a[p]);
		}
		else{
			if(A<=B){
				ans[p]=1;
				s1.push(a[p]);
			}
			else{
				ans[p]=2;
				s2.push(a[p]);
			}
		}
		vis[a[p]]=1;
		++p;
	}
	ans[p]=1;
	vis[x]=1;
	++p;
	return true;
}
bool gao(int n){
	s1.push(n+1);
	s2.push(n+1);
	int p=0;
	for(int i=1;i<=n;++i){
		//cout<<i<<' '<<p<<endl;
		if(!deal(i,p,n)) return false;
		//print(n);
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	if(!gao(n)) puts("NIE");
	else{
		puts("TAK");
		for(int i=0;i<n;++i){
			printf("%d%c",ans[i],i==n-1?'\n':' ');
		}
	}
	//print(n);
	return 0;
}
