import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static InputStream is;
    static PrintWriter out;
    static String INPUT = "";
    
    static void solve()
    {
        int cas = 1;
        long mod = 3814697265625L;
        for(int T = ni();T >= 1;T--){
            long n = nl();
            long ret = C(2*n, n, 5, 18) - C(2*n, n-1, 5, 18);
            if(ret < 0)ret += mod;
            out.println("Case #" + (cas++) + ": " + ret);
        }
    }
    
    public static long C(long n, long r, int p, int q)
    {
        if(r < 0 || r > n || n < 0)return 0;
        long P = 1;
        for(int i = 0;i < q;i++)P *= p;
        
        long z = n - r;
        long e0 = 0;
        for(long u = n/p;u > 0;u /= p)e0 += u;
        for(long u = r/p;u > 0;u /= p)e0 -= u;
        for(long u = z/p;u > 0;u /= p)e0 -= u;
        
//        long em = 0;
//        for(long u = n/P*p;u > 0;u /= p)em += u;
//        for(long u = r/P*p;u > 0;u /= p)em -= u;
//        for(long u = z/P*p;u > 0;u /= p)em -= u;
        
        long[] fact = new long[p*(q+1)+1];
        long[] ifact = new long[p*(q+1)+1];
        fact[0] = ifact[0] = 1;
        for(int i = 1;i <= p*(q+1);i++){
            if(i % p == 0){
                fact[i] = fact[i-1];
            }else{
                fact[i] = mul(fact[i-1], i, P);
            }
            ifact[i] = invl(fact[i], P);
        }
        
//        tr(ff(n, p, q, fact, ifact), ff(r, p, q, fact, ifact), ff(z, p, q, fact, ifact));
        long ret = 1;
        while(n > 0){
            ret = mul(mul(mul(
                    ret, ff(n, p, q, fact, ifact), P),
                    invl(ff(r, p, q, fact, ifact), P), P),
                    invl(ff(z, p, q, fact, ifact), P), P)
                    ;
            n /= p; r /= p; z /= p;
        }
        ret = mul(ret, pow(p, e0, P), P);
//            if(!(p == 2 && q >= 3) && (em&1)==1){
//                tr("kimasi");
//                ret = (P-ret) % P;
//            }
        
        return ret;
    }
    
    public static long invl(long a, long mod)
    {
        long b = mod;
        long p = 1, q = 0;
        while(b > 0){
            long c = a / b;
            long d;
            d = a; a = b; b = d % b;
            d = p; p = q; q = d - c * q;
        }
        return p < 0 ? p + mod : p;
    }
    
    public static long ff(long n, int p, int q, long[] fact, long[] ifact)
    {
        long u = n/p;
        int v = (int)(n%p);
        boolean plused = q % 2 == 0;
        if(plused)q++;
        
        int r = (q-1)/2;
        long P = 1;
        for(int j = 1;j <= q;j++)P *= p;
        long PP = P / p * (p-1);
//        tr(n, p, q, u, v, r, P, PP);
        
        long ret = fact[v];
        outer:
        for(int j = 1;j <= r;j++){
            long[] betanums = new long[2*r+1];
            long sign = 1;
            for(int i = -r;i <= r;i++){
                if(i != j && -i != j){
                    if(u-i == 0)continue outer;
                    betanums[i+r] = u-i;
                    if(betanums[i+r] < 0){
                        sign *= -1;
                        betanums[i+r] *= -1;
                    }
                }
            }
            for(int i = -r;i <= r;i++){
                if(i != j && -i != j){
                    long w = j-i;
                    if(w < 0){
                        sign *= -1;
                        w *= -1;
                    }
                    for(int k = 0;k <= 2*r;k++){
                        if(betanums[k] != 0){
                            long g = gcd(betanums[k], w);
                            betanums[k] /= g;
                            w /= g;
                        }
                    }
                    if(w != 1){
//                        throw new AssertionError("dead");
                    }
                }
            }
            long beta = sign == -1 ? PP-1 : 1;
            for(int k = 0;k <= 2*r;k++){
                if(betanums[k] > 0){
                    beta = mul(beta, betanums[k], PP);
                }
            }
            
            long po = pow(fact[j*p], beta, P);
            ret = mul(ret, po, P);
        }
        if(p == 2 && ((u*2%8 >= 3 && u*2%8 < 7) != (ret % 4 == 3)))ret = P-ret;
        
        outer2:
        for(int j = 1;j <= q-1;j++){
            long cell = mul(mul(fact[j*p+v], ifact[j*p], P), ifact[v], P);
            long[] alphanums = new long[q];
            long sign = 1;
            for(int i = 0;i <= q-1;i++){
                if(i != j){
                    alphanums[i] = u-i;
                    if(u-i == 0)continue outer2;
                    if(alphanums[i] < 0){
                        sign *= -1;
                        alphanums[i] *= -1;
                    }
                }
            }
            for(int i = 0;i <= q-1;i++){
                if(i != j){
                    long w = j-i;
                    if(w < 0){
                        sign *= -1;
                        w *= -1;
                    }
                    for(int k = 0;k <= q-1;k++){
                        if(alphanums[k] != 0){
                            long g = gcd(alphanums[k], w);
                            alphanums[k] /= g;
                            w /= g;
                        }
                    }
                    if(w != 1){
//                        throw new AssertionError("dead2");
                    }
                }
            }
            long alpha = sign == -1 ? PP-1 : 1;
            for(int k = 0;k <= q-1;k++){
                if(alphanums[k] > 0){
                    alpha = mul(alpha, alphanums[k], PP);
                }
            }
//            tr("alpha", j, r, cell, alpha);
            long po = pow(cell, alpha, P);
            ret = mul(ret, po, P);
        }
        
        if(plused){
            return ret % (P/p);
        }else{
            return ret;
        }
    }
    
    public static long gcd(long a, long b) {
        while (b > 0) {
            long c = a;
            a = b;
            b = c % b;
        }
        return a;
    }
    
    
    public static long pow(long a, long n, long mod) {
        //        a %= mod;
        long ret = 1;
        int x = 63 - Long.numberOfLeadingZeros(n);
        for (; x >= 0; x--) {
            ret = mul(ret, ret, mod);
            if (n << 63 - x < 0)
                ret = mul(ret, a, mod);
        }
        return ret;
    }
    
    public static long mul(long a, long b, long mod)
    {
        if(a >= mod || a < 0)a %= mod;
        if(a < 0)a += mod;
        if(b >= mod || b < 0)b %= mod;
        if(b < 0)b += mod;
        
        long ret = 0;
        int x = 63-Long.numberOfLeadingZeros(b);
        for(;x >= 0;x--){
            ret += ret;
            if(ret >= mod)ret -= mod;
            if(b<<~x<0){
                ret += a;
                if(ret >= mod)ret -= mod;
            }
        }
        return ret;
    }

    
    public static void main(String[] args) throws Exception
    {
        long S = System.currentTimeMillis();
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        
        solve();
        out.flush();
        long G = System.currentTimeMillis();
        tr(G-S+"ms");
    }
    
    private static boolean eof()
    {
        if(lenbuf == -1)return true;
        int lptr = ptrbuf;
        while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
        
        try {
            is.mark(1000);
            while(true){
                int b = is.read();
                if(b == -1){
                    is.reset();
                    return true;
                }else if(!isSpaceChar(b)){
                    is.reset();
                    return false;
                }
            }
        } catch (IOException e) {
            return true;
        }
    }
    
    private static byte[] inbuf = new byte[1024];
    static int lenbuf = 0, ptrbuf = 0;
    
    private static int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
    
    private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
    
    private static double nd() { return Double.parseDouble(ns()); }
    private static char nc() { return (char)skip(); }
    
    private static String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    private static char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    
    private static char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
    
    private static int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
    
    private static int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private static long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}
