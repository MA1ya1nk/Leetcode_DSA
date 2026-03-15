class Fancy {
    const long long MOD = 1e9 + 7;
    vector<long long> seq;
    long long mult = 1, add = 0;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    long long modInverse(long long a) {
        return power(a, MOD - 2, MOD);
    }

public:
    Fancy() {}

    void append(int val) {
        // Store val neutralized by current cumulative transforms
        // So that when we apply (x * mult + add) we get val back
        long long v = (val - add % MOD + MOD) % MOD;
        v = v * modInverse(mult) % MOD;
        seq.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mult = mult * m % MOD;
        add  = add  * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= (int)seq.size()) return -1;
        return (seq[idx] * mult % MOD + add) % MOD;
    }
};