//ÊäÈëÊä³öÍâ¹Ò
void In(int &x){
	char ch;
	while (ch = getchar(),ch < '0' || ch > '9');
	x = ch - '0';
	while (ch = getchar(),ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}

void Out(int x){
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}
