class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == divisor)
            return 1;

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (divisor == 1)
            return dividend;

        bool sign = true;

        if (dividend >= 0 && divisor < 0)
            sign = false;

        if (dividend < 0 && divisor >= 0)
            sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long ans = 0;

        while (n >= d) {

            long long temp = d;
            long long multiple = 1;

            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            ans += multiple;
        }

        return sign ? ans : -ans;
    }
};