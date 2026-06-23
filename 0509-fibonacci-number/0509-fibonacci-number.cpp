class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int last = 1;
        int slast = 0;
        int curr;

        for (int i = 2; i <= n; i++) {
            curr = last + slast;
            slast = last;
            last = curr;
        }

        return last;
    }
};