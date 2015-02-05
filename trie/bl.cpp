#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	cout<<80000<<endl;
	for(int i=0;i<80000-1;++i){
		cout<<i<<' '<<i+1<<' '<<i+1<<endl;
	}
	return 0;
}
