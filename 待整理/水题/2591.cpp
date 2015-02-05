#include<stdio.h>
int s[10000000];
int min(int a,int b){
	long long t;
	if(a<b) return a;
	return b;
}

int deal(int n){
	int t1,t2,p1=0,p2=0,count=0;
	if(s[n-1]) return s[n-1];
	else{
		s[0]=1;
		++count;
		while(1){
			if(count==n) break;
			t1=2*s[p1]+1;
			t2=3*s[p2]+1;
			s[count]=min(t1,t2);
			if(s[count]==t1) ++p1;
			if(s[count]==t2) ++p2;
			++count;
		}
		return s[count-1];
	}
}

int main(){
	int ans,count,n;
	while(scanf("%d",&n)!=EOF){
		ans=deal(n);
		printf("%d\n",ans);
	}
	return 0;
}
