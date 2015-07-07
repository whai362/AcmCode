#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1e6+6;
const int BEI=12000;
#define PB push_back
struct Dt{
	int h,m,s;
	Dt(int _h,int _m,int _s){
		h=_h;
		m=_m;
		s=_s;
	}
};
vector<Dt> tab[3*N];
void predo(){
	int s=0,f=0;
	//+12 +60
	for(int i=0;i<12;++i){
		for(int j=0;j<60;++j){
			for(int k=0;k<6;++k){
				
				int jj=(s-f+360*BEI)%(360*BEI);
				if(jj>180*BEI) jj=360*BEI-jj;
				//if(i==0 && j==1 && k==3){
				//	cout<<s<<' '<<f<<' '<<jj<<endl;
				//}
				tab[jj].PB(Dt(i,j,k*10));
				s=(s+BEI/12)%(360*BEI);
				f=(f+BEI)%(360*BEI);
			}
		}
	}
}
int main(){
	predo();
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<tab[n].size();++i){
			Dt ans=tab[n][i];
			printf("%02d:%02d:%02d\n",ans.h,ans.m,ans.s);
		}
	}
	return 0;
}
