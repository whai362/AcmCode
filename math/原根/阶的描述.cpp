求一道数论题目 证明若b是a模n的逆元，则ordn(a) = ordn(b)。（a模n的阶等于b模n的阶）
设a模n的阶为m，则m是满足a^m≡1 (mod n)的最小正整数。
设b模n的阶为k，则k是满足b^k≡1 (mod n)的最小正整数。
由于b是a模n的逆元，所以有ab≡1 (mod n)，
可得a^(m-1)≡b (mod n)，
所以b^k≡a^(km-k)≡1 (mod n)。
又由于m是满足a^m≡1 (mod n)的最小正整数，
所以km-k被m整除，而m-1与m是互素的，有k被m整除。
同理我们还可以得到也m被k整除。
综上可得m=k，即a模n的阶等于b模n的阶。
