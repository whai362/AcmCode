//主要是用来求某个字符串的最长回文子串
void Manacher(char s[], int len[], int n) {
	memset(len, 0, sizeof(len));
	for (int i = 0, j = 0, k; i < 2 * n; i += k, j = max(j - k, 0)) {
		while (i - j >= 0 && i + j + 1 < 2 * n && s[(i - j) / 2] == s[(i + j + 1) / 2]) j ++;
		len[i] = j;
		for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] < j - k; k ++) {
			len[i + k] = min(len[i - k], j - k);
		}
	}
}