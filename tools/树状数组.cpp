int BIT[N];
int lowbit(int x){ return x&-x; }
int sum(int x){
	int s=0;
	while(x>0){
		s+=BIT[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int x){
	while(x<=maxa){
		++BIT[x];
		x+=lowbit(x);
	}
}

