long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// if gcd(a,m)!=1, inverse does not exist.

//Fermat little theorem:
// A^(M-1)=1 mod M
// Multiply A^-1 on both sides
// A^-1 = A^(M-2)mod M => find using binary exponentiation
// USE ONLY WHEN 'M' is Prime=> Ex: 10^9+7
long long moduloMulInverse(long long a,long long mod)
{
    return binpow(a,mod-2,mod);
}

// A and M should be coprime
// IMP:  Extended Euclid algo to find Modulo Multiplicative Inverse 
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
 
    if (M == 1){
        return 0;
    } 
    while (A > 1) {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
 
    if (x < 0){
        x += m0;
    }
    return x;
}
