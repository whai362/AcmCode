#include<cstdio>
#include<fstream>
using namespace std;
#define M 1000000000
int main(){
	int i;
	long long r=1;
	ofstream fout("out.txt");
	for(i=1;i<10005;++i){
		r=(r*i)%M;
		if(r%10){
			fout<<r%10<<',';
		}
		else{
			while(!(r%10)) r=r/10;
			fout<<r%10<<',';
		}
	}
	return 0;
}
