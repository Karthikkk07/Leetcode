
class Solution {
private:

    int countAtMost(vector<int>& nums, int limit) {
        if (limit < 0) {
            return 0;
        }

        int left = 0;
        int oddCount = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            while (oddCount > limit) {

                if (nums[left] % 2 != 0) {
                    oddCount--;
                }

                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};