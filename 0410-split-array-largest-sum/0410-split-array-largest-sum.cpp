class Solution {
public:

    int countPartitions(vector<int>& nums, long long maxSum) {
        int partitions = 1;
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } 
            else {
                partitions++;
                currentSum = num;
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());

        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countPartitions(nums, mid) <= k) {
                high = mid;
            } 
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};