#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=105;
char str[N];
int main(){
    int T,len;
	scanf("%d",&T);
	while(T--){
    scanf("%d",&len);
	scanf("%s",str);
    sort(str, str + len);
	printf("%s\n",str);
    while (next_permutation(str, str + len)){
        printf("%s\n",str);
    }
	}
    return 0;
}
