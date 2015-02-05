#include<cstdio>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
const double eps=1e-8;
int x[5];
struct Data{
	double n;
	int flag;
	Data(double _n,int _flag){
		n=_n;
		flag=_flag;
	}
};
int setN(int i){
	return 1<<i;
}
int getN(int n,int i){
	return (n>>i) && 1;
}
bool eq(double a,double b){
	if(fabs(a-b)<eps) return true;
	return false;
}
int main(){
	while(scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3])!=EOF){
	queue<Data> q;
	for(int i=0;i<4;++i){
		q.push(Data(x[i],setN(i)));
	}
	int flag=0;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		//cout<<now.n<<' '<<now.flag<<endl;
		if(eq(now.n,24.0) && now.flag==15){
			flag=1;
			break;
		}
		for(int i=0;i<4;++i){
			if(!getN(now.flag,i)){
				q.push(Data(now.n+x[i],now.flag | setN(i)));
				q.push(Data(now.n-x[i],now.flag | setN(i)));
				q.push(Data(now.n*x[i],now.flag | setN(i)));
				if(x[i]) q.push(Data(now.n/x[i],now.flag | setN(i)));
			}
		}
	}
	if(flag) puts("Yes");
	else puts("No");
	}
	return 0;
}
