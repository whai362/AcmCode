#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int c[55];
long long pow(int n){
	long long res=1;
	for(int i=0;i<n;++i){
		res<<=1;
	}
	return res;
}
int main(){
	int n;
	for(int i=0;i<n;++i){
		scanf("%d",&c[i]);
	}
	sort(c,c+n);
	long long l,r,tmp;
	tmp=pow(c[n-1]-1);
	l=tmp;
	r=l+tmp;
	for(int i=n-2;i>=0;--i){
		long long tmp_l,tmp_r;
		tmp=pow(c[i]-1);
		tmp_l=tmp;
		tmp_r=tmp_l+tmp;
		while(tmp_r<=r){
			if(tmp_r>
		}
	}
}
