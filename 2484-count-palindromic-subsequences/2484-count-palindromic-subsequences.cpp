class Solution {
public:
    int pre[10000][10][10];
    int suf[10000][10][10];

    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        // Clear arrays in case the same object is reused
        memset(pre, 0, sizeof(pre));
        memset(suf, 0, sizeof(suf));

        int cnt[10] = {};

        // Build prefix pair counts
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';

            if (i > 0) {
                for (int a = 0; a < 10; a++) {
                    for (int b = 0; b < 10; b++) {
                        pre[i][a][b] = pre[i - 1][a][b];
                    }
                }
            }

            // Add pairs: a ... c
            for (int a = 0; a < 10; a++) {
                pre[i][a][c] += cnt[a];
            }

            cnt[c]++;
        }

        memset(cnt, 0, sizeof(cnt));

        // Build suffix pair counts
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - '0';

            if (i < n - 1) {
                for (int a = 0; a < 10; a++) {
                    for (int b = 0; b < 10; b++) {
                        suf[i][a][b] = suf[i + 1][a][b];
                    }
                }
            }

            // Add pairs: c ... a
            for (int a = 0; a < 10; a++) {
                suf[i][a][c] += cnt[a];
            }

            cnt[c]++;
        }

        long long ans = 0;

        // Choose the center
        for (int i = 2; i < n - 2; i++) {

            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {

                    // Left:  a ... b
                    // Right: b ... a
                    ans += 1LL * pre[i - 1][a][b]
                         * suf[i + 1][a][b];

                    ans %= MOD;
                }
            }
        }

        return ans;
    }
};