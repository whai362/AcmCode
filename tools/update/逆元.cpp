LL ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

//要求a与m互质
LL inv(LL a,int m){   //求逆元
    LL d,x,y,t= (LL)m;
    d= ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

//逆元非递归写法
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}

