#include <string>
#include <iostream>
using namespace std;

int main()
{
    int n;cin>>n;
    while (n--)
    {
        char d2x[17] = "0123456789abcdef";
        int flag[4] = {1,2,4,8};
        string s;cin>>s;
        int len = s.length();
		int i;
		for(i=0;i<len;++i){
			if(s[i]!='0') break;
		}
		int j=0;
		for(;i<len;++i,++j){
			s[j]=s[i];
		}
		s[j]=0;
        int mod = len%4;
        int num = 0;
        for (int i=mod;i>0;i--)
        {
            if (s[mod-i]=='1')
            {
                num += flag[i-1];
            }
        }
        if (mod)
            cout<<d2x[num];
        for (int i=mod;i<len;i+=4)
        {
            num = 0;
            for (int j=0;j<4;j++)
            {
                if (s[i+j]=='1')
                {
                    num += flag[3-j];
                }
            }
            cout<<d2x[num];
        }
        cout<<endl;
    }
    return 0;
}
