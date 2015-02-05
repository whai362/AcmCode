#include <iostream>
#include<string>
using namespace std;
int main() {
	int n,i,j;
	while(cin>>n&&n){
		int a[1000]={0};
		string p[1001];
		for(i=0;i<n;i++) cin>>p[i];
		for(i=1;i<n;i++)
			for(j=0;j<i;j++)
				if(p[i]==p[j]){ a[j]++; break; }
		j=0;
		for(i=1;i<n;i++){
			if(a[i]>a[j])j=i;
		}
		cout<<p[j]<<endl;
	}
	return 0;
}

