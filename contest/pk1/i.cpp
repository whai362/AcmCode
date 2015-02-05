#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
long long a[2005],b[2005];
int main(){
	int i,j,k,m,n;
	while(cin>>n && n){
		for(i=0;i<2;++i){
			priority_queue< long long,vector<long long>,less<long long> > h;
			for(j=0;j<n;++j)
			  cin>>a[j];
			if(!i){
				for(j=0;j<n;++j)
				  h.push(a[j]);
			}
			else{
				for(j=0;j<n;++j){
					h.push(a[0]+b[j]);
				}
				for(j=1;j<n;++j){
					if(a[j]+b[0]>=h.top()) break;
					for(k=0;k<n;++k){
						if(a[j]+b[k]>=h.top()) break;
						else{
							h.pop();
							h.push(a[j]+b[k]);
						}
					}
				}
			}
			for(j=n-1;j>=0;--j){
				b[j]=h.top();
				h.pop();
			}
		}
		cout<<b[0];
		for(i=1;i<n;++i)
		  cout<<' '<<b[i];
		printf(" \n");
	}
	return 0;
}

