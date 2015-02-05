#include <iostream>
#include <cstring>
using namespace std;
/*
这个模板 字符串是从0开始的
next数组是从1开始的
*/
const int N = 1000002;
int next[N];
char S[N], T[N];
int slen, tlen;

void getNext(){
	int i,j;
	i=0;
	j=next[0]=-1;
	while(i<tlen){
		if(j==-1 || T[i]==T[j])
			next[++i]=++j;
		else
			j=next[j];
	}
}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/
int KMP_Index(){
    int i = 0, j = 0;
    getNext();
    while(i < slen && j < tlen){
        if(j == -1 || S[i] == T[j]){
            i++; j++;
        }
        else
            j = next[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}
/*
返回模式串在主串S中出现的次数
*/
int KMP_Count(){
    int ans = 0;
    int i, j = 0;

    if(slen == 1 && tlen == 1){
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext();
    for(i = 0; i < slen; i++){
        while(j > 0 && S[i] != T[j])
            j = next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen){
            ans++;
            j = next[j];
        }
    }
    return ans;
}
void gao(){
    int i = 0, j = 0;
	if(slen>=tlen){
		i=i+slen-tlen;
	}
	else{
		j=j+tlen-slen;
	}
	cout<<i<<' '<<j<<endl;
    getNext();
	while(i<slen){
		if(j==-1 || S[i]==T[j]){
			++i;
			++j;
			if(i==slen) cout<<j<<endl;
			if(i==slen && j!=0){
				--i;
				j=next[j-1];
			}
		}
		else{
			if(j==-1) cout<<'!'<<next[j]<<endl;
			j=next[j];
		}
	}
    //while(i < slen && j < tlen){
    //    if(j == -1 || S[i] == T[j]){
    //        i++; j++;
    //    }
    //    else
    //        j = next[j];
    //}
    //if(j == tlen)
    //    return i - tlen;
    //else
    //    return -1;
}
int main(){
    int TT;
    int i, cc;
    cin>>TT;
    while(TT--){
        cin>>S>>T;
        slen = strlen(S);
        tlen = strlen(T);
		gao();
        //cout<<"模式串T在主串S中首次出现的位置是: "<<KMP_Index()<<endl;
        //cout<<"模式串T在主串S中出现的次数为: "<<KMP_Count()<<endl;
    }
    return 0;
}
/*
test case
aaaaaa a
abcd d
aabaa b
*/

