class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0 || (n % 10 == 0 && n != 0)) return false;

        long long revHalf = 0;  // 🔥 changed to long long

        while (n > revHalf) {
            int ld = n % 10;
            revHalf = revHalf * 10 + ld;
            n /= 10;
        }

        return (n == revHalf || n == revHalf / 10);
    }
};