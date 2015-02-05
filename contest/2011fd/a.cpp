#include<iostream>
#include<cstdio>
using namespace std;

int n,s1,s2,s0,v1,v2,v0;
double d0,d1,d2;
bool check(int mid){
	if (n-mid*s1>=s2) return true;
	return false;
}

int bitsearch(){
	int l=0,r=n/s1;
	while (l<r-1){
		int mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	return l;
}

int main(){
	int cases;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		scanf("%d%d%d%d%d",&n,&s1,&v1,&s2,&v2);
		d1=double(v1)/s1;
		d2=double(v2)/s2;
		if (d1<d2){
			v0=v1;v1=v2;v2=v0;
			s0=s1;s1=s2;s2=s0;
			d0=d1;d1=d2;d2=d0;
		}
		cout<<"++++++++++++"<<endl;
		int ans=(n/s1)*v1;
		int k=bitsearch();cout<<k<<endl;
		int tmp=k*v1+(n-k*s1)/s2*v2;
		ans=max(ans,tmp);
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}

