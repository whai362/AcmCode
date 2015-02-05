#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[2][1000005];
char temps[2][10000005];
int L;
struct str{
    char strs[12];
    inline int operator < (const str & s)const{
        return strcmp(strs,s.strs)<0;
    }
}m1[1000005],m2[1000005];
int next(char *&s){
    if(*s==0) return 0;
    int ans=0;
    while((*s)<='9'&&(*s)>='0'){
        ans*=10;
        ans+=(*s)-'0';
        s++;
    }
    return ans;
}
int main(){
    int t,num;
	int cas;
	scanf("%d",&t);
    for(cas=1;cas<=t;cas++){
        memset(m1,0,sizeof(m1));
        memset(m2,0,sizeof(m2));
        cin>>L;
        scanf("%s %s",s[0],s[1]);
        int p1 =0;
        char *ptr1=*s;
        int s1=0;
        while(num=next(ptr1)){
            char temp=*ptr1;
            s1+=num;
            while(num--)
            {
                temps[0][p1]=temp;
                p1++;
            }
            ptr1++;
        }
        s1/=L;
        int s2=0;
        char *ptr2=s[1];
        int p2=0;
        while(num=next(ptr2)){
            char temp=*ptr2;
            s2+=num;
            while(num--)
            {
                temps[1][p2]=temp;
                p2++;
            }
            ptr2++;
        }
        s2/=L;
        p1=0;
        for(int j=0;j<L;j++){
            for(int i=0;i<s1;i++){
                m1[i].strs[j]=temps[0][p1];
                p1++;
            }
        }
        p2=0;
        for(int j=0;j<L;j++){
            for(int i=0;i<s2;i++){
                m2[i].strs[j]=temps[1][p2];
                p2++;
            }
        }    
        int flag=1;
        if(s1!=s2){
            printf("Case %d: No\n",cas);
            continue;
        }
        sort(m1,m1+s1);
        sort(m2,m2+s2);
        for(int i=0;i<s1 && flag;i++){
            for(int j=0;j<L && flag;j++){
                if(m1[i].strs[j]!=m2[i].strs[j]) flag=0;
            }
        }
        if(flag) printf("Case %d: Yes\n",cas);
		else printf("Case %d: No\n",cas);
	}
    return 0;
}

