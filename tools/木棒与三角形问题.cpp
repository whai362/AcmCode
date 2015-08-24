木棒与三角形问题，一般都可以枚举最长边，用容斥来做

1. 求长度为l的木棒，截成3段，求能组成三角形的方法数(截的位置不同算不同的方法比如1 3 3和3 3 1算不同的方法)。
//方法一：
LL gao(int l){
	LL ret=0;
	for(int i=1;2*i<l;++i) {
		ret+=(l-1)/2-(l/2-i);
	}
	return ret;
}

//方法二：
//枚举最长边，用容斥来做
LL cal(LL a, LL remain) {
	if(a < remain) return 0;
	return remain - 1;
}

LL gao(LL l) {
	LL ret = (l - 1) * (l - 2) / 2;
	for(int i = 1; i < l; ++i) {
		ret -= 3 * cal(i, l - i);
	}
	return ret;
}

2. 给出3根木棒，长度分别为a, b, c，分别给它们一个增量a1, b1, c1，使得它们能构成一个三角形，且a1 + b1 + c1 == l，且a1, b1, c1 >= 0。问能构成三角形的方法数(增量不同算不同的方法)。
限制：1 <= a, b, c <= 1e5; 0 <= l <= 1e5

LL cal(LL a, LL b, LL c, LL r) {
	if(a < b + c + r) return 0;
	return r + 1;
}

void gao(LL a, LL b, LL c, LL l) {
	LL ans = (l + 1) * (l + 2) / 2;
	for(int i = 0; i <= l; ++i) {
		ans -= cal(a + i, b, c, l - i);
		ans -= cal(b + i, a, c, l - i);
		ans -= cal(c + i, a, b, l - i);
	}
	cout<<ans<<endl;
}


3. 给出3根木棒，长度分别为a, b, c，分别给它们一个增量a1, b1, c1，使得它们能构成一个三角形，且a1 + b1 + c1 <= l，且a1, b1, c1 >= 0。问能构成三角形的方法数(增量不同算不同的方法)。
限制：1 <= a, b, c <= 1e5; 0 <= l <= 1e5

LL cal(LL a, LL b, LL c, LL r) {
	if(a < b + c) return 0;
	LL tmp = min(r, a - (b + c));
	return (tmp + 1) * (tmp + 2) / 2;
}

void gao(LL a, LL b, LL c, LL l) {
	LL ans = (l + 1) * (l + 2) * (l + 3) / 6;

	for(int i = 0; i <= l; ++i) {
		ans -= cal(a + i, b, c, l - i);
		ans -= cal(b + i, a, c, l - i);
		ans -= cal(c + i, a, b, l - i);
	}
	cout<<ans<<endl;
}
