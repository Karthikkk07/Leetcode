class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;

        for (int num : nums) {
            xorr ^= num;
        }

        long long bit = xorr & -xorr;

        int a = 0;
        int b = 0;

        for (int num : nums) {
            if (num & bit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};