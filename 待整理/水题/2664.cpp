#include<iostream>
#include<string>
using namespace std;
int main(){
	int c,count,f,i,j,k,m,r;
	string se[105],re;
	while(cin>>k&&k){
		cin>>m;
		f=1;
		for(i=0;i<k;++i) cin>>se[i];
		for(i=0;i<m;++i){
			cin>>c>>r;
			count=0;
			while(c--){
				cin>>re;
				for(j=0;j<k;++j) if(se[j]==re){ ++count; break; }
			}
			if(count<r) f=0; 
		}
		if(f) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
