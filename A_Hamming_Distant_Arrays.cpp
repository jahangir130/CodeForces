#include <bits/stdc++.h>
using namespace std;
 
// --Jahangir--BUBT_CSE_55_8--//

class Solver {
    static const long long MOD = 998244353;
    int N;
    vector<long long> fact, invFact, A, W;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return power(x, MOD - 2);
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long nCrLarge(long long n, int r) {
        if (r < 0 || r > n) return 0;
        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) num = num * ((n - i) % MOD) % MOD;
        for (int i = 1; i <= r; i++) den = den * i % MOD;
        return num * modInverse(den) % MOD;
    }

public:
    Solver(int n) : N(n) {
        fact.resize(N + 1);
        invFact.resize(N + 1);
        A.resize(N + 1);
        W.resize(N + 1);
        fact[0] = invFact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invFact[i] = modInverse(fact[i]);
        }
    }

    long long solve() {
        for (int c = 1; c <= N; c++) {
            vector<vector<long long>> dp(N + 1, vector<long long>(N + 1));
            dp[0][0] = 1;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j <= N; j++) {
                    if (!dp[i][j]) continue;
                    for (int k = 0; k <= c && j + k <= N; k++) {
                        dp[i + 1][j + k] = (dp[i + 1][j + k]
                            + dp[i][j] * nCr(N - j, k)) % MOD;
                    }
                }
            }
            A[c] = dp[N][N];
        }

        for (int c = 1; c <= N; c++) {
            W[c] = (A[c] - A[c - 1] + MOD) % MOD;
        }

        int maxSum = N - 1;
        vector<vector<long long>> dpSeq(N, vector<long long>(maxSum + 1));
        dpSeq[0][0] = 1;

        for (int k = 1; k < N; k++) {
            for (int s = 0; s <= maxSum; s++) {
                for (int cost = 1; cost <= s; cost++) {
                    int c = cost + 1;
                    if (c > N) break;
                    dpSeq[k][s] = (dpSeq[k][s]
                        + dpSeq[k - 1][s - cost] * W[c]) % MOD;
                }
            }
        }

        long long ans = 0;
        long long W1 = W[1];
        long long total = 1LL * N * N;

        for (int k = 0; k < N; k++) {
            long long pos = nCrLarge(total, k);
            long long base = power(W1, total - k);
            long long ways = 0;
            for (int s = k; s <= maxSum; s++) ways = (ways + dpSeq[k][s]) % MOD;
            ans = (ans + pos * base % MOD * ways % MOD) % MOD;
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Solver solver(N);
    cout << solver.solve() << '\n';
    return 0;
}
