#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int main(){
	long long n;
	while(scanf("%lld",&n) && n){
	map<int,int> hash;
	int len=1,flag=1,cas=0;
	long long num=8;
	map<int,int>::iterator p;
	while(num%n){
		if(len>2500){
			flag=0;
			break;
		}
		num=((num*10)%n+8%n)%n;
		p=hash.find(num);
		if(p==hash.end())
			hash.insert(pair<int,int>(num,1));
		else{
			flag=0;
			break;
		}
		++len;
	}
	printf("Case %d: ",++cas);
	if(flag) printf("%d\n",len);
	else puts("0");
	}
	return 0;
}
