class Solution {
public:
    int findMin(vector<int>& nums) {
        int minval=INT_MAX;
        int n=nums.size();
        for (int i=0;i<n;i++){
            minval=min(minval,nums[i]);
        }
        return minval;
    }
};