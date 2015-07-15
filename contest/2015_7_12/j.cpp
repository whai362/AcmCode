#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define PB push_back
vector<double> line;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		int x;
		scanf("%d",&n);
		line.clear();
		line.PB(0);
		line.PB(1);
		for(int i=0;i<n;++i){
			scanf("%d",&x);
			double tmp=(line[x]+line[x+1])/2;
			printf("%f\n",tmp);
			line.insert(line.begin()+x+1,tmp);
		}
	}
	return 0;
}
