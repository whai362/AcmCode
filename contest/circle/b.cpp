#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
long long x, y, t;
long long egcd(long long a, long long b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        long long e = egcd(b, a % b);
        t = x; x = y; y = t - a / b * y;
        return e;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    long long m1, m2, r1, r2, d, c, t;
    bool sb;
    int n;
    while (cin >> n)
    {
        sb = 0;
        cin >> m1 >> r1;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> m2 >> r2;
            if (sb) continue;
            d = egcd(m1, m2);
            c = r2 - r1;
            if (c % d)
            {
                sb = 1;
                continue;
            }
            t = m2 / d;
            x = (c / d * x % t + t) % t;
 
            r1 = m1 * x + r1;
            m1 = m1 * m2 / d;
        }
        if (sb)
            cout << -1 << endl;
        else
            cout << r1 << endl;
    }
 
}
