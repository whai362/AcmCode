#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	for(double x=0;x<100.0;x=x+1){
		cout<<log((1-x)/(1-2*x-x*x*x))<<endl;
	}
	return 0;
}
