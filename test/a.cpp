#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
ofstream fout("in.txt");
int main(){
	int i,j,k;
	srand(time(NULL));
	int n,c,f,h,p;
	fout<<10<<endl;
	for(i=0;i<10;++i){
		n=1+rand()%19999;
		if(n%2==0) ++n;
		c=1+rand()%80000;
		if(c<n) c+=n;
		f=900000000+rand()%100000001;
		fout<<n<<' '<<c<<' '<<f<<endl;
		for(j=0;j<c;++j){
			h=1+rand()%200000;
			p=1+rand()%2000;
			fout<<h<<' '<<p<<endl;
		}
		fout<<endl;
	}
	
	return 0;
}
