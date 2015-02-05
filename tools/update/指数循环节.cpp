//¹«Ê½x >= Phi(C), A^x = A ^ (x%Phi(C) + Phi(C)) (mod C)
int phi[N];
void get_phi(){
	for(int i=0;i<N;++i) phi[i]=i;
	for(int i=2;i<N;++i) if(phi[i]==i)
		for(int j=i;j<N;j+=i)
			phi[j]=phi[j]/i*(i-1);
}

