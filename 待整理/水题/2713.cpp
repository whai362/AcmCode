#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const double pi=acos(-1.0);
int main(){
	char s[105],t[15];
	int i,l,cnt1,cnt2;
	double a[5];
	while(cin.getline(s,sizeof(s))){
		l=strlen(s);
		cnt1=cnt2=0;
		for(i=0;i<l;++i){
			if(s[i]>='0' && s[i]<='9'){
				t[cnt1++]=s[i];
			}
			else if(cnt1){
				t[cnt1]=0;
				sscanf(t,"%lf",&a[cnt2++]);
				cnt1=0;
			}
		}
		t[cnt1]=0;
		sscanf(t,"%lf",&a[cnt2++]);
		cout<<s<<": "<<int((a[0]*a[1]*2/1000+a[2]*2.54)*pi+0.5)<<endl;
	}
	return 0;
}
