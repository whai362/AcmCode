#include<fstream>
#include<iostream>
#include<time.h>
using namespace std;
ofstream fout("out.txt");
int main(){
	long long n,k=1,count=0;
	for(n=0;n<2e31;++n){
		k=1,count=0;
		double start=clock();
		while(k<=n){
			k=k<<1;
			++count;	
		}
		while(k!=1){
			if(k>n) k=2*(k-n)-1;
			else k=k<<1;
			++count;
		}
		fout<<n<<':'<<count<<endl;
		fout<<double(clock()-start)/CLOCKS_PER_SEC<<endl;
	}
	return 0;
}
