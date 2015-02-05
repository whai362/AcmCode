#include<cstdio>
#include<iostream>
using namespace std;
const int Mod=20140518;
long long a_b_Mod_c(long long a, int b, int c){
    long long result = 1;
    int digit[305];
    int i,k;
    i = 0;
    while(b){
        digit[i++] = b%2;
        b >>= 1;
    }
    for(k = i-1; k >= 0; k--)
    {
        result = (result * result) % c;
        if(digit[k] == 1)
        {
            result = (result * a) % c;
        }
    }
    return result;
}
int main(){
	int n,k;
	
}
