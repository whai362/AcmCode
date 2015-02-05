#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string str,txt;
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	while(cin>>n){
		getline(cin,txt);
		txt="";
		for(int i=0;i<n;++i){
			getline(cin,str);
			txt+=str;
		}
		/*int len=0;
		for(int i=0;i<n;i++){
			gets(str);
			int l=strlen(str);
			for(int j=0;j<l;j++){
				txt[len]=str[j];
				len++;
			}
		}*/
		__int64 ans=1,cnt1=0,cnt2=0;
		int len=txt.length();
		int flag1=0,flag2=0;
		for(int i=0;i<len;++i){
			if(txt[i] == '{')
				flag1 = 1;
			else if(flag1 && txt[i] == '|')
				cnt1++;
			else if(flag1 && txt[i] == '}')
			{
				flag1 = 0;
				ans*=(cnt1+1);
				cnt1 = 0;
			}
			else if(txt[i] == '$' && flag2 == 0)
				flag2 = 1;
			else if(txt[i] == '$' && flag2 == 1)
			{
				ans = ans*(cnt2+1);
				cnt2 = 0;
				flag2 = 0;
			}
			else if(flag2 && txt[i] == ' ')
				cnt2++;
			else if(flag2 && txt[i] != ' ' && txt[i]!='$')
			{
				ans = ans*(cnt2+1);
				cnt2 = 0;
			}
			if(ans>100000)
				break;
		}
		if(ans>100000)
			puts("doge");
			//printf("doge\n");
		else
			cout<<ans<<endl;
			//printf("%I64d\n",ans);
	}
	return 0;
}
