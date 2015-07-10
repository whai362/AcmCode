#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<string,double> mp;
void predo(){
	mp["A"]=4;
	mp["A-"]=3.7;
	mp["B+"]=3.3;
	mp["B"]=3.0;
	mp["B-"]=2.7;
	mp["C+"]=2.3;
	mp["C"]=2.0;
	mp["C-"]=1.7;
	mp["D"]=1.3;
	mp["D-"]=1.0;
	mp["F"]=0;
}
int main(){
	predo();
	int n;
	double p;
	string str;
	while(scanf("%d",&n)!=EOF){
		double ans=0;
		double sum=0;
		for(int i=0;i<n;++i){
			cin>>p>>str;
			if(str=="P" || str=="N") continue;
			ans+=p*mp[str];
			sum+=p;
		}
		if(ans==0) puts("0.00");
		else{
			printf("%.2f\n",ans/sum);
		}
	}
	return 0;
}
