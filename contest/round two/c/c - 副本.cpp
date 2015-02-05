#include<fstream>
#include<iostream>
using namespace std;
ofstream fout("out2.txt");
int main(){
	long long n,k=1,count=0;
	for(n=1;n<2e31;++n){
		k=1,count=0;
		while(k<=n){
			k=k<<1;
			++count;	
		}
		k=2*n/(2*n+1-k);
		while(k!=1){
			k=k>>1;
			++count;
		}
		fout<<n<<':'<<count<<endl;
	}
	return 0;
}
