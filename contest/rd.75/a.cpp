#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char a[20];
	int i,len;
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;++i){
		if(a[i]!='1' && a[i]!='4') break;
		else if(a[i]=='4'){
			if(!(i-1>=0 && (a[i-1]=='1' || (i-2>=0 &&a[i-2]=='1')))) break;
		}
	}
	if(i==len) printf("YES\n");
	else printf("NO\n");
	return 0;
}
