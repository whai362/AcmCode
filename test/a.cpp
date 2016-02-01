/*题解：
  由于字符串长度不超过100，且文字的行数不超过100，所以可以暴力判断，判断一组的时间复杂度为100 * 100，然后100组的时间复杂度为1e6，在1s的时间内可以解决。
  其中对于忽略大小写的选项，只要统一转化为小写字符判断即可。
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;

char word[N];
char text[N];

//把字符串里的字符统一转换成小写的
void to_lowercase(char *str) {
	int len = strlen(str);
	for(int i = 0; i < len; ++i) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

//判断字符串text是否包含字符串word
bool ok(char *text, int op) {
	char tmp[N];
	int text_len = strlen(text);
	for(int i = 0; i < text_len; ++i) {
		tmp[i] = text[i];
	}
	if(op == 0) to_lowercase(tmp);	//判断是否要忽略大小写

	//判断包含关系
	int word_len = strlen(word);
	for(int i = 0; i <= text_len - word_len; ++i) {
		int flag = 1;
		for(int j = 0; j < word_len; ++j) {
			if(word[j] != tmp[i + j]) {
				flag = 0;
				break;
			}
		}
		if(flag) return true;
	}
	return false;
}

int main() {
	int op, n;
	scanf("%s", word);
	scanf("%d", &op);
	scanf("%d", &n);

	if(op == 0) to_lowercase(word);	//判断是否要忽略大小写

	for(int i = 0; i < n; ++i) {
		scanf("%s", text);
		if(ok(text, op)) {
			printf("%s\n", text);
		}
	}
	return 0;
}
