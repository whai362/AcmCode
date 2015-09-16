int jiou(int n, int k) {
	return ((n - k)&k) > 0 ? 0 : 1;
}
