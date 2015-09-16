//高斯消元整数模板
//使用前注意：
//增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var，使用前初始化a，x
const int N = 25,
          INF = 0x3f3f3f3f;
int a[N][N];	//增广矩阵
int x[N];	//解集
int free_x[N];	//用来存储自由变元
int free_num;	//自由变元的个数
//有equ个方程，var个变元。
//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int gauss(int equ, int var) {
	int max_r, col, k;
	free_num = 0;
	for (k = 0, col = 0; k < equ && col < var; k++, col++) {
		max_r = k;
		for (int i = k + 1 ; i < equ; i++)
			if (abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;
		if (a[max_r][col] == 0) {
			k--;
			free_x[free_num++] = col; //自由变元
			continue;
		}
		if (max_r != k) {
			for (int j = col; j < var + 1; j++)
				swap(a[k][j], a[max_r][j]);
		}
		for (int i = k + 1; i < equ; i++)
			if (a[i][col] != 0)
				for (int j = col; j < var + 1; j++)
					a[i][j] ^= a[k][j];
	}
	for (int i = k; i < equ; i++)
		if (a[i][col] != 0)
			return -1;
	if (k < var)return var - k;
	for (int i = var - 1; i >= 0; i--) {
		x[i] = a[i][var];
		for (int j = i + 1; j < var; j++)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;
}

//对结果的处理(这里是统计大于0的结果个数)
void deal(int equ, int var) {
	int fn = gauss(equ, var);	//自由变元个数
	/*(if(fn==-1){		//无解
		puts("inf");
		return ;
	}*/
	if (fn == 0) {		//唯一解
		int ans = 0;
		for (int i = 0; i < var; ++i)	//x[]存着唯一解
			ans += x[i];	//解访问处
		printf("%d\n", ans);
		return ;
	}
	else {	//多解
		//枚举自由变元
		int ans = INF,
		    tot = (1 << fn);
		for (int i = 0; i < tot; i++) {
			int cnt = 0;
			for (int j = 0; j < fn; j++) {
				if (i & (1 << j)) {
					x[free_x[j]] = 1;	//解访问处
					cnt++;
				}
				else x[free_x[j]] = 0;	//解访问处
			}
			for (int j = var - fn - 1; j >= 0; j--) {
				int idx;
				for (idx = j; idx < var; idx++)
					if (a[j][idx])
						break;
				x[idx] = a[j][var];	//解访问处
				for (int l = idx + 1; l < var; l++)
					if (a[j][l])
						x[idx] ^= x[l];	//解访问处
				cnt += x[idx];
			}
			//这里可以用for统一访问
			ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
}
