#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[15];
char hash[55];
void print(int len){
	string str="";
	for(int i=0;i<len;++i){
		str+=hash[a[i]];
	}
	cout<<str<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string str;
	for(int i=0;i<52;++i){
		if(i&1)
			hash[i]=char('a'+(i>>1));
		else
			hash[i]=char('A'+(i>>1));
		//cout<<hash[i];
	}
	//cout<<endl;
	cin>>n;
	while(n--){
		cin>>str;
		int len=str.length();
		for(int i=0;i<len;++i){
			if(str[i]>='A' && str[i]<='Z')
				a[i]=(str[i]-'A')*2;
			else
				a[i]=(str[i]-'a')*2+1;
		}
		sort(a,a+len);
		/*for(int i=0;i<len;++i){
			cout<<a[i]<<' ';
		}
		cout<<endl;*/
		print(len);
		while(next_permutation(a,a+len)){
			print(len);
		}
	}
	return 0;
}
