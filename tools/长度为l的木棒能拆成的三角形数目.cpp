//求长度为l的木棒，截成3段，求能组成三角形的方法数。
LL gao(int l){
	LL ret=0;
	for(int i=1;2*i<l;++i){
		ret+=(l-1)/2-(l/2-i);
	}
	return ret;
}

