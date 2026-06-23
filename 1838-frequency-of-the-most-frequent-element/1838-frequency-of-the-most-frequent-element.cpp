class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int l = 0, maxFreq = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

           
            while ((long long)(r - l + 1) * nums[r] - sum > k) {
                sum -= nums[l];
                l++;
            }

            maxFreq = max(maxFreq, r - l + 1);
        }

        return maxFreq;
    }
};