#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int m;
	int cnt=0;
	int sum=0;
	for(int i=0;i<k;++i){
		scanf("%d",&m);
		sum+=m-1;
		for(int j=0;j<m;++j){
			scanf("%d",&a[j]);
		}
		if(a[0]==1){
			for(int j=0;j<m;++j){
				if(a[j]==j+1) ++cnt;
				else break;
			}
		}
	}
	//cout<<sum<<' '<<cnt<<endl;
	printf("%d\n",sum+(n-1)-2*(cnt-1));
	return 0;
}
