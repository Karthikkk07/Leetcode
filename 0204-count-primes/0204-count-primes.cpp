class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Only store odd numbers
        vector<bool> isPrime(n, true);

        isPrime[0] = isPrime[1] = false;

        // All even numbers > 2 are not prime
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }

        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 1; // 2 is prime

        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};