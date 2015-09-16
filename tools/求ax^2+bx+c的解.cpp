vector<double> x;
void cal(double a, double b, double c) {	//¼ÆËãa*x^2+b*x+c=0µÄ½â
	if (a == 0 && b == 0)
		return ;
	if (a == 0) {
		double t = -c / b;
		//if(t>=0 && t<=100)
		x.PB(t);
		return ;
	}
	double delta = b * b - 4 * a * c;
	if (delta < 0) return ;
	if (delta == 0) {
		double t = -b / (2 * a);
		//if(t>=0 && t<=100)
		x.PB(t);
	}
	else {
		double t1 = (-b + sqrt(delta)) / (2 * a);
		double t2 = (-b - sqrt(delta)) / (2 * a);
		//if(t1>=0 && t1<=100)
		x.PB(t1);
		//if(t2>=0 && t2<=100)
		x.PB(t2);
	}
}

