#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[15][15];
using namespace std;
int main(){
    string str="12345678";
	int cnt=0;
	int len=str.length();
	for(int i=0;i<len;++i){
		a[str[i]-'0'][i]=1;
	}
    while (next_permutation(str.begin(), str.end())){
        int flag=1;
		for(int i=0;i<len;++i){
			if(a[str[i]-'0'][i]){
				flag=0;
				break;
			}
		}
		if(flag){
			++cnt;
			//cout<<str<<endl;
		}
	}
	cout<<cnt<<endl;
    return 0;
}
